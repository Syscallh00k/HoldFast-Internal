#ifndef ModelProperties_H
#define ModelProperties_H

#include "../sdk.h"

namespace HoldFast {
	class ModelProperties {
	public:
		ModelProperties(uintptr_t base) : addr(base) {}

		BipedReferences GetBipedReferences() {
			uintptr_t raw_mp = *(uintptr_t*)(addr + Offsets::ModelProperties::bipedReferences);
			if (!raw_mp)return NULL;
			return BipedReferences(raw_mp);
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