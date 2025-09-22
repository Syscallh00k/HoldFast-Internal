#ifndef ENTRY_H
#define ENTRY_H

#include "../Visuals/visuals.h"
#include "../Misc/Misc.h"

namespace HoldFast {
	namespace Entry {
		inline void DoCheat() {
			if (!HoldFast::Instance::ClientComponent_Instance || !HoldFast::cache.player_list.size())return;

			uintptr_t raw_rm = *(uintptr_t*)(HoldFast::Instance::ClientComponent_Instance + HoldFast::Offsets::ClientRoundPlayerManager);

			ClientRoundPlayerManager round_manager(raw_rm);
			if (!raw_rm || !round_manager.GameLoaded() || !round_manager.LocalPlayerActive())return;

			std::vector<uintptr_t> list;
			{
				std::lock_guard<std::mutex> lock(HoldFast::cache.player_mutex);
				list = HoldFast::cache.player_list;
			}

			for (auto round_player : list) {
				ClientRoundPlayer player(round_player);
				HoldFast::ClientPlayerBase player_base = player.GetPlayerBase();
				if (!player_base.IsAliveAndSpawned())continue;

				if (Features::Visuals::remove_team &&
					(cache.local_player.GetPlayerBase().GetSpawnData().GetSquadID() ==
						player_base.GetSpawnData().GetSquadID()
						)) continue;

				esp.DrawVisuals(round_player);
			}

			misc.DoMisc();
		}
	}
}

#endif