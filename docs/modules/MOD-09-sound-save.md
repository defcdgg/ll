# MOD-09 音频驱动 (sound.c) + 存档库 (agb_sram.c)

> 分析人: plan (2026-08-31)。sound.c 234 行 (17 函数全✅) + agb_sram.c 81 行。
> **本模块解锁了脚本 opcode 全部 8053xxx callees 的命名。**

## sound.c = m4a 驱动包装层 (0x080533F0-0x0805388F)

| 地址 | 语义名 | 语义 |
|---|---|---|
| 0x080533F0 | `SoundMain_Frame` | 每帧入口 (AgbMain/VBlank 调用): 处理淡入(03000F38 bit2)/淡出(bit4)音量斜坡 + `m4aSoundMain()` + 曲目管理 |
| 0x080534B4 | `SoundTracks_Frame` | 4 个曲目槽管理: 播完自动重启/淡入挂起 (附 C 注释) |
| 0x0805359C | `Sound_Init` | m4aSoundInit + 状态清零 |
| 0x080535E8 | `Sound_GetFlags` | 返回 gSoundTaskFlags |
| 0x080535F4 | `Sound_VSyncOff` | m4aSoundVSyncOff + bit0 |
| 0x0805360C | `Sound_VSyncOn` | m4aSoundVSyncOn + 清 bit0 |
| 0x08053628 | `Bgm_Play` | 播放 BGM: 歌号 0x3F/0x40/0x41 重映射到 0x11B/0x11C/0x11A, m4aSongNumStart + 音量 |
| 0x08053688 | `Bgm_Stop` | m4aSongNumStop(当前号) |
| 0x0805369C | `Bgm_SetVolume` | 音量钳制 ≥2 → m4aMPlayVolumeControl |
| 0x080536C0 | `Bgm_FadeIn` | 斜坡参数 (gFadeFrom=0) |
| 0x080536EC | `Bgm_FadeOut` | 斜坡参数 (gFadeFrom=当前音量) |
| 0x08053720 | `Bgm_Continue` | m4aSongNumContinue |
| 0x08053734 | `Sfx_TrackBusy` | 曲目槽 bit 测试 |
| 0x0805374C | `Sfx_Play` | MPlayStart(gMPlayInfos2[arg1], 曲目) + 循环标志 |
| 0x080537C0 | `Sfx_PlayFade` | 同上 + 临时淡出挂起 |
| 0x08053838 | `Sfx_StopTrack` | m4aMPlayStop + 清位 |
| 0x08053884 | `Sfx_GetLoopFlag` | gSfxTrackLoopBits bit |

### 新命名 RAM (sound.c 区, 0x03000F38-0x03000F50)

| 符号 | 语义 |
|---|---|
| gUnk_03000F38 | `gSoundTaskFlags` (bit0=VSyncOff, bit2=淡入中, bit4=淡出中) |
| gUnk_03000F3A | `gPlayingSongId` |
| gUnk_03000F3C | `gBgmVolume` |
| gUnk_03000F3E | `gFadeFromVolume` |
| gUnk_03000F40 | `gFadeDuration` |
| gUnk_03000F41 | `gFadeCounter` |
| gUnk_03000F42 | `gSfxTrackActiveBits` |
| gUnk_03000F43 | `gSfxTrackLoopBits` |
| gUnk_03000F48[4] | `gSfxTrackSongIds` |
| gUnk_03000F50 | `gSfxTrackFadeBits` |

> 修正: 之前把 0x03004850 命名为 gCurrentSongId — 实为 BGM/脚本装载请求 id
> (sub_8008DCC 写入, sub_80525E8 消费), 现名 `gBgmRequestId` (中等置信)。

## agb_sram.c (官方 SRAM 库)

`ReadSram`(代码拷入 IWRAM 执行提速) / `WriteSram` / `VerifySram`(返回错址) / `WriteSramEx`(3 次重试),
版本串 `SRAM_V112`。被 save.c 的 `Save_Fsm` 使用。

## save.c (0x080109F8-0x08010F10, 5 函数全✅)

| 地址 | 语义名 | 语义 |
|---|---|---|
| 0x080109F8 | `Save_Fsm` | 状态机 (状态号在 gUnk_03004D44): 读槽→校验→写槽→校验→四槽格式化(F9-FC)→全槽失效(FD: 4 个镜像首字节=0xFF)→收尾(FF); 槽号 gUnk_03004DD0, 每槽 0x800B, SRAM 0x0E000000+slot<<11 ↔ 镜像 0x02021000+slot<<11 |
| 0x08010BEC | `Save_FillSlot0` | 槽序列化 |
| 0x08010CCC | `Save_FillSlot1` | |
| 0x08010D80 | `Save_FillSlot2` | |
| 0x08010E58 | `Save_FillSlot3` | |

**存档布局**: 15 槽 (gUnk_03004DD0 ≤ 0xE), 4 个镜像区 0x02021000/02023000/02025000/02027000 = 每槽 4 页。
