#pragma once

#define get_member(name, offset, type) \
    auto inline name() -> type { return *reinterpret_cast<type*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::offset); }

#define set_member(name, offset, type) \
    auto inline name(type set_field) -> void { *reinterpret_cast<type*>(reinterpret_cast<std::uintptr_t>(this) + Offsets::offset) = set_field; }

#define member(name, offset, type) \
    get_member(get_##name, offset, type) \
	set_member(set_##name, offset, type)

#define static_get_member(name, field, type) \
	auto static inline name() -> type {static type retn; Offsets::field.GetStaticValue(reinterpret_cast<void*>(&retn)); return retn; }

#include "../Mono/NaResolver.h"
#include "../Utils/unityStructs.h"
#include "../Utils/offset.h"
#include "../Render/draw.h"
#include "../Utils/vector.h"

//!all clients inhearite base classes!
//! 
//sdk
#include "TransformData/TransformData.h"
#include "Transformation/Transformation.h"
#include "ClientGameManager/ClientGameManager.h"
#include "ClientComponentReferenceManager/ClientComponentReferenceManager.h"
#include "ClientRoundPlayerManager/ClientRoundPlayerManager.h"
#include "PlayerInitialDetails/PlayerInitialDetails.h"
#include "PlayerSpawnData/PlayerSpawnData.h"
#include "RoundPlayerInformation/RoundPlayerInformation.h"
#include "CommonGlobalVariables/CommonGlobalVariables.h"
#include "BipedReferences/BipedReferences.h"
#include "ModelProperties/ModelProperties.h"
#include "FirearmWeaponProperties/FirearmWeaponProperties.h"
#include "Weapon/Weapon.h"
#include "ClientWeaponHolder/ClientWeaponHolder.h"
#include "PlayerActorInitializer/PlayerActorInitializer.h"
#include "ClientPlayerBase/ClientPlayerBase.h"
#include "ClientRoundPlayer/ClientRoundPlayer.h"

namespace HoldFast
{
	class SDK
	{
	public:
		SDK();
		NaResolver::Class ClientComponentReferenceManager_class;
		auto assembly_path(std::string assembly_name) -> std::string;

		NaResolver* resolver;
		std::string assemblies_path;


	}inline *sdk;

}