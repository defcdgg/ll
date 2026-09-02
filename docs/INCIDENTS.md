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
| 2026-09-02 | `rename_fn.sh sub_800661C MapScene_Load` 终验失败后下次 make 找不到 `asm/nonmatchings/sub_800661C.s` | 脚本失败回滚恢复了 `ll.cfg/code.s/functions.tsv`，但未恢复已删除的 asm 切片 | 用 `python3 scripts/gen_asm.py` 按恢复后的权威源重建 asm; 改名期间改用定向补丁并先跑 fncheck |
| 2026-09-02 | 实装 sub_804EF50 时, 我的 code_0.h 原型 / functions.tsv note / progress.md 条目被并发 agent 的 `git add -A` 提交 (2140bb6/f9a308d) 扫入 HEAD, 唯独 code_8044394.c 真身未扫 (HEAD 一度处于"note 说✅ 但代码仍 INCLUDE_ASM"的不一致态) | 多 agent 各自 `git add -A` 会连带提交别人工作区里未完成的共享文件改动 | 收尾改用**定向 `git add <自己的文件>`** 而非 `-A`; 提交前 `git diff --stat` 核对只含本次函数; 事后单独 commit code_8044394.c 补齐一致性 (fncheck 64B + SHA1 绿) |
| 2026-09-02 | 实装 sub_8048764 提交时, `git add functions.tsv docs/progress.md` 把 gpnux(sub_80207DC)/opencode(sub_804EF50) 未提交的台账note+progress段落一并扫进我的 commit 2140bb6 | 共享文件用整文件 `git add` 会吞掉他人未提交改动; 只对 src/*.c 用了 `git add -p` 选块, 对 functions.tsv/progress.md 疏忽了 | 共享文件 (functions.tsv/progress.md/code_0.h/linker.ld) **一律 `git add -p` 逐块选**, 提交前 `git diff --cached <file>` 核对只含自己行; 本次扫入的是他人**已完成**成果且内容正确、ROM 绿, 不回退 (后续 03b0965/f9a308d 已各自补交代码, 台账一致) |
| 2026-09-02 | 第二次踩同一坑: 提交 code_8010F10 挂起记录时 `git add docs/progress.md` 整文件, 把他人未提交的 `0x08088D80 地图场景描述符表` 段扫进我的 commit bbc02b6 | 明知上次教训仍对 progress.md 用整文件 add; 且当时该 commit 已被他人 4608fb0 压在下面无法安全 reset | 扫入的是他人**已完成**文档内容、未损坏、ROM 绿, 不回退不重写历史; **铁律: progress.md/INCIDENTS.md/functions.tsv/code_0.h/linker.ld 提交前必 `git add -p` + `git diff --cached` 核对**, 本会话已两次违反, 下次提交共享文档前先 mental check |
