#ifndef UNITYSTRUCTS_H
#define UNITYSTRUCTS_H
#include <vector>
#include <cstdint>
#include <array>
#include <cassert>

namespace HoldFast {
	namespace Enums {
		enum PlayerActions : int
		{
			// Token: 0x04000309 RID: 777
			None,
			// Token: 0x0400030A RID: 778
			Obsolete_ShipAutoMove,
			// Token: 0x0400030B RID: 779
			Jump,
			// Token: 0x0400030C RID: 780
			StartAimingFirearm,
			// Token: 0x0400030D RID: 781
			StopAimingFirearm,
			// Token: 0x0400030E RID: 782
			FireFirearm,
			// Token: 0x0400030F RID: 783
			Obsolete_FireCannon,
			// Token: 0x04000310 RID: 784
			Obsolete_Driveship,
			// Token: 0x04000311 RID: 785
			Run,
			// Token: 0x04000312 RID: 786
			Crouch,
			// Token: 0x04000313 RID: 787
			PlayerAutoWalk,
			// Token: 0x04000314 RID: 788
			SwitchWeapon,
			// Token: 0x04000315 RID: 789
			StartReloadFirearm,
			// Token: 0x04000316 RID: 790
			InterruptReloadFirearm,
			// Token: 0x04000317 RID: 791
			FinishReloadFirearm,
			// Token: 0x04000318 RID: 792
			EnableCombatStance,
			// Token: 0x04000319 RID: 793
			DisableCombatStance,
			// Token: 0x0400031A RID: 794
			StartMeleeWeaponHold,
			// Token: 0x0400031B RID: 795
			StopMeleeWeaponHold,
			// Token: 0x0400031C RID: 796
			ExecuteMeleeWeaponStrike,
			// Token: 0x0400031D RID: 797
			MeleeStrikeHigh,
			// Token: 0x0400031E RID: 798
			MeleeStrikeLow,
			// Token: 0x0400031F RID: 799
			MeleeStrikeLeft,
			// Token: 0x04000320 RID: 800
			MeleeStrikeRight,
			// Token: 0x04000321 RID: 801
			StartMeleeBlock,
			// Token: 0x04000322 RID: 802
			StopMeleeBlock,
			// Token: 0x04000323 RID: 803
			ChangeMeleeBlock,
			// Token: 0x04000324 RID: 804
			MeleeBlockHigh,
			// Token: 0x04000325 RID: 805
			MeleeBlockLow,
			// Token: 0x04000326 RID: 806
			MeleeBlockLeft,
			// Token: 0x04000327 RID: 807
			MeleeBlockRight,
			// Token: 0x04000328 RID: 808
			FireDryFirearm,
			// Token: 0x04000329 RID: 809
			StartCrouching,
			// Token: 0x0400032A RID: 810
			StopCrouching,
			// Token: 0x0400032B RID: 811
			StopGestureAnimation,
			// Token: 0x0400032C RID: 812
			PlayerGestureDanceGanGamStyle,
			// Token: 0x0400032D RID: 813
			PlayerGestureDanceHipHop,
			// Token: 0x0400032E RID: 814
			PlayerGestureDanceThriller,
			// Token: 0x0400032F RID: 815
			PlayerGestureDanceBelly,
			// Token: 0x04000330 RID: 816
			PlayerGestureMusketKick,
			// Token: 0x04000331 RID: 817
			PlayerGestureMusketCrouch,
			// Token: 0x04000332 RID: 818
			PlayerGestureInstrumentBass,
			// Token: 0x04000333 RID: 819
			PlayerGestureInstrumentGuitar,
			// Token: 0x04000334 RID: 820
			PlayerGestureInstrumentDrums,
			// Token: 0x04000335 RID: 821
			PlayerGestureSalute,
			// Token: 0x04000336 RID: 822
			PlayerGesturePointing,
			// Token: 0x04000337 RID: 823
			PlayerGestureLookingHorizon,
			// Token: 0x04000338 RID: 824
			PlayerGestureMaleLayingDownPose,
			// Token: 0x04000339 RID: 825
			ExecuteSecondaryAttack,
			// Token: 0x0400033A RID: 826
			PlayerGestureSaluteMusket,
			// Token: 0x0400033B RID: 827
			PlayerGesturePresentArmsMusket,
			// Token: 0x0400033C RID: 828
			PlayerGesturePray,
			// Token: 0x0400033D RID: 829
			PlayerGestureSurrender,
			// Token: 0x0400033E RID: 830
			PlayerGesturePoint,
			// Token: 0x0400033F RID: 831
			PlayerGestureWave,
			// Token: 0x04000340 RID: 832
			PlayerGestureSillyDance,
			// Token: 0x04000341 RID: 833
			PlayerGestureSaluteSword,
			// Token: 0x04000342 RID: 834
			PlayerGestureAttentionWave,
			// Token: 0x04000343 RID: 835
			PlayerGestureDancingTwerk,
			// Token: 0x04000344 RID: 836
			PlayerGestureDancingFunny,
			// Token: 0x04000345 RID: 837
			PlayerGestureSwingDancing,
			// Token: 0x04000346 RID: 838
			PlayerGestureNorthernSoulFloorCombo,
			// Token: 0x04000347 RID: 839
			PlayerGestureBackFlip,
			// Token: 0x04000348 RID: 840
			StartBayonetAttach,
			// Token: 0x04000349 RID: 841
			StartBayonetDetach,
			// Token: 0x0400034A RID: 842
			InterruptBayonetAttach,
			// Token: 0x0400034B RID: 843
			InterruptBayonetDetach,
			// Token: 0x0400034C RID: 844
			FinishBayonetAttach,
			// Token: 0x0400034D RID: 845
			FinishBayonetDetach,
			// Token: 0x0400034E RID: 846
			PlayerGesturePanic,
			// Token: 0x0400034F RID: 847
			PlayerGestureSitDown,
			// Token: 0x04000350 RID: 848
			PlayerGestureCharge,
			// Token: 0x04000351 RID: 849
			PlayerGestureTauntAxe,
			// Token: 0x04000352 RID: 850
			PlayerGestureTauntAxe2,
			// Token: 0x04000353 RID: 851
			WeaponUnloaded,
			// Token: 0x04000354 RID: 852
			PlayerGestureCheer,
			// Token: 0x04000355 RID: 853
			StartGestureAnimation,
			// Token: 0x04000356 RID: 854
			PlayerGestureRPSPaper,
			// Token: 0x04000357 RID: 855
			PlayerGestureRPSRock,
			// Token: 0x04000358 RID: 856
			PlayerGestureRPSScissors,
			// Token: 0x04000359 RID: 857
			PlayerGestureWhistle,
			// Token: 0x0400035A RID: 858
			StartCrouchWalkingWeaponGesture,
			// Token: 0x0400035B RID: 859
			ExitCrouchWalkingWeaponGesture
		};

		// Token: 0x02000007 RID: 7
		enum AmmoType : int
		{
			// Token: 0x04000023 RID: 35
			aNone,
			// Token: 0x04000024 RID: 36
			CannonBall,
			// Token: 0x04000025 RID: 37
			OBSOLETE_SmallBuckShot,
			// Token: 0x04000026 RID: 38
			ChainShot,
			// Token: 0x04000027 RID: 39
			Lantern,
			// Token: 0x04000028 RID: 40
			CarryAmmoBox,
			// Token: 0x04000029 RID: 41
			LargeBuckShot,
			// Token: 0x0400002A RID: 42
			RocketCarcass,
			// Token: 0x0400002B RID: 43
			CaseRockets,
			// Token: 0x0400002C RID: 44
			CarryRocketsAmmoBox,
			// Token: 0x0400002D RID: 45
			RocketShell,
			// Token: 0x0400002E RID: 46
			Spyglass,
			// Token: 0x0400002F RID: 47
			IgniteExplosiveBarrel,
			// Token: 0x04000030 RID: 48
			CarryExplosiveBarrel,
			// Token: 0x04000031 RID: 49
			CarrySwivelGun,
			// Token: 0x04000032 RID: 50
			SmallRocketShell,
			// Token: 0x04000033 RID: 51
			Frontlines_MillsGrenadeMKII,
			// Token: 0x04000034 RID: 52
			Frontlines_Stielhandgranate_1916,
			// Token: 0x04000035 RID: 53
			Frontlines_Frontlines_No37_MKI,
			// Token: 0x04000036 RID: 54
			Frontlines_HandNebelBombe,
			// Token: 0x04000037 RID: 55
			CarryMachineGunAllied,
			// Token: 0x04000038 RID: 56
			CarryMachineGunCentral,
			// Token: 0x04000039 RID: 57
			MachineGunAmmo,
			// Token: 0x0400003A RID: 58
			CarryMachineGunAmmobox,
			// Token: 0x0400003B RID: 59
			CarryHowitzerAmmobox,
			// Token: 0x0400003C RID: 60
			HowitzerHEShell,
			// Token: 0x0400003D RID: 61
			HowitzerSmokeShell,
			// Token: 0x0400003E RID: 62
			CarryHeavyMortarAmmobox,
			// Token: 0x0400003F RID: 63
			HeavyMortarHEShell,
			// Token: 0x04000040 RID: 64
			HeavyMortarSmokeShell,
			// Token: 0x04000041 RID: 65
			FestiveRocket,
			// Token: 0x04000042 RID: 66
			IgniteTNT,
			// Token: 0x04000043 RID: 67
			CarryTNT,
			// Token: 0x04000044 RID: 68
			TurretHEShell,
			// Token: 0x04000045 RID: 69
			ShrapnelShot,
			// Token: 0x04000046 RID: 70
			HowitzerBuckShot,
			// Token: 0x04000047 RID: 71
			SmallCannonBall,
			// Token: 0x04000048 RID: 72
			MortarCannonBall,
			// Token: 0x04000049 RID: 73
			ChristmasConfettiBuckshot,
			// Token: 0x0400004A RID: 74
			ChristmasConfettiBuckshotSmall,
			// Token: 0x0400004B RID: 75
			Frontlines_3InchDeckGunShell,
			// Token: 0x0400004C RID: 76
			Disassemble,
			// Token: 0x0400004D RID: 77
			Frontlines_CoastGunHEShell
		};
		enum NetworkConnectionError : int
		{
			// Token: 0x040001F3 RID: 499
			InternalDirectConnectFailed = -5,
			// Token: 0x040001F4 RID: 500
			EmptyConnectTarget,
			// Token: 0x040001F5 RID: 501
			IncorrectParameters,
			// Token: 0x040001F6 RID: 502
			CreateSocketOrThreadFailure,
			// Token: 0x040001F7 RID: 503
			AlreadyConnectedToAnotherServer,
			// Token: 0x040001F8 RID: 504
			NoError,
			// Token: 0x040001F9 RID: 505
			ConnectionFailed = 14,
			// Token: 0x040001FA RID: 506
			TooManyConnectedPlayers = 17,
			// Token: 0x040001FB RID: 507
			RSAPublicKeyMismatch = 20,
			// Token: 0x040001FC RID: 508
			ConnectionBanned,
			// Token: 0x040001FD RID: 509
			InvalidPassword,
			// Token: 0x040001FE RID: 510
			DetectedDuplicatePlayerID,
			// Token: 0x040001FF RID: 511
			NATTargetNotConnected = 61,
			// Token: 0x04000200 RID: 512
			NATTargetConnectionLost,
			// Token: 0x04000201 RID: 513
			NATPunchthroughFailed,
			// Token: 0x04000202 RID: 514
			IncompatibleVersions,
			// Token: 0x04000203 RID: 515
			ServerAuthenticationTimeout,
			// Token: 0x04000204 RID: 516
			ConnectionTimeout = 70,
			// Token: 0x04000205 RID: 517
			LimitedPlayers,
			// Token: 0x04000206 RID: 518
			IsAuthoritativeServer = 80,
			// Token: 0x04000207 RID: 519
			ApprovalDenied,
			// Token: 0x04000208 RID: 520
			ProxyTargetNotConnected = 90,
			// Token: 0x04000209 RID: 521
			ProxyTargetNotRegistered,
			// Token: 0x0400020A RID: 522
			ProxyServerNotEnabled,
			// Token: 0x0400020B RID: 523
			ProxyServerOutOfPorts,
			// Token: 0x0400020C RID: 524
			NetworkShutdown = 100,
			// Token: 0x0400020D RID: 525
			UserDefined1 = 128,
			// Token: 0x0400020E RID: 526
			UserDefinedDefault = 150,
			// Token: 0x0400020F RID: 527
			UserDefinedKicked,
			// Token: 0x04000210 RID: 528
			UserDefinedBanned,
			// Token: 0x04000211 RID: 529
			UserDefinedSteamRequired,
			// Token: 0x04000212 RID: 530
			UserDefinedServerShutdown,
			// Token: 0x04000213 RID: 531
			UserDefinedLostConnection,
			// Token: 0x04000214 RID: 532
			UserDefinedServerNotInitialized,
			// Token: 0x04000215 RID: 533
			UserDefinedVACBanned,
			// Token: 0x04000216 RID: 534
			UserDefinedVACTimeout,
			// Token: 0x04000217 RID: 535
			UserDefinedSessionExpired,
			// Token: 0x04000218 RID: 536
			UserDefinedInvalidPlatform,
			// Token: 0x04000219 RID: 537
			UserDefinedPlayFabRequired,
			// Token: 0x0400021A RID: 538
			UserDefinedNoLicense,
			// Token: 0x0400021B RID: 539
			UserDefinedIncompatibleMods,
			// Token: 0x0400021C RID: 540
			EnterUserIntoQueue,
			// Token: 0x0400021D RID: 541
			QueueIsFull,
			// Token: 0x0400021E RID: 542
			ServerContainsDuplicatePlayerNames,
			// Token: 0x0400021F RID: 543
			ServerContainsPlayerWithSameName,
			// Token: 0x04000220 RID: 544
			TimeoutAfterGameSuspended
		};

		enum FactionCountry : int
		{
			// Token: 0x040001B0 RID: 432
			Nocne,
			// Token: 0x040001B1 RID: 433
			British,
			// Token: 0x040001B2 RID: 434
			French,
			// Token: 0x040001B3 RID: 435
			Prussian,
			// Token: 0x040001B4 RID: 436
			Russian,
			// Token: 0x040001B5 RID: 437
			Italian,
			// Token: 0x040001B6 RID: 438
			Allied,
			// Token: 0x040001B7 RID: 439
			Central,
			// Token: 0x040001B8 RID: 440
			Austrian,
			// Token: 0x040001B9 RID: 441
			Internal_Frontline_British = 100,
			// Token: 0x040001BA RID: 442
			Internal_Frontline_French,
			// Token: 0x040001BB RID: 443
			Internal_Frontline_USA,
			// Token: 0x040001BC RID: 444
			Internal_Frontline_Ottoman,
			// Token: 0x040001BD RID: 445
			Internal_Frontline_Austria,
			// Token: 0x040001BE RID: 446
			Internal_Frontline_German,
			// Token: 0x040001BF RID: 447
			Internal_Frontline_Australian
		};

		enum ModelBonePositionType : int
		{
			// Token: 0x04004DB2 RID: 19890
			Nonea,
			// Token: 0x04004DB3 RID: 19891
			Root,
			// Token: 0x04004DB4 RID: 19892
			Hips,
			// Token: 0x04004DB5 RID: 19893
			LowerSpine,
			// Token: 0x04004DB6 RID: 19894
			MiddleSpine,
			// Token: 0x04004DB7 RID: 19895
			Chest,
			// Token: 0x04004DB8 RID: 19896
			Neck,
			// Token: 0x04004DB9 RID: 19897
			Head,
			// Token: 0x04004DBA RID: 19898
			LeftHand,
			// Token: 0x04004DBB RID: 19899
			RightHand,
			// Token: 0x04004DBC RID: 19900
			ItemBone,
			// Token: 0x04004DBD RID: 19901
			RodBone
		};

		enum PlayerAnimatableActions : int
		{
			// Token: 0x04005626 RID: 22054
			aJump,
			// Token: 0x04005627 RID: 22055
			aShootFirearm,
			// Token: 0x04005628 RID: 22056
			aReloadFirearm,
			// Token: 0x04005629 RID: 22057
			aDeath_Firearm,
			// Token: 0x0400562A RID: 22058
			aMeleeStrikeHigh,
			// Token: 0x0400562B RID: 22059
			aMeleeStrikeLow,
			// Token: 0x0400562C RID: 22060
			aMeleeStrikeLeft,
			// Token: 0x0400562D RID: 22061
			aMeleeStrikeRight
		};

		enum bone_offset : uint32_t {
			root = 0x10,
			pelvis = 0x18,
			leftThigh = 0x20,
			leftcalf = 0x28,
			leftFoot = 0x30,
			rightThigh = 0x38,
			rightCalf = 0x40,
			rightFoot = 0x48,
			leftUpperArm = 0x50,
			leftForeArm = 0x58,
			leftHand = 0x60,
			rigthUpperArm = 0x68,
			rightForearm = 0x70,
			rightHand = 0x78,
			head = 0x80,
			spine = 0x88,
			eyes = 0x90
		};

	}

	class HFList {
	public:
		int Count() const {
			uintptr_t item = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (!item) return 0;
			return *reinterpret_cast<int*>((uintptr_t)this + 0x18);
		}

		uintptr_t Value() const {
			return *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
		}

		uintptr_t GetValue(int index) const {
			uintptr_t value = this->Value();
			if (!value) return 0;
			return *reinterpret_cast<uintptr_t*>(value + 0x20 + (index * 0x8));
		}
	};
}




#endif