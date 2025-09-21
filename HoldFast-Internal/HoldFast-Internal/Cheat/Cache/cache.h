#ifndef CACHE_H
#define CACHE_H

#include <mutex>
#include <vector>
#include <shared_mutex>

#include "../../SDK/sdk.h"

namespace HoldFast {
	class Cache {
	public:
		Matrix4x4 view_matrix;
		std::mutex player_mutex;
		std::vector<ClientRoundPlayer> player_list;
		ClientRoundPlayer local_player{0};

		void PlayerThread();
		void UpdateViewMatrix();
	}; inline Cache cache;
}

#endif