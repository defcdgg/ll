# 函数清单与生成管线重构计划 (TSV 化)

> 前提: 全树 `make`+SHA1 绿; 全部工作未提交 (用户已 tar 备份); **重构期间禁止 commit**, 完成后统一提交。
> 执行方式: 每个 R 步做完过"验收门"，用户确认后才进下一步。
> 生成日期: 2026-09-01。
> **进度: R0-R4 ✅ 完成。R0-R3 (functions.tsv 取代并删除 functions.yaml; gen_asm 增量等价; audit/atlas/auto_match 切 TSV; merge=union);
> AGENTS.md 开工手册 + TSV note 列; R4 (rename_fn.sh 两轮自反演练 SHA1 绿; match_fn.sh 三场景干跑通过)。
> 追加完成: R5 (make code.s/asm/verify/remaining 四目标 + gen_reports.py; ida_rename.py 推迟到有 i64 时)。
> **全部完成 (R0-R7): 终验四项全过 (SHA1 绿/591 全量 fncheck OK/gen_asm 幂等/audit 0 漂移);
> 统一提交 4 commit (工具链/函数清单/源码/文档) + tag post-tsv-refactor。重构收官, 可复工并行匹配。**

## 0. 待确认的默认决策 (逐步执行前一次性确认, 可单条否决)

| # | 决策 | 默认 |
|---|---|---|
| D1 | TSV 含 `kind` 列 (c/asm 区分真C与asm占位) | ✅ 要 |
| D2 | 单文件 `functions.tsv` + `merge=union`, 不分片 | ✅ 单文件 |
| D3 | functions.yaml 去留 | ✅ **已直接删除** (atlas/auto_match/audit 全部改读 TSV, 未走生成物过渡) |
| D4 | (已删)ASSIGNMENTS: 已删除, "分工总览"保留手写 | ✅ 混合 |
| D5 | git worktree 隔离 (REFACTOR_PLAN 待拍板(worktree)) | ⏸ 推迟到重构后复工时做 |

## R0 — 基线快照 (无风险, 纯读)

因为重构期间不 commit, git 不能作为回退点 (HEAD 落后 26k 行), 必须先自建文件级快照:

```
.scratch/refactor/snapshot/
  functions.yaml ll.cfg code.s linker.ld          # 函数清单与生成物
  src/ include/ asm-listing.txt sha256sums.txt   # 全源码 + asm 目录清单+哈希
  baseline.tsv                                    # 1065 行: addr|status|kind|name|tu (重构等价性对照的"旧答案")
```

**验收门**: snapshot 文件数与 sha256 清单落盘; `sha1sum -c ll.sha1` 仍绿。

## R1 — `functions.tsv` + 生成器 `scripts/tsv_init.py`

TSV 模式 (制表符分隔, 首行表头, 按 addr 升序):

```
addr	status	kind	name	tu	module
0x080002a0	1	c	VBlank_UpdateGameScreen	code_80002A0	M00
0x080055e8	0	asm	sub_80055E8	code_8005020	M03
0x08007bd0	1	c	MapZone_Trigger	code_8005020	M03
```

- **主键 = addr** (ll.cfg 实测 0 重复, 改名永不产生孤儿)。
- `kind` 推导: `[1]` 且 src 有真 C 定义 → `c`; `[1]` 且 src 是 `INCLUDE_ASM("asm/matchings")` → `asm`; `[0]` → `asm`。
- `name`/`tu`/`module` 是**缓存列**, 权威来源分别是 ll.cfg / src 归属 / modules.draft.yaml 区间。
- 行数必须 = functions.yaml 条目数 (1065); 每行 addr 能在 ll.cfg 反查到 name。

**验收门**: `tsv_init.py` 输出 1065 行; 与 R0 baseline.tsv 逐行 diff 为空; 重复 addr = 0。

## R2 — `scripts/gen_asm.py` (取代 split_asm.py)

行为:
1. 读 functions.tsv + ll.cfg + code.s。
2. 按 **addr→ll.cfg 当前名** 定位 code.s 函数块 (不信 TSV 缓存名; 不一致 → 报告 `drift: 0xADDR old→new`, `--sync` 回写缓存列)。
3. status=1 → `asm/matchings/<name>.s`; status=0 → `asm/nonmatchings/<name>.s`。
4. **增量写**: 内容不变不 touch (消灭 split_asm 全删重建 → 全量重编风暴)。
5. 孤儿清理: 目录里存在但 TSV 不要求的 .s → 删除并报告。
6. `--dry-run`: 只报告将写/将删, 不落盘。

**验收门 (等价性红线)**:
```
python3 scripts/gen_asm.py            # 全量生成一次
diff -r <(现 asm/ 快照) <(新生成 asm/)  # 必须为空
make build/src/code_8005020.o && python3 scripts/fncheck.py sub_8007BD0  # 抽查
timeout 900 make && sha1sum -c ll.sha1  # 绿
```

## R3 — 消费者切换 + audit 地址化

- ~~tsv2yaml.py~~ 不需要: yaml 已删除, 消费者直接读 TSV。
- `split_asm.py` → 薄壳: 打印 deprecation + 转调 gen_asm.py。
- `scripts/audit.py` 重写为 addr 键控:
  - 三方核对: TSV × ll.cfg × build/*.o (kind=c 走 fncheck; kind=asm 走 matchings .s 字节)。
  - (旧 ASSIGNMENTS 已删): `sub_XXXXXX` 型名字**直接取地址** join TSV (根治改名孤儿); 语义名按 name join; 两边都找不到 → 报 `stale-row`。
  - (实际: ASSIGNMENTS 已删, audit 改为 TSV 卫生检查 + status=1 全量字节核验)
- Makefile: `asm:` 目标指向 gen_asm; ADD_ASM_DEPS 机制不变。

**验收门**: `audit.py` 报 0 漂移 0 stale; `tsv2yaml` 产物与现 functions.yaml diff 为空; make+SHA1 绿。

## R4 — 工作流脚本 (根治本次改名事故类)

`scripts/rename_fn.sh <old> <new>` — 一条命令, 失败自动从 snapshot 回滚:
1. 前置: 函数已被 $DECOMP_AGENT 认领 (或 --force); 目标名不与 ll.cfg 任何条目撞车。
2. 备份将触碰的文件 → `.scratch/refactor/pre-rename/`。
3. 改 ll.cfg → 重出 code.s (gbadisasm, 与 git 版 cmp 幂等)。
4. 改 include/*.h 原型 + src/*.c 全部引用点 (INCLUDE_ASM stub 行 / 真 C 调用点) — **原型默认保持 K&R 或原样换名, 不自动升级签名** (本次事故根因; 需升级时人工确认后加 `--prototype`)。
5. gen_asm.py (增量) → 定向重编受影响 C 文件 → fncheck: 被改名函数 + 全部调用者。
6. 任一 FAIL → 自动回滚 + 非零退出。

`scripts/match_fn.sh <fn>` — 合入尾巴自动化: 校验 src 已是真 C → TSV 翻 `1 c` → tsv2yaml → gen_asm → make → SHA1 → audit → 提示 commit (重构期间跳过 commit)。

**验收门**: 拿一个已匹配函数演练 rename_fn (改名→改回, 两轮后 SHA1 仍绿); match_fn 对 `sub_8007BD0` 干跑 (已匹配, 应全绿 no-op)。

## R5 — make 目标 + 周边生成

- `make code.s` (gbadisasm 重出), `make asm` (gen_asm), `make verify` (make+SHA1+audit+全量 fncheck 扫描 kind=c), `make remaining [MODULE=code_80264C0]` (TSV 剩余报表, 直接回答"还剩哪些")。
- `scripts/ida_rename.py`: ll.cfg vs i64 名字 diff → 批量重命名脚本 (清 progress.md 的 IDA 同步欠账)。
- `docs/reports/` 已删 (静态快照过期); 需要时由 TSV+callgraph 重生成。

**验收门**: 四个 make 目标可用; reports 重生成后与旧 CSV 语义 diff 报告 (新增/消失条目) 人工过目。
> 实测: code.s/asm 幂等 0 写入; verify 全绿 591/591; remaining 四 C 文件 分组报表正常; gen_reports 产出 functions.csv+remaining.txt。
> 2026-09-05: 按上文 R5 结论 (静态快照过期) 删掉 functions.csv, gen_reports.py 只产 remaining.txt; 全量清单以 functions.tsv 为唯一来源 (已含 asm_lines 列)。残留 functions.csv 会在下次运行时自动清掉。
> 2026-09-05: remaining.txt 改为 remaining.md (Markdown 表格, 名称列链接 `../../asm/nonmatchings/<name>.s`, VS Code/VSCodium 里 Ctrl+Click 直接打开切片)。纯 .txt 编辑器无内置点路径跳转, 只有终端 fileLinks 与 Markdown 支持。残留 remaining.txt 下次运行自动清掉。

## R6 — 文档与并发规则

- `.gitattributes`: `functions.tsv merge=union` + 现有四行保留。
- `RULES.md`: 「符号改名管线」整节改写为 rename_fn.sh 流程; split_asm 相关表述全部替换; 新增规则: **改名不得顺手改原型签名** (本次事故, 附 5 字节教训)。
- `INCIDENTS.md`: 工作循环更新 (TSV 行 = 认领粒度不变, 冲突面从"改 yaml 任意行"缩到"改自己那行"); 事故记录追加本次改名事故。
- (PLAN.md 已删, 速查并入 AGENTS.md §4)
- (已删) `(已删)ASSIGNMENTS` 顶部加"本表状态列由 audit 生成, 勿手改"声明。

**验收门**: 文档内所有 `split_asm` / `functions.yaml 手改` 指引清零 (grep 验证)。

## R7 — 终验 + 统一提交

1. 全量 `make` + SHA1 绿。
2. `fncheck` 扫描: 全部 status=1 函数 (预期 ~590 个 OK)。
3. gen_asm 幂等: 连跑两次, 第二次 0 写入。
4. `audit.py`: 0 漂移 0 stale。
5. 提交 (重构后首次): 按逻辑拆 3-4 个 commit —
   ① 工具链+脚本 (scripts/, .gitattributes, Makefile)
   ② 函数清单 (functions.tsv + 生成物 yaml + ll.cfg/code.s 相关)
   ③ 源码 (src/ include/ linker.ld, 含 C 文件 拆分与改名)
   ④ 文档 (docs/, modules.draft.yaml) + tag `post-tsv-refactor`。

## 待拍板方案 (原 COLLABORATION §2 遗留, 重构后复工前决定)

- **worktree 物理隔离** (原方案 A ★★★★★): 每 agent `git worktree add ../ll-<X> -b agent/<X>` + 各自 setup.sh;
  build//ll.gba/.scratch/ 独立, 根除"make 编进别人半成品"。合并只剩 TSV/linker.ld/iwram.h (union 可自动)。
- **CI 钩子** (原方案 C ★★★☆☆): pre-commit 别跑全量 make (树常瞬时红会挡提交), 改为"只对本次 commit 触及的函数跑 fncheck"。

## 风险与回滚

| 风险 | 对策 |
|---|---|
| gen_asm 与 split_asm 输出不一致 | R2 等价性红线 diff -r 为空才继续; 否则逐字节定位修 gen_asm |
| audit 地址化后误报 stale | R0 baseline.tsv 对照; stale-row 只报告不自动改 |
| rename 演练搞坏树 | 两轮改名自反 (A→B→A), 结束必 SHA1 绿; 失败回滚 snapshot |
| 中途断电/会话断 | snapshot + 每步验收门都是可停留点; TSV 未切换前旧管线始终可用 |
| 其他 agent 在重构期间偷偷复工 | 开工前确认 .claims 无新增进行中锁; 每步开头 `claim.sh --list` 检查 |
