#ifndef Weapon_H
#define Weapon_H

#include "../sdk.h"

namespace HoldFast {
	class Weapon {
	public:
		Weapon(uintptr_t base) : addr(base) {}

		FirearmWeaponProperties ResolveFirearmProperties() {
			if (!IsValid())return NULL;
			return GameFunctions::ResolveFirearmWeaponProperties(addr);
		}

		std::string GetDisplayName() {
			if (!IsValid())return "";
			uintptr_t raw_name = *(uintptr_t*)(addr + Offsets::Weapon::displayName);
			if (!raw_name)return "";
			wchar_t* wide_name = reinterpret_cast<wchar_t*>(raw_name + 0x14);
			std::wstring w_name(wide_name);
			return std::string(w_name.begin(), w_name.end());
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