# RULES.md — 经验库 (代码生成规律 / 坑 / 失败案例)

> **开工手册在仓库根 `AGENTS.md`** (铁律/函数清单/工作循环/permuter/工具)。本文只放**深度经验**:
> 写 C 前查同族规律、卡寄存器时查诊断与失败存档、改名/注册符号前查管线细节。持续追加。
> 历史来源: 原 RULES.md (2026-09-01 拆分)。

## agbcc (GCC 2.x) 代码生成规律

已验证的规律, 按 C 写法反推汇编形态:

> ⚠ **编号修正 (2026-09-01)**: 合并两份规则清单时 **72 / 78 / 86 / 87 / 88 各撞过一次号**。
> 已把每组里**靠后**的那条改编为 **97 / 98 / 99 / 100 / 101** (首现者保留原号,
> 所以指向首现者的旧引用全部仍有效)。标题行带“原误编为 N”后缀的就是改过的那条。
> 已知引用同步: AGENTS.md §3 “1-D”→规则99; progress.md 的 sub_8048818→规则97、
> “两个新规律”→规则100/101。若再在旧文档里看到歧义的 规72/78/86/87/88, 按上下文案例函数名判定。

1. **调用方侧的 u8 截断** (`lsls r0,#0x18; lsrs r0,#0x18`) = 被调函数首参类型是 u8
2. **加法操作数不交换**: 想要 `adds r4, r0, r1` (乘积在左) 写 `(u32)(i * 0xC8 + (u32)ptr)`,
   想要 ptr 在左写 `ptr + i * 0xC8`
3. **分支极性**: `if (!(x & 0x20)) A; else B;` → `ands; cmp; bne→B` 直落 A
4. **continue 形式**: `if (...) continue;` → `beq 循环增量处`, 比嵌套取反 if 贴合目标
5. **RMW 位标志**: `newval = CONST | read; write = newval;` (命名临时变量)
   - CONST 在左 → `adds r0, r2, #0` + `orrs r0, r1`
   - `|=` 会把读操作规范化到 r0, 有时需要这个形态 (对比选择)
6. **extern 具名符号防常量折叠**: 表基址/外设地址要在 linker.ld 注册成符号
   (GCC 不对符号基址做常量折叠, 池里保留完整地址; 字面常量会被折叠如 0x0839CE7C-0x71*4 → 0x0839CCB8)
7. **全局当数组直用**: `extern u8 arr[]; arr[i]` 比局部指针变量更贴近原始代码的寄存器分配
8. **单表达式 vs 多语句**: 间接调用 `tbl[idx](ptr)` 单表达式让 GCC2 先展开被调地址(表池在前);
   拆成两个池加载顺序相反的语句会颠倒
9. **flag 分支形状**: `val = load; flag = 1; if (val <= N) flag = 0;` →
   `ldrb; movs r2,#1; cmp; bhi; movs r2,#0` (1-初始化+条件清零, 不是 bge 反转)
10. **命名局部变量影响寄存器分配**: 临时变量的声明位置/命名会影响 home 寄存器
    (例: newval 命名临时变量强制结果落 r0, load 落 r1; `u8 val` 具名局部改变 flag 分支前的指令顺序)
11. **结构体成员访问 vs 裸指针偏移**: `ptr->field_BB = 0` 逐成员独立寻址
    (每成员 `mov rX, ip; adds rX, #off`, GCC 不做相邻偏移 CSE), 而 `*(u8*)(arg0+0xBB)` 系列会被
    CSE 成 `adds r1, #1` 连续递增。目标汇编出现 `mov ip, r0` 缓存 + 每成员 fresh 寻址 = 原代码是结构体成员访问
12. **闩自增调度**: `for(;;i++) { call(..., i+1, 1); }` GCC2 调度器自动把闩自增
    (`adds r4,#1; lsls; lsrs`) 吊到 bl 之前 —— 遇到"自增在调用前"的目标代码先试最自然形式,
    不要手工 `++i`/拆语句 (会被合并成经临时寄存器的形态)
13. **RMW 拆两条赋值**: `x = x & MASK; x = CONST | x;` 两条语句的调度与 `x = (x & MASK) | CONST`
    一条语句不同 (中间会插入其他语句的常量物化)。单语句不匹配时试拆分
14. **头文件类型冲突**: 定义带 struct 指针形参而头文件是 `void*` 时, 定义改用 `void *arg0` +
    函数体首行 `Struct *ptr = (Struct *)arg0;` —— cast 局部不影响代码生成 (已验证)
15. **表基址池加载位置决定 tbl 局部取舍**: 目标汇编里 `ldr rX, =表基址` 出现得早(首个实参求值前)
    → 用 `tbl` 局部变量且首语句赋值; 出现得晚(贴近首次使用) → 不用局部, 直接重复写 `表[arg].field` 表达式
    (CC4 案例=后者; sub_80210C0 案例=前者)。注意 tbl[0].field_X 无下标运算时 tbl 局部不会被传播优化掉
16. **switch 分发形状**: 少量 case 时 GCC2 生成 `cmp; beq case0; cmp; beq case1; b default`
    (beq 正跳转进 case 体), 而 if/else-if 生成 bne 跳过形状 —— 目标是 beq 链时改写 switch
    (sub_802093C 案例)。case 体只算地址/赋公共变量, store 放 switch 后, 载入值用命名临时
    (new_var) 才能落在独立寄存器
17. **三个连续 `sym = 0` 字节存储的寄存器轮换未解 → 已解**: sub_8020B54 目标把三个地址分配成
    r5/r6/r4 (池序不变), 任何语句顺序变体都得到 r4/r5/r6; agbcc local_alloc 按 QTY_CMP_PRI
    (=floor_log2(n_refs)*n_refs*size/life) 排序, 全 0 权重按 qty 序。
    ✅ **2026-09-02 解**: `do { gUnk_03000716 = 0; } while (0);` 屏障 (规则 113) 打破等优先级 tiebreak,
    最后一条 strb 的 qty 因屏障多一条 insn 的 life 变化, 权重不再相等, 分配轮换归位。
18. **permuter 高分解可能语义错误**: 置换可能把索引换成别的变量/把加法挪过分支,
    分数低但行为错 (案例: sub_8053138 的 70 分版用检查字节当索引、sub_805321C 的 45 分版
    在 if 路径引用未初始化 r6)。凡 permuter 改动过数据流的解, 合入前必须人工核对每条访存
19. **script 处理器族的值链寄存器分配**: `val = *ptr; val += N;` 分支两侧公共尾存时,
    目标要求 ldrh 直写 val 的寄存器 (r0) 且池常量落 r1; 现有写法 (数组索引/ofsPtr/+=)
    GCC2 都生成临时寄存器 —— 该类问题仍未解。sub_801A684 后来确认并非同一根因，已由规则 83 收尾
20. **循环内常量存储的外提**: `ptr->field_BC = 0` 的 0 常量会被 loop.c 当循环不变量外提,
    寄存器强制用 call-saved r7 (多 push)。long long 局部变量 (zero=0 后存其低字节) 可阻止外提,
    但 movs 的调度位置仍差 1 条 —— 卡住 sub_804C890 (75分)
21. **结构体数组寻址的两段形式**: 全局结构体内嵌数组 (如 gUnk_03004F20 的 0x18 偏移数组)
    用成员形式 `s.arr[i].f` 时 GCC 会把成员偏移折进 strh/ldrh 的立即数 (strh [r0,#0x18]);
    目标是两段寻址 (adds r2,#0x18 再 adds r0,r0,r2) 时要写显式字节指针:
    `*(u16 *)((u8 *)&sym + 0x18 + index * 24)` (案例 sub_801761C/sub_8017588)
22. **if/else-if 链 vs switch**: 目标是 `cmp;beq;cmp;beq;b` + 函数体放在链条之后(体外) = 原代码是
    `switch(x) { case N: ... break; }`; 若是内联布局(第一个 body 紧跟)则是 if/else-if
23. **不要把重读的全局缓存成局部**: 目标在函数调用后重读 `gUnk_XXX`(ldrb) 说明原代码没有局部缓存,
    每次直接写全局访问即可 (缓存反而多占寄存器导致 push {r4-r7})
24. **mask 链必须逐条语句**: `x &= ~3; x &= ~0xC;` 各自一条 —— 写成单表达式
    `x & ~3 & ~0xC` 会被 GCC2 代数折叠成 `x & ~0xF`, 指令序列完全不同
25. **`do { stmt; } while (0)` 屏障**: 包住某条语句可阻止 GCC2 与相邻语句合并/调度
    (permuter 常用此招)。**实测必要**: sub_8019148 的末位 `d &= ~0xC000` 去掉屏障后,
    GCC2 将它与前一条 `&= ~0x2000` 折叠成池常量, 指令序列改变 —— 屏障不可省略
26. **赋值表达式作存储地址**: `*(u16 *)(new_var = 0x04000008) = d;` ——
    命名变量+赋值表达式的形态改变 GCC2 对存储地址伪寄存器的处理
27. **初始化顺序即指令顺序**: `i = 0` 的 movs 出现在目标两个池加载之后 = 原 C 是
    `ptr = ...; i = 0;` 顺序, 声明处初始化(`u16 i = 0;`)会让 movs 提前
28. **寄存器差异不计入 asm-differ score 的假象**: score=0 不代表字节一致!
    终验用 `arm-none-eabi-objcopy -O binary --only-section=.text xx.o xx.bin && cmp xx.bin yy.bin`
29. **反向假象: 单函数 .o 的 score 会被"未重定位的字面池"污染**。
    真 C 编出的 .o 里字面池是 `.word 0` + `R_ARM_ABS32 gUnk_XXX` 重定位项,
    而 gbadisasm 生成的 target.o 池里是硬码值 —— 于是**逐指令全对也会报 score=400**
    (池被 objdump 解码成假指令)。正确做法: 先用绝对符号脚本部分链接, 再比字节:

    ```bash
    printf 'SECTIONS { .text 0 : { *(.text) } }\ngUnk_03004614 = 0x03004614;\n' > .scratch/abs.ld
    arm-none-eabi-ld -T .scratch/abs.ld -o .scratch/linked.o .scratch/t.o
    arm-none-eabi-objcopy -O binary --only-section=.text .scratch/linked.o .scratch/mine.bin
    arm-none-eabi-objcopy -O binary --only-section=.text permuter/<func>/target.o .scratch/tgt.bin
    cmp -l .scratch/mine.bin .scratch/tgt.bin   # 只剩 bl 编码差 = 已匹配
    ```

30. **GCC2 的 flatten_expr 会把加法链里的常量/符号地址归到最左项**。
    写 `dest = A + (B + K) + C` 无论怎么加括号都得到 `(A + K) + B + C`（K=常量或符号地址同理）。
    目标若是 `A + (B + K)` 的分步形式（先算 B+K 再与 A 相加）,
    **必须把 `B + K` 拆成独立语句的临时变量**, 单表达式无解 (sub_8007A1C)。

31. **赋给指针局部 vs 整数局部 会差一条 mov**。`dst = (u8*)((f0-1)<<15)` 当 f0 是 CSE 临时且已死时,
    GCC2 直接 `subs r0,#1; lsls r4,r0,#15`; 而 `bankOff = (f0-1)<<15`（u32 局部）会出
    `mov r1,r0; subs r1,#1; lsls r1,r1,#15`。目标里多出的那条 `adds rX,rY,#0` 就是
    “这里原本存的是整数临时变量”的确证 (sub_8007A1C)。

32. **字面量 vs extern 符号不只防常量折叠, 还会改变寄存器分配**。
    sub_8007A1C 里图块缓存基址写 `(u32)gUnk_02006000`（需在 linker.ld 注册）会多占一个 callee-saved
    变成 `push {r4-r7}`; 改回字面量 `0x02006000` 后与目标逐字节一致。
    即“能宏化/符号化”不等于“应该”, 以字节为准。

33. **有时需要一条“死 store”才能复现目标的寄存器分配**。
    sub_8007A1C 必须在声明处写 `u8 rows = gUnk_030046A0[arg0].field_9;`（后面会重赋值,
    该 store 被 GCC2 删除不发任何指令）, 否则字面池加载位置从偏移 4 跑到 8。
    症状：“逐指令序列归一化后完全相同, 但 push 多一个寄存器 / 池加载位置差两格” 时,
    试加或减一个死初始化、或改临时变量的类型（u32/指针）。

34. **循环体内两条独立 `adds` 的顺序由调度决定**。
    `*dest++ = *src++` 出 `adds r4,#2; adds r1,#2`, 目标要 `src` 先自增 ——
    写成 `*(u16*)dest = *(u16*)src; src += 2; dest += 2;` 仍会被调度回去,
    是 **permuter 的语句置换**找到的解 (sub_8007A1C)。

    `R_ARM_THM_CALL` 的 bl 偏移依赖最终链接地址, 单 .o 里必然不同, 不算真差异。
    一切以 `make` + SHA1 为准。(案例: sub_8052BA0 首试即此情况, score 假高 400, 实际字节一致)
35. **`strh` 紧跟 `ldrh` 再 `bl` = 原代码是两次独立访问**: 目标
    `strh r1,[r2]; ldrh r0,[r2]; bl sub_8008B14` 对应 `gU = expr; f(gU);` 两条语句,
    没有局部缓存也没有寄存器直传 —— 写成 `val = expr; gU = val; f(val);` 会少一条 ldrh。
    (案例 sub_8052BA0)
36. **同一函数内 `+` 与 `|` 可以混用且必须按目标拼**: `data[2] + (data[3]<<8)` 生成 `adds`,
    `data[2] | (data[3]<<8)` 生成 `orrs` —— 两者语义等价但字节不同, 必须逐分支照抄目标助记符。
    (案例 sub_8052BA0: 赋值侧用 `+`, 实参侧用 `|`)
37. **switch 不写 `default:` 才复现比较链分发**: 目标是 `cmp#1;beq; cmp#1;bgt; cmp#0;beq; b 尾`
    这种二分形状时, 写 `switch (x) { case 0: ... case 1: ... case 2: ... }` 且**不要加 default 标签**;
    加了 default 会多出一个空基本块, 分发顺序改变。(案例 sub_8052C24)
38. **每个 case 里重复写公共赋值, 不要外提**: 三个 case 各自 `ldr r1,=sym; movs r0,#0xff; strb`
    = 源码里每个 case 都写了 `gU = 0xFF;`。提到 switch 之后只会存一份, 少两份池加载 → 不匹配。
    (案例 sub_8052C24)
39. **跨调用存活的变量自然落被调保存寄存器**: 目标 `push {r4,r5,lr}` + `bl` 后仍用 `ldrb r0,[r4,#1]`
    说明 `data` 被分配到 r4 —— GCC2 local-alloc 会自动避开 call-clobbered 的 r0-r3, **不需要**
    手工加 `register` 或拆表达式。同理, 调用之后的 `*ptr += N` 必然重读 `ldr r0,[r5]`
    (r3 已被调用展平), 写 `data += N; *ptr = ...` 反而不匹配。(案例 sub_8052BA0/sub_8052C24)
40. **switch 的 case 贯穿(fall-through)会直接反映在布局上**: 目标里 case0 body 末尾**没有** `b 尾`
    而是直接接到 case1 body(物理相邻) = 源码 case0 少写一个 `break`。
    反过来, 两个 body 之间有 `b 尾` 就是有 break。建议加 `/* fall through */` 注释。
    (案例 sub_8052C90: case 0 → `sub_8009B44();` 贯穿到 case 1 → `sub_80089E0(3);`)
41. **只出现 `lsls r0,#0x18` 而没有配对的 `lsrs`** = 源码是 `(u8)ret != 0` 这类**只测零**的用法
    (左移保留零性, GCC2 省掉回移)。仍说明被调函数返回 u8, 但写法上不要手加 `(u8)` 强转。
42. **只用于分发/判断一次的指针不要当长命局部**: 目标 `ldr r0,[r4]; ldrb r0,[r0,#1]` 把值留在 r0
    (无独立 home) = 该值在源里只被读一次; 若目标把它放在 r2/r4 并在多处引用, 才需要命名局部。
    同一句 `data = (u8 *)*ptr;` 两种情况 GCC2 自己会区分, 不必改写。
    (对比: sub_8052C90 用 r0 一次性 vs sub_8052D4C 用 r4 多处引用)
    (案例 sub_8052D4C: `if (sub_8001030(...) != 0)`)
43. **两个都跳调用的指针同时住进 r4/r5 时的先后**: 被调保存寄存器从 r4 往上分配,
    **n_refs 大的先拿 r4**。sub_8052D4C 里 `data`(4 refs: 1 定 + 3 用) 拿到 r4,
    `ptr`(3 refs) 拿到 r5 —— 与目标一致, 无需干预。
44. **被调函数已匹配但没进头文件时的补法**: 先确认定义在调用点之前(否则之前是隐式 int 声明),
    再按定义的真实类型补上完全一致的原型 —— 同类型不会改变已有代码生成。
    (案例: 新增 `u8 sub_8001030(u16);` / `u8 sub_80010AC(u16);` 到 code_0.h, code_0.c 不受影响)
45. **`adds r0,#1; ldrb rX,[r0]` 连续走位 ≠ 数组下标**: 目标里地址逐次 +1 地读一串字节
    (且最后一个可能是 `ldrb rX,[r0,#1]`), 必须写成前递指针 `a1 = *(++p); ... ; a6 = *(p + 1);`;
    写成 `data[1]..data[6]` 会得到 `ldrb rX,[rBase,#N]` 偏移寻址, 字节不同。(案例 sub_80528C8)
46. **`return x != 1` 会编成无分支序列** `eors/negs/orrs/lsrs`; 想要目标的
    `cmp #1; beq L; movs #1; b end; L: movs #0` 分支形, 必须写成两条语句:
    `if (x == 1) { return 0; } return 1;`。(案例 sub_80528C8)
47. **GCC2 动用 r8 时的固定序言/尾声**: `push {r4,r5,r6,lr}; mov r6, r8; push {r6}; sub sp, #N`
    对应尾声 `add sp, #N; pop {r3}; mov r8, r3; pop {r4,r5,r6}; pop {r1}; bx r1`。
    能否复现取决于**活跃值个数刚好溢出 r0-r7**: sub_80528C8 需要 ptr + 6 个 u8 局部
    (其中 2 个溢到栈、1 个进 r8); 少一个局部就不进 r8, 多一个就多 push 一个寄存器。
    写法上就是普通的多局部变量, 不要手工干预。
48. **一串无分支的 `池加载 + ldrb + strb` 平行赋值**: 若 ptr 在整个过程中从未占用 scratch 寄存器,
    GCC2 会把它一直留在 r0 **不产生入口复制**(目标开头没有 `adds rX, r0, #0`)。
    反推时别因为没看到复制就以为写错了。(案例 sub_8052CF0)
49. **池常量先查具名符号**: 0x03001944 已有 `gMainGameState`。用名字写(更可读且防常量折叠);
    确实没符号时才新增 linker.ld 条目。
50. **并发陷阱: `make` 会把其他智能体改到一半的源文件一起编进来**。
    本轮 sub_80528C8 合入后 SHA1 报 760 万字节差异, 实际原因是 code_1.c / code_1b.c /
    code_8005020.c 在 22:00-22:11 被别人改动且缺 linker.ld 符号, 与本次合入无关。
    判定三步: ① `ls -l --time-style=+%H:%M:%S src/*.c` 看哪些文件 mtime 晚于你上次绿灯;
    ② 用 ll.map 把差异地址归属到 .o; ③ 只重编自己的对象
    `make build/src/<你的文件>.o` + 部分链接 cmp 自证清白。
51. **验证 r8/高位寄存器是否泄漏的新方法**: 把当前 TU 备份一份, 将目标函数换回
    `INCLUDE_ASM("asm/matchings", <func>);` 重编, 然后逐函数比对两个 .o 的反汇编字节:
    除目标函数外全部一致 = 无泄漏。比“等整个 ROM 绿”快得多且不受其他智能体干扰。
52. **单函数回环: 单独编 `sub_xxx.o` → dump 汇编 → 用 tools/asm-differ 对 `sub_xxx.s`**。
    这是**不依赖整 ROM 的唯一逐指令验证手段**, 多智能体并行时必用。一条命令:

    ```bash
    scripts/fndiff.sh <func> [候选.c]        # 默认用 permuter/<func>/base.c
    scripts/fndiff.sh sub_8052C24
    #    参考: asm/nonmatchings/sub_8052C24.s
    #    == sub_8052C24 : permuter/sub_8052C24/base.c ==
    #    TARGET ... CURRENT (630)
    ```

    它做的四步: ① 无 `permuter/<func>/compile.sh` 时自动生成(与 Makefile 同一套 flag:
    cpp → preproc → agbcc -O2 -fhex-asm -fprologue-bugfix → as); ② 无 `target.o` 时从
    `asm/nonmatchings/<func>.s` 拼 `macros/function.inc` 汇编出来; ③ 编候选到
    `.scratch/fndiff/<func>/mine.o`; ④ `diff.py -o -f mine.o -F target.o <func>`。
    已匹配的函数会自动回退用 `asm/matchings/<func>.s` 作参考, 所以也能当回归测试用。

    **score 解读规则**: 每个未重定位的字面池约值 400 分(规则 29), 所以
    `score ≈ 400 × 池个数 + 10 × 真差异行数`。典型: 无池函数应为 0;
    1 个池 400; 4 个池 1600。**score 不等于 0 不代表没匹配, 必须配合 fncheck 定性。**

    **匹配完成后必须固化胜出版本**(否则下次人跑 base.c 会得到完全不同的 score, 误以为没匹配):

    ```bash
    scripts/fndiff.sh --promote <func> permuter/<func>/<winner>.c   # 回写 base.c + 清理中间变体
    ```

    本轮实测: 4 个函数的 `base.c` 停在首个失败尝试上, score 与实际差 5-6 倍。
53. **两个验证工具分工**: `fndiff.sh` 看**逐指令形状**(快, 能定位到哪一行不对);
    `fncheck.py` 看**字节级定论**(自动施加池重定位 + 排除 bl 槽)。两个都不需要整 ROM 绿。
    标准顺序: fndiff 迭代到形状一致 → fncheck 确认 OK → 合入 → make 全量终验。
54. **⭐ 函数"返回类型非 void 但体内没有 return" 会把 r0 整个函数锁死 → 所有寄存器上移一位**
    (案例 sub_8008124, 破解过程见 progress.md)。
    症状: 指令序列逐条已完全一致, 但目标里 **r0 一次都没出现**, 且第 8 个横跨全函数的值被塞进 `ip`
    (Thumb-1 的 `ldr Rt,[pc,#imm]` / `strb Rt,[Rb]` 只认 r0-r7, 所以表现为
    `ldr r4,=sym; mov ip,r4` + 使用时 `mov r1,ip; strb r3,[r1]`)。
    机理: 非 void 且无 return → 没有任何指令写 r0 → flow 认为 r0 从入口一直活到结尾,
    `find_free_reg` 从 r0 往上扫时全程被拒, 于是临时量落 r1、主变量从 r2 起分配。
    写法: `u32 sub_8008124(void) { ...; gUnk_03004640 = i; }` —— **不要**补 `return 0;`
    (会多一条 `movs r0,#0` 并释放 r0, 分配立刻退回原样), 也**不要**改成 void。
    头文件里保持 K&R 式 `u32 sub_8008124();` 即可, 调用方 `f();` 不受影响。
    判据: 全 ROM 只有 sub_8008124 一个 nonmatching 函数完全不碰 r0 —— 见到 r0 缺席就想这条。
55. **⭐⭐ 遇到“无法解释的连续相同 `ldr`”或“相邻 I/O 寄存器共基址访问”, 先查 `include/gba/macro.h`**。
    不要自己拼 `REG_DMA3SAD/DAD/CNT` 或手造结构体 —— SDK 宏展开后就是原代码的形状:
    ```c
    #define DmaSetUnchecked(n, src, dest, control) {
        vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##n;   /* ← 共基址 + 偏移 0/4/8 */
        dmaRegs[0] = (vu32)(src);
        dmaRegs[1] = (vu32)(dest);
        dmaRegs[2] = (vu32)(control);
        dmaRegs[2];                                /* ← 就是那次“值未用的 volatile 空读”! */
    }
    #define DmaWait(n) { vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##n;
                         while (dmaRegs[2] & (DMA_ENABLE << 16)); }
    #define DmaCopy32(n, s, d, size) DmaSet(n, s, d,
        (DMA_ENABLE|DMA_START_NOW|DMA_32BIT|DMA_SRC_INC|DMA_DEST_INC)<<16 | ((size)/(32/8)))
    ```
    所以目标里的 `str r0,[r2,#0/#4/#8]` + 两条重复 `ldr r0,[r2,#8]` + `ands r0,#0x80000000`
    全部自然得到。sub_80527AC 的正解就是两行:
    `DmaCopy32(3, 0x0203DE00, 0x0600B800, gUnk_03000F24 * 64); DmaWait(3);` ——
    参考同族已匹配写法 sub_801A0F0。反例: 自己拼寄存器会多/少指令;
    改用 types.h 的 `DmaCnt` 位域 `->Enable` 会变成 `lsls #0x18; lsrs #0x18` 字节抽取, 也不对。
    同理先查: `CpuSet/CpuFastSet/CpuFastCopy`、`DmaFill*/DmaClear*`、`IntrEnable`、`SPI*` 等。
56. **`asm/matchings/<func>.s` 是"已匹配"的权威记录, 不要手工删改**。
    `scripts/gen_asm.py` 依据 `functions.tsv` + `ll.cfg` + `code.s` **增量重建** (内容不变不 touch);
    所以: 改完 TSV 必须跑 gen_asm; 不要直接编辑这两个目录里的文件;
    `fndiff.sh` 对已匹配函数回退用 `asm/matchings/<func>.s` 做参考, 因此它同时是回归测试。
57. **单函数对比的地址必须取 `code.s`, 不能取 `ll.map`**。
    并行开发中别人改完函数会改变各 .o 尺寸, 整个 ROM 布局跟着漂移。
    本轮实测: `sub_8052580` 在 ll.map 里是 `0x0805257c`, 而原始地址是 `0x08052580`(差 4 字节);
    拿漂移后的地址去比 baserom 会把一个**完全正确**的函数误报成 FAIL。
    正确优先级: `code.s`(原始反汇编, 永远等于 baserom) > `linker.ld`(数据符号 base+offset)
    > `ll.map`(仅兜底)。`scripts/fncheck.py` 已按此修正。
    推论: **ROM 红不等于你的函数错** —— 先 `fncheck.py <自己的函数>` 定性,
    再看 `--blame` 的首个差异地址属于谁。
    `--blame` 已能自动识别这种位移: 先采样定位主偏移量, 再把假差异剥掉 ——
    本轮实测 `差异 7381151 字节 → 真实内容差异 5997 字节`, 归属从“data.o 5.9M”
    变成可解读的 `code_1b.o 1108 / code_1c.o 257 / code_0.o 112`。
58. **目标里某寄存器第一次出现就是 RMW（`ands r2,r0` / `adds r3,r2,#1`）且从头没有被写入**
    = 源码是**未初始化的局部变量**（真 bug，不是参数）。
    判别方法: 看调用点 —— 若调用前没有给 r0-r3 赋值的动作（直接 `bl f`）, 就不是参数,
    而是原代码写了个没赋值的局部。GCC2 不删这个读也不优化它。
    改写成参数会多一条 `mov`, 预先赋值会多一条 `movs` —— 都不匹配。(案例 sub_8019E60)
59. **`do { for(...){...} } while(0);` 屏障会改变下一条指令的调度槽位**（规律25 的第二个实例）。
    sub_8019E60 里第二个循环的 `movs r1,#0` 目标位置在 `lsls r0,r0,#6` 与 `orrs r2,r0` 之间;
    不加屏障则 GCC2 把它留到 `orrs` 之后（差 4 字节）。同时需要两处“多写的临时变量”
    （`tmp = 0x400; attr &= ~tmp;` 与循环体内 `tmp = attr; map[i] = tmp;`）——
    只加其中一处仍差 4-8 字节; 把 tmp 拆成两个不同名变量也会退回 4 字节。
    这类“调度槽位”问题优先交给 permuter（本轮 base=60 → 找到 score=0）。
60. **定位 ROM 首差异时，要区分 BL 偏移和真正的代码错误**。本轮 `cmp -l` 首个差异在
    `0x080003D4`，表面上是 `sub_80002A0` 调用 `sub_805008C` 的 BL 偏移；继续比较
    `ll.map` 与 `code.s` 的函数起始地址后，发现真正原因是前序 `sub_804AC60` 少了 4 字节，
    使后续函数整体前移。排查顺序应为：`cmp -l` 找首字节 → 反汇编确认是否为 BL →
    对比该调用目标的地址 → 用 `fncheck.py` 验证调用者和被调函数，避免误改首个出现差异的函数。
61. **全局符号的有符号视图会直接改变 GCC2 的代码长度**。`gUnk_030009C5` 若声明为 `u8`，
    `sub_804AC60` 会省掉 `lsls/asrs #24`，函数短 4 字节；声明为 `s8` 后，agbcc 生成目标所需的
    `ldrb; lsls #24; asrs #24`，函数长度和后续布局恢复一致。只有一个使用点时，优先修正
    `iwram.h` 的符号类型；修改后必须检查所有引用并重新跑 `make` + SHA1，避免因类型变化影响其他函数。
62. **固定寄存器扩展不是纯 C 匹配方案**。`sub_80531A8` 的目标只与候选 C 相差
    `ptr/data` 的 `r1`/`r2` home；`register ... asm("r1")` 可以强行得到 60 字节一致，
    但这属于编译器扩展，会掩盖 GCC2 原始寄存器分配规律。项目要求保持可移植的纯 C 时，
    应保留语义正确的 C 草稿、函数状态继续标为 `[0]`，并在进度文档记录寄存器差异，
    不要为了让 SHA1 变绿而引入固定寄存器或内联汇编。
63. **头文件原型冲突要先排除并发竞态**。若 `make` 报“conflicting types”，但预处理后的声明和定义
    完全一致，可能是另一个智能体正在写共享头文件。先用 `make -B build/src/<module>.o` 单独重编，
    再运行 `fncheck.py`；确认对象可编译后才修改原型，避免把并发瞬态误当成代码错误。
64. **"两个分支结果相同"的空转 if 必须原样保留**（案例 sub_8052758）：
    目标 `cmp r0,#0; beq 尾; movs r0,#0` 且两条路径最终值完全一样 = 原代码写了
    `if (arg0 != 0) { arg0 = 0; }`。简化成 `arg0 = 0;` 只剩一条 `movs` → 少 6 字节。
    这类"语义冗余但代码存在"的形态是原作者的 bug/半成品，反编译时**不能顺手清理**。
65. **`u8` 形参永远拿不到 `x < 0` 这条指令**（案例 sub_804F0B8）。
    GCC2 对 u8 提升后的 `x < 0` 会报 "comparison is always false due to limited range"
    并**整条删除**（实测 `int f1(u8 a){ if(a<0) ... }` 直接变成 `movs r0,#0`）。
    所以目标里只要有 `cmp rX,#0; blt`，该变量就**不能**声明成 u8。
    但入口又有 `lsls rX,#0x18; lsrs rX,#0x18` 的零扩展 —— 两者共存的唯一写法是：
    **形参声明 `s32`，并在函数体第一句显式 `arg1 = (u8)arg1;`**（零扩展由这句产生）。
    实测 `s8`/`char` 形参会在每个有符号比较前多插一对 `lsls/asrs`；
    `s32 v = arg1;` 再比较则会被 cprop 把零扩展传过去、同样折叠掉 `<0`。
66. **一个函数可能需要多个 `do {} while(0)` 屏障，位置不同效果不同**（案例 sub_804F0B8）。
    该函数需要**两个**：一个包 `if (a==0 && b==0) return 0;`，另一个包三条 `arg1` 测试。
    只留后者差 7 字节（ret 落到 r4 而非 r5），只留前者差 48 字节，全去掉差 51 字节。
    屏障同时影响“寄存器 home 分配”和“`<0` 折叠是否发生”，不只是调度。
    探序方法：把“语句顺序 × 屏障位置”当成搜索空间写脚本穷举（本轮 6×4 组合命中），
    比手工试错快得多。
67. **多实参 K&R 调用: 把重复的基址表达式提成“声明处初始化”的局部指针**（案例 sub_8020974）。
    同一个 10 参调用 `sub_801B81C(...)`, 写法不同会产生两种完全不同的调度：
    - 内联写 4 次 `gUnk_08393B28[arg1].field_X` → GCC2 把地址 CSE 成 `adds r,#4` 连续递增，
      并把两个 `ldrb` 提前算好后塞进 r8/r9 → 多出一对 `push/pop {r5,r6}` + `mov r8,r3` 等 6 条指令。
    - 改成调用前先 `Unk_08393B28 *entry = &gUnk_08393B28[arg1];` → 基址先进 r4，
      4 个成员各自 `[r4] / [r4,#4] / [r4,#8] / [r4,#0xa]` **带位移独立寻址**，
      两个 `ldrb` 被推迟到 r1/r2 空出来之后，完全不碰高位寄存器 → 逐指令全等。
    判据：目标里出现 `ldr rX,[r4]; ldr rX,[r4,#4]; ldrh rX,[r4,#8]; ldrh rX,[r4,#0xa]`
    这种“同一基址 + 不同位移”= 原代码有一个结构体指针局部；
    若是 `adds r,#4` 连续递增 = 内联重复下标。另见规则 11。
    ⚠ 局部指针类型必须在函数之前：若 typedef 在文件更后面，**整块前移**即可（纯搬迁，
    不改任何函数的代码生成），别为了避开而再造一个别名 struct。
68. **`u8` 计数器的包含式上界会把截断放在循环闩上**（案例 sub_8016978）。
    `for (i = 0; i <= 0xF; i++)` 且 `i` 为 `u8` 时，GCC2 生成
    `adds r0,r1,#1; lsls r0,#0x18; lsrs r1,r0,#0x18; cmp r1,#0xF; bls loop`。
    这里比较的是截断后的新 `i`，同时命中分支的 `return i + 1` 也会生成同样的 u8 截断。
    如果目标尾部有这组 `lsls/lsrs`，不要把计数器改成 `s32`，也不要先把循环重写为
    `< 16` 后再假定代码生成等价；先保留源码的窄类型和包含式边界逐指令验证。
    本例还有两个地址池，但 `fndiff` 只报 score=400：`gInventory` 是已注册符号、候选 `.o`
    中需要重定位，ROM 表 `0x0839CFAA` 是硬编码常量。**score 不能按池数量机械估算**，
    应看 `objdump -r` 或直接以 `fncheck` 的“已施加 N 个池重定位”作为定论。
69. **连续同体的 switch case 会保留两端比较，布尔范围表达式可能被折叠**（案例 sub_801B878）。
    目标 `cmp kind,#8; bgt fallback; cmp kind,#6; blt fallback` 对应
    `switch (kind) { case 6: case 7: case 8: ...; default: ...; }`，其中 `kind` 为 `s16`。
    写成 `kind >= 6 && kind <= 8` 或 `kind > 8 || kind < 6` 时，GCC2 会规范化成
    `kind -= 6; kind <= 2`；拆成嵌套 if 又可能得到等价但不匹配的 `cmp #5; ble`。
    看到“先上界、后下界、区间内共用一个块”的形状，应优先尝试连续 case，而不是继续排列 if。
70. **调用前未改写的参数寄存器可能是在隐式转发实参**（案例 sub_801B878）。
    调用点以 `r2=sp` 传第三参数，包装函数只设置 `r0/r1` 就 `bl sub_801A884`，说明入口 `r2`
    必须原样活到 fallback 调用。若错误地把包装函数或被调函数声明成两参数，C 语义看似相同，
    但分配器会把 `arg0` 放进 r2，既覆盖真实第三实参，也产生 r2/r3 home 差异。
    应把原型写全为 `u8 f(u8 *arg0, u8 arg1, u8 *arg2)` 并显式传 `arg2`；ABI 会自然省掉
    对 r2 的重复赋值。反推原型时不仅看 callee 前紧邻的 mov，还要回溯入口寄存器是否一路未被改写。
71. **相同的入口 `u8` 截断不代表形参本身就是 `u8`**（案例 sub_8019748）。
    目标五个参数都出现 `lsls/lsrs #0x18`，但直接定义成五个 `u8` 形参会生成
    `push {r4,r5,lr}`，在索引乘 20 之后才把全局基址载入 r0，score=629。
    命中写法是五个 `u32` 形参先分别赋给五个独立 `u8` 局部，再用窄局部计算和存储；
    这样 GCC2 会把基址提前放进 r6，生成 `push {r4,r5,r6,lr}`，第 5 参数也因此从
    `[sp,#0x10]` 读取。这里局部收窄既负责截断，也改变 local-alloc 的生命周期与寄存器压力。
    受控实验还表明 `ptr = (u8 *)global + index * 0x14` 本身即可命中，不必机械拆出
    `u8 *tbl = (u8 *)global`；判断因果时一次只改变形参类型、局部变量或地址表达式中的一个因素。
72. **语义相同的 switch fall-through 与显式 return 仍会生成不同布局**（案例 sub_801B8AC）。
    case 6 调用函数后与 case 7/8 都返回 `arg1`；写成贯穿时 GCC2 会合并返回块并把 case 6 主体外置，
    比目标少 4 字节。目标在两处各有 `adds r0,r4,#0; b end`，因此 case 6 必须显式 `return arg1`，
    case 7/8 再写另一份 return。反推 switch 时要按物理重复块保留源级重复，不能只按语义合并。
97. **一个内存装载值要喂给两个用途时，把原变量声明成宽类型（u32）可让 load 直接落进它的 home 寄存器**。  *(原误编为 72, 2026-09-01 修重号)*
    案例 sub_8048818：目标为 `ldrb r2,[r0]`（formation → r2）`adds r0,r2,#0`（拷给 idx）
    `cmp r2,#0` / `subs r0,r2,#1` —— 测试和减法都**读 formation(r2)**，结果写 idx(r0)。
    写成 `u8 formation` 时 GCC2 把 load 放进临时量再**拷两份**
    （`adds r3,r0,#0; adds r2,r0,#0`，多 1 条指令，score 845）；
    改成 `u32 formation` + `u8 idx` 后 load 直接进 r2，只剩一次拷贝 → 命中。
    副作用正好对：`idx = formation`（u32→u8）无需截断，`idx = formation - 1` 才需要
    `lsls/lsrs #0x18` —— 与目标完全一致。
    与规则 71 同一类：**类型宽度是分配器输入，不只是语义标注**。
    另：本函数是接力完成的 —— 智能体 B 推到 25 分并在 progress.md 留下
    “permuter 用 new_var(u32) 分离调用实参”的线索，本条就是按该线索收尾。
    **所以挂起函数的备注要写具体（到“哪个量是什么类型”这一层），下一个人能直接接。**
73. **短路条件顺序可直接决定循环旋转，具名 ROM 符号还能阻止 `base+1` 池折叠**（案例 sub_80166A4）。
    目标在调用后先检查 `++i > 7`，未超限才读取并后增 `src`，对应
    `while (i <= 7 && (ch = *src++) != 0)`；把哨兵条件单独放在 while 顶部会生成另一种布局。
    若表基址写成硬编码 `0x08095028`，GCC2 会为首次 `src++` 另造 `0x08095029` 池；
    声明 `extern const u8 gUnk_08095028[]` 并在 linker.ld 注册绝对符号后，才会保留
    单一基址池和目标的 `adds src,#1`。
74. **`fndiff` 与 `fncheck` 测的不是同一个东西，结论冲突时以 `fncheck` 为准**。
    `fndiff.sh` 编的是 `permuter/<func>/base.c`（**候选**），`fncheck.py` 读的是
    `build/src/*.o`（**已合入 src/ 的真身**）。两者不一致 = 合进去的版本呷 permuter 里那个不一样
    （常见于：合入后又改了 src、或别人合入了旧版本、或正在迭代）。
    实测: sub_8045EB8 `fndiff=5` 但 `fncheck=FAIL` —— permuter 里 08:58 的新候选已对，
    但 src/code_1b.c 里合入的是旧版本。
    → **合入后必须跑一次 `fncheck`**（它才是对 src 的校验），别拿 fndiff 的分数当合入结论。
    ⚠ **但 `fncheck` 对仍是 `INCLUDE_ASM` 的函数会报假 OK**：它只比对 `build/*.o` 在该地址的字节，
    而 asm 占位编出来的就是原始反汇编 → 必然一致。实测 `sub_8009370`/`sub_8018E34`/`sub_804BE90`
    三个**未匹配**的挂起项 fncheck 全报 OK。所以判“是否真已匹配”要看
    `functions.tsv` 的 status 列（或 `audit.py` 的 status=1 字节核验），不能只看 fncheck。
75. **函数清单会漂移，定期跑 `python3 scripts/audit.py`**。
    它交叉核对 `functions.tsv` × `functions.tsv note 列` × `build/*.o` 字节，
    并列出各翻译单元的 mtime（10 分钟内被人改过的自动标“避开”）。
    本轮实测发现 **58 个函数已经匹配但函数清单还写“待开始”** —— 不查就是 58 个重复劳动。
    `--fix` 可自动校正（仅改已字节验证通过的行）。
76. **`x |= 0xFF` 这类“或全 1”字面量会被 GCC2 直接折叠掉整个 RMW**（案例 sub_804BE90）。
    u8 变量 `ptr[0] |= 0xFF;` 因 `ldrb` 已零扩展、值域已知 ≤0xFF，GCC2 折成
    `movs r0, #255; strb r0, [r4]` 两条。实测 5 种拼法全部折叠：
    `|=0xFF` / `=0xFF|ptr[0]` / `|=(u8)-1` / `|=~0` / `*ptr = *ptr|0xFF`。
    目标若是 `ldrb r0,[r4]; mov r1,r8; orrs r0,r1; strb r0,[r4]` 的真 RMW（且 r8 在 preheader 预置），
    **则掩码必然是一个变量**：写 `u8 mask; ... mask = 0xFF;` 放在循环内，
    GCC2 会当循环不变量提到 preheader 并因要跨 `bl` 存活而分配 r8 —— 形态自然全对。
    推广：目标里“常量先 `movs` 进寄存器再参与运算”且该寄存器是高位被调保存寄存器时，
    先想“这是个跨调用存活的变量”，而不是常量物化。
77. **规则 2（加法操作数顺序）不适用于指针加法**（案例 sub_804BE90）。
    `base + n*16` / `(u8*)((u32)n*16 + (u32)base)` / `&arr[n*16]` /
    `(u8*)((u32)base + n*16)` 四种写法得分 **完全相同**（均 65/132），
    `adds r4, r0, r1` vs `adds r4, r1, r0` 改不动 —— GCC2 对 `PLUS: pointer+int`
    做了规范化，指针固定放第二操作数。所以“乘积在左/在右”的拼法只适用于
    **纯整数加法**（如 sub_8020C58 的 `i * 0xC8 + (u32)ptr`），不要在指针地址上耗时间。
78. **结构体成员形式还会改变"可交换运算目的寄存器"的选择**（案例 sub_804C4D8，是规则 11 的新推论）。
    同一个 `x |= 0x40`：
    - `u8 *ptr; ptr[0] |= 0x40;` → GCC2 生成 `mov r0, ip; orrs r0, r1`，**目的寄存器是常量那个**；
    - `Unk_03000AE8 *entry; entry->field_0 |= 0x40;` → `adds r0, r1, #0; orrs r0, r7`，
      **目的寄存器是读回来的值**（= 目标形态）。
    机理：local-alloc 的 `combine_regs` 把 dest 与"在本 insn 死亡"的那个源操作数绑定；
    结构体形式让成员值成为独立 qty，改变了谁在此死亡。
    实测代价：非结构体的 13 种拼法（`|=CONST` / `=CONST|x` / `=x|CONST` / newval 两步 / 具名 b /
    flag 变量 / `do{}while(0)` 屏障）全停在 66~90 分，结构体形式**一击全等**。
    → **凡是 RMW 位标志的形态对不上，先换成结构体成员写法再试**，别在 `|` 的操作数顺序上穷举。
    类型冲突时不必改共享头：本地 `typedef struct {...} Unk_XXX;` +
    `(Unk_XXX *)&gUnk_XXX[idx * 16]` 转型即可（已验证字节不变）。
98. **尾部地址临时量能反向改变整个函数的寄存器 home**（案例 sub_8016758）。  *(原误编为 78, 2026-09-01 修重号)*
    当 switch 的比较链、case 顺序和指令数都已一致，却有两组稳定的寄存器互换时，
    不要只在 switch 内反复换类型。该函数把尾部单表达式 `x * 2` 提成具名
    `int xOffset` 后，入口保留的 `kind` 从 r3 归位 r1、动画 bit 从 r1 归位 r3，
    尾部也从“地址 r0 / 值 r1”归位为“地址 r1 / 值 r0”。原因是局部量改变了
    伪寄存器生命周期与分配优先级，即使它在控制流合流之后才出现，也会影响全函数分配。
    这类修改应一次只增加一个临时量，并同时观察入口和尾部，而不是只看改动附近。
79. **普通 RAM 不得用 `volatile` 当调度工具；先检查会被 DSE 删除的冗余写入**（案例 sub_801B81C）。
    `volatile` 只用于真实 IO 寄存器，不能为了阻止 GCC2 重排而加在普通对象或局部变量上。
    本例自然 setter 已逐指令相同，只是 `field_14` 的 store 被推迟跨过三个栈参数 load，score=130；
    指针局部、赋值表达式、声明顺序和 `do {} while (0)` 均无效。零分写法是在后面的 `field_10`
    写入后再次写 `field_14 = arg6`：第二次写被死存储删除，不增加目标指令，却改变调度依赖，
    使第一次 store 紧跟 arg6 的 load。遇到这种单纯调度差异，应对可疑冗余语句做消融实验；
    命中后保留并注释，不能按 C 语义“清理”掉。该规律与规则 64 的原作者冗余代码同类。
80. **固定内偏移可能被折进绝对池；异步共享字段的 volatile 必须有硬件语义证据**（案例 sub_8016E30）。
    直接反复写 `*(u32 *)(gUnk + 0x1C)` 时，GCC2 会把池变成 `gUnk+0x1C`，再为访问
    `gUnk[2/3/0xB]` 生成反向减法；先写 `u8 *state = gUnk` 才保留目标基址池和
    `[r4,#offset]`。本例的字段由串行 IRQ 路径同时访问，目标也在连续存储之间反复 `ldr`，
    因而将“指针字段本身”声明为 volatile 有真实异步语义，不违背规则 79；普通 RAM 不可照搬。
    此外，`i = 0` 与 `packet = field` 的源码顺序会直接决定调用后的 `movs`/`ldr` 顺序。
81. **相邻硬件寄存器若目标共享一个基址，就用 `REG_ADDR_*` 建寄存器块指针**（案例 sub_8016F30）。
    分别写 `REG_SIODATA8` 与 `REG_SIOCNT` 会让 GCC2 为 0x0400012A/0x04000128 各建一个池；
    目标却是一次 `ldr r2,=REG_ADDR_SIOCNT`，随后 `[r2,#2]` 和 `[r2]`。用
    `vu16 *sio = (vu16 *)REG_ADDR_SIOCNT` 既保留硬件命名，也复现共享基址。
    同函数还证明常量的局部类型会改变池加载 home：直接存 0xFEFE 会多一次 r1→r0 复制，
    先赋给 `u16 sioData` 才让 `ldr r0,=0xFEFE` 直达目标；共享零值则需独立 `u32 zero`。
82. **空 switch case 会固定比较树，即使它与 default 语义相同也不能删除**（案例 sub_801D12C）。
    外层显式 `case 4: break` 让 GCC2 先生成 `cmp #4; beq`，再分派 0..2 与 5；删掉后
    会压缩成 `0..2` 范围测试。第二个内层 switch 的 `case 0: break` 同样迫使目标生成
    `cmp #7; bgt`、`cmp #1; bge`、`b default`，删掉会改成升序范围检查并少 2 字节。
    另一个易误判点是类型：虽然值来自 `ldrb`，保存到 `s16` 后才会得到目标的 `bgt/bge`；
    用 `u8` 会变成 `bhi/bls` 并触发更激进的值域折叠。
83. **两个相同常量若只差物化顺序，可让一个恒等式延迟到 RTL 再折叠**（案例 sub_801A684）。
    本函数的语义已经完全一致，最后只差目标 `movs r1,#0; movs r0,#0` 与候选的反序。
    两个普通局部直接写 `zero8 = 0; zero16 = 0;` 时，GCC2 会把字节零传播到远处的 `strb`，
    先为两次 `strh` 生成半字零。把字节零写成无符号恒等式
    `zero8 = off0 & ~off0` 后，combine 仍把它化成 0，但保留较早的伪寄存器生成位置；
    随后的 `zero16 = 0` 因而生成第二条 `movs`，寄存器和顺序同时归位。
    该技巧不读取额外内存、不增加最终指令，也不需要 `volatile`。普通 RAM/局部变量仍禁止
    使用 `volatile` 调度；只有真实 IO 寄存器可以使用。
84. **循环比较的左右操作数位置会决定入口测试能不能常量代入**（案例 sub_80532DC）。
    目标入口测试是 `cmp r0,#0; bls`（即把 `i=0` 代入后的 `n > 0`），而底部测试是
    `cmp r7,r4; bhi`（r7=n 在左）。对应源码必须写 **`for (i = 0; n > i; i++)`**（界在左）。
    写成常见的 `i < n` 则得到 `cmp r4,r0; bcs`，combine 不会把 `i=0` 代入，差 22 字节。
    同理，循环上界若是表达式（如 `t >> 1`），先存进局部再用，否则 CSE 不成立。
85. **并发修改头文件原型会打断已匹配函数**（案例 sub_804F0B8）。
    他人把 `sub_804DD90` 从 `u8 (u8,u8)` 改回 K&R `u32 ()`（因为全原型会让另一个函数
    把 `0x6C+0x21` 折叠成 `0x8D`），导致本函数调用点少了返回值的 u8 截断（`lsls r0,#0x18`）。
    修法：不改共享原型，在**调用点显式截断** `if ((u8)sub_804DD90(a, 6) != 0)` ——
    按规律 41，只测零时 GCC2 生成 `lsls #0x18; cmp #0`（无配对 lsrs），与目标一致。
    推论：依赖“头文件原型带米截断”的匹配很脆，**调用点自己写截断更鲁棒**。
86. **`(u8)(x << 4)` 想要 `lsls #0x1c` + `lsrs #0x18`，必须先落进一个 u8 临时变量**
    （案例 sub_80140D0 / sub_8014124，半字节合并）。
    写成一条表达式 `byte = (u8)(nib << 4) | (byte & 0xF)` 时，agbcc 认为整条式子最后要
    截断，于是把 `nib << 4` 留在 SImode，改为在 `orrs` 之后补 `lsls #0x18; lsrs #0x18`
    ——指令条数相同但落点不同，差 260 分。拆成
    `hi = nib << 4; byte = hi | (byte & 0xF);` 后，u8 赋值强制在此处截断，combine 把
    `(x << 4) & 0xFF` 合成 `lsls #0x1c; lsrs #0x18`，并且因为两个操作数都已是 u8，
    末尾不再补截断，与目标逐条相同。
    推论：**目标末尾有没有 `lsls #0x18; lsrs #0x18` 就是判据** —— 有则合并结果需要截断
    （某个操作数是 int，如 `nib - 1`），没有则截断必须提前绑到某个子表达式上。
    同一函数的两条分支可以一条有、一条没有，别强行对称。
87. **同一个局部变量兼职两个无关值，可以同时买到寄存器 home 和 `adds rX, rY, #0` 拷贝**
    （案例 sub_8014084，permuter 找到）。
    目标入口是 `ldr r1, =0x03004DE4; strh r0, [r1]; movs r2, #0; ldr r4, =0x03004D60;
    adds r3, r1, #0`：计数器地址存在**两个**伪寄存器里，靠一条拷贝相连，而循环里
    `ldrb r1, [r0]` 又把 r1 抢回去装载入的字节。直觉写法（宏解引用两次）只产生一个
    地址伪寄存器，cse1 把循环内的常量并进它，于是它整段活着占住 r1，把字节挤到 r2、
    把 `i` 挤到 r3 —— 全函数指令形状全对，只差 3 个寄存器 home 加这条拷贝（660 分）。
    解法是让**一个 `u32` 变量先装地址、循环里再装载入的字节**：
    ```c
    u32 val;
    val = (u32)&gUnk_03004DE4;
    *(u16 *)val = 0;              /* 地址用途，占 r1 */
    for (...) {
        val = gUnk_03004D60[i >> 1];   /* 同一变量改装字节，r1 被复用 */
        if ((mask & val) != 0) gUnk_03004DE4++;   /* 独立常量 → 第二个伪寄存器 */
    }
    ```
    地址伪寄存器就此在入口块内死亡（归 local-alloc），循环里的计数器地址是另一个跨块
    伪寄存器（归 global-alloc），loop 把它提到 preheader、cse2 把冗余常量加载化成
    `adds r3, r1, #0`。三处寄存器 home 一次性归位。
    **这是 rule 29「变量复用」的最强形态**：不是为了省寄存器，而是为了制造伪寄存器的
    生死边界。凡是「指令全对、只差几个 home」的函数都值得试一遍。
88. **local-alloc 的 qty 优先级表只覆盖块内伪寄存器，跨块的 home 争议归 global-alloc**
    （工具：`scripts/qtydump.sh`，补丁 `scripts/patches/agbcc-qty-dump.patch`）。
    `local_alloc()` 只给**完整活在一个基本块内**的伪寄存器发号，`block_alloc()` 里
    按 `QTY_CMP_PRI = floor_log2(refs)*refs*size/life*10000` 排序（同分按 qty 号小者优先）。
    循环计数器、跨分支的指针、函数级长命值都由 global.c 分配，**不会出现在这张表里**。
    实测 sub_8014084 / sub_80531A8 的 qty 表只有 life 2-10、pri 1-6 万的短命量，
    真正决定 home 的 `i`/数组基址/载入字节一个都不在。
    所以：qty 表用来解释「同一基本块内两个临时谁先拿到低号寄存器」；
    看到跨块的 home 差异就别查它了，直接按 rule 87 改伪寄存器的生死边界。
    补丁只在 `block_alloc()` 末尾读数组打印（`qty_birth/death/n_refs` 是
    `local_alloc()` 的 alloca，`qty_order` 是 `block_alloc()` 的 alloca，
    到 `dump_local_alloc` 时全部悬空），由环境变量 `AGBCC_QTY_DUMP` 开关，
    编译成**独立**二进制 `tools/agbcc/bin/agbcc_qtydump`，构建管线始终用 `bin/agbcc`。
    已验证 10 个翻译单元的 .s 与原编译器逐字节相同。

99. **⭐⭐ 数据表的 C 声明维度会强制改变消费者的索引算术 —— 默认保持 1-D**。  *(原误编为 86, 2026-09-01 修重号)*
    把 `const u8 t[]` 改成 `const u8 t[4][4][2]` 不是"纯文档变更": 一旦消费者改写为
    `t[a][b][c]`, GCC2 会重算地址表达式, 生成完全不同的指令。实测同一语义三种写法:
    ```c
    /* A: 1-D + 预乘掩码 —— ROM 实际形态 */
    t[((attr0 >> 11) & 0x18) + ((attr1 >> 13) & 6)]      → lsr #0xb; mov #0x18; and; lsr #0xd; mov #6; and; add
    /* B: 3-D 声明 + t[shape][size][0] */
    t[(attr0 >> 14) & 3][(attr1 >> 14) & 3][0]            → lsr #0xe; lsl #0x1 / lsl #0x3,
                                                            且 attr1 先于 attr0 读, push 列表也变了
    ```
    两者指令数、顺序、寄存器分配全不同 → **必然不匹配**。
    判据: ROM 里出现 `& 0x18` / `& 6` / `& 0xC0` 这类**预乘字节偏移掩码**
    (而不是 `& 3` + 独立 `lsl`) = 原代码把表当**扁平字节数组用字节偏移索引**,
    声明就必须是 `u8[]`。
    → **逻辑维度写注释, 不要改类型**。要改类型必须先确认全部消费者已是真 C 且逐个 fncheck。
    (另见规则 21/67: 结构体成员形式同样会改变寻址形态, 同一类陷阱。)

100. **⭐⭐ 不要用 `goto` 复刻"跳过某个判断"的控制流 —— 给同一个 flag 赋值, 让 GCC2 的 jump-threading 自己生成绕过块**。  *(原误编为 87, 2026-09-01 修重号)*
    案例 `Stats_BuildSkillList` (原 sub_800A048)。ROM 的控制流是:
    ```
    cmp r0, #1
    bne _FLAGCHECK      ; 不满足 → 落到 flag 检查 (flag=0 会 continue)
    b   _ACCEPT         ; 满足   → **直接跳过** flag 检查进接受块
    _FLAGCHECK:
    adds r1, r2, #1
    cmp r5, #0
    beq _CONT
    _ACCEPT:
    ```
    看上去非 `goto` 不可。但项目禁用 goto。正确写法是把**两条路都写成 `flag = 1`**:
    ```c
    flag = 0;
    if (tbl[i*5] == 0xFF) {
        if (gPartyMemberIds[0] == 1)
            flag = 1;            /* ← 不是 goto, 也不是 continue */
    } else if (tbl[i*5] <= lvLimit)
        flag = 1;
    if (flag == 0)
        continue;
    *skills++ = i + 1;
    count++;
    ```
    GCC2 的 CSE/flow 能证明 `flag==1` 时后面的 `cmp r5,#0; beq` 必不跳，于是**自己把
    接受块线进那条路径**，包出的 `b _ACCEPT` 与 ROM 逐字节一致 (bytecmp: OK 156B)。
    实测对比 (同一函数): 用 `goto accept` 的写法残留 13 字节差且长度呷对；
    而上面的 flag 写法 **0 字节差**。→ **遇到"看起来要 goto/汇编才能凑出的控制流",
    先试把分支归约成对同一个变量的赋值**。

101. **u8 形参上的 `+1` 会生成移位域加法, 不是 `adds #1`** (规则 30 的新变体)。  *(原误编为 88, 2026-09-01 修重号)*
    `lvLimit = lv + 1;` 其中 `lv` 是 **u8 形参** 时, GCC2 先做零扩展 `lsls r1,#0x18`,
    然后把 `+1` 折进已移位的域里: `movs r0,#0x80; lsls r0,r0,#0x11` (即 1<<24) →
    `adds r1,r1,r0` → `lsrs r1,r1,#0x18`。写成 `u8 lvLimit = lv + 1;` 或先赋局部再加
    都得同样的形态; 但写成 `int` 局部或 `(u8)(lv+1)` 强转会退回 `adds #1`。→ 目标里看到
    `movs rX,#0x80; lsls rX,rX,#0x11` 就是 **1<<24**, 背下来能省一轮试探。

89. **u16→s16 的字段类型直接决定 ldrh/ldrsh, 错了整体位移**。`StaticMapObject.x/y/z` 与
    `ChestObject.x/y` 实为 **u16** (目标 `ldrh` 零扩展); 声明成 s16 会生成 `ldrsh` (符号扩展),
    单函数看着只差 2 字节, 但 `-8/+8` 的尺寸漂移让后续所有函数位移 → ROM 大面积红。
    → 见到 `ldrsh` 先查 struct 字段类型, 不要急着调 C 写法。实测×2 (2026-09-01)。

90. **被调返回值按 u8 原型读会多出 lsls 截断**。`if (Sprite_EnqueueRender(...) != 0)` 目标是
    直接 `cmp r0,#0` (无 `lsls r0,#0x18`) —— code_0.h 的 `u8` 返回原型对**个别调用点**是错的。
    解法: 本 TU 内声明 s32 原型 + 链接期同址别名 `Sprite_EnqueueRender_S32 = Sprite_EnqueueRender`
    (linker.ld), 不改共享头文件 (会牵连其他 TU 的已匹配调用点)。

91. **独立数据符号 vs 基址±偏移决定字面池布局**。目标用 `gfx=r4` 缓存 + `gfx+0x144` / `gfx-0x180`
    (movs+lsls 构造偏移) 时, C 必须写成 **同一指针变量的 ±偏移**; 换成独立符号 (gUnk_08087500 等)
    会多出 4 个池条目, 函数尺寸虽同但池位置不同 → 后续全部位移。→ Logo_LoadAssets 实测。
    反向: 目标用独立池常量时, 不要自作聪明合并成基址算术。

92. **在 TU 里定义"占位数组"会占 .data 导致 rom 溢出**。`u8 gUnk_08095028[][8] = {{}};` 让
    .data 长 8 字节, 链接报 `region rom overflowed by 8`。占位/前向引用一律 `extern const` +
    linker.ld 绝对符号, 数据本体留给数据区计划 (PLAN_DATA)。

93. **跨 TU 补原型必须同步 code_0.h 的空括号声明**。`void sub_X();` (K&R 未指定参数) 与真 C 的
    `void sub_X(u8)` 冲突 (`can't match an empty parameter name list declaration`)。
    实装函数时先 grep code_0.h, 把 `()` 升级为带参原型 —— 只影响本 TU 代码生成, 已匹配调用点
    无 C 引用时安全。

94. **注释块嵌套事故重演防范**: 在 `/* */` 草稿内追加 `/* ... */` 小节注释会提前闭合外层,
    后半草稿变成 live 代码 (`syntax error before /`)。改草稿前 `grep -n '/\*|\*/' <file>` 配对,
    改完立刻单文件编译。→ INCIDENTS.md 事故表 2026-09-01 再现。

95. **json.dump 整文件重写会打乱共享清单格式**。`scripts/data.json` 用 `json.dump(indent=1)`
    重写产生 4 万行假 diff。共享机器文件只做**定向字符串替换** (assert count==1) 保格式。

96. **硬件寄存器一律走 `REG_*` 宏 (volatile 类型), 真 C 与 permuter base.c 都不许用普通 u16 裸地址**。
    io.h 的宏本质是 `#define REG_BLDY (*(vu16 *)0x04000054)` —— `vu16 = volatile unsigned short` (types.h)。
    - 真 C 里写 `*(u16 *)0x04000054 = v;` (普通 u16) = **禁止**: volatile 不是装饰, 它改变代码生成
      (多次访问不被重排/合并、RMW 不被折叠、"值未用的空读"不被死代码消除), 非 volatile 版和 ROM 对不上。
    - **permuter 跑分同理**: base.c 不能 include 项目头, 必须把 io.h 的定义原样内联进去:
      ```c
      typedef volatile unsigned short vu16;
      #define REG_KEYINPUT (*(vu16 *)0x04000130)
      ```
      用普通 `u16` 定义寄存器宏, permuter 是在给**另一个程序**打分 —— 分数与真实构建脱钩 (假高分/假平台期)。
      先例: `permuter/sub_8050014/base.c`、`sub_8016F30/base.c`。
    - 宏名/地址必须从 io.h 抄 (寄存器号陷阱见 AGENTS.md §3: `0x04000054`=REG_BLDY 不是定时器);
      u16 寄存器的字节访问用 `*(vu8 *)&REG_x` (目标 ldrb/strb 时)。
    - 扫描违例: `grep -rnE '\(\s*(vu?16|u16)\s*\*\s*\)\s*0x04' src/*.c permuter/*/base.c` 应只命中 io.h 宏展开形态。
102. **⭐⭐ 数据符号的“拼写形式”会改变寄存器 home：强转宏 (`const_int`) ≠ extern 数组 (`symbol_ref`)**
    （案例 `Inv_FindHeldItemOnPage` / 原 sub_80169EC）。
    为了绕过未登记的 ROM 符号, 常见写法是 `#define gTable ((const u8 *)0x0839CFAA)`。
    这让 GCC2 看到一个 **`const_int` 地址常量**, 与真 `extern const u8 gTable[]` 产生的
    **`symbol_ref`** 走不同的 local-alloc 路径 —— 实测同一个函数里表基址被分到 **r2**,
    而 ROM 用的是 **r0**; 指令条数与形状全对, 只差 4 字节 (score 20)。
    改成在 `linker.ld` 登记绝对符号 + 头文件 `extern` 声明后逐字节命中 (score 20 → 0)。
    **推论**: 遇到“形状全对只差几个寄存器 home”时, 先查参与计算的地址常量是不是被写成了强转字面量;
    把旧宏换成真符号后**必须重跑 `audit.py`** —— 同文件里靠这个宏才匹配的兄弟函数可能反过来被带偏
    (实测 `Inv_FindFirstHeld`/`Inv_FindPrevHeld` 两种写法均 OK, 但不可假定普适)。
    另注意: 只有“多个 qty 抢寄存器”的函数才敏感; 单 qty 的函数两种写法同果。
     关联: 规则 87 (一个变量兼职两个值)、规则 88 (qty 优先级表只覆盖块内伪寄存器)。

103. **循环体用到的字面量 0, 先存入独立变量再参与赋值, 会让 agbcc 把 `movs rX,#0` 提到循环前 preheader 的最前面**（案例 `sub_80175C0`）。
     同一函数, 循环体 `p->field_0 = 0; p->field_2 = 0;` 直接写字面量时, 生成 `adds r4,#0x18; movs r0,#1; movs r1,#0` (零常量最后加载);
     改成 `zero = 0; p = &gSioSession.unk18[zero]; ... p->field_0 = zero; p->field_2 = zero;` 后,
     生成 `movs r1,#0; adds r4,#0x18; movs r0,#1` (零常量最先加载), 逐字节命中 (64B)。
     **推论**: 循环前 preheader 里几条独立 `movs`/`adds` 的先后顺序由“哪条指令先被数据流引用”决定;
     想指定某常量最先加载, 就把该常量当作变量先初始化、并让循环地址也经由它计算。
     关联: 规则 29 (字面池重定位误判)、规则 76 (home 互换) —— 都是“调度槽位/寄存器 home”类卡点,
     这类卡点用 permuter 探索语句顺序即可, 结构无需重排。

104. **memcpy/拷贝族函数的寄存器 home 由“参数/局部变量声明形式”决定，且“复合赋值 vs 两步赋值”改变 LSL 槽**（案例 `sub_8017640`）。
     目标形状: `adds r3,r0; adds r4,r1`（dst→r3、src→r4），字节路径 `lsls r2,r2,#2; subs r2,#1`（变换直接在 count 上做）。
     - **寄存器 home**: 形参写成 `void *dst, void *src` + 函数顶部先声明 `u8 *d; u8 *s;`（在 if 外集中声明）, prologue 才是 `dst→r3, src→r4`;
       一次性在分支内 `u8 *d = dst` 或直接用 `u8 *dst` 形参, 编译器生成反过来的 `adds r4,r0; adds r3,r1`（dst→r4、src→r3）, 全函数镜像偏移。
     - **LSL 槽**: `count = count * 4; count--;`（两句）生成 `lsls r2,r2,#2; subs r2,#1`（原地改 r2, 匹配）；
       `count = count * 4 - 1;`（一句）生成 `lsls r0,r2,#2; subs r2,r0,#1`（借用 r0, 多 2 字节）。
     - 两个分支各自循环用 `while (count != -1)` + 循环尾 `count--` 才产生 `movs r0,#1; negs r0,r0; cmp r2,r0` 的 -1 哨兵预检结构。
      **推论**: 拷贝族函数卡“寄存器镜像”时, 先试“形参 void* + 顶部集中声明指针局部变量”; 卡“差一条移位”时, 把复合赋值拆成两句。
     关联: 规则 87 (一个变量兼职两个值)、规则 103 (调度槽位)。

105. **u8 参数减 1 后当表索引时, 必须显式 `(u8)(x - 1)` 强转, 否则 agbcc 会把 -1 折叠进表基址产生错误序列**（案例 `sub_80166FC`）。
     目标序列 `subs r0,#1; lsls r0,r0,#24; lsrs r0,r0,#21`（(u8)(idx-1)<<3 的表指针计算）。
     写成 `gUnk_08095828[charId - 1]`（charId 为 u8 形参）时, 编译器把 -1 的移位量折进基址,
     生成 `lsls r1,r0,#3`（无 subs）, 整体错位 67 字节; 改成 `gUnk_08095828[(u8)(charId - 1)]`
     后逐字节命中。
     **推论**: 遇 u8 索引表达式被“聪明地”常数折叠时, 用显式 u8 回绕强转阻断折叠, 逼出 ROM 的
     subs+lsls+lsrs 三步截断序列。
     另注意同一函数里 `dest = x*2 + 0x02005800 + y*64` 的**加数书写顺序**决定 `lsls r1,r5,#1`
      (x*2 先入 r1) 还是 `lsls r2,r2,#6` (y*64 先) —— 与目标不一致就整体镜像, 顺序调整即可。
     关联: 规则 104 (寄存器 home)、规则 30 (移位域加法)。

106. **"global-alloc 域" 表基址提升进 r8 / RAM 基址循环内现取的决策, 可以被 C 结构改变, 不必改编译器**（案例 `sub_8009370`, 首个被攻破的 "global-alloc 域三连"）。
     目标形状: preheader `ldr r7,=0x0808A234; mov r8,r7`（ROM 表基址进 r8）且 `0x03000010` 循环头现取;
     循环体条件 `movs r0,#4; ands r0,r2`（AND 结果落常量寄存器 r0, b 保持 QI/subreg）。
     - **保持窄类型不落局部**: 条件必须直接写 `gUnk_03000010[i] != 0 && (gUnk_03000010[i] & 4) == 0`
       （两次直接下标访问）。若先 `b = gUnk_03000010[i]` 再 `b & 4`, GCC2 把 b zero_extend 成 SI,
       生成 `ands r2,r0`（结果落 b 寄存器, 差 2 字节）。
     - **DMA 源拆三行**: `off = (...<<5)+2; base = (u8*)gMenuEntityPaletteTable; src = (u32)(base + off);`
       再 DmaSet, 才能让 ROM 表基址提升进 r8 并保住 `adds r0,#2`; 直接写 `gMenuEntityPaletteTable + off`
       会把 +2 折进池常量（丢 adds）, 且基址不被提升。
     - **推论**: 遇挂起项 note 写着 "global-alloc 域 / 别再穷举 C 写法" 时, 仍应先穷举
       "窄类型不落局部变量" 与 "指针/偏移拆分变量" 两类结构 —— 提升决策往往由中间变量的
       存在与类型决定, 不是铁板一块。打 agbcc global.c 转储补丁 (路径 a) 是最后手段。
     关联: 规则 29 (字面池重定位)、规则 76/87/88 (寄存器 home 与 qty)、规则 104 (拷贝族 home)。

107. **s32/u16 减 1 后再按 s8 比较时, 若直接 `if ((s8)g > 0)` 编译器复用寄存器移位 (lsls rX,rX,#24) 而非重读内存 (movs+r0,ldrsb)**（案例 `sub_80188BC`）。
     目标序列: `subs r0,r2,#1; strb r0,[r1]; movs r0,#0; ldrsb r0,[r1,r0]; cmp r0,#0; bgt clear`
     —— 减后**重读内存**取带符号字节。直接写 `gUnk_03000316--; if ((s8)gUnk_03000316 > 0)`
     会被 GCC2 改成 `lsls r0,r0,#24; cmp r0,#0` (复用寄存器, 差 4 字节); 插入中间变量
     `tmp = gUnk_03000316; if ((s8)tmp > 0)` 后强制重读, 逐字节命中。
     **推论**: 想让减/改后的全局值被"当作新读"产出 ldrsb/ldrsh 序列, 就经一个局部变量中转,
     阻断寄存器数据流的 reuse; 这也是可控 "home 互换" 的一招。
     **⚠ 反例教训 (2026-09-02 踩坑)**: 本函数曾用 **readkeys/clear/tail 三标签 `goto`** 强控块布局来
     匹配目标 (readkeys 带 `b tail`, clear fall-through)。`goto` 违反铁律 4 / 规则 100 —— 规则 100 已
     证明这类"跳过块"控制流用 **flag 赋值让 GCC2 jump-threading 自生成绕过块** 同样逐字节命中且更规范。
     **正确做法**: 遇到疑似非 goto 不可的控制流, 先按规则 100 把分支归约成对同一变量的赋值
     (如 `flag = 1;`), 再交给 flow/CSE; 只有当 flag 写法也无法复刻时才考虑 goto, 且须在
     functions.tsv note 里标注"用了 goto 凑形, 待 flag 重构"。不要在规则里把 goto 当推荐手段。
     关联: 规则 104 (home 由声明形式决定)、规则 103 (调度槽位)、规则 100 (禁 goto)。
108. **`for(i=0;i<N;i++){if(x==t[i])break;} return i;` 线性查找: GCC2 把首迭代(i=0)peel 到循环外, 循环体先 `i++` 再 `cmp #N-1/bhi` 收尾**（案例 `sub_804F050`）。
     目标形状: `movs r1,#0; ldrb r3,[base]; cmp arg,r3; beq ret; loop: adds r0,r1,#1; (u8 截断 lsls/lsrs); cmp r1,#0xf; bhi ret; ldrb r0,[r1,base]; cmp arg,r0; bne loop; ret: mov r0,r1`。
     —— 即 `t[0]` 的比较被提到循环前单独做一次, 循环内从 i=1 起, 退出条件写成 `i > N-1`(`bhi`) 而非 `i >= N`; 无命中时返回 N。
     **要点**: ① 参数与 `i` 都必须是 `u8`, 才会产出 `lsls #0x18; lsrs #0x18` 字节截断 (arg0 入口也截断一次); 写成 `int i` 会丢这两条移位。
     ② 表基址用**真 extern 数组** `gInvPageItemIds[i]` 索引, 不要 `((const u8*)0x0839CFAA)[i]` 强转宏 —— 后者换寄存器分配 (同 `code_8010F10.c` 注释, 规则见 data_805769C.h)。
     ③ peel 是编译器自动做的, **不要**手写 `if(x==t[0])return 0;` 再进循环去"复刻"它, 直接写朴素 for+break 即命中。
     **变体 (案例 `sub_804EF90`)**: 界是变量 (`i < gUnk_03000DDC`) 时, peel 出的首块仍先 `ldrb count; cmp i,#0; bhs ret`, 循环体每轮**重读** count (全局不缓存); 带 `ret` 累加器 (默认 0xFF, 命中 `ret=i`) 时返回值走 r5 而非直接 r1, 但 peel/bhi 骨架不变。
     ⚠ 表若是已登记的结构体数组 (如 iwram.h `Unk_03000DEntry gUnk_03000D88[]`), **直接复用该类型**, 别在函数里再 `typedef`+`extern` 一份同名/同址符号 —— 与头文件声明冲突编译即红; 4 字节元素 → 索引算术是 `lsls r0,r2,#2`。
      关联: 规则 99 (数据表保持 1-D extern)。
109. **同一 ROM 表需要"第二种类型视图"时, 用同址别名符号声明, 绝不用 cast**（案例 `sub_8048BAC`）。
      表已按 `u8[]` 登记且被别的**已匹配**函数占用 (如 `gUnk_0839CC4C` 被 `sub_8048B88` 以 `gUnk_0839CC4C[i*4]` 用), 而本函数需要 `struct[]` 视图 (字段偏移当 ldrb displacement、且基址在分支内**早加载**) 时:
      写 `((Struct *)gArr)[i].field` → GCC2 **先算下标再取基址** → 基址晚加载进 r1、arg0 挤进 r1、`adds r0,#2` 折进下标, 三处全错 (实测连 FAIL 3 次: 直址下标 `gArr[i*4+2]` 把 +2 折进 index; 局部 `p=gArr+i*4;p[2]` 与 cast 都 base-late)。
      **正解**: linker.ld 的 SECTIONS **外**加同址别名 `gUnk_0839CC4C_entries = 0x0839CC4C;` + 本 TU `extern Struct gUnk_0839CC4C_entries[];`, 用**真 extern 结构体数组** `gUnk_0839CC4C_entries[i].field` 索引 → 基址在块首 `ldr r1,=addr`、arg0 落 r2、`.field` 折成 `ldrb [r0,#off]`, 一次命中。
      关联: 规则 15 (基址池加载位置↔tbl 局部)、规则 108② (真 extern 数组 vs 强转宏换寄存器)、§7 别名符号 (同址多视图)。

110. **多个 RAM 地址复位 (各 `=0`) 时, 把其中两个写成链式赋值 `B=(C=0)` 可以消掉一个地址伪寄存器, 改变 r8/ip 的 home 争议**（案例 `sub_804AB40`, 2026-09-02）。
     目标形状: 4 个 strb 用 4 个独立高位 home (r8/sb/r7/ip) + 池序 [94A,B,C,D]; 朴素 4 行散写时
     mine 是 3 个独立 home + 池序正确但 A/D 的 home 与目标互换 (17 字节差)。
     - **链式赋值 = 地址伪寄存器压缩器**: `gX = (gY = 0)` 使 gX/gY 的地址共享同一伪寄存器
       (内层地址值是外层赋值的数据流来源), 4 散写 4 伪寄存器 → 2 散 + 1 链 3 伪寄存器。
     - **存储序 = 分配序**: strb 顺序跟随 allocno 分配顺序而非语句顺序; 全链 `D=(C=(B=(A=0)))`
       反而生成 stores=[A,B,C,D] 逆链序 — 半链形态的序最难猜, 逐个 bytecmp 穷举。
     - **do-while + 守卫** (`if (i < N) do {...} while (cnt < N)`) 才是"顶测 i/底测 count"的正确源结构,
       for/while 双条件都会多测一次; 与规则 21/108 同族 (首迭代结构由编译器拆)。
     - **终址复用常量伪寄存器**: 尾段 `&tbl[i]` 直接用真 extern 数组名 (不落 ptr 变量) 时,
       它与循环不变量共享 home, 省一条 `adds rX,rY,#0`。
     ⚠ 本案例最终 17 字节差 (9 条 home 指令) 仍未归零: 目标 home 序 [D→ip,C→r7,B→sb,A→r8]
     隐含 qty 创建序 D→C→B→A, 但能产生该序的 C 写法全都同时破坏循环体 home —— 已实测穷尽
     链/排列/划分 300+ 变体 + permuter 10 万次, 属于 global-alloc 域深层问题 (同"三连"家族)。
     关联: 规则 87 (变量兼职制造伪寄存器生死边界)、规则 106 (global-alloc 域可被 C 结构改变)、
     规则 104 (home 由声明形式决定)。

111. **同一全局在两个互斥分支里各读一次时, 分支内 `u8 x = g; if (x == N)` 局部化可打破跨分支 CSE, 改变全局-alloc 的 home 分配**（案例 `sub_80094FC`, 2026-09-02）。
     目标: `>6` 测一次、`==7`/`==2` 各自**重读**一次 (3 条 ldrb), 计数器 c 落 **r1**、state 落 r0。
     直写 `if (g > 6) {...if (g == 7)...}` 时 GCC2 把 state 的 3 次读 **CSE 成 1 个长命伪寄存器**
     (掩码结果 reg51, 用 3 次跨块) → 占掉 r1, 计数器 c 被迫落 r0 (`adds r0,#1` 就地增),
     与目标差 103 字节。把 ==7/==2 的读改成**分支内局部** `u8 s2 = gUnk_03004910; if (s2 == 7)`
     后, 分支内读是独立短命伪寄存器, CSE 不再跨块合并 → c 落 r1 (`adds r1,r0,#1`)、state 重读 r0, 逐字节命中。
     **诊断法**: `gccdump.greg` 看 `X preferences: 0` —— 该伪寄存器被硬分 r0 (案例是 c);
     冲突表里 `X conflicts: ... 0 ...` 即与硬 r0 冲突 (case 是分支内读挤掉它)。
     **判据**: 目标里"同一地址连续 3 条 ldrb"而朴素 C 只有 1 条 = 原代码存在分块读。
     注意: 这是规则 23 (勿缓存重读全局) 的反向实例 —— 不是缓存进跨块局部, 而是**分块短命局部**
     恰好阻止 CSE。两者都只为复现 GCC2 的分配行为。
     关联: 规则 88 (跨块 home 归 global-alloc, 按伪寄存器生死边界改)、规则 87、规则 97。

112. **switch 守卫的分式拆分让独立 load 落进 `ands` 与 `subs` 的调度空隙**（案例 `sub_800A534`, 2026-09-02）。
     目标形状: `ldrb [tbl,#8]; ands r0,r1; ldrb r2,[tbl,#6]; subs r0,#1; cmp r0,#6; bhi` ——
     val(=tbl[6]) 的装载被调度在 `ands`(取低4位) 与 `subs`(-1) 之间。
     直觉写法 `v = (tbl[8]&0xF)-1; val = tbl[6]; if (v<=6) switch(v)` 生成
     `ands; subs; ldrb`(val 装载落在 subs 之后, 差 8 字节), 且直接交换语句序
     (`val` 先) 会搅乱 tbl/val 的寄存器 home(差 24 字节)。
     **正解**: 把 `-1` 从 v 的赋值里拆到守卫与 switch 的表达式:
     ```c
     v = tbl[8] & 0xF;          /* 只有 ands */
     val = tbl[6];              /* 独立 load 落在中间 */
     if (v - 1 <= 6)            /* subs 在此处生成 */
         switch (v - 1) { ... } /* CSE 复用同一个 subs 结果 */
     ```
     调度器于是把 ldrb 塞进 ands→subs 之间, 逐字节命中。
     **配套 (val 的 home 之争)**: 若不处理, val(=tbl[6]) 的伪寄存器生命周期跨过整个
     switch (load→add), 全局分配优先级反而低于 tbl 基址 → val 落 r3/基址落 r2, 差 7 字节。
     正解 = 第一分支内 **重读** `u8 bonusVal = tbl[6];`(被 CSE 合并成 val 的副本, 不增指令),
     使 val 的首次使用提前到 switch 之前 (生命周期变短) → 优先级反超基址 → val 落 r2/基址落 r3。
     **不要用** `register` 关键字硬定 home (编译器扩展, 本项目禁), 重读语句是纯 C。
     这属于"把一条表达式按 RTL 层次拆成多语句"的调度槽位技巧, 与规则 13/25/83 同类 ——
     判定: 目标出现 `ands ...; ldrb ...; subs ...`(装载夹在掩码与减之间) 就用分式拆分。
     关联: 规则 25 (屏障定槽)、规则 103 (常量顺序由引用序决定)。

 113. **目标有跳表但所有 case 都指向同一块 (如全 `return 10`) 时, 必须每个 case 独立写语句**（案例 `sub_8009F70`, 2026-09-02）。
      写成 `case 0: case 1: ... case 10: return 10;`(合并 case 标签) 会被 GCC2 折叠成
      范围测试 `cmp #10;bgt; cmp #0;blt; movs #10`, 丢 `mov pc,r0` 跳表。
      每个 case 单独 `return 10;` 才生成 11 项跳表、全部指向同一块 —— 与 sub_8048BD0
      (≥2 个不同目标天然出跳表) 不同, 单目标全靠独立语句强出。
     判定: 目标 `lsls r0,#2; ldr r1,=表; ldr r0,[r0]; mov pc,r0` 且跳表项全同址。

 114. **K&R 旧式定义是"空形参声明 + 全原型编译"的调和剂**（案例 `sub_8009F70`, 2026-09-02）。
      头文件 `u16 f();`(空形参, 项目既有约定, 见 §7 改名警告) 下, 定义写全原型
      `u16 f(u8,u8,u8)` 触发 GCC2 `default-promotion` 冲突报错; 就算能编译, 全原型会让
      已匹配调用方的寄存器分配漂移 (sub_8048818 formation r2→r3, 差 12B)。
      **定义改用旧式**: `u16 f(a,b,c) u8 a; u8 b; u8 c; { ... }` —— 与 `()` 声明兼容,
      且生成的 u8 入口掩码 (lsls/lsrs) 与全原型完全一致 (bytecmp 216B 同)。
      关联: AGENTS.md §7「改名不得顺手改原型签名」; 判定: 改全原型后某调用方 fncheck FAIL。

 115. **移除-移位循环: `count--` 后置 + 循环界写 `count - 1`, 让截断延迟到循环后**（案例 `sub_804C8E0`, 2026-09-02）。
      目标形状 (数组移除元素后 `break`):
      ```
      adds r0, r1, #0       @ j = i  (for 初始化先于界计算)
      subs r4, #1           @ count-1 (不截断!)
      adds r3, r4, #0       @ bound = count-1 的副本 (循环界用 r3, r4 作备)
      cmp r0, r3; bge skip
      do { values[j]=values[j+1]; j=(u8)(j+1); } while (j < r4);
      lsls r0, r3; lsrs r4  @ count = (u8)count  (延迟截断写回)
      ```
      直觉写法 `count--; for (j=i; j<count; j++) values[j]=values[j+1];` 会**立即**截断
      (`subs+lsls+lsrs` 紧跟 --), 循环界直接用截断后 count, 少了 bound 副本, 且 obj 被挤到
      r7 而移位基址用 r3 —— 全部错位。
      **正解**: `for (j=i; j<count-1; j++) values[j]=values[j+1]; count--;`
      —— for-init(j=i) 先出, 界表达式 count-1 算进 r4 并复制 r3 作界, count-- 延迟到循环后
      才以 (u8) 写回; 此形态下编译器把 obj 分配 r8 (r7 要让给移位基址 `mov r7, sp`)。
       判定: 目标移位循环用 `mov r7, sp` 基址 + bound 副本 + 循环后 `lsls/lsrs` 截断。
       关联: 规则 12 (调度器吊闩), 规则 10/33/47 (伪寄存器生命周期 ↔ 写法)。

 116. **`for` 循环写成 `count > i` (界在左) 才触发 GCC 的循环旋转**（案例 `sub_804FA04`, 2026-09-02）。
      `for (i=0; i<count; i++)`(标准写法) 生成**未旋转**形态: 顶部守卫 `cmp i,count; bcs skip`,
      循环回边 `cmp i,count; bcc` (i 在左)。目标若为**旋转**形态 (guard `cmp count,#0; bls skip`
      测试界本身, 回边 `cmp count,i; bhi`, 循环体无前跳即 do-while 风格), 写成 `count > i`:
      `for (i=0; count>i; i++)` 会触发循环旋转, guard 变 `cmp count,#0` —— 逐字节命中。
      判定: 目标循环入口前有 `cmp <界>,#0; bls/bhi` 且回边是 `<界> <循环变量>` 方向。
       关联: 规则 115 (界表达式顺序), 规则 3 (分支极性)。

116. **三个及以上等权重 RAM 地址复位 (`=0`) 卡寄存器轮换时, 用 `do { X = 0; } while (0);` 屏障包住其中一个, 打破 local_alloc 的平手 tiebreak**（案例 `sub_8020B54`, 2026-09-02）。
     QTY_CMP_PRI 全等 (n_refs=2/size=4/life=30) 的三个地址伪寄存器, 平手时按 qty 号小者先拿
     r4/r5/r6, 目标却是 r5/r6/r4 轮换 —— 之前穷举 40+ 写法 (语句序/链式/指针/类型) 全撞 6B 地板。
     给**最后一条**存储加 `do { } while (0)` 屏障后, 该 qty 因屏障多包一条 insn, life 微变,
     权重不再全等, qsort 次序翻转, 三条 ldr + 三条 strb 全部归位, 逐字节命中 (fncheck OK, 60B)。
     **注意**: 屏障必须只包**最后一个** `=0` (包中间的会把中间 qty 单独拎出, 反而破坏存储序)。
     判定: 目标三条 strb 顺序 714,715,716 而 C 得 714,716,715 (链式) / r4,r5,r6 (散写) 时,
     先试"最后一个存储加 do-while 屏障", 比链式赋值更精准 —— 链式还会搅乱池序 (规则 110)。
     关联: 规则 17 (同题已解)、规则 25 (do-while 屏障定槽)、规则 110 (链式=地址伪寄存器压缩)。
 117. **跨块 home 争议 = global-alloc 的 `allocno_compare` 排序, 用 `-da` 的 `.flow` 转储量化**（案例 `sub_8045F10`, 2026-09-02, 未破）。
      规则 88 说"跨块的 home 归 global-alloc, 别查 qty 表", 但没说怎么算 —— 补上:
      源码 `tools/agbcc/gcc/global.c:605 allocno_compare()`, 与 QTY_CMP_PRI **同形**:
      `pri = floor_log2(n_refs) * n_refs / allocno_live_length * 10000 * size`, **降序**发号,
      同分按 allocno 号小者优先; 再由 `find_reg()` 按 r0→r15 升序取第一个不冲突的硬寄存器
      (两轮: pass0 只准复用"已被别的 allocno 占用"的槽, pass1 才准开新槽)。
      取数: `agbcc -da` 会吐 `x.i.flow`, 里面 `Register N used R times across L insns; set S times; user var`
      就是 (n_refs, live_length), 且这是 **global-alloc 前**的真值 (`-dl` 的 lreg 是分配后的, 数字会漂)。
      用法: 目标 home 与候选 home 只差一次**相邻交换**时, 先算出两者 pri, 再看要把哪个 allocno
      的 refs 抬到多少 / live 压到多少 —— 比盲改写法快一个数量级。
      实测 `sub_8045F10`: obj(3 refs/13 live)=0.231 > result(4/42)=0.190 > dirMask(2/37)=0.054
      → 候选发号 obj=r2, result=r3, dirMask=r4; 目标要 dirMask=r2, 即 pri(dirMask) 必须 > 0.231
      (refs≥5, 或 refs=4 且 live≤34)。
      ⚠ **抬 refs 这条路基本是死的**: `x = x` / `(void)x` / `x |= 0` / `x &= 0xFFFF` / `x << 0` /
      `x * 1` / 重复子表达式 `(e && e)` `(e | e)` `(e + e)` / `if (x) { x = x; }` **全部在 tree/CSE
      阶段被折掉**, flow 里 refs 纹丝不动 (与规则 88 对 local-alloc 的结论一致)。
      能抬 refs 的只有"语义上真读写该变量"的语句, 而那必然留下指令 —— 所以 `case: dirMask++;
      dirMask--;` ×2 能做到逐字节 0 分, 但那是**伪造语句**, 铁律 4 禁止, 不得合入
      (它唯一证明的是: 目标里 dirMask 这个 allocno 的 pri 确实高于 obj)。
关联: 规则 87 (一个变量兼职两个值 = 改伪寄存器生死边界)、规则 88、规则 102。
 120. **⭐ 函数末尾"多一条把值装进 r0 却没人用"的 load = 原代码有 `return <表达式>`, 被 K&R `void f();` 原型掩盖**（案例 `sub_8016E80`, 2026-09-02, 破 34B→0）。  *(原编 118, 与并发 agent 的 s8 截断条目撞号, 2026-09-02 修重号)*
      目标尾部 `ldrb r0,[r1,#2]; ldrb r2,[r1,#3]; orrs r0,r2; strb r0,[r1,#2]; ldrb r0,[r1,#3]` ——
      最后那条 `ldrb` 读出的值既不被读也不参与返回路径, 直觉上像编译器残渣, 其实是
      `return gSioState[3];` 的物化 (调用方 `bl` 后立刻重载 r0, 所以"返回值被忽略")。
      判据: **epilogue (`add sp/pop/bx`) 之前**出现一条目的寄存器为 r0、且其值在程序里
      再未被使用的 load/算术指令 → 先按"真返回值"补 `return`, 而不是当死代码删。
      配套坑: 头文件里 `void f();` 是**旧式非原型声明**, 定义写成 `u8 f(u8 *)` 不会报冲突,
      但反过来若先按 void 定义, 就永远少这一条指令 (本例差 2 条 = 4 字节)。
      同函数另两处可复用的 home 手法 (规则 87 的同一思路, 案例同):
      ① **交换双缓冲的临时量复用循环指针变量** (`packet = *(u16 **)(state+0x2C); ... *(u32 *)(state+0x28) = (u32) packet;`)
        —— 单开一个 `u32 temp` 会多出一个 allocno, BB0 的 state/temp home 整体错位 (实测差 34B→8B);
      ② **循环里换用第二个指针变量** (`st = state;` 放在 `i = 0;` 之后) 才生成目标那条
        `adds r7, r5, #0`; 全程只用 `state` 则不生成 (实测差 132B→8B)。
      ③ `i = 0;` 必须是循环外的独立语句 + `for (; i <= 1; i++)` 空 init, 否则 `movs rN,#0`
        会落到那条拷贝之后。
      ④ 收尾的 `CpuSet` 立即数 0x04000006 / 0x05000006 分别是 `CpuCopy32(src,dst,24)` 与
        `CpuFill32(0,dst,24)` 的宏展开 (后者自带 `vu32 tmp` 栈槽 = `sub sp,#4` + `str r0,[sp]`),
        别手写裸 CpuSet (规则 55)。
      关联: 规则 54 (非 void 无 return 锁死 r0 —— 本条是它的镜像)、规则 87、规则 117。
 118. **s8 返回值截断位置: `s8 tmp = result; if (tmp >= 0)` 使 `lsls/lsrs #0x18` 排在 `cmp` 之前**（案例 `sub_804F10C`, 2026-09-02）。
      目标: `call → lsls r0,#0x18; lsrs r1,#0x18; cmp r0,#0; blt; adds r7,r1,#0`
      朴素写 `if (result >= 0) { found = result; break; }` 产 `lsls r0,#0x18; cmp r0,#0; blt; lsrs r7,#0x18`
      截断 (u8)result 在 cmp 之后才出货。加 `s8 tmp = result;` 后 agbcc 把截断结果暂存 r1 (tmp 伪寄存器),
      `cmp r0,#0` 仍用原始 r0, 截断从 "if-body 内的赋值" 提前到 "tmp 的赋值" —— 因 tmp 的赋值在 if 判别之前,
      编译器把截断指令提前。同理, `int idx = values[i] * 0xC8` 把乘法从子表达式提升为独立伪寄存器,
      避免内联求值时 `pool + values[i] * 0xC8` 的乘-加序列被调度器重排。
      关联: 规则 71 (局部收窄改变生命周期)、规则 106 (中间变量决定 global-alloc)、规则 115 (截断延迟到循环后)。
 119. **SIOCNT/SIODATA8 这类"控制+数据同基址"硬件寄存器, 想要 ROM 的 `ldr rN,=0x04000128; strh rX,[rN,#2]`
      形状 (基址池字面量三处共享一个), 必须按两-u16 结构视图访问: `((SioMultiCnt *)REG_ADDR_SIOCNT)->Data`;
      io.h 分开的 `REG_SIOCNT`/`REG_SIODATA8` 各开一个地址字面量 → 池差 4B。且必须用**非 volatile** 的
      `SioMultiCnt`(types.h 已带): 换 `vSioMultiCnt`(volatile) 会把 `.Error` 读拆成半字访存, 破坏目标
      `ldr word + lsls #0x19/lsrs #0x1f` 位域提取形状 (差 137B)。配套②: 同址 RAM 的"结构化视图"应注册成
      **独立别名符号** (如 gUnk_03004DF0, 与 gSioState 同址双符号), 不要用 `#define OBJ (*(struct*)0xADDR)`
      宏 —— 宏让每处成员访问自带常量+偏移池加载, 池字面量激增 (差 160B); extern 对象统一 `ldr rN,=0xADDR; [rN,#off]`。
      另: 访问走全局对象名而非"局部指针=cast(gSioState)" 也影响分配 (局部指针版差 185B, 需对象语义)。
      （案例 `sub_8016FC0`, 2026-09-02; 参考同为 agbcc 的已匹配参考 C, 一次合入。）

 121. **⭐ 循环里的"值未用的死读" (`ldrb r0,[r0]` 结果即弃) 在 agbcc 下只有 volatile 读能保形**（案例 `sub_80454A4`, 2026-09-02, 用户拍板用 volatile 合入）。
       目标第一个循环: `if ((u8)(obj[0xAB]-7) > 1) idx = obj[0xBE];` 编译出的 `ldrb r0,[r0]`
       结果从未被用 (下一条指令就是 `adds r0,r6,#1` 覆盖 r0)。穷举 40+ 非 volatile 形态全部被 DCE 删除:
       `(void)obj[0xBE];` / `idx = obj[0xBE];`(局部死)/ `idx=..; idx^=idx` / `obj[0xBE] += 0` /
       `obj[0xBE]=obj[0xBE]` / switch 空 case / `if(x==0xFF) continue;` / 死 store `obj[0xBB]=obj[0xBE]`
       (有 strb 不符) / 局部数组 store (有 strb 不符) / 函数调用 (有 bl 不符) / 位域 / do-while 屏障——
       唯一逐字节一致的是 `idx = ((volatile u8 *)obj)[0xBE];` (bytecmp 除 6 个 bl 槽全同)。
       **推理**: 死读在 ROM 里真实存在 → 原代码必然是 volatile 读 (agbcc 唯一天然产此形态的写法),
       volatile 在此是**忠实还原原代码**, 不是规则 79 禁止的"纯调度 hack"。故本项目破例:
       当"目标含非 IO 死读"且穷举证明只有 volatile 保形时, 允许在**单点读**上加 volatile 并注明依据,
       不同于 code_80002A0.c OAM 先例 (那例 volatile 用于阻止两条 live load 的 CSE 合并, 属调度 hack, 保留 INCLUDE_ASM)。
        **判定**: ① 死读结果真的不流向任何后续指令 (看目标汇编下一指令); ② 穷举 ≥20 种非 volatile 形态确认
        DCE 全删; ③ 加 volatile 后 fncheck 全绿。三条件齐才破例, 否则仍按规则 79 保留 INCLUDE_ASM。
 122. **所有局部变量声明必须集中在函数开头 (C89 风格), 禁止块内/中途声明**（2026-09-03 全项目规范）。
        agbcc (egcs 1.1 系) 是 C89 编译器: 在 for 循环体 / if 分支内声明变量 (`u8 *obj = ...;`
        `u16 idx = ...;` 等) 会改变伪寄存器 (qty/allocno) 的创建顺序与生命周期边界, 进而改变
        global-alloc 的 home 分配和 local-alloc 的调度槽位 —— 同一语义不同声明位置, 字节结果不同。
        判定: ① 函数体内所有 `u8/u16/u32/指针` 声明一律上提到函数开头统一声明; ② 中途才需要的
        临时量也先声明 (可留空初始化); ③ 循环变量 i/j 也在开头声明。
         关联: 规则 10/33/47 (伪寄存器生命周期↔声明), 规则 106 (中间变量决定 global-alloc)。
 123. **ROM 池地址常量的物化顺序, 用 `int` 局部 (赋裸地址值) 而不是 `u8*` 局部/内联 cast 控制**（案例 `sub_803F328`, 2026-09-03）。
        目标在 `bl Bg0_InitClear` 后先 `ldr r1,=0x02035AC0`(池加载) 再 `movs r4,#2`(v=2);
        写成 `sub_80196D4(0,(u8*)0x02035AC0,...)`(内联 cast) 或 `base=(u8*)0x02035AC0;`(指针局部)
        都让 GCC 先物化 `movs r4,#2` 再加载池 → 0x4c 处 4B 逆序。
        **正解**: `int base; ... base = 0x02035AC0; ... sub_80196D4(0,(u8*)base,...)` ——
        `int` 局部赋值裸地址值, 池加载伪寄存器先于 `v=2` 的 movs 被 global-alloc 排到前面
        (规则 44 的"池加载早=用局部"镜像: 不是表基址而是任意 ROM 地址常量同样适用)。
        传入处再 `(u8*)base` cast。fncheck 284B OK。
 124. **switch 的 case 块源码顺序 = ROM 块发射顺序 (GCC2 保序), 尾块异常合并时先对齐 case 顺序**（案例 `sub_8032D74`, 2026-09-03）。
        ROM 顺序 0→19→20→6→9 的 switch 按"习惯的数值序" 0,6,9,19,20 书写时, 相距最远的
        case0/case19 各自的 `gUnk_03000820 = X; break;` 尾被跨块 tail-merge 成共享
        `strb r0,[rN]; b end` (bytecmp 155B 差); 按 ROM 序重排后每处存储就近内联, 差异立降。
        判定: 目标里同一个"写状态全局"的 strb 在多个 case 各自独立出现 (共享一个池字但
        不共享指令), 而候选把它们合并进共享尾块 → 首先检查 case 声明顺序是否与 ROM 一致。
        关联: 规则 16/37 (switch 分发), 近亲验证 sub_8042AB4/sub_80405A4 (均已匹配, 源序=ROM序)。
 125. **三目 if-conversion 的基值取 else 分支**: `cond ? A : B` (A>B) 生成 `base=B; cond真: add (A-B)`;
        要得到 `base=A; cond真: sub` 必须写成 `!cond ? B : A` 或 `cond==0 ? B : A`（案例 `sub_8032D74`, 2026-09-03）。
        目标: `ldr r2,=0x371; cmp r0,#0; bne skip; subs r2,#0xF` — 基值 0x371 是 cond(obj[0xBE]!=0) 为**真**时的值,
        即 C 写法是 `obj[0xBE] == 0 ? 0x362 : 0x371` (cond 为假取 0x362, 为真取基值 0x371)。
        写成 `obj[0xBE] != 0 ? 0x371 : 0x362` 会得 `base 0x362; beq skip; adds #0xF`, 分支极性+算术全反。
        判定: 目标是 base=大值+subs → 三目真值分支写大值; 目标是 base=小值+adds → 真值分支写小值。


## 寄存器分配定量诊断 (agbcc -dl 转储) —— 破解"怎么写都不换寄存器"类卡壳
agbcc (egcs 1.1 系) 自带 RTL 转储开关, 对定位寄存器 home 问题极其有用:

```bash
arm-none-eabi-cpp -nostdinc -I tools/agbcc/include -iquote include x.c -o x.i
tools/preproc/preproc x.i | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit \
    -Wparentheses -O2 -fhex-asm -fprologue-bugfix -dl -o x.s
grep '^Register ' gccdump.lreg          # 每个伪寄存器: used N times across M insns / pref / dies in K places
grep '^;; Register .* in' gccdump.lreg  # 最终硬寄存器分配结果
```

其他可用字母: `-dj`(jump 后) `-dc`(combine 后) `-df`(flow 后) `-dg`(global-alloc 后)。

### QTY_CMP_PRI 模型 (源码 tools/agbcc/gcc/local-alloc.c:1435)

```
pri = (int)(((double)(floor_log2(n_refs) * n_refs * size) / (death - birth)) * 10000)
```

- 分配两轮: ①有硬寄存器建议(copy-sugg)的 qty 先试建议寄存器; ②其余按 pri 降序
- **pri 相同则 qty 号小者优先** (`qty_compare_1` 返回 `q1 - q2`) —— 参数/最先定义的局部变量 qty 号最小, 平手时它先拿寄存器
- `find_free_reg` 从 r0 往上扫, 取第一个在 [birth, death) 区间未被占用的寄存器
- `n_refs` 由 flow.c 统计, **包含 REG_EQUIV / REG_EQUAL 注释里出现的寄存器**
- 空语句 `;`、`(void)0;`、`ptr = ptr;` 这类"想刷引用数"的写法会在 CSE 阶段就消失, **不影响 n_refs**
- 推论: 想让一个长生命周期变量拿到 r1, 它的 pri 必须 ≥ 同函数内所有会抢 r1 的短命临时量。
  典型短命临时量 = 字面池加载(2 refs / 4 insns) → **pri = 5000**; 移位/加法中间量(2 refs / 3 insns) → 6666
- 实测: `n_refs=4 / life=24` → 3333 抢不过 5000; 要翻盘需 `n_refs ≥ 6`(12/24=5000 平手, qty 号小者胜)
  或 `life ≤ 16`
- ⚠ 转储文件写在**当前工作目录**(`gccdump.lreg`), 跑完记得 `rm -f gccdump.lreg`, 别污染仓库根目录
- **定位“多占一个寄存器”的具体手法**: 先在 `^Register ` 摘要里找到那个不该长命的 qty
  (看 `used N times across M insns`, M 异常大就是它), 再到同一文件的 RTL 体里
  `grep -n "reg/v:SI <N>"` 看它到底在哪条指令被多引用了一次 ——
  本轮就靠这一步发现 sub_80529B8 的尾部 `*ptr += 2` 被 CSE 复用成了 `data + 2`
  (目标其实是重新 `ldr r0,[r3]`), 即“`data` 变量本身不应当存在”。
  这比盲猜写法快得多, 也能直接告诉你该删哪个局部变量。

## 失败案例存档 (已穷举过、别再重复的方向)

### ⭐ global-alloc 域三连（sub_8009370 / sub_8018E34 / sub_804BE90）—— `qtydump.sh` 已定性，别再穷举 C 写法

2026-09-01 用 `scripts/qtydump.sh`（打过诊断补丁的 `tools/agbcc/bin/agbcc_qtydump`，
只 dump **local-alloc** 的 qty 优先级表）扫了这三个挂起项的最优候选，结论是**它们不在 local-alloc 域**：

| 函数 | 字节差(bytecmp) | local-alloc 表里的 qty | 争议值是否出现在表里 |
|---|---|---|---|
| `sub_8009370` | 78 / 216 | 16 个，**全部**分到 r0；含循环体在内的 3 个块是 **0 qty** | ✗ 表基址/数据指针是跨块长寿命值 |
| `sub_8018E34` | 37 / 152 | 17 个，最长 `life` 仅 12，只用到 r0/r1 | ✗ 尾段"表基址进 r0 还是 r1"不在表内 |
| `sub_804BE90` | 64 / 168 | 14 个，最长 `life` 仅 8；2 个块 0 qty | ✗ "表基址 vs `-1` 谁进 sl"不在表内 |

**机制（已核对 toplev.c 的 pass 顺序：local-alloc 先跑、global-alloc 后跑）**
1. local-alloc 只管**完全活在单个基本块内**的伪寄存器，从 r0 往上发寄存器；
   它拒绝 r0 的唯一原因是 `regs_live_at` 里 r0 已被标记存活 —— 而那个存活信息来自 **flow 对硬寄存器的判定**
   （入口参数寄存器、返回值寄存器、调用点），**不是来自 C 层的表达式形状**。
2. 争议的那些长寿命值（跨分支/跨调用的基址、循环不变量）由**后跑的 global-alloc** 分配，
   它只能拿 local-alloc 剩下的，所以 `qtydump.sh` 这张表里**根本看不到它们**。
3. 推论：**穷举等价 C 写法改不动这类卡点**——改的是伪寄存器图，但被改的那一层不是决策层。

**不要再重复的方向**（三个函数各自实测过，全部无效）：语句顺序/括号位置、具名临时变量、
`&`/`|` 操作数左右互换、指针局部 vs 内联表达式、`do{}while(0)` 屏障、空语句刷 n_refs、
声明处初始化 vs 分离赋值、permuter（只探索语句顺序与括号，正好是这一层）。

**两条真正可行的下一步**
- **(a) 补 global-alloc 转储**：照 `scripts/patches/agbcc-qty-dump.patch` 的路子给
  `tools/agbcc/gcc/global.c` 打补丁，dump 每个全局伪寄存器的候选/优先级/最终硬寄存器；
  这才是这三个函数的决策层。
- **(b) 先查"硬寄存器存活"差异**（成本极低，且已被验证有效）：
  **sub_8008124 就是这么破的**（规则 54）—— 返回类型非 void 且体内无 return ⇒ 没有任何指令写 r0
  ⇒ flow 认为 r0 从入口活到结尾 ⇒ local-alloc 全程不敢用 r0 ⇒ 所有寄存器整体上移一位。
  所以遇到"目标 r0 用量异常少 / 某常量被提升进高位寄存器"这类症状，
  **先怀疑函数签名（形参个数与类型、返回类型、有无 return），而不是函数体写法**。

### sub_80531A8 —— ptr/data 的 r1↔r2 互换, 已确认非写法问题

目标指令序列已 100% 复现(含池加载位置/分支极性/合并尾存), 只剩两个 home 寄存器号互换。
已穷举的方向全部无效, **不要再试**:

| 尝试 | 结果 |
|---|---|
| 620 种等价写法(6 种表访问 × 6 种取值 × 3 种条件结构 × 声明顺序/cast/空语句) | `n_refs` 恒为 4, `life` 恒为 24, 输出 `add r2, r0, #0` 不变 |
| permuter 12k 次迭代 | 停在 score=70 (7 行纯寄存器差异) |
| 编译 flag 变体: -O1 / -O2 / -Os / -g / -fforce-mem / -fno-gcse / 去掉 -fprologue-bugfix | 全部仍为 `add r2, r0, #0` —— **不是 flag 问题** |
| `;` / `(void)0;` / `ptr = ptr;` 想刷 n_refs | 在 CSE 阶段就消失, n_refs 不变 |
| `u32 *p1 = ptr;` 别名 (能把 n_refs 抬到 5) | **触发 GCC2 CSE 误编译**: 直接吞掉 `ldr rX,[ptr]`, 把 data 当 ptr 用 —— 绝对不可用 |
| 引入 `tbl`/`ofsPtr` 局部拉长池临时量生命周期 | 池加载会被提前到 `ldrb` 之前, 指令顺序反而错 |

定量结论: 要翻盘必须 `n_refs(ptr) ≥ 6` 或 `life(ptr) ≤ 16`, 而目标自身的指令数就把 life 钉在 24。
→ 真实原始写法必然带某种我们还没识别出的 ptr 引用形式; 下一步应当给 agbcc 打补丁
打印完整 qty 优先级表(而非只看 flow 摘要), 或拿同族函数(sub_8053138/sub_805321C)
交叉比对找共性。

### 其他已确认的死路

- `old_agbcc`: 项目统一用 agbcc, 不要混用
- `objcopy --rename-section` 生成 baserom.o: 会清零内容, 用坑 5 的 `ld -r` 方案
- 裸地址访问硬件寄存器: 一律用 `include/gba/io.h` 的 `REG_*` 宏(volatile 不影响代码生成)

## 符号改名管线 (函数/数据通用) —— 数据侧批量命名必用

名字有三个独立载体, **漏一个就会链接失败或函数清单丢状态**:

| 载体 | 作用 | 是否进 git |
|---|---|---|
| `ll.cfg` | gbadisasm 的名字源, 决定 `code.s` 里所有标号与 `bl` 目标符号 | ✅ |
| ~~`functions.yaml`~~ | **已删除 (2026-09-01)**; 函数清单 = `functions.tsv` (addr 主键, status 列) | ✅ |
| `include/*.h` + `src/*.c` | 原型/定义/调用点/`INCLUDE_ASM` 行 | ✅ |
| `code.s` → `asm/{matchings,nonmatchings}/*.s` | **全部重生成, 禁止手改** | ❌ (gitignore) |

固定流程 (实测 3.8s 重生成 + 完全可复现):

```bash
# 0) 先确认重生成是幂等的 (没改过 ll.cfg 时应该一字不差)
tools/gbadisasm/gbadisasm baserom.gba -c ll.cfg > /tmp/code.s.new && cmp code.s /tmp/code.s.new

# 1) 机械改名 (函数名出现在 ll.cfg / 头文件 / src 的 INCLUDE_ASM 行; functions.tsv 不用改,
#    gen_asm 按 addr 从 ll.cfg 取当前名, --sync 回写缓存列; 推荐直接用 scripts/rename_fn.sh)
sed -i 's/\bOldName\b/NewName/g' ll.cfg include/code_0.h src/*.c

# 2) 重生成反汇编 + 重切 asm 目录 (bl 目标会跟着换, 无需手改任何 .s)
tools/gbadisasm/gbadisasm baserom.gba -c ll.cfg > code.s
python3 scripts/gen_asm.py --sync

# 3) 数据符号还要改 iwram.h/ewram.h + linker.ld 的偏移行
#    (linker.ld 里是 `. = 0x0000XXXX; sym = .;`, 按地址排序原地改名即可, 不要移动行)

# 3b) ✅ Makefile 已补上 INCLUDE_ASM → asm/*.s 的依赖 (2026-09-01), 改名后会自动重编
#     引用方 TU。以前需要 `touch src/*.c`, 现在不需要了。
#     (回归测试: touch asm/matchings/<某函数>.s → 应看到它所在 TU 重新 agbcc)
#     ✔ `gen_asm.py` 是**增量**的: 只有内容变化的 .s 才被 touch, 改名后只重编真正受影响的 TU。

# 4) 刷新 m2c 上下文 + 终验
make ctx && timeout 900 make 2>&1 | tail -3 && python3 scripts/audit.py
```

**为什么安全**: `asm/*.s` 里的 `bl` 全部已被符号化 (实测 code.s 6360 个 `bl` 零个数字目标),
所以改名后重切就自动一致。数据符号则根本不会被按名字引用 —— gbadisasm 把数据地址写成
`.4byte 0x080576D0` 硬码, **所以数据符号改名永远不影响 asm**, 只影响 C 侧。

**两个坑**:
1. 改函数名时若该函数在 `src/` 里已是真 C, `gen_asm.py` 仍会生成 `asm/matchings/<新名>.s`
   (没人 include), 无害; TSV 以 addr 为主键, **改名不会丢状态** (旧 yaml 按名索引的孤儿问题已根除)。
2. **改局部变量名安全, 改声明顺序/个数不安全** (规 10/33/47: 伪寄存器生命周期会变)。
   只改拼写、加注释 → 字节不变; 拆合并语句 → 必须 fncheck 定性。

## 硬件寄存器操作规范 (必须遵守)

- **寄存器访问一律用 `include/gba/io.h` 的 `REG_*` 宏**, 禁止裸地址:
  ```c
  REG_DISPCNT |= DISPCNT_BG0_ON;   // ✓ (*(vu16*)0x04000000, volatile)
  *(u16 *)0x04000000 |= 0x100;     // ✗ 裸地址
  ```
- 位标志用 io.h 的 `DISPCNT_*` / `BGCNT_*` / `DISPSTAT_*` 常量 (如 DISPCNT_BG0_ON=0x100,
  BGCNT_SCREENBASE(n), BGCNT_CHARBASE(n), BGCNT_WRAP=0x2000)
- volatile 限定符(宏自带)与裸指针代码生成**完全一致**(已验证 sub_8019148), 无需担心
- 非 I/O 的数据地址(EWRAM 缓冲 0x02xxxxxx / VRAM 图形数据 0x06007000 等)不是寄存器,
  若 defines.h 无对应宏则保留字面量
- 已知寄存器: REG_DISPCNT=0x04000000 (DISPCNT_BG0_ON=0x0100 开 BG0, OBJ_ON=0x1000),
  REG_BG0CNT=0x04000008 (bit0-1 优先级, bit2-3 CBB 字符块, bit4-5 SBB 屏幕块,
  bit6 256色, bit7 尺寸, bit13 wraparound)
- **DMA 通道号别凭记忆写**: 0x040000B0=DMA0SAD (DMA0 首通道!), DMA3SAD=0x040000D4。
  实测踩坑: sub_8008978 用 DMA0, 误写 REG_DMA3SAD 导致池值变 0x040000D4 (SHA1 差 1 字节)
- **遇到 `0x04xxxxxx` 先查 `include/gba/io.h` 的偏移表再猜功能**, 别凭数量级臆想。
  典型误判: `0x04000130` 很容易当成定时器(定时器在 0x100-0x10E), 实际是 **REG_KEYINPUT**。
  旁边的 `mvns` 就是铁证 —— 按键是低有效, 原代码必定写 `~REG_KEYINPUT` 取反成按键掩码;
  定时器取反没意义。配套形状: `bics r0, r3` = `keys & ~旧值` → 新按下边沿检测的标准三件套
  (新边沿存 F2E、现状存 F2C、然后存后读回当实参)。→ sub_8050014
- u16 寄存器的字节读取: `(u8)REG_VCOUNT` 会生成 ldrh+截断(3条), 目标常是 ldrb(1条) ——
  用 `*(u8 *)&REG_VCOUNT` 或裸字节指针; 参照目标汇编选择
- volatile 读的死读取语句(`dma[2];`)可用于对齐"无条件寄存器回读"的目标形态
  —— 且这形态就是项目自带的 **`DmaSet` 宏** (include/gba/macro.h: DmaSetUnchecked 的
  `dmaRegs[0/1/2] = ...; dmaRegs[2];` 展开)。DMA 设置代码一律用
  `DmaSet(通道, src, dest, control)`, 不要手写寄存器数组
- **DMA 通道与地址陷阱**: REG_ADDR_TM0CNT_L = 0x04000100 (定时器在 0x100 段)!
  0x04000040 不是任何标准寄存器 (io.h 无宏) → 目标 DAD 写 0x04000040 时只能用字面量。
  教训: 宏名的语义不能想当然, 必须 grep 核对 REG_OFFSET_* 的实际值

## linker.ld 符号注册

- IWRAM 内偏移: `. = 0x00000XXX; gUnk_03000XXX = .;` (在 iwram section 内, 按地址排序插入,
  **插错位置会报 cannot move location counter backwards**)
- 新增符号后链接报 undefined reference = 忘了在 linker.ld 注册 (IWARM 偏移或 SECTIONS 外绝对符号二选一)
- ROM 绝对地址表: `gUnk_08XXXXXX = 0x08XXXXXX;` (**必须在 `SECTIONS {}` 外面**)
- 同一地址需要不同类型视图时用别名: `gUnk_03000730_arr = 0x03000730;` (同样放 SECTIONS 外)

## 踩过的坑

### 1. GCC2 跨函数状态泄漏 (最重要!)

同翻译单元内, **使用 r8/sb/sl (高位寄存器) 的函数会改变后续所有函数的寄存器分配**。

症状: 新函数单测 score=0, 合入后 make SHA1 失败, 但差异在**别的函数**。
定位: `cmp -l ll.gba baserom.gba` 找差异字节 → 查 ll.map 归属函数。

解法: **拆分翻译单元**。已拆两次: `src/code_1.c` + `src/code_1b.c` (在 sub_8020CC4 后),
`src/code_1b.c` + `src/code_1c.c` (在 sub_804F0B8 stub 处), linker.ld 中按顺序拼接。
以后合入使用 r8/sb/sl 或间接调用 (_call_via_rX) 的函数时, 如 SHA1 失败且差异在别处, 继续拆文件。
拆分锚点必须是 INCLUDE_ASM stub 行 (保持 ROM 顺序), includes 块照搬到新文件头部。

### 2. linker.ld 别名符号放错位置

别名符号放在 section 内部会让重定位叠加段基址
(0x03000730 → 0x06000730, 池值被污染, ROM 只差 1 字节)。
**所有绝对赋值符号一律放 SECTIONS {} 外面**。

### 3. 头文件旧声明 `void func()`

遇到带 u8/u16 形参的真定义会报 conflicting types。
按反汇编证据升级为全原型 (参数类型从调用方代码生成推断)。
同时 functions.tsv 的 status 才不会放错目录。

### 4. 编辑失误: 保留旧 INCLUDE_ASM 行

替换 INCLUDE_ASM 为真 C 时容易把原行留在新串里 → 链接期 symbol already defined。
合入前 grep 确认: `grep -n "<func>" src/*.c` 应只有一处定义。

### 5. objcopy --rename-section 清零内容 (本机 binutils 怪癖)

baserom.o 的正确生成方式 (不用 objcopy rename):

```bash
arm-none-eabi-objcopy -I binary -O elf32-littlearm baserom.gba /tmp/b1.o
printf 'SECTIONS { .text 0x08000000 : { *(.data) } }\n' > /tmp/wrap.ld
arm-none-eabi-ld -r -T /tmp/wrap.ld /tmp/b1.o -o baserom.o
```

(b1.o 的 .data 已含正确内容; 若直接 objcopy rename 或调整地址, 内容会被清零)

### 6. permuter 用法细节

- `-j` 必须带参数: `-j 4`
- base.c 不能 include 项目头文件 (permuter 用系统 cpp -nostdinc), 类型 typedef 内联
- 参考目标文件名必须固定: base.c / target.o / compile.sh / settings.toml
- compile.sh 必须可执行
- 临时变量/结构体大小错了会白跑很久, 先用 diff.py -o 确认基本形状再开 permuter

### 7. setup.sh 相关

- `scripts/gen_asm.py` / `tsv_init.py` 无第三方依赖, 系统 python3 即可 (旧 split_asm 的 pyyaml 依赖已随 yaml 函数清单一起移除)
- `data/raw_data/*.bin` 由 `scripts/dumpraw.py` 从 baserom.gba 提取 (2026-09-01 起 **setup.sh 已自动跑**;
  之前不跑, 新克隆 `make` 必报 `Failed to open "data/raw_data/byte_XXXX.bin"` —— `src/data_805769C.c` 等三处 INCBIN)
- **`scripts/fndiff.sh` 硬编码 `.venv/bin/python`**, 所以 `.venv` 是必需品而不是可选项; 但函数清单侧脚本
  (gen_asm/audit/fncheck/tsv_init/gen_reports) 系统 python3 就够。asm-differ 要 `colorama watchdog
  Levenshtein cxxfilt`, permuter 要 `toml`, m2c 只要 `graphviz` —— setup.sh 现在自建 venv 并装这些
  (`--skip-venv` 可跳)。**pip 失败只警告不中断**, 因为 make 不依赖它。
- ⚠ 改 setup.sh 的 agbcc 段时注意: `tools/agbcc/install.sh` **无条件** cp `agbcc`/`old_agbcc`/`agbcc_arm`,
  所以 `./build.sh || true` 这种"容忍 agbcc_arm 失败"的写法是假的 —— 会死在 install.sh 上且报错指不到真因。
  现在 build.sh 失败即停并打 `.scratch/agbcc-build.log` 尾部; 另外 `old_agbcc` 也要查 (m4a/m4a_tables/agb_sram 用它)。
- functions.tsv 的 status 与 src 中 INCLUDE_ASM 目录引用必须一致 (推导规则见 `tsv_init.py`, 怀疑漂移时重跑它交叉核对:
  引用 "asm/matchings" 的函数 yaml 必须是 [1], 否则 split 后文件缺失编译失败

### 8. 旧 ll.gba 让 sha1sum 误报绿灯 (本轮实际踩到)

`make` 如果**编译阶段就失败**(例如头文件原型与真 C 冲突), 它不会重写 `ll.gba`,
磁盘上留下的是上一次成功构建的产物 —— 此时单独跑 `sha1sum -c ll.sha1` 仍然报"成功",
很容易误判为"基线是绿的"。本轮接手时 `src/code_1.c` 就因为
`sub_8020A0C`/`sub_8020A7C`/`sub_8045F10` 三个旧 `void ()` 声明编译不过,
而 ll.gba 显示零字节差。

→ **开工先 `make` 看尾部有没有报错**, 不要只 `sha1sum -c`。
→ 修真 C 时同步升级头文件原型(按反汇编证据定参数/返回类型), 改完再 make。

### 9. 单函数 .o 对比时字面池未重定位 (score 假高)

见规则 29。典型现象: diff.py 逐行全绿但 score=400~600,
差异行集中在池常量地址(被 objdump 解码成 `movs r0, r0` 之类的假指令)。
用部分链接 + cmp 一次就能定性, 别去调写法。

### 10. 分节注释 `/* ==== 标题 ====` 漏写 `*/` → 吞掉紧跟的那一行 extern

`iwram.h` 里追加的 `/* ==== 视口/摄像机滚动 ... ====` 没有闭合, C 注释在**下一个** `*/`
处才结束 —— 也就是下一行 `extern s16 gCameraMinY;        /* 0x0300464C ... */` 的**行尾注释符**
把它关掉, 于是 `extern` 声明整行被注释掉, 使用者报 `'gCameraMinY' undeclared`。
症状: 只有紧跟分节标题的**第一行**声明消失, 后面的都正常 → 极易误判成"谁删了声明"。

→ 分节标题一律写 `/* ==== 标题 ==== */`; 排查用注释配对扫描:
```bash
python3 -c "import glob
for f in glob.glob('include/*.h')+glob.glob('src/*.c'):
    s=open(f,errors='replace').read(); i=0
    while True:
        a=s.find('/*',i)
        if a<0: break
        b=s.find('*/',a+2)
        if b<0: print(f,'UNTERMINATED line',s[:a].count(chr(10))+1); break
        i=b+2"
```
→ 同一坑的另一面: 往已被 `#include` 的头文件里搬 typedef/extern 时, 必须**同时删掉** .c 里的
本地重复声明 (agbcc 对 typedef 重复报 `conflicting types` 且是**错误**), 且要逐字段核对
两边布局一致再删, 否则改了类型 = 改了 codegen。

### 11. 目标里多出一个"死" callee-saved 初始化 (`movs r7, #0` 且全函数不再读 r7)

全 ROM 只有两例 (sub_8045EB8 / ChestObjects_LoadForMap)。egcs 会删掉"写了从没读"的
局部变量初始化 (实测 `u8 x = 0;` 完全不用 / `x++` / `if (x) {}` / `volatile u8 x = 0;` /
结构体局部 `s.a = 0;`+`if (s.a)` **全部被删**, 一个都不留), 所以这个 `movs r7, #0`
**必然对应源码里真实存在的一次读**, 只是那次读被 CSE 折成了零指令:

    *flags |= extra;      /* extra 恒为 0 → OR 0 被折叠, RMW 整条消失 */

关键在**顺序**: CSE 折叠读点发生在 flow 算活跃性**之后**, flow 仍把 `extra` 记成 live,
于是定义它的 `movs r7, #0` 活了下来, 并逼出第 4 个 callee-saved 寄存器 (push 变
`{r4,r5,r6,r7,lr}`)。同理 `*flags += x;`、`*flags = *flags | x;` 这类"值恒等"的
读点都可以当吊闩用 (与规则 89 的"故意保留死代码"是一对反向技巧: 89 是**造**一条假读,
这里是**留**一条真读到被折叠的表达式上)。

排查配方 (sub_8045EB8 实测, 88B 全绿):
1. 先按语义写最小版 (基址指针 + `u8 i = 0` + 目标原型), 确认只差 push/pop 与那条 `movs rN,#0`;
2. 补一个末位声明的局部 (`u8 extra = 0;`) + 函数末尾一条恒等读 → 一次命中;
3. 声明顺序 = 伪寄存器顺序: 目标里 `p, i, flags, extra` 分别落 r6/r5/r4/r7,
   把 extra 提前会整体错位 (见规则 51/54 的 home 讨论)。

## 工具与命令补充 (速查见 AGENTS.md §4)
| 工具 | 位置 | 用途 |
|---|---|---|
| m2c | tools/m2c (submodule) | asm→C 初转 |
| asm-differ | tools/asm-differ (submodule) | 汇编 diff (单函数 -o / 全 ROM -e) |
| decomp-permuter | tools/decomp-permuter (submodule) | 置换搜索压分 |
| diff_settings.py | 项目根 | asm-differ 配置 (base=baserom.o, my=ll.elf) |
| `agbcc -dl` | tools/agbcc/bin | **RTL/寄存器分配转储** → `gccdump.lreg` (查 qty 优先级与 home 寄存器) |
| `permuter/try.sh` | permuter/ | `./permuter/try.sh <func> <file.c>` → 编译 + 报 diff.py score |
| `.scratch/abs.ld` 部分链接法 | 临时 | 排除未重定位字面池假象, 做单函数字节级终验 (规则 29) |
| .venv | 项目根 | python 环境 (yaml/pycparser/graphviz/colorama/levenshtein/toml/pynacl) |
| **scripts/fndiff.sh** | 项目根 | **单函数回环**: 单独编 <func>.o → dump 汇编 → `tools/asm-differ` 对 `asm/{non,}matchings/<func>.s`; `--promote` 固化胜出版本 (规则 52) |
| **scripts/fncheck.py** | 项目根 | **单函数字节级定论**(自动施加池重定位+排除 bl 槽, 不需整 ROM 绿) + `--blame` 把 ROM 差异归属到 .o。<br>2026-09-01 修了三个假阴性: ① asm-match 函数无 `.size` 属性被误报 NOT BUILT (现用同节下一个符号/节大小定长);<br>② 指向段符号 `.text` 的 R_ARM_ABS32 报未解析 (现用 `函数ROM地址 - 节内偏移` 推段基址, 不取会漂移的 ll.map);<br>③ 无缓存导致慢。现 **588/588 已匹配函数全部可验**, 0 假 FAIL |
| **scripts/bytecmp.sh** | 项目根 | **候选级**字节判定: 编 `permuter/<func>/*.c` → 部分链接(施加池重定位) → 与 target.o 逐字节 cmp。<br>补上 fndiff(形状) 与 fncheck(已合入真身) 之间的空档。⚠ fndiff 的 score 会假阳性<br>(实测一个少一条 `ldrh` 的破代码也报 score=400), 候选阶段必须走 bytecmp |
| **scripts/typecov.py** | 项目根 | 逐函数变量类型解析, 把字段访问归到**真实结构体** —— 解决"按字段名 grep 被多个结构体同名字段污染" |
| **scripts/rename_scoped.py** | 项目根 | 按类型限定地改结构体字段名, 不碰其它结构体的同名字段; 编译器会反过来验证解析对不对 |
| **scripts/claim.sh** | 项目根 | **函数认领锁**(原子, 防两人做同一个) + `--list`/`--table` |

## 快速命令参考

```bash
# 环境激活 (fish)
source .venv/bin/activate.fish

# 多智能体协作三件套
export DECOMP_AGENT=B
scripts/claim.sh <func>                            # 认领 (失败则换一个)
make build/src/<你的文件>.o && python3 scripts/fncheck.py <func>   # 单函数自证
python3 scripts/fncheck.py --blame                 # ROM 红了看是谁的 .o
scripts/claim.sh --release <func>

# 全量构建+验证
make

# 重新提取 raw_data (换 baserom 后)
.venv/bin/python scripts/dumpraw.py

# 重新生成 asm 目录 (functions.tsv 改后; 增量, 幂等)
python3 scripts/gen_asm.py
# 从 src 重新推导函数清单 (交叉验证/初始化)
python3 scripts/tsv_init.py

# 重新生成 m2c 上下文 (头文件改后)
make ctx

# 找某函数地址
grep "<func>" ll.map

# 找 ROM 差异字节
cmp -l ll.gba baserom.gba

# 按 nonmatching 函数大小排序挑软柿子
for f in asm/nonmatchings/*.s; do echo "$(wc -l < $f) $f"; done | sort -n | head

# 单函数 .o 字节级终验 (排除未重定位字面池假象, 规则 29)
./permuter/<func>/compile.sh <候选.c> x .scratch/t.o
printf 'SECTIONS { .text 0 : { *(.text) } }\ngUnk_XXX = 0x03XXXXXX;\nsub_YYY = 0x08XXXXXX;\n' > .scratch/abs.ld
arm-none-eabi-ld -T .scratch/abs.ld -o .scratch/linked.o .scratch/t.o
arm-none-eabi-objcopy -O binary --only-section=.text .scratch/linked.o .scratch/mine.bin
arm-none-eabi-objcopy -O binary --only-section=.text permuter/<func>/target.o .scratch/tgt.bin
cmp -l .scratch/mine.bin .scratch/tgt.bin     # 只剩 bl 槽 = 已匹配

# 查寄存器分配为何不给某变量 (破解 home 问题)
arm-none-eabi-cpp -nostdinc -I tools/agbcc/include -iquote include <file>.c -o .scratch/x.i
tools/preproc/preproc .scratch/x.i | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit \
    -Wparentheses -O2 -fhex-asm -fprologue-bugfix -dl -o .scratch/x.s
grep '^Register ' gccdump.lreg; grep '^;; Register .* in' gccdump.lreg; rm -f gccdump.lreg
```
