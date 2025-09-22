#ifndef RoundPlayerInformation_H
#define RoundPlayerInformation_H

#include "../sdk.h"

namespace HoldFast {
	class RoundPlayerInformation {
	public:
		PlayerInitialDetails GetInitialDetails() {
			uintptr_t raw_pid = *(uintptr_t*)(addr + Offsets::PlayerBase::InitialDetails);
			return PlayerInitialDetails(raw_pid);

		}
		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
		RoundPlayerInformation(uintptr_t base) : addr(base) {}
	private:
		uintptr_t addr;
	};
}

#endif