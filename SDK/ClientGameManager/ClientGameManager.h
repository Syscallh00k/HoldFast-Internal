#ifndef ClientGameManager_H
#define ClientGameManager_H

#include "../sdk.h"

namespace HoldFast {
	class ClientGameManager {
	public:

		ClientGameManager(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}


#endif