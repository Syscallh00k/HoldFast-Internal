#ifndef CommonGlobalVariables_H
#define CommonGlobalVariables_H

#include "../sdk.h"

namespace HoldFast {
	class CommonGlobalVariables {
	public:
		CommonGlobalVariables(uintptr_t base) : addr(base) {}

		bool GetServerUpdateProperties() {
			uintptr_t raw_properties = *(uintptr_t*)(addr + Offsets::GlobalVariables::serverUpdateProperties);
			if (!raw_properties)return false;
			return *(bool*)raw_properties;
		}

		void SetServerUpdateProperties(bool value) {
			uintptr_t raw_properties = *(uintptr_t*)(addr + Offsets::GlobalVariables::serverUpdateProperties);
			if (!raw_properties)return;
			*(bool*)raw_properties = value;
		}

		float GetBulletSpeed() {
			uintptr_t raw_speed = *(uintptr_t*)(addr + Offsets::GlobalVariables::firearmBulletTravelSpeed);
			if (!raw_speed)return 0.0f;
			return *(float*)raw_speed;
		}

		void SetBulletSpeed(float speed) {
			if (GetBulletSpeed() <= 0 || GetServerUpdateProperties())return;
			uintptr_t raw_speed = *(uintptr_t*)(addr + Offsets::GlobalVariables::firearmBulletTravelSpeed);
			if (!raw_speed)return;
			*(float*)raw_speed = speed;
			SetServerUpdateProperties(true);
		}

		float GetForwardWalkSpeed() {
			uintptr_t raw_speed = *(uintptr_t*)(addr + Offsets::GlobalVariables::ForwardWalkSpeed);
			if (!raw_speed)return 0.0f;
			return *(float*)raw_speed;
		}
		
		void SetForwardWalkSpeed(float speed) {
			if (GetForwardWalkSpeed() == speed)return;
			uintptr_t raw_speed = *(uintptr_t*)(addr + Offsets::GlobalVariables::ForwardWalkSpeed);
			if (!raw_speed)return;
			*(bool*)raw_speed = speed;
		}

		float GetForwardRunSpeed() {
			uintptr_t raw_speed = *(uintptr_t*)(addr + Offsets::GlobalVariables::ForwardRunSpeed);
			if (!raw_speed)return 0.0f;
			return *(float*)raw_speed;
		}

		void SetForwardRunSpeed(float speed) {
			if (GetForwardRunSpeed() == speed)return;
			uintptr_t raw_speed = *(uintptr_t*)(addr + Offsets::GlobalVariables::ForwardRunSpeed);
			if (!raw_speed)return;
			*(bool*)raw_speed = speed;
		}

		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
	private:
		uintptr_t addr;
	};
}

#endif