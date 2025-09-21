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
			uintptr_t raw_rpi = *(uintptr_t*)(addr + Offsets::PlayerBase::CurrentRoundPlayerInformation);
			return RoundPlayerInformation(raw_rpi);
		}

		PlayerActorInitializer GetPlayerActorInitializer() {
			uintptr_t raw_pai = *(uintptr_t*)(addr + Offsets::PlayerBase::playerActorInitializer);
			return PlayerActorInitializer(raw_pai);
		}
		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
		ClientPlayerBase(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}


#endif