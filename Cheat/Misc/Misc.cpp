#include "Misc.h"

void HoldFast::Misc::DoMisc() {
	CommonGlobalVariables player_variables = cache.local_player.GetPlayerBase().GetGlobalVariables();
	if (player_variables.IsValid()) {
		if (Features::Misc::instant_hit)
			player_variables.SetBulletSpeed(99999.0f);
	}
}