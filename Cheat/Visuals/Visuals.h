#ifndef VISUALS_H
#define VISUALS_H

#include "../Cache/cache.h"

namespace HoldFast {
	class Visuals { // use pre set instance 
	public:
		void DrawVisuals(HoldFast::ClientRoundPlayer round_player);
	}; inline Visuals esp;
}
#endif