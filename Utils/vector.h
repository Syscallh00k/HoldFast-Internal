#pragma once
#include <vector>
#include <Windows.h>
#include <xmmintrin.h>

#define M_PI		3.14159265358979323846	
#define Assert( _exp ) ((void)0)
#define RAD2DEG(x) ((x) * (180.0 / M_PI))
#define DEG2RAD(x) ((x) * (M_PI / 180.0f))
#define m128 __m128 

class Vector2 {
public:
	float x, y;


	inline Vector2() {
		x = y = 0.0f;
	}

	inline Vector2(float X, float Y) {
		x = X; y = Y;
	}
	bool is_empty() {
		if (x == 0 && y == 0)
			return true;
		
		return false;
	}
};

class string {
public:
	char zpad[0x10] = {};

	int size;
	wchar_t str[128 + 1];

	string(const wchar_t* st) {
		size = min(wcslen((wchar_t*)st), 128);
		for (int i = 0; i < size; i++) {
			str[i] = st[i];
		}
		str[size] = 0;
	}

};


struct transform_data_t
{
	uint64_t transform_array{};
	uint64_t transform_indices{};
};

struct transform_access_read_only_t
{
	uint64_t transform_data{};
};


class Vector4
{
public:
	float x, y, z, w;

	inline Vector4() {
		x = y = z = w = 0.0f;
	}

	inline Vector4(float X, float Y, float Z, float W) {
		x = X; y = Y; z = Z, w = W;
	}
};

class Vector3
{
public:
	float x, y, z;

	inline Vector3() {
		x = y = z = 0.0f;
	}

	inline Vector3(float X, float Y, float Z) {
		x = X; y = Y; z = Z;
	}

	inline float operator[](int i) const {
		return ((float*)this)[i];
	}

	inline Vector3& operator-=(float v) {
		x -= v; y -= v; z -= v; return *this;
	}

	inline Vector3 operator*(float v) const {
		return Vector3(x * v, y * v, z * v);
	}

	inline Vector3 operator/(float v) const
	{
		return Vector3(x / v, y / v, z / v);
	}

	inline Vector3& operator+=(const Vector3& v) {
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector3& operator+=(const float& v) {
		x += v; y += v; z += v; return *this;
	}

	inline Vector3& operator-=(const Vector3& v) {
		x -= v.x; y -= v.y; z -= v.z; return *this;
	}

	inline Vector3 operator-(const Vector3& v) const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	inline Vector3 operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	inline float Length()
	{
		auto number = (x * x + y * y + z * z);
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y; // floating point bit level hacking [sic]
		i = 0x5f3759df - (i >> 1); // Newton's approximation
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y)); // 1st iteration
		y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

		return 1 / y;
	}

	inline Vector3 Normalize()
	{
		float mag = Length();
		if (mag > 0.00001f)
		{
			x = x / mag;
			y = y / mag;
			z = z / mag;
		}
		else
		{
			x = 0;
			y = 0;
			z = 0;
		}
		return *this;
	}

	inline bool IsZero()
	{
		if (this->x == 0 && this->y == 0 && this->z == 0)
			return true;

		return false;
	}

	inline float magnitude2d()
	{
		return sqrtf(
			(this->x * this->x)
			+
			(this->z * this->z));
	}

	inline bool operator==(const Vector3& v) const {
		if (this->x == v.x && this->y == v.y && this->z == v.z)
			return true;
		else
			return false;
	}

	inline bool operator!=(const Vector3& v) const {
		if (this->x == v.x && this->y == v.y && this->z == v.z)
			return false;
		else
			return true;
	}
};

struct Matrix4x4 {
	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
};
inline float Dot(const Vector3& Vec1, const Vector3& Vec2) {
	return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
}

struct matrix34_t
{
	Vector4 vec1 = {};
	Vector4 vec2 = {};
	Vector4 vec3 = {};
};
struct matrix3x4_t
{
	matrix3x4_t() {}
	matrix3x4_t(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23)
	{
		m_flMatVal[0][0] = m00;	m_flMatVal[0][1] = m01; m_flMatVal[0][2] = m02; m_flMatVal[0][3] = m03;
		m_flMatVal[1][0] = m10;	m_flMatVal[1][1] = m11; m_flMatVal[1][2] = m12; m_flMatVal[1][3] = m13;
		m_flMatVal[2][0] = m20;	m_flMatVal[2][1] = m21; m_flMatVal[2][2] = m22; m_flMatVal[2][3] = m23;
	}

	float* operator[](int i) { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
	const float* operator[](int i) const { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
	float* Base() { return &m_flMatVal[0][0]; }
	const float* Base() const { return &m_flMatVal[0][0]; }

	float m_flMatVal[3][4];
};

inline bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos, Matrix4x4 view_matrix)
{
	Vector3 TransVec = Vector3(view_matrix._14, view_matrix._24, view_matrix._34);
	Vector3 RightVec = Vector3(view_matrix._11, view_matrix._21, view_matrix._31);
	Vector3 UpVec = Vector3(view_matrix._12, view_matrix._22, view_matrix._32);
	float w = Dot(TransVec, EntityPos) + view_matrix._44;
	if (w < 0.098f) return false;
	float y = Dot(UpVec, EntityPos) + view_matrix._42;
	float x = Dot(RightVec, EntityPos) + view_matrix._41;
	ScreenPos = Vector2((GetSystemMetrics(0) / 2) * (1.f + x / w), (GetSystemMetrics(1) / 2) * (1.f - y / w));
	return true;

}
struct bounds_t {
	float left, right, top, bottom;
};

struct box_bounds {
	float left, right, top, bottom;
	bool onscreen = false;

	bool empty() {
		if (this->left == 0 && this->right == 0 && this->top == 0 && this->bottom == 0)
			return true;

		if (this->left == FLT_MAX || this->right == FLT_MIN || this->top == FLT_MAX || this->bottom == FLT_MIN)
			return true;

		return false;
	}
	static box_bounds null() {
		return { 0, 0, 0, 0 };
	}
};

