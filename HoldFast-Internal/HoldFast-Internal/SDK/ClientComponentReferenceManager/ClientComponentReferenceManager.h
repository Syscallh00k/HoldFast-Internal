#ifndef ClientComponentReferenceManager_H
#define ClientComponentReferenceManager_H

#include "../sdk.h"


namespace HoldFast {
	class ClientComponentReferenceManager {
	public:

		ClientComponentReferenceManager(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}

#endif

