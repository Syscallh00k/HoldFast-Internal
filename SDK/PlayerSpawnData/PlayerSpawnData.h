#ifndef PlayerSpawnData_H
#define PlayerSpawnData_H

#include "../sdk.h"

namespace HoldFast {
	class PlayerSpawnData {
	public:
		PlayerSpawnData(uintptr_t base) : addr(base) {}

		Enums::FactionCountry GetSquadID() {
			if (!IsValid())return Enums::FactionCountry::Nocne;
			return *(Enums::FactionCountry*)(addr + Offsets::SpawnData::SquadID);
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