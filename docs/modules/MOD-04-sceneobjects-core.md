# MOD-04 场景对象核心 (0x0801A3C4-0x08020D50)

> 分析人: plan (2026-08-31)。源文件 `src/code_801A3C4.c` (642 行, 30 个真 C 函数)。
> **核心发现: 场景对象 (0xC8 字节) 有自己的脚本 VM** — 对象头部 +0x0/+0x4 是两个代码区指针,
> +0x8/+0xC 是命令流指针; 行为按 `*(u16*)(obj+0x18) & 0xF` 的 kind 值经
> `gUnk_0839CE7C[]` 函数表分发 (类似 MOD-08 的 opcode 表, 但按对象类型)。

## 对象结构 (0xC8 字节, 池 0x02037028, 关键字段)

+0x0/4 脚本代码指针 | +0x8/C 命令流 | +0x10/14 脚本基址对 | +0x18 kind(bits0-3) | +0x1A/1C/1E 计数
+0x24 标志(bit11=移动完成) | +0x28/29 复制槽 | +0x3C 精灵设置区(Unk_801B81C) | +0x66 样式
+0x6C/6E 移动坐标 | +0x88 数据指针 | +0xA2 移动状态 | +0xA3 移动参数 | +0xAB 方向
+0xB0 状态位(0x80=移动,0x2000=跳跃,bit1=锁定) | +0xB2 步长 | +0xBB/BC/BD 辅助
+0xBE 槽号(≤0xB 有效) | +0xBF/C0 朝向/参数 | +0xC3 事件值

## 真 C 函数 (30 个中 22 个已读)

| 地址 | 状态 | 语义名 | 语义 |
|---|---|---|---|
| 0x0801A684 | ✅C | `Obj_ResetScript` | 解析脚本头 (双偏移→+0/4, +4→8/C), 清计数, 按 kind 6-8 分发 |
| 0x0801B760/790/7B8 | ✅C | `ObjFlag_Set/Test/ClearAll` | gUnk_03000518 位图 (0x80B) + 03000598 |
| 0x0801B81C | ✅C | `ObjSprite_Setter` (已匹配) | 10 参精灵设置器 (field_10-2F, 见 MOD-05 跳跃/滑动调用) |
| 0x0801B878 | ✅C | `Obj_CmdDispatch` | kind 6/7/8→801AD0C, 其他→801A884 (对象命令分发) |
| 0x0801B8AC | ✅C | `Obj_FrameDispatch` | kind 6→801B570, 7/8→空, 其他→801B0B8 (每帧分发) |
| 0x0801B8E8 | ✅C | `Obj_FindJumpEntry` | 命令流跳转表查找 (value 比较步进) |
| 0x0801B8FC | ✅C | `Obj_FindJumpEntryAt` | 同上, 从 +0xC 表按 arg1 索引 |
| 0x0801B920 | ✅C | `OamAffine_Copy32` | gUnk_030034C0[32]→OAM 仿射参数 |
| 0x0801B954/95C | ✅C | `Obj_GetByte2/GetU16At1` | 指针槽字段读取 |
| 0x0801D12C | ✅C | `Obj_SetMoveState` | 0xA2 = f(0xAB 方向, 坐标相等判定) 移动状态机 |
| 0x0801DE44 | ✅C | `ResetSceneObjects` (已有名) | 清生成队列+按出生点表逐个 801D710 初始化 |
| 0x08020798/07A4 | ✅C | `Obj_Get744/Dec630` | 计数器 getter/递减 |
| 0x0802093C | ✅C | `Obj_ReadEventVal` | 按对象 0xBC 选 0x88 指针表偏移 → 0xC3 |
| 0x08020974 | ✅C | `ObjSprite_SetById` | gUnk_08393B28[arg1] 表 → ObjSprite_Setter |
| 0x080209EC | ✅C | `Obj_ResetWalkOfs` | 0x88=0, 0xB0\|=2 (槽≤6) |
| 0x08020A0C | ✅C | `ObjSprite_SetJump` | gUnk_0839B2A4 表 + arg1<<5 → 跳跃精灵 |
| 0x08020A7C | ✅C | `Party_AllAnimIdle` | 5 对象 8045F10(0x114) 检查 |
| 0x08020AB0 | ✅C | `ObjGroup_AnyEvent` | 80489E8 事件扫描 + 8044498 |
| 0x08020AE4 | ✅C | `ObjList_IncAffine` | 链表 (0x03000690) 遍历, 各对象 +0xB2 递增 |
| 0x08020B04 | ✅C | `ObjGroup_Spawn` | 80462E4 收集槽号 → 801D568 逐个初始化 |
| 0x08020B48 | ✅C | `Obj_Get718` | gUnk_03000718 getter |
| 0x08020B90 | ✅C | `Obj_Register` | gUnk_030006F8[714++]=obj; 槽>0xB → 718=obj (主角对象) |
| 0x08020BC0 | ✅C | `Obj_WalkCooldown` | 0x6C -= 0xB2 (≤0 归零返回 1) |
| 0x08020BF0/20C2C | ✅C | `Obj_FrameDispatchByKind` | 主角对象按 0xBE 分派 gUnk_0839CE7C 表 (0x71-0xFD 两段) |
| 0x08020C58 | ✅C | `Objs_PerFrameUpdate` | 遍历 0300062C 计数, 跳过 0xFF/状态 8/5, 按 gUnk_03000324 bit5 分派 804CEE0/804DD70 |
| 0x08020CC4 | ✅C | `ObjSprite_SetFromTable` | gUnk_08393B28[arg5] → ObjSprite_Setter + 0xB0\|=0x2000 |

## 对象行为表 (发现, 待逐个分析)

- `gUnk_0839CE7C[]`: 对象 kind → 行为函数表 (主角 0x71-0xB 段 + 0xFD 段)
- `gUnk_08393B28[]` / `gUnk_0839B2A4[]`: 精灵配置表 (field_0/4/8/A 四元组)
- `gUnk_0839CFAA[16]`: 出生点类别表 (MOD-03 Inv_FindFirstHeld 也引用)
- 0x03000690: 对象链表头 (field_8=首节点); 030006F8[]: 对象指针注册表; 03000714/718: 注册数/主角

## 未匹配 (54 个)

801A3C4, 801A5EC, 801A6F4, 801A884, 801AD0C, 801B0B8, 801B570, 801B964, 801BE34, 801C484,
801CA08, 801CBA4, 801CE80, 801CF90, 801D19C, 801D214, 801D378, 801D468, 801D568, 801D710,
801D984, 801DAA0, 801DB3C, 801DC20, 801DD04, 801DDB0, 801DEDC, 801DF90, 801E040, 801E1D8,
801E30C, 801E4D4, 801E690, 801E848, 801EA70, 801EC3C, 801ED40, 801EE6C, 801EEE4, 801F3FC,
801F76C, 801F884, 801FA10, 801FAB8, 801FEBC, 801FF40, 80200E8, 8020228, 802031C, 8020648,
80207DC, 8020840, 80208A4, 8020B54。
(801D710=对象初始化, 801BE34/801C484=对象命令执行分支, 80207DC=生成初始化 — 重点)

## 调用图证据 (2026-08-31)

- 与 MOD-05 同一系统: 物理跨 code_801A3C4.c / code_8020D50.c 两个文件, 调用边密集
- 依赖 0x08044394-0x080446BC 的**全局状态服务** (804442C/8044514/804448C 被 801BE34/801C484/80177AC 调用;
  sub_804442C/8044514 = 全局状态复位/初始化, callers 78-84 个)
- 对象行为函数族实际分布在 0x08044C-0x0804F (804C2FC=对象生成, 804CEE0/804DD70=每帧分发,
  8045F10=动画检查, 80462E4=槽号收集) — 物理在 MOD-07 区但语义属本系统
