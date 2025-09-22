#ifndef FirearmWeaponProperties_H
#define FirearmWeaponProperties_H

#include "../sdk.h"

namespace HoldFast {
	class FirearmWeaponProperties {
	public:
		FirearmWeaponProperties(uintptr_t base) : addr(base) {}


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