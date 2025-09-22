#ifndef PlayerActorInitializer_H
#define PlayerActorInitializer_H

#include "../sdk.h"

namespace HoldFast {
	class PlayerActorInitializer {
	public:
		PlayerActorInitializer(uintptr_t base) : addr(base) {}

		bool IsLocalPlayer() {
			return *(bool*)(addr + Offsets::PlayerActorInitializer::is_localplayer);
		}
		ModelProperties GetModelProperties() {
			uintptr_t raw_mp = GameFunctions::get_CurrentModel(addr);
			if (!raw_mp) return NULL;
			return ModelProperties(raw_mp);
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