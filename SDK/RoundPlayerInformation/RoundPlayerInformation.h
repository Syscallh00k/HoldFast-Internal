#ifndef RoundPlayerInformation_H
#define RoundPlayerInformation_H

#include "../sdk.h"

namespace HoldFast {
	class RoundPlayerInformation {
	public:
		PlayerInitialDetails GetInitialDetails() {
			if (!IsValid())return NULL;
			uintptr_t raw_pid = *(uintptr_t*)(addr + Offsets::PlayerBase::InitialDetails);
			return PlayerInitialDetails(raw_pid);

		}
		std::string GetPlatformType() {
			if (!IsValid())return NULL;
			Enums::PlayerPlatform platform = *(Enums::PlayerPlatform*)(addr + Offsets::PlayerBase::PlayerPlatform);
			switch (platform) {
			case Enums::Nonbe:
					return "Unknown";
				break;
			case Enums::PSN:
				return "PSN";
				break;
			case Enums::Steam:
					return "Steam";
				break;
			case Enums::Xbox:
				return "Xbox";
				break;
			case Enums::CustomLogin:
					return "Custom";
				break;
			}
			return "Unknown";
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