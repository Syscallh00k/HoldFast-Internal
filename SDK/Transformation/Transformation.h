#ifndef Transformation_H
#define Transformation_H

#include "../sdk.h"
#include <emmintrin.h>

namespace HoldFast {
	class Transformation {
	public:
		Transformation(uintptr_t base) : addr(base) {}
		bool IsValid() {
			if (!addr || IsBadReadPtr((void*)addr, sizeof(uintptr_t)))
				return false;

			return true;
		}
		uintptr_t get_addy() {
			return addr;
		}
		Vector3 GetPosition()
		{
			if (!(uintptr_t)addr)
				return Vector3();

			auto TransformAccessReadOnly = *reinterpret_cast<transform_access_read_only_t*>(addr + 0x38);

			auto TransformData = *reinterpret_cast<transform_data_t*>(TransformAccessReadOnly.transform_data + 0x18);

			auto Index = *reinterpret_cast<unsigned int*>(addr + 0x40);

			if (Index > 1000000)return Vector3();

			const m128 MultiplyVector1 = { -2.000, 2.000, -2.000, 0.000 };
			const m128 MultiplyVector2 = { 2.000, -2.000, -2.000, 0.000 };
			const m128 MultiplyVector3 = { -2.000, -2.000, 2.000, 0.000 };

			m128 Result{};

			int TransformIndex = *reinterpret_cast<int*>(TransformData.transform_indices + 0x4 * Index);
			int Safe = 0;
			if (TransformIndex > 1000000)return Vector3();

			Result = *reinterpret_cast<m128*>(TransformData.transform_array + 0x30 * Index);

			while (TransformIndex >= 0 && Safe++ < 200) {
				matrix34_t Matrix = *reinterpret_cast<matrix34_t*>(TransformData.transform_array + 0x30 * TransformIndex);
				__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.vec2), 0x00));	// xxxx
				__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.vec2), 0x55));	// yyyy
				__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.vec2), 0x8E));	// zwxy
				__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.vec2), 0xDB));	// wzyw
				__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.vec2), 0xAA));	// zzzz
				__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&Matrix.vec2), 0x71));	// yxwy
				__m128 tmp7 = _mm_mul_ps(*(__m128*)(&Matrix.vec3), Result);

				Result = _mm_add_ps(_mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(xxxx, MultiplyVector2), zwxy),
								_mm_mul_ps(_mm_mul_ps(yyyy, MultiplyVector3), wzyw)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(zzzz, MultiplyVector3), wzyw),
								_mm_mul_ps(_mm_mul_ps(xxxx, MultiplyVector1), yxwy)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
					_mm_add_ps(
						_mm_mul_ps(
							_mm_sub_ps(
								_mm_mul_ps(_mm_mul_ps(yyyy, MultiplyVector1), yxwy),
								_mm_mul_ps(_mm_mul_ps(zzzz, MultiplyVector2), zwxy)),
							_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
						tmp7)),
					*(__m128*)(&Matrix.vec1));

				TransformIndex = *reinterpret_cast<int*>(TransformData.transform_indices + 0x4 * TransformIndex);
			}

			return { Result.m128_f32[0], Result.m128_f32[1], Result.m128_f32[2] };
		}

	private:
		uintptr_t addr;
	};
}

#endif