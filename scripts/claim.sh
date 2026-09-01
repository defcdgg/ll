#!/usr/bin/env bash
# claim.sh -- 函数认领锁, 防止两个智能体同时改同一个函数 / 同一段共享文件
#
#   scripts/claim.sh sub_8052C24              # 认领 (原子); 已被别人占了则失败并显示持有者
#   scripts/claim.sh --note "寄存器home卡住" sub_8052C24   # 更新备注(状态变更)
#   scripts/claim.sh --release sub_8052C24    # 释放
#   scripts/claim.sh --list                   # 列出当前所有认领
#   scripts/claim.sh --table                  # 输出"进行中/挂起"Markdown 表 (贴到别处)
#
# 锁目录 .claims/ 建议加入 .gitignore (本地协调) 或提交 (跨机器协调)。

set -euo pipefail
cd "$(dirname "$0")/.."
D=.claims
mkdir -p "$D"

mode=add; note=""; funcs=()
while [ $# -gt 0 ]; do
  case "$1" in
    --release) mode=del; shift ;;
    --note)    note="${2:-}"; shift 2 ;;
    --list|--table) mode=$1; shift ;;
    *) funcs+=("$1"); shift ;;
  esac
done

if [ "$mode" = "--list" ] || [ "$mode" = "--table" ]; then
  shopt -s nullglob
  files=( "$D"/*.lock )
  if [ "$mode" = "--table" ]; then
    echo "| 函数 | 状态 | 备注 |"
    echo "|---|---|---|"
  fi
  for f in "${files[@]}"; do
    fn=$(basename "$f" .lock)
    st=$(awk -F= '/^status=/{print $2}' "$f")
    ag=$(awk -F= '/^agent=/{print $2}' "$f")
    nt=$(awk -F= '/^note=/{print $2}' "$f")
    if [ "$mode" = "--table" ]; then
      echo "| $fn | $st ($ag) | $nt |"
    else
      printf "%-22s %-10s %-12s %s\n" "$fn" "$st" "$ag" "$nt"
    fi
  done
  [ ${#files[@]} -eq 0 ] && echo "(无认领)"
  exit 0
fi

[ ${#funcs[@]} -eq 0 ] && { echo "用法: claim.sh [--release|--note TXT] <func>..."; exit 2; }

agent=${DECOMP_AGENT:-$(whoami)}
rc=0
for fn in "${funcs[@]}"; do
  f="$D/$fn.lock"
  if [ "$mode" = del ]; then
    rm -f "$f"; echo "released $fn"; continue
  fi
  # 原子认领: noclobber 重定向 = "不存在才创建", 同时允许自己更新自己的锁
  if [ -e "$f" ]; then
    hold=$(awk -F= '/^agent=/{print $2}' "$f" 2>/dev/null || echo '?')
    if [ "$hold" != "$agent" ]; then
      echo "SKIP $fn (已被 $hold 认领)"; rc=1; continue
    fi
    st=进行中; [ -n "$note" ] && st=挂起
    { echo "agent=$agent"; echo "status=$st"; echo "note=$note";
      echo "since=$(awk -F= '/^since=/{print $2}' "$f")"; } > "$f"
    echo "updated $fn ($st)"
    continue
  fi
  st=进行中
  [ -n "$note" ] && st=挂起
  if ( set -C; { echo "agent=$agent"; echo "status=$st"; echo "note=$note";
                 echo "since=$(date -Is)"; } > "$f" ) 2>/dev/null; then
    echo "claimed $fn -> $agent ($st)"
  else
    echo "SKIP $fn (竞态: 别人刚抢了)"; rc=1
  fi
done
exit $rc
