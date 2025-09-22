#ifndef OFFSETS_H
#define OFFSETS_H

#include <Windows.h>

namespace HoldFast {

	namespace Features {
		namespace Visuals {
			inline bool box = false;
			inline bool corner_box = false;
			inline bool held_item = false;
			inline bool health = false;
			inline bool distance = false;
			inline bool name = false;
			inline bool rank = false;
			inline bool skeleton = false;
			inline float render_distance = 400.0f;
			inline bool remove_team = false;
		}

		namespace Aimbot {

		}

		namespace Misc {
			inline bool no_recoil;
		}
	}
	namespace Instance {
		inline uintptr_t ClientComponent_Instance;
	}
	namespace GameFunctions {
		inline uintptr_t(*GetAllRoundPlayer)(uintptr_t);
		inline bool(*Is_Alive_Spawned)(uintptr_t);
		inline bool(*get_LocalPlayerActive)(uintptr_t);
		inline uintptr_t(*get_MainCamera)();
		inline uintptr_t(*get_CurrentModel)(uintptr_t);
		inline uintptr_t(*get_left)(uintptr_t);
		inline uintptr_t(*get_right)(uintptr_t);
		inline uintptr_t(*get_up)(uintptr_t);
		inline uintptr_t(*get_down)(uintptr_t);
		inline uintptr_t(*get_ActiveWeaponDetails)(uintptr_t);
		inline uintptr_t(*ResolveFirearmWeaponProperties)(uintptr_t);
	}
	namespace FunctionLocation {
		inline void* GetAllRoundPlayers = 0;
		inline void* Is_Alive_Spawned = 0;
		inline void* get_LocalPlayerActive = 0;
		inline void* get_MainCamera = 0;
		inline void* get_CurrentModel = 0;
		inline void* get_left = 0;
		inline void* get_right = 0;
		inline void* get_up = 0;
		inline void* get_down = 0;
		inline void* get_ActiveWeaponDetails = 0;
		inline void* ResolveFirearmWeaponProperties = 0;
	}
	namespace Offsets {
		inline uintptr_t ClientRoundPlayerManager = 0;
		inline uintptr_t ClientProjectileLaunchingManager = 0;
		inline uintptr_t PlayerTransformData = 0;
		inline uintptr_t ClientPlayerBase = 0;
		inline uintptr_t ClientGameManager = 0;
		inline uintptr_t initializedOnMap = 0;

		namespace GlobalVariables {
			inline uintptr_t ForwardRunSpeed = 0;
			inline uintptr_t ForwardWalkSpeed = 0;
			inline uintptr_t serverUpdateProperties = 0;
			inline uintptr_t characterJumpForceScale = 0;
			inline uintptr_t infiniteFirearmAmmo = 0;
			inline uintptr_t firearmBulletTravelSpeed = 0;
		}
		namespace Weapon {
			inline uintptr_t displayName = 0;
		}
		namespace PlayerBase {
			inline uintptr_t CurrentRoundPlayerInformation = 0;
			inline uintptr_t InitialDetails = 0;
			inline uintptr_t playerActorInitializer = 0;
			inline uintptr_t ClientWeaponHolder = 0;
			inline uintptr_t commonGlobalVariables = 0;
		}
		namespace PlayerInitialDetails {
			inline uintptr_t DisplayName = 0;
			inline uintptr_t Rank = 0;
		}

		namespace PlayerActorInitializer {
			inline uintptr_t is_localplayer;
		}

		namespace ModelProperties {
			inline uintptr_t bipedReferences = 0;
		}

		namespace BipedReferences {
			inline uintptr_t root = 0;
			inline uintptr_t pelvis = 0;
			inline uintptr_t leftThigh = 0;
			inline uintptr_t leftCalf = 0;
			inline uintptr_t leftFoot = 0;
			inline uintptr_t rightThigh = 0;
			inline uintptr_t rightCalf = 0;
			inline uintptr_t rightFoot = 0;
			inline uintptr_t leftUpperArm = 0;
			inline uintptr_t leftForearm = 0;
			inline uintptr_t leftHand = 0;
			inline uintptr_t rightUpperArm = 0;
			inline uintptr_t rightForearm = 0;
			inline uintptr_t rightHand = 0;
			inline uintptr_t head = 0;
		}


	}
}


#endif