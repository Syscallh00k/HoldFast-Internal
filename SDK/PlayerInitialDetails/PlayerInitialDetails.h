#ifndef PlayerInitialDetails_H
#define PlayerInitialDetails_H

#include "../sdk.h"

namespace HoldFast {
	class PlayerInitialDetails {
	public:
		PlayerInitialDetails(uintptr_t base) : addr(base) {}

		std::string GetUsername() {
			uintptr_t raw_name = *(uintptr_t*)(addr + Offsets::PlayerInitialDetails::DisplayName);
			if (!raw_name)return "";
			wchar_t* wide_name = reinterpret_cast<wchar_t*>(raw_name + 0x14);
			std::wstring w_name(wide_name);
			return std::string(w_name.begin(), w_name.end());
		}

		int GetRank() {
			 
			uintptr_t raw_rank = *(uintptr_t*)(addr + Offsets::PlayerInitialDetails::Rank);
			return (int)(raw_rank);
				
		}

		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
	private:
		uintptr_t addr;
	};
}

#endif