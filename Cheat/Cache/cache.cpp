#include "cache.h"

void HoldFast::Cache::PlayerThread(){

	HoldFast::sdk = new HoldFast::SDK();
	static uintptr_t raw_client = 0;

	while (true) {
		HoldFast::sdk->ClientComponentReferenceManager_class.klass.GetField("ClientInstance").GetStaticValue(&raw_client);
		if (!raw_client)continue;

		uintptr_t raw_rm = *(uintptr_t*)(raw_client + HoldFast::Offsets::ClientRoundPlayerManager);
		if (!raw_rm)continue;

		ClientRoundPlayerManager round_manager(raw_rm);

		if (!round_manager.GameLoaded() || !round_manager.LocalPlayerActive()) continue;

		uintptr_t obj_list = HoldFast::GameFunctions::GetAllRoundPlayer(raw_rm);
		if(!obj_list) continue;

		uintptr_t item = *(uintptr_t*)(obj_list + 0x10);
		if (!item) continue;

		int size = *(int*)(item + 0x18);

		if (size <= 0) continue;

		cache.UpdateViewMatrix();

		std::vector<ClientRoundPlayer> temp_list;

		for (auto i{ 0 }; i < size; i++) {
			uintptr_t raw_rp = *(uintptr_t*)(item + 0x20 + (i * 0x8));
			if (!raw_rp)continue;

			ClientRoundPlayer round_player(raw_rp);

			ClientPlayerBase player_base = round_player.GetPlayerBase();

			if (!player_base.IsValid())continue;
			if (!player_base.IsAliveAndSpawned())continue;

			PlayerActorInitializer player_actor = player_base.GetPlayerActorInitializer();
			
			if (player_actor.IsLocalPlayer()) {
				local_player = round_player;
				continue;
			}

			temp_list.push_back(round_player);
		}

		std::lock_guard<std::mutex> lock(cache.player_mutex);
		cache.player_list.swap(temp_list);

		HoldFast::Instance::ClientComponent_Instance = raw_client;
		std::this_thread::sleep_for(std::chrono::milliseconds(3));
	}
}

void HoldFast::Cache::UpdateViewMatrix() {
	uintptr_t cam = HoldFast::GameFunctions::get_MainCamera();
	if (!cam || IsBadReadPtr((void*)cam, sizeof(uintptr_t))) return;
	uintptr_t camera = *reinterpret_cast<uintptr_t*>(cam + 0x10);
	if (!camera || IsBadReadPtr((void*)camera, sizeof(uintptr_t))) return;
	view_matrix = *reinterpret_cast<Matrix4x4*>(camera + 0x30c);
}