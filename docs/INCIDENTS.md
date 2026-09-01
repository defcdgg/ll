# INCIDENTS.md — 并发/构建事故记录

> 每次多 agent 事故追加一行 (时间 | 事件 | 根因 | 对策)。操作性铁律见 AGENTS.md §0。
> 历史来源: 原 INCIDENTS.md §3 (2026-09-01 拆分)。

## 事故表

| 时间 | 事件 | 根因 | 对策 |
|---|---|---|---|
| 20:14 | `(已删)ASSIGNMENTS` 里"智能体B 进行中: sub_80444A4"整行在我读后消失 | 并发编辑同一 md | 编辑前重读；状态表改由 `claim.sh --table` 生成 |
| 20:1x | `linker.ld` 报 `cannot move location counter backwards`（0x4A90 插在 0x4AA0 之后） | 手工插入未排序 | 方案 B 自动生成 + 排序 |
| 22:2x | 合入 sub_80528C8 后 SHA1 报 760 万字节差异，误以为是自己（r8 泄漏） | `make` 把别人 22:00-22:11 改的 code_1.c/code_1b.c/code_8005020.c 一起编进来 | `fncheck.py` 单函数自证 + `--blame` 归属 |
| 22:4x | 我用 `cp .scratch/linker.ld.orig linker.ld` 回退临时符号，**差点静默覆盖别人 22:38 的编辑** | 整体回退共享文件 | 铁律 3；改用逐行 edit |
| 22:2x | 我几次 `rm -rf .scratch` 可能删掉了别人的中间文件 | 共用临时目录 | 用 `.scratch/<agent>/`；已把 `.scratch/` 加入 .gitignore |
| 23:0x | `RULES.md` 出现**两套重号的规则 30-34** | 两个智能体同时往编号列表尾部追加, 各自从 30 开始 | 已重排为连续 1-53。**根治建议**: 规则改用稳定 ID(如 `R-FLATEXPR`)而非裸序号, 或每人只往自己那半段加号 |
| 23:5x | `fncheck.py` 把一个**完全正确**的函数报成 FAIL（地址差 4 字节） | 它优先用 `ll.map` 取地址, 而别人的改动让 ROM 布局漂移了 | 改为 `code.s` > `linker.ld` > `ll.map`。→ 规则 57 |
| 23:5x | 合入 sub_8052580 后 ROM 又红了（首个差异 0x080003D4, 在 sub_80002A0 里） | 别人 23:50 改了 `include/code_0.h` 原型（`sub_8008124`/`sub_80187A8` 等 111 行）→ 改变了 code_0.c 的代码生成 + 各 .o 尺寸漂移 | `fncheck.py sub_8052580` 确认自己 OK 后照常提交; 不背别人的锅也不去改别人的文件 |
| 21:0x | `src/data_87E83F0.c` 突然 `multiple definition of gWalkMoveDirLut/gSpriteTileCountTable` + `.rodata is not within region rom`（溢出 0xE8=232 B） | **新故障模式**: 该文件 171–766 行是一个 `/* ... */` 大注释块（装草稿）。agent 删掉了块内 486 行草稿正文, 但**留下了块起始的孤立 `/*`** → 下一个 `*/` 提前闭合, 把后面所有草稿定义变成 live 代码 | 修法: `git show HEAD:<file>` 回底 + 只重新贴回有效 hunk（本次是 2 处语义改名）。
  **教训**: 改大注释块时必须 `grep -n '/\*\|\*/' <file>` 配对检查; 删完立刻 `make` 而不是只看 diff |
| 21:0x | 同一文件里另一个 agent 把重复定义改名成 `gUnk_087E94FC_bytes` 来绕过 `conflicting types` | 把**症状当根因**: 真正问题是注释块失效, 不是名字撞车 | 遇到"突然多出一堆重复定义"先查注释/预处理边界, 不要靠改名绕过 |
| 21:1x | `make` 链接失败: `gWalkMoveDirLut` / `gSpriteTileCountTable` 各被定义两次 (`src/data_805769C.c` 20:45 与 `src/data_87E83F0.c` 21:02), 且 `.rodata` 溢出 `rom` 区 | 两个智能体分别把同一批 rodata 落地到自己的 TU, 都没查对方 | 按 23:5x 行先例: `fncheck.py Save_LoadContinue` 已 OK, 照常推进不背锅。**建议**: rodata 落地前先 `grep -rn '<符号名>' src/` |
| 2026-09-01 | 本侧实装 sub_8008CC0 时发现 INCLUDE_ASM 行已被并发 agent 替换为 ChoiceMenu_ResolveDest 真 C, code.s 中途被对方重生成 | INCLUDE_ASM 行消失 + functions.yaml/ll.cfg mtime 变化 | 编辑前重读 + 不回退对方成果; ll.cfg 函数改名前先 rg 确认现名 (本会话×1) |
| 2026-09-01 | git stash pop 被 tools/gbadisasm/Makefile 的 CRLF 幻影修改卡住 (内容 diff 为 0 但 git 视为已修改) | `diff <(git show HEAD:f) f` 退出码 0 | `git add <file>` 标记当前内容后再 pop; 根治需统一 .gitattributes 行尾 |

