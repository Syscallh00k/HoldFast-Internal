#include "sdk.h"
#include <filesystem>
#include <iostream>
#include <string>

#define get_offset(klasss, offset_name, offset_field) \
        offset_field = klasss.klass.GetField(offset_name).GetOffset(); \
        if (offset_field <= 0) throw (std::string("Failed to get ") + offset_name + " offset")

#define get_field(klasss,offset_name,offset_field) \
		offset_field = klasss.klass.GetField(offset_name); \
		if (offset_field.fieldInfo == nullptr) throw (std::string("Failed to get ") + offset_name + " field")

#define get_method_address(klasss,method_name,method_field) \
		method_field = resolver->GetMethod(klasss,method_name).method.GetInvokeAddress(); \
		if (method_field == nullptr) throw (std::string("Failed to get ") + method_name + " method")


#define get_generic_method_address(klasss,method_name,method_field) \
		method_field = klasss.GetMethod(method_name).GetInvokeAddress(); \
		if (method_field == nullptr) throw (std::string("Failed to get ") + method_name + " method")

auto HoldFast::SDK::assembly_path(std::string assembly_name) -> std::string
{
	return this->assemblies_path + assembly_name;
}


HoldFast::SDK::SDK()
{
	try
	{
		assemblies_path = std::filesystem::current_path().string() + "\\Holdfast NaW_Data\\Managed\\";

		resolver = &naResolverInstance;
		if (!resolver->Setup()) {
			throw "Failed to setup mono resolver";
		}
		ClientComponentReferenceManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientComponentReferenceManager");
		NaResolver::Class ClientRoundPlayerManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientRoundPlayerManager");
		NaResolver::Class RoundPlayer_Class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "RoundPlayer");
		NaResolver::Class PlayerBase_Class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerBase");
		NaResolver::Class ServerAzureBackendManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ServerAzureBackendManager");
		auto ClientConnectionManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientConnectionManager");
		auto TransformData_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "TransformData");
		NaResolver::Class camera_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "Camera");
		NaResolver::Class BipedReferences_class = resolver->GetClass(assembly_path("RootMotion.dll"), "RootMotion", "BipedReferences");
		NaResolver::Class LineRenderer_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "LineRenderer");
		NaResolver::Class GameObject_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "GameObject");
		NaResolver::Class debug_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "Debug");
		NaResolver::Class transformation_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "Transform");
		NaResolver::Class PlayerOwner_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerOwne");
		NaResolver::Class CommonGlobalVariables_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "CommonGlobalVariables");
		NaResolver::Class FirearmWeaponProperties_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "FirearmWeaponProperties");
		NaResolver::Class Stack_class = resolver->GetClass(assembly_path("mscorlib.dll"), "System.Collections.Generic", "Stack<T>");
		NaResolver::Class DamageableObjectApplyDamagePacket_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "DamageableObjectApplyDamagePacket");
		NaResolver::Class HomelessMethods_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "HomelessMethods");
		NaResolver::Class GenericObjectPool_class = resolver->GetClass(assembly_path("HoldfastUtils.Runtime.dll"), "HoldfastGame", "GenericObjectPool`1");
		NaResolver::Class BitStream_class = resolver->GetClass(assembly_path("uLink.Runtime.dll"), "uLink", "BitStream");
		NaResolver::Class ModelRenderableItems_class = resolver->GetClass(assembly_path("Uniforms.Runtime.dll"), "HoldfastGame", "ModelRenderableItems");
		NaResolver::Class ProjectileLaunchingManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ProjectileLaunchingManager");
		NaResolver::Class ComponentReferenceManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ComponentReferenceManager");
		NaResolver::Class PlayerAnimationHandler_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerAnimationHandler");
		NaResolver::Class ClientPlayerDamageManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientPlayerDamageManager");
		NaResolver::Class OwnerCameraManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "OwnerCameraManager");
		NaResolver::Class WeaponHolder_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "WeaponHolder");
		NaResolver::Class Weapon_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "Weapon");
		NaResolver::Class ClientPlayerBase_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientPlayerBase");
		NaResolver::Class LagPosition_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "LagPosition");
		NaResolver::Class PlayerActorInitializer_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerActorInitializer");
		NaResolver::Class ClientRoundPlayer_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientRoundPlayer");
		NaResolver::Class Homeless_Method = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "HomelessMethods");
		NaResolver::Class ModelBonePositions_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ModelBonePositions");
		NaResolver::Class ModelProperties_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ModelProperties");
		NaResolver::Class RoundPlayerInformation_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "RoundPlayerInformation");
		NaResolver::Class PlayerInitialDetails_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerInitialDetails");
		NaResolver::Class DamageDealer_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "DamageDealer");
		NaResolver::Class PhysicsProjectileObject_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PhysicsProjectileObject");
		NaResolver::Class mGun_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "MalbersAnimations.Weapons", "MGun");
		NaResolver::Class OwnerPacketToServer_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "OwnerPacketToServer");
		NaResolver::Class ClientWeaponHolder_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "ClientWeaponHolder");
		NaResolver::Class WeaponModel_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "WeaponModel");
		NaResolver::Class PlayerDamageManagerRPCManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerDamageManagerRPCManager");
		NaResolver::Class DamageableObjectManagerRPCManager_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "DamageableObjectManagerRPCManager");
		NaResolver::Class MeleeAttackInterruptPacket_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "MeleeAttackInterruptPacket");
		NaResolver::Class PlayerSpawnData_class = resolver->GetClass(assembly_path("Assembly-CSharp.dll"), "HoldfastGame", "PlayerSpawnData");
		NaResolver::Class racast_hit_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "RaycastHit");
		NaResolver::Class Time_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "Time");
		NaResolver::Class Gizmos_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "Gizmos");
		NaResolver::Class Texture2D_class = resolver->GetClass(assembly_path("UnityEngine.CoreModule.dll"), "UnityEngine", "Texture2D");

		get_offset(ClientComponentReferenceManager_class, "clientRoundPlayerManager", HoldFast::Offsets::ClientRoundPlayerManager);
		get_offset(ClientComponentReferenceManager_class, "clientGameManager", HoldFast::Offsets::ClientGameManager);
		get_offset(ClientComponentReferenceManager_class, "clientProjectileLaunchingManager", HoldFast::Offsets::ClientProjectileLaunchingManager);
		get_offset(RoundPlayer_Class, "PlayerBase", HoldFast::Offsets::ClientPlayerBase);
		get_offset(ClientRoundPlayerManager_class, "initializedOnMap", HoldFast::Offsets::initializedOnMap);


		get_offset(PlayerBase_Class, "<CurrentRoundPlayerInformation>k__BackingField", HoldFast::Offsets::PlayerBase::CurrentRoundPlayerInformation);
		get_offset(ClientPlayerBase_class, "playerActorInitializer", HoldFast::Offsets::PlayerBase::playerActorInitializer);

		get_offset(PlayerActorInitializer_class, "isLocalPlayer", HoldFast::Offsets::PlayerActorInitializer::is_localplayer);

		get_offset(RoundPlayerInformation_class, "InitialDetails", HoldFast::Offsets::PlayerBase::InitialDetails);
		get_offset(RoundPlayerInformation_class, "PlayerPlatform", HoldFast::Offsets::PlayerBase::PlayerPlatform);
		get_offset(PlayerInitialDetails_class, "DisplayName", HoldFast::Offsets::PlayerInitialDetails::DisplayName);
		get_offset(PlayerInitialDetails_class, "Rank", HoldFast::Offsets::PlayerInitialDetails::Rank);
		get_offset(ModelProperties_class, "bipedReferences", HoldFast::Offsets::ModelProperties::bipedReferences);
		get_offset(RoundPlayer_Class, "PlayerTransformData", HoldFast::Offsets::PlayerTransformData);
		get_offset(PlayerBase_Class, "weaponHolder", HoldFast::Offsets::PlayerBase::ClientWeaponHolder);
		get_offset(Weapon_class, "displayName", HoldFast::Offsets::Weapon::displayName);
		get_offset(PlayerBase_Class, "commonGlobalVariables", HoldFast::Offsets::PlayerBase::commonGlobalVariables);

		get_offset(CommonGlobalVariables_class, "<ForwardRunSpeed>k__BackingField", HoldFast::Offsets::GlobalVariables::ForwardRunSpeed);
		get_offset(CommonGlobalVariables_class, "<ForwardWalkSpeed>k__BackingField", HoldFast::Offsets::GlobalVariables::ForwardWalkSpeed);
		get_offset(CommonGlobalVariables_class, "characterJumpForceScale", HoldFast::Offsets::GlobalVariables::characterJumpForceScale);
		get_offset(CommonGlobalVariables_class, "serverUpdateProperties", HoldFast::Offsets::GlobalVariables::serverUpdateProperties);
		get_offset(CommonGlobalVariables_class, "infiniteFirearmAmmo", HoldFast::Offsets::GlobalVariables::infiniteFirearmAmmo);
		get_offset(CommonGlobalVariables_class, "firearmBulletTravelSpeed", HoldFast::Offsets::GlobalVariables::firearmBulletTravelSpeed);
		get_offset(PlayerSpawnData_class, "Faction", HoldFast::Offsets::SpawnData::SquadID);
		get_offset(PlayerBase_Class, "<Health>k__BackingField", HoldFast::Offsets::PlayerBase::health);
		get_offset(PlayerBase_Class, "<PlayerStartData>k__BackingField", HoldFast::Offsets::PlayerStartData);

		//bones
		get_offset(BipedReferences_class, "root", HoldFast::Offsets::BipedReferences::root);
		get_offset(BipedReferences_class, "pelvis", HoldFast::Offsets::BipedReferences::pelvis);
		get_offset(BipedReferences_class, "leftThigh", HoldFast::Offsets::BipedReferences::leftThigh);
		get_offset(BipedReferences_class, "leftCalf", HoldFast::Offsets::BipedReferences::leftCalf);
		get_offset(BipedReferences_class, "leftFoot", HoldFast::Offsets::BipedReferences::leftFoot);
		get_offset(BipedReferences_class, "rightThigh", HoldFast::Offsets::BipedReferences::rightThigh);
		get_offset(BipedReferences_class, "rightCalf", HoldFast::Offsets::BipedReferences::rightCalf);
		get_offset(BipedReferences_class, "rightFoot", HoldFast::Offsets::BipedReferences::rightFoot);
		get_offset(BipedReferences_class, "leftUpperArm", HoldFast::Offsets::BipedReferences::leftUpperArm);
		get_offset(BipedReferences_class, "leftForearm", HoldFast::Offsets::BipedReferences::leftForearm);
		get_offset(BipedReferences_class, "leftHand", HoldFast::Offsets::BipedReferences::leftHand);
		get_offset(BipedReferences_class, "rightUpperArm", HoldFast::Offsets::BipedReferences::rightUpperArm);
		get_offset(BipedReferences_class, "rightForearm", HoldFast::Offsets::BipedReferences::rightForearm);
		get_offset(BipedReferences_class, "rightHand", HoldFast::Offsets::BipedReferences::rightHand);
		get_offset(BipedReferences_class, "head", HoldFast::Offsets::BipedReferences::head);


		get_method_address(ClientRoundPlayerManager_class, "GetAllRoundPlayers", HoldFast::FunctionLocation::GetAllRoundPlayers);
		get_method_address(ClientRoundPlayerManager_class, "get_LocalPlayerActive", HoldFast::FunctionLocation::get_LocalPlayerActive);
		get_method_address(PlayerBase_Class, "get_SpawnedAndAlive", HoldFast::FunctionLocation::Is_Alive_Spawned);
		get_method_address(camera_class, "get_main", HoldFast::FunctionLocation::get_MainCamera);
		get_method_address(PlayerActorInitializer_class, "get_CurrentModel", HoldFast::FunctionLocation::get_CurrentModel);
		get_method_address(WeaponHolder_class, "get_ActiveWeaponDetails", HoldFast::FunctionLocation::get_ActiveWeaponDetails);
		get_method_address(Weapon_class, "ResolveFirearmWeaponProperties", HoldFast::FunctionLocation::ResolveFirearmWeaponProperties);

		get_method_address(TransformData_class, "get_left", HoldFast::FunctionLocation::get_left);
		get_method_address(TransformData_class, "get_right", HoldFast::FunctionLocation::get_right);
		get_method_address(TransformData_class, "get_up", HoldFast::FunctionLocation::get_up);
		get_method_address(TransformData_class, "get_down", HoldFast::FunctionLocation::get_down);


		//casting
		HoldFast::GameFunctions::GetAllRoundPlayer = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::GetAllRoundPlayers);
		HoldFast::GameFunctions::Is_Alive_Spawned = *reinterpret_cast<bool(*)(uintptr_t)>(FunctionLocation::Is_Alive_Spawned);
		HoldFast::GameFunctions::get_LocalPlayerActive = *reinterpret_cast<bool(*)(uintptr_t)>(FunctionLocation::get_LocalPlayerActive);
		HoldFast::GameFunctions::get_MainCamera = *reinterpret_cast<uintptr_t(*)()>(FunctionLocation::get_MainCamera);
		HoldFast::GameFunctions::get_CurrentModel = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::get_CurrentModel);
		HoldFast::GameFunctions::get_ActiveWeaponDetails = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::get_ActiveWeaponDetails);
		HoldFast::GameFunctions::ResolveFirearmWeaponProperties = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::ResolveFirearmWeaponProperties);

		HoldFast::GameFunctions::get_left = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::get_left);
		HoldFast::GameFunctions::get_right = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::get_right);
		HoldFast::GameFunctions::get_up = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::get_up);
		HoldFast::GameFunctions::get_down = *reinterpret_cast<uintptr_t(*)(uintptr_t)>(FunctionLocation::get_down);

		std::cout << "[~] Successfully dump all offsets" << std::endl;
	}
	catch (const char* message)
	{
		MessageBoxA(NULL, message, "Error", NULL);
	}
	catch (...)
	{
		MessageBoxA(NULL, "[!] Some error in sdk class", "Error", NULL);
	}

}
