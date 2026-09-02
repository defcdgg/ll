# 路线: 道具→装备→属性 (Game Data Route)

> 分析人: plan (2026-08-31)。**34 函数全匹配 + PartyForm_ApplyBonus 新匹配**。
> 这条路线从脚本 opcode 出发, 经背包/装备/属性/宝箱/回复到存档快照, 全部有真 C 可读。

## 路线图

```
脚本 opcode (MOD-08)                    数据层 (MOD-02)                     ROM 表
┌──────────────────────┐    ┌──────────────────────────┐    ┌─────────────────────┐
│ Op_GiveTakeItem      │───→│ AddInventoryItem         │←───│ gInventory (IWRAM)  │
│ Op_EquipItem         │───→│ RemoveInventoryItem      │    │                     │
│ Op_FullHealParty     │───→│ Silver_Add / Silver_Sub  │───→│ gSilverAmount       │
│ Op_SilverAddSub      │    │ FullHealParty            │    │                     │
│ Op_IfItemQtyJump     │    │ FullHealCharacter        │    │                     │
│ Op_ChestOpen         │───→│ Chest_Open               │    │ gChestFlags         │
│ Op_IfSaveLoadedJump  │───→│ (存档状态门)              │    │                     │
└──────────────────────┘    │ EquipItem (换装)          │    │                     │
                            │   └→ Stats_RecalcEquip   │───→│ gUnk_08093418       │
                            │   └→ Chara_GetFormGfx    │    │ gUnk_08092248       │
                            │ Chara_ClearTempStatus    │    │ gUnk_087EA580       │
                            │ Party_InitStats          │    │ (CharaBaseData)     │
                            └──────────────────────────┘    └─────────────────────┘
                                        ↓
                            PartyForm_ApplyBonus (新增✅)
                            gEquipBonusAtk / gEquipBonusDef
```

## 函数清单 (34 个, 全部已匹配+语义命名)

### 脚本 opcode 层 (MOD-08, code_804F0B8.c)
| 语义名 | 地址 | 动作 |
|---|---|---|
| Op_GiveTakeItem | 0x080530D4 | data[2]>100→Remove(-100) 否则 Add(+n) |
| Op_EquipItem | 0x080530B4 | `EquipItem(data[1], data[2], data[3])` |
| Op_FullHealParty | 0x0805309C | 全队回复 |
| Op_SilverAddSub | 0x08053104 | data[1]?+:- 金钱 |
| Op_IfItemQtyJump | 0x08053138 | gInventory[id]>0x62 条件跳转 |
| Op_ChestOpen | 0x0805316C | `Chest_Open(gUnk_03004860)` 开宝箱 |
| Op_IfSaveFlagJump | 0x0805321C | 存档标志条件跳转 |
| Op_IfSaveLoadedJump | 0x080531A8 | 存档状态门 |

### 背包/金钱 (MOD-02, code_8005020.c)
| 语义名 | 地址 | 语义 |
|---|---|---|
| AddInventoryItem | 0x0800AA60 | 背包 +count (上限 99) |
| RemoveInventoryItem | 0x0800AA84 | 背包 -count (下限 0) |
| Silver_Add | 0x0800AAA4 | 金钱 + (上限 999999) |
| Silver_Sub | 0x0800AAC0 | 金钱 - (下限 0) |

### 装备/属性 (MOD-02)
| 语义名 | 地址 | 语义 |
|---|---|---|
| EquipItem | 0x0800A9C0 | 换装 (旧装备回背包→Recalc) |
| Stats_RecalcEquip | 0x0800A79C | base+equip→最终七维 (消费 gEquipBonus*) |
| Stats_ClearEquipBonus | 0x0800ABBC | 9 个加成累加器清零 |
| Chara_GetFormGfx | 0x0800A0E4 | 装备→形态图形 id |
| Chara_ClearTempStatus | 0x0800AB7C | 清临时状态 |
| Party_InitStats | 0x0800A924 | 10 人 Stats 初始化+背包清空 |
| Party_AnyEquip | 0x0800AB3C | 队伍有人装武器→1 |

### 查表 (ROM 表消费)
| 语义名 | 地址 | 查的表 |
|---|---|---|
| ItemFindSlot | 0x0800A8D0 | `gItemDataTable` (5B/项: id+type+value) |
| ItemGetValue | 0x0800A958 | 同上 field_4 |
| ItemGetUsePower | 0x0801026C | 同上 + 装备特效修正 |
| ExpToLevel | 0x0800A86C | `gExpTable` (累计经验差值) |
| LevelToExp | 0x0800A8A0 | 同上求和 |

### 回复
| 语义名 | 地址 | 语义 |
|---|---|---|
| FullHealParty | 0x0800A980 | 全队 HP/MP 满 |
| FullHealCharacter | 0x0800ACA4 | 单人 HP/MP 满 |

### 宝箱
| 语义名 | 地址 | 语义 |
|---|---|---|
| ChestObjects_LoadForMap | 0x08008F28 | 场景切换时按地图筛选 256 项宝箱表，建立 gChests[16] |
| CheckFacingEvent | 0x08003F40 | A 键面向交互；宝箱项返回 itemId 对应的脚本事件 |
| Chest_Open | 0x0800908C | 音效(8/9)+ChestFlags 翻转+精灵重建 |
| Chest_BuildSprite | 0x08008FD0 | 宝箱 OAM 链 (开/关两形态) |
| ChestFlags_ClearAll | 0x08009168 | gChestFlags[0x20] 清零 |
| ChestFlags_Toggle | 0x08009184 | 位翻转 |
| ChestFlags_Test | 0x080091A4 | 读位 |

### 新匹配
| 语义名 | 地址 | 语义 |
|---|---|---|
| **PartyForm_ApplyBonus** | 0x0800AC08 | 队伍形态一致性检查: 4 角色 form 高 4 位全同 + 为 0xE/0xF → 设 gEquipBonusAtk/Def |

### RAM 全局变量 (已命名)

| 语义名 | 地址 | 类型 | 消费者 |
|---|---|---|---|
| gInventory | 0x03004980 | u8[0xFF] | 全路线 |
| gSilverAmount | 0x03002C38 | u32 | 金钱 |
| gPartyStats | 0x03004AC0 | PlayerStats[] | 七维/装备/HP/MP |
| gChestFlags | 0x03004870 | u8[0x20] | 宝箱开启位图 |
| **gEquipBonusAtk** | 0x03004AAC | u8 | 形态加成·攻 (PartyForm_ApplyBonus 写, Stats_RecalcEquip 读) |
| **gEquipBonusDef** | 0x03004A80 | u8 | 形态加成·防 |
| gEquipBonusAtkBase | 0x03004A90 | u8 | Stats_RecalcEquip: equip_atc 初值 |
| gEquipBonusDef2 | 0x03004AA8 | u8 | Stats_RecalcEquip: equip_def += |
| gEquipBonusRes/Men/Agl/Noa/Luc | 0x03004A94-AB8 | u8 ×5 | 其余四维加成 |
| gBgmRequestId | 0x03004850 | u8 | BGM 装载请求 |

### ROM 表

| 语义名 | 地址 | 布局 | 消费者 |
|---|---|---|---|
| **gItemDataTable** (gUnk_08093418) | 0x08093418 | 5B/项 ×0x30: [0]=charaId+1, [1]高4位=type, [4]=value | ItemFindSlot/ItemGetValue |
| **gExpTable** (gUnk_08092248) | 0x08092248 | u32 ×N: 逐级经验差值 | ExpToLevel/LevelToExp |
| **gCharaBaseData** (gUnk_087EA580) | 0x087EA580 | CharaBaseData 12B/角色: field_0/2=u16 成长率, field_4 高4=形态/低4=种族, pad[6]=含 0x0A 图鉴组 | Chara_GetFormGfx/PartyForm_ApplyBonus/SkillMenu 等 |

### ROM 数据定性 (2026-08-31 plan, 数据驱动)

`0x087EA580` = **敌人/角色基础数据表** (3072B = 256 项 × 12B, 有效 0-247, 末 8 项全零):

| 偏移 | 字段 | 数据证据 |
|---|---|---|
| +0x00 | u16 `expReward` 击败经验 | entry1=10 → entry22(boss)=15000, 单调性按怪强排 |
| +0x02 | u16 `goldReward` 击败金币 | **≈ exp/2** (210/248 项比值恰为 2.0) |
| +0x04 | u8 `formRace` | 高4位=外形类别 (0=常规, 0xD/0xE/0xF=特殊形态), 低4位=属性族 (0-7) |
| +0x05 | u8 `dropItemId` | 32 项非零, 范围 1-17 (掉落物 id) |
| +0x06 | u8 `hp` | entry1=6 (最弱小怪) → entry22=85 (boss) → entry222=150 (特殊形态) |
| +0x07 | u8 `attack` | 203/248 项=0; 非零 1-22 常见, 60-80 罕见 |
| +0x08 | u8 `defense` | 0(72)/1(54)/2(69) 三档为主 |
| +0x0A | u8 `aiTableIdx` | 0-57, ×3 索引 gUnk_0839CEFC 的 3B 位域记录 (sub_804DD90 case0-6 查询) |
| +0x0B | u8 `resistFlags` | 位段: 0xFF(42)/0x20(32)/0x10(28)/0x04(18)... 元素抗性/吸收位 |

**消费者**: Chara_GetFormGfx(+4&F), PartyForm_ApplyBonus(+4&F0), sub_800AAF8/AB18(u16 拼),
sub_804DD90(+0x0A→AI 表), gUnk_0839CEFC[idx] = AI 行为位域表。

**ROM 数据不落 C 数组**: data1.s 用 `.incbin baserom.gba, 0x7E9554` 把 0x087E9554-0x08800000
原始数据整体打入 ROM (0x087EA580 已在其内)。单独建 C 数组会使 .rodata 溢出 8MB
(实测: ld 报 `address 0x8800c00 not within region rom`)。
正确做法: **linker.ld 绝对别名** `gCharaBaseData = 0x087EA580;` + iwram.h 中
`extern const EnemyCharaStat gCharaBaseData[];` — 类型信息给编译器, 数据留在 .incbin。

### 双视图别名 (同一个地址, 两种类型)

```c
/* linker.ld (SECTIONS 外) */
gUnk_087EA580  = 0x087EA580;   /* 字节视图: sub_800AAF8/AB18/AADC/804DD90 局部 extern */
gCharaBaseData = 0x087EA580;   /* 结构视图: PartyForm_ApplyBonus */
```
iwram.h:
```c
extern const EnemyCharaStat gCharaBaseData[];
/* gUnk_087EA580 不在 iwram.h — 各 TU 用局部 extern 保持原状:
 *   code_8005020.c: extern u8 gUnk_087EA580[]      (非 const, 3 处)
 *   code_8044394.c: extern const u8 gUnk_087EA580[] (const, 1 处)
 * const 性不同会报 conflicting types (agbcc 严格) */
```
⚠ 两个视图不能混用: 字节视图函数 (sub_800AAF8/AB18) 改成 struct 字段访问会改变 GCC2
代码生成 (ldrb→ldrh 等), 导致已匹配 ROM 变红 (实测踩到, 规则 67 变体)。

## 新增代码片段 (PartyForm_ApplyBonus, 已入 src/)

```c
/* PartyForm_ApplyBonus — 队伍形态一致性检查 (0x0800AC08):
 * 4 名角色 (1-based id) 的种族/形态字节 (field_4 高 4 位) 全部相同时,
 * 若形态为 0xE/0xF (特殊形态) 则设置全队攻/防加成 (Stats_RecalcEquip 消费)。 */
void PartyForm_ApplyBonus(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    u8 val;
    Unk_Struct* p0, *p1, *p2, *p3;
    p0 = &gCharaBaseData[arg0];
    p1 = &gCharaBaseData[arg1];
    p2 = &gCharaBaseData[arg2];
    p3 = &gCharaBaseData[arg3];

    val = p0->field_4 & 0xF0;

    if( val == (p1->field_4 & 0xF0)
        && val == (p2->field_4 & 0xF0)
        && val == (p3->field_4 & 0xF0))
    {
        switch(val >> 4)
        {
            case 0xF:
                gEquipBonusAtk = 0x22;
                gEquipBonusDef = 0x2D;
                break;
            case 0xE:
                gEquipBonusAtk = 0x3C;
                gEquipBonusDef = 0x3F;
                break;
        }
    }
}
```
