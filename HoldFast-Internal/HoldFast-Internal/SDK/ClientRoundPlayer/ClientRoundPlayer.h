#ifndef ClientRoundPlayer_H
#define ClientRoundPlayer_H

#include "../sdk.h"


namespace HoldFast {
	class ClientRoundPlayer {
	public:

		ClientPlayerBase GetPlayerBase() {
			uintptr_t raw_pb = *(uintptr_t*)(addr + Offsets::ClientPlayerBase);
			return ClientPlayerBase(raw_pb);
		}

		TransformData GetPlayerTransformData() {
			uintptr_t raw_pb = *(uintptr_t*)(addr + Offsets::PlayerTransformData);
			return TransformData(raw_pb);
		}

		ClientRoundPlayer(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}

#endif

