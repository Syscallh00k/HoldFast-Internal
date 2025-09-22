#ifndef BipedReferences_H
#define BipedReferences_H

#include "../sdk.h"

namespace HoldFast {
	class BipedReferences {
	public:
		BipedReferences(uintptr_t base) : addr(base) {}
		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
		Transformation GetRoot() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::root);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetPelvis() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::pelvis);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetLeftThigh() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::leftThigh);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetLeftCalf() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::leftCalf);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetLeftFoot() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::leftFoot);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetRightThigh() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::rightThigh);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetRightCalf() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::rightCalf);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetRightFoot() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::rightFoot);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetLeftUpperArm() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::leftUpperArm);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetLeftForearm() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::leftForearm);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetLeftHand() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::leftHand);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetRightUpperArm() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::rightUpperArm);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetRightForearm() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::rightForearm);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetRightHand() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::rightHand);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		Transformation GetHead() {
			if (!IsValid())return NULL;
			uintptr_t raw = *(uintptr_t*)(addr + Offsets::BipedReferences::head);
			if (!raw) return NULL;
			uintptr_t cached_ptr = *(uintptr_t*)(raw + 0x10);
			if (!cached_ptr) return NULL;
			return Transformation(cached_ptr);
		}

		box_bounds get_bounds(float expand, Matrix4x4 view_matrix) {
			box_bounds ret = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

			auto head = GetHead();
			auto leftHand = GetLeftHand();
			auto rightHand = GetRightHand();
			auto leftFoot = GetLeftFoot();
			auto rightFoot = GetRightFoot();

			Transformation transforms[] = { head, leftHand, rightHand, leftFoot, rightFoot };

			for (auto& transform : transforms) {
				if (transform.IsValid()) {
					Vector3 pt = transform.GetPosition();
					if (!pt.IsZero()) {
						Vector2 screen;
						if (WorldToScreen(pt, screen, view_matrix)) {
							if (screen.x < ret.left)
								ret.left = screen.x;
							if (screen.x > ret.right)
								ret.right = screen.x;
							if (screen.y < ret.top)
								ret.top = screen.y;
							if (screen.y > ret.bottom)
								ret.bottom = screen.y;

							ret.onscreen = true;
						}
					}
				}
			}

			if (ret.left == FLT_MAX || ret.right == FLT_MIN || ret.top == FLT_MAX || ret.bottom == FLT_MIN)
				return box_bounds::null();

			ret.left -= expand;
			ret.right += expand;
			ret.top -= expand;
			ret.bottom += expand;

			return ret;
		}

	
	private:
		uintptr_t addr;
	};
}

#endif