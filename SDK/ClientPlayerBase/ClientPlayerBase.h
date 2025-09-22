#ifndef ClientPlayerBase_H
#define ClientPlayerBase_H

#include "../sdk.h"

namespace HoldFast {
	class ClientPlayerBase {
	public:
		bool IsAliveAndSpawned() {
			return GameFunctions::Is_Alive_Spawned(addr);
		}

		RoundPlayerInformation GetCurrentRoundPlayerInformation() {
			if (!IsValid())return NULL;
			uintptr_t raw_rpi = *(uintptr_t*)(addr + Offsets::PlayerBase::CurrentRoundPlayerInformation);
			return RoundPlayerInformation(raw_rpi);
		}

		PlayerActorInitializer GetPlayerActorInitializer() {
			if (!IsValid())return NULL;
			uintptr_t raw_pai = *(uintptr_t*)(addr + Offsets::PlayerBase::playerActorInitializer);
			return PlayerActorInitializer(raw_pai);
		}

		CommonGlobalVariables GetGlobalVariables() {
			if (!IsValid())return NULL;
			uintptr_t raw_cgv = *(uintptr_t*)(addr + Offsets::PlayerBase::commonGlobalVariables);
			return CommonGlobalVariables(raw_cgv);
		}

		PlayerSpawnData GetSpawnData() {
			if (!IsValid())return NULL;
			uintptr_t raw_cgv = *(uintptr_t*)(addr + Offsets::PlayerStartData);
			return PlayerSpawnData(raw_cgv);
		}

		float GetHealth() {
			if (!IsValid())return NULL;
			return *(float*)(addr + Offsets::PlayerBase::health);
		}

		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}


		ClientWeaponHolder GetWeaponHolder() {
			if (!IsValid())return NULL;
			uintptr_t raw_rpi = *(uintptr_t*)(addr + Offsets::PlayerBase::ClientWeaponHolder);
			return ClientWeaponHolder(raw_rpi);
		}

		ClientPlayerBase(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}


#endif