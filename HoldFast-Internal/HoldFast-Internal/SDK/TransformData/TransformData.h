#ifndef TransformData_H
#define TransformData_H

#include "../sdk.h"


namespace HoldFast {
	class TransformData {
	public:
		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
		Vector3 GetLeft() {
			uintptr_t raw_position = GameFunctions::get_left(addr);
			if (!raw_position)return Vector3();
			return *(Vector3*)raw_position;
		}
		Vector3 GetRight() {
			uintptr_t raw_position = GameFunctions::get_right(addr);
			if (!raw_position)return Vector3();
			return *(Vector3*)raw_position;
		}
		Vector3 GetUp() {
			uintptr_t raw_position = GameFunctions::get_up(addr);
			if (!raw_position)return Vector3();
			return *(Vector3*)raw_position;
		}
		Vector3 GetDown() {
			uintptr_t raw_position = GameFunctions::get_down(addr);
			if (!raw_position)return Vector3();
			return *(Vector3*)raw_position;
		}
		TransformData(uintptr_t base) : addr(base) {}

	private:
		uintptr_t addr;
	};
}

#endif

