#ifndef ClientRoundPlayerManager_H
#define ClientRoundPlayerManager_H

#include "../sdk.h"

namespace HoldFast {
	class ClientRoundPlayerManager {
	public:
		bool GameLoaded() {
			return *(bool*)(addr + Offsets::initializedOnMap);
		}
		bool LocalPlayerActive() {
			return GameFunctions::get_LocalPlayerActive(addr);
		}
		ClientRoundPlayerManager(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}

#endif