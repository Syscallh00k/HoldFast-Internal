#ifndef ClientWeaponHolder_H
#define ClientWeaponHolder_H

#include "../sdk.h"

namespace HoldFast {
	class ClientWeaponHolder {
	public:
		ClientWeaponHolder(uintptr_t base) : addr(base) {}

		Weapon GetActiveWeapon() {
			if (!IsValid())return NULL;
			return GameFunctions::get_ActiveWeaponDetails(addr);
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