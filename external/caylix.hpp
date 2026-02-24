#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "caylix.h"

namespace cx {
	const cx_float pi = CX_PI;
	const cx_float tau = CX_TAU;
	const cx_float epsilon = CX_EPSILON;
	const cx_float pi_half = CX_PI_HALF;
	const cx_float pi_sq = CX_PI_SQUARED;
	const cx_float e = CX_E;

	inline cx_float radian(const cx_float degree)
	{
		return CX_DEG_TO_RAD(degree);
	}
	inline cx_float degree(const cx_float radian)
	{
		return CX_RAD_TO_DEG(radian);
	}

	inline cx_float lerp(const cx_float a, const cx_float b, const cx_float t)
	{
		return cx_lerp(a, b, t);
	}
	inline cx_float clamp(const cx_float value, const cx_float min, const cx_float max)
	{
		return cx_clamp(value, min, max);
	}

	class Vec2;
	class Vec3;
	class Vec4;
	class Mat2;
	class Mat3;
	class Mat4;
	class Quat;

	class Vec2 {
	public:
		Vec2() : v { 0.0, 0.0 } {}
		Vec2(const cx_float x, const cx_float y) : v { x, y } {}
		Vec2(const cx_float fT) : v { fT, fT }{}
		Vec2(const cx_vec2 &other) : v { other.x, other.y } {}
		Vec2(const cx_vec3 &other) : v { other.x, other.y } {}
		Vec2(const cx_vec4 &other) : v { other.x, other.y } {}
		Vec2(const cx_quat &other) : v { other.x, other.y } {}


		inline const cx_float& x() const { return v.x; }
		inline const cx_float& y() const { return v.y; }
		Vec2 set(const cx_float x, const cx_float y) const;
		cx_vec2 get() const;
		const cx_float *data() const;
		static Vec2 zero();
		inline Vec2 operator-() const;
		inline Vec2 operator+(const Vec2 &other) const;
		inline Vec2 operator-(const Vec2 &other) const;
		inline Vec2 operator+(const cx_float fT) const;
		inline Vec2 operator-(const cx_float fT) const;
		inline Vec2 operator*(const cx_float fT) const;
		inline Vec2 operator/(const cx_float fT) const;
		inline Vec2& operator+=(const Vec2 &other);
		inline Vec2& operator-=(const Vec2 &other);
		inline Vec2& operator+=(const cx_float fT);
		inline Vec2& operator-=(const cx_float fT);
		inline Vec2& operator*=(const cx_float fT);
		inline Vec2& operator/=(const cx_float fT);
		inline bool operator==(const Vec2 &other) const;
		inline bool operator!=(const Vec2 &other) const;
		cx_float dot(const Vec2 &other) const;
		cx_float cross(const Vec2 &other) const;
		cx_float distance(const Vec2 &other) const;
		cx_float mag_sq() const;
		cx_float mag() const;
		Vec2 normalize() const;
		Vec2 rotate(const cx_float angle) const;
		cx_float angle(const Vec2 &other) const;
		Vec2 proj(const Vec2 &other) const;
		Vec2 reflect(const Vec2 &other) const;
		void print() const;


	private:
		cx_vec2 v;
	};

	class Vec3 {
	public:
		Vec3() : v { 0.0, 0.0, 0.0 } {}
		Vec3(const cx_float x, const cx_float y, const cx_float z) : v { x, y, z } {}
		Vec3(const cx_float fT) : v { fT, fT, fT } {}
		Vec3(const cx_vec2 &other) : v { other.x, other.y, 0.0 } {}
		Vec3(const cx_vec3 &other) : v { other.x, other.y, other.z } {}
		Vec3(const cx_vec4 &other) : v { other.x, other.y, other.z } {}
		Vec3(const cx_quat &other) : v { other.x, other.y, other.z } {}


		inline const cx_float& x() const { return v.x; }
		inline const cx_float& y() const { return v.y; }
		inline const cx_float& z() const { return v.z; }
		Vec3 set(const cx_float x, const cx_float y, const cx_float z) const;
		cx_vec3 get() const;
		const cx_float *data() const;
		static Vec3 zero();
		Vec3 operator-() const;
		Vec3 operator+(const Vec3 &other) const;
		Vec3 operator-(const Vec3 &other) const;
		Vec3 operator+(const cx_float fT) const;
		Vec3 operator-(const cx_float fT) const;
		Vec3 operator*(const cx_float fT) const;
		Vec3 operator/(const cx_float fT) const;
		Vec3& operator+=(const Vec3 &other);
		Vec3& operator-=(const Vec3 &other);
		Vec3& operator+=(const cx_float fT);
		Vec3& operator-=(const cx_float fT);
		Vec3& operator*=(const cx_float fT);
		Vec3& operator/=(const cx_float fT);
		bool operator==(const Vec3 &other) const;
		bool operator!=(const Vec3 &other) const;
		cx_float dot(const Vec3 &other) const;
		Vec3 cross(const Vec3 &other) const;
		cx_float distance(const Vec3 &other) const;
		cx_float mag_sq() const;
		cx_float mag() const;
		Vec3 normalize() const;
		cx_float angle(const Vec3 &other) const;
		void print();

	private:
		cx_vec3 v;
	};

	class Vec4 {
	public:
		Vec4() : v { 0.0, 0.0, 0.0, 0.0 } {}
		Vec4(const cx_float _x, const cx_float _y, const cx_float _z, const cx_float _w) : v { _x, _y, _z, _w } {}
		Vec4(const cx_float fT) : v { fT, fT, fT, fT } {}
		Vec4(const cx_vec2 &other) : v { other.x, other.y, 0.0, 0.0 } {}
		Vec4(const cx_vec3 &other) : v { other.x, other.y, other.z, 0.0 } {}
		Vec4(const cx_vec4 &other) : v { other.x, other.y, other.z, other.w } {}
		Vec4(const cx_quat &other) : v { other.x, other.y, other.z, other.w } {}


		inline const cx_float& x() const { return v.x; }
		inline const cx_float& y() const { return v.y; }
		inline const cx_float& z() const { return v.z; }
		inline const cx_float& w() const { return v.w; }
		Vec4 set(const cx_float x, const cx_float y, const cx_float z, const cx_float w) const;
		cx_vec4 get() const;
		const cx_float *data() const;
		static Vec4 zero();
		Vec4 operator-() const;
		Vec4 operator+(const Vec4 &other) const;
		Vec4 operator-(const Vec4 &other) const;
		Vec4 operator+(const cx_float fT) const;
		Vec4 operator-(const cx_float fT) const;
		Vec4 operator*(const cx_float fT) const;
		Vec4 operator/(const cx_float fT) const;
		Vec4& operator+=(const Vec4 &other);
		Vec4& operator-=(const Vec4 &other);
		Vec4& operator+=(const cx_float fT);
		Vec4& operator-=(const cx_float fT);
		Vec4& operator*=(const cx_float fT);
		Vec4& operator/=(const cx_float fT);
		bool operator==(const Vec4 &other) const;
		bool operator!=(const Vec4 &other) const;
		cx_float dot(const Vec4 &other) const;
		Vec4 cross(const Vec4 &other) const;
		cx_float distance(const Vec4 &other) const;
		cx_float mag_sq() const;
		cx_float mag() const;
		Vec4 normalize() const;
		void print();

	private:
		cx_vec4 v;
	};

	class Mat2 {
	public:
		Mat2() : m { 0.0, 0.0, 0.0, 0.0 } {}
		Mat2(const cx_float m00, const cx_float m01,
			 const cx_float m10, const cx_float m11) : m { m00, m01, m10, m11 } {}
		Mat2(const cx_float fT) : m { fT, 0.0, 0.0, fT } {}
		Mat2(const cx_mat2 &other) : m { other.m00, other.m01, other.m10, other.m11 } {}
		Mat2(const cx_mat3 &other) : m { other.m00, other.m01, other.m10, other.m11 } {}
		Mat2(const cx_mat4 &other) : m { other.m00, other.m01, other.m10, other.m11 } {}


		static Mat2 set(const cx_float m00, const cx_float m01,
				        const cx_float m10, const cx_float m11);
		cx_mat2 get() const;
		const cx_float *data() const;
		static Mat2 zero();
		static Mat2 identity();
		static Mat2 rotation(const cx_float angle);
		Mat2 operator+(const Mat2 &other) const;
		Mat2 operator-(const Mat2 &other) const;
		Mat2 operator*(const cx_float fT) const;
		Mat2 operator/(const cx_float fT) const;
		Mat2 operator+=(const Mat2 &other);
		Mat2 operator-=(const Mat2 &other);
		Mat2 operator*(const Mat2 &other) const;
		Vec2 operator*(const Vec2 &other) const;
		cx_float det() const;
		Mat2 transpose() const;
		Mat2 inverse() const;
		cx_float trace() const;
		Vec2 rotate(const Vec2 &other, const cx_float angle) const;
		bool isOrthogonal() const;
		void print() const;

	private:
		cx_mat2 m;
	};

	class Mat3 {
	public:
		Mat3() : m { 0.0, 0.0, 0.0, 0.0 } {}
		Mat3(const cx_float m00, const cx_float m01, const cx_float m02,
		     const cx_float m10, const cx_float m11, const cx_float m12,
			 const cx_float m20, const cx_float m21, const cx_float m22) : m { m00, m01, m02,
																			   m10, m11, m12,
																			   m20, m21, m22} {}
		Mat3(const cx_float fT) : m { fT, 0.0, 0.0,
									  0.0, fT, 0.0,
									  0.0, 0.0, fT} {}
		Mat3(const cx_mat2 &other) : m { other.m00, other.m01, 0.0,
										 other.m10, other.m11, 0.0,
			                             0.0,       0.0,       1.0 } {}
		Mat3(const cx_mat3 &other) : m { other.m00, other.m01, other.m02,
										 other.m10, other.m11, other.m12,
			                             other.m20, other.m21, other.m22 } {}
		Mat3(const cx_mat4 &other) : m { other.m00, other.m01, other.m02,
										 other.m10, other.m11, other.m12,
			                             other.m20, other.m21, other.m22 } {}

		cx_mat3 get() const;
		const cx_float *data() const;
		static Mat3 zero();
		static Mat3 identity();
		static Mat3 translation(const cx_float tx, const cx_float ty);
		static Mat3 scaling(const cx_float sx, const cx_float sy, const cx_float sz);
		static Mat3 shearX(const cx_float shx);
		static Mat3 shearY(const cx_float shy);
		static Mat3 shear(const cx_float shx, const cx_float shy);
		static Mat3 reflectionX();
		static Mat3 reflectionY();
		static Mat3 reflectionZ();
		Mat3 operator+(const Mat3 &other) const;
		Mat3 operator-(const Mat3 &other) const;
		Mat3 operator*(const cx_float fT) const;
		Mat3 operator/(const cx_float fT) const;
		Mat3 operator+=(const Mat3 &other);
		Mat3 operator-=(const Mat3 &other);
		Mat3 operator*(const Mat3 &other) const;
		Vec3 operator*(const Vec3 &other) const;
		cx_float det(void) const;
		Mat3 transpose() const;
		Mat3 inverse(void) const;
		cx_float trace(void) const;
		static Mat3 rotationZ(const cx_float angle);
		static Mat3 rotationY(const cx_float angle);
		static Mat3 rotationX(const cx_float angle);
		static Mat3 eulerZYX(const cx_float psi, const cx_float theta, const cx_float phi);
		static Mat3 eulerXYZ(const cx_float phi, const cx_float theta, const cx_float psi);
		void print(void) const;

	private:
		cx_mat3 m;
	};

	class Mat4 {
	public:
		Mat4() : m { 0.0, 0.0, 0.0, 0.0,
			         0.0, 0.0, 0.0, 0.0,
			         0.0, 0.0, 0.0, 0.0,
			         0.0, 0.0, 0.0, 0.0 } {}
		Mat4(const cx_float m00, const cx_float m01, const cx_float m02, const cx_float m03,
			 const cx_float m10, const cx_float m11, const cx_float m12, const cx_float m13,
			 const cx_float m20, const cx_float m21, const cx_float m22, const cx_float m23,
			 const cx_float m30, const cx_float m31, const cx_float m32, const cx_float m33) : m { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33, } {}
		Mat4(const cx_float fT) : m { fT,  0.0, 0.0, 0.0,
									  0.0, fT,  0.0, 0.0,
									  0.0, 0.0, fT,  0.0,
									  0.0, 0.0, 0.0, fT } {}
		Mat4(const cx_mat2 &other) : m { other.m00, other.m01, 0.0, 0.0,
								  other.m10, other.m11, 0.0, 0.0,
								  0.0,   0.0,   1.0, 0.0,
				                  0.0,   0.0,   0.0, 1.0 } {}
		Mat4(const cx_mat3 &other) : m { other.m00, other.m01, other.m02, 0.0,
								         other.m10, other.m11, other.m12, 0.0,
								         other.m20, other.m21, other.m22, 0.0,
				                         0.0,       0.0,       0.0,       1.0 } {}
		Mat4(const cx_mat4 &other) : m { other.m00, other.m01, other.m02, other.m03,
								         other.m10, other.m11, other.m12, other.m13,
								         other.m20, other.m21, other.m22, other.m23,
				                         other.m30, other.m31, other.m32, other.m33 } {}


		static Mat4 set(const cx_float m00, const cx_float m01, const cx_float m02, const cx_float m03,
				        const cx_float m10, const cx_float m11, const cx_float m12, const cx_float m13,
				        const cx_float m20, const cx_float m21, const cx_float m22, const cx_float m23,
						const cx_float m30, const cx_float m31, const cx_float m32, const cx_float m33);
		cx_mat4 get() const;
		const cx_float *data() const;
		static Mat4 zero();
		static Mat4 identity();
		static Mat4 translation(const cx_float tx, const cx_float ty, const cx_float tz);
		static Mat4 scaling(const cx_float sx, const cx_float sy, const cx_float sz);
		static Mat4 shearX(const cx_float sy, const cx_float sz);
		static Mat4 shearY(const cx_float sx, const cx_float sz);
		static Mat4 shearZ(const cx_float sx, const cx_float sy);
		static Mat4 shear(const cx_float sxy, const cx_float sxz,
						  const cx_float syx, const cx_float syz,
						  const cx_float szx, const cx_float szy);
		static Mat4 perspectiveLH_NO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar);
		static Mat4 perspectiveLH_ZO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar);
		static Mat4 perspectiveRH_NO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar);
		static Mat4 perspectiveRH_ZO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar);
		static Mat4 perspective(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar);
		static Mat4 orthogonalLH_NO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far);
		static Mat4 orthogonalRH_NO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far);
		static Mat4 orthogonalLH_ZO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far);
		static Mat4 orthogonalRH_ZO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far);
		static Mat4 lookAtLH(const Vec3 eye, const Vec3 center, const Vec3 up);
		static Mat4 lookAtRH(const Vec3 eye, const Vec3 center, const Vec3 up);
		static Mat4 lookAt(const Vec3 eye, const Vec3 center, const Vec3 up);
		Mat4 operator+(const Mat4 &other) const;
		Mat4 operator-(const Mat4 &other) const;
		Mat4 operator*(const cx_float fT) const;
		Mat4 operator/(const cx_float fT) const;
		Mat4 operator+=(const Mat4 &other);
		Mat4 operator-=(const Mat4 &other);
		Mat4 operator*(const Mat4 &other) const;
		Vec4 operator*(const Vec4 &other) const;
		cx_float det() const;
		Mat4 transpose() const;
		Mat4 inverse() const;
		cx_float trace() const;
		static Mat4 rotationZ(const cx_float angle);
		static Mat4 rotationY(const cx_float angle);
		static Mat4 rotationX(const cx_float angle);
		static Mat4 eulerZYX(const cx_float psi, const cx_float theta, const cx_float phi);
		static Mat4 eulerXYZ(const cx_float phi, const cx_float theta, const cx_float psi);
		static Mat4 fromQuat(const Quat& q);
		void print();

	private:
		cx_mat4 m;
	};

	class Quat {
	public:
		Quat() : q { 0.0, 0.0, 0.0, 0.0 } {}
		Quat(const cx_float x, const cx_float y, const cx_float z, const cx_float w) : q { x, y, z, w } {}
		Quat(const cx_float fT) : q { fT, fT, fT, fT } {}
		Quat(const cx_vec2 &other) : q { other.x, other.y, 0.0, 1.0 } {}
		Quat(const cx_vec3 &other) : q { other.x, other.y, other.z, 1.0 } {}
		Quat(const cx_vec4 &other) : q { other.w, other.x, other.y, other.z } {}
		Quat(const cx_quat &other) : q { other.w, other.x, other.y, other.z } {}

		const cx_float& x() const;
		const cx_float& y() const;
		const cx_float& z() const;
		const cx_float& w() const;
		static Quat set(const cx_float x, const cx_float y, const cx_float z, const cx_float w);
		cx_quat get() const;
		static Quat zero();
		static Quat identity();
		static Quat fromAxisAngle(const cx_float x, const cx_float y, const cx_float z, const cx_float angle);
		static Quat fromAxisAngle(const Vec3 axis, const cx_float angle);
		static Quat fromAxisAngle(const Vec4 axis, const cx_float angle);
		Quat operator-() const;
		Quat operator+(const Quat &other) const;
		Quat operator-(const Quat &other) const;
		Quat operator*(const cx_float fT) const;
		Quat operator/(const cx_float fT) const;
		Quat operator*(const Quat &other) const;
		bool operator==(const Quat &other) const;
		bool operator!=(const Quat &other) const;
		Quat normalize() const;
		cx_float mag() const;
		Quat conjugate() const;
		Quat inverse() const;
		Quat lerp(const Quat p, const cx_float t) const;
		Quat nlerp(const Quat p, const cx_float t) const;
		Quat slerp(const Quat p, const cx_float t) const;
		cx_float dot(const Quat p) const;
		Vec3 rotate(const Vec3 v) const;
		Vec4 rotate(const Vec4 v) const;
		void print() const;

	private:
		cx_quat q;
	};

#ifdef CX_IMPLEMENTATION
	// inline const cx_float& Vec2::x() const
	// {
	// 	return v.x;
	// }

	// inline const cx_float& Vec2::y() const
	// {
	// 	return v.y;
	// }

	inline Vec2 Vec2::set(const cx_float x, const cx_float y) const
	{
		return Vec2(cx_vec2_set(x, y));
	}

	inline cx_vec2 Vec2::get() const
	{
		return v;
	}

	const cx_float *Vec2::data() const
	{
		return v.vec;
	}

	Vec2 zero()
	{
		return Vec2(cx_vec2_zero());
	}

	inline Vec2 Vec2::operator-() const
	{
		return Vec2(cx_vec2_negate(v));
	}

	inline Vec2 Vec2::operator+(const Vec2 &other) const
	{
		return Vec2(cx_vec2_add(v, other.v));
	}

	inline Vec2 Vec2::operator-(const Vec2 &other) const
	{
		return Vec2(cx_vec2_sub(v, other.v));
	}

	inline Vec2 Vec2::operator+(const cx_float fT) const
	{
		return Vec2(cx_vec2_addf(v, fT));
	}

	inline Vec2 Vec2::operator-(const cx_float fT) const
	{
		return Vec2(cx_vec2_subf(v, fT));
	}

	inline Vec2 Vec2::operator*(const cx_float fT) const
	{
		return Vec2(cx_vec2_mulf(v, fT));
	}

	inline Vec2 operator*(const cx_float fT, const Vec2 &vec)
	{
		return vec * fT;
	}


	inline Vec2 Vec2::operator/(const cx_float fT) const
	{
		return Vec2(cx_vec2_divf(v, fT));
	}

	inline Vec2& Vec2::operator+=(const Vec2 &other)
	{
		v.x += other.v.x;
		v.y += other.v.y;
		return *this;
	}

	inline Vec2& Vec2::operator-=(const Vec2 &other)
	{
		v.x -= other.v.x;
		v.y -= other.v.y;
		return *this;
	}

	inline Vec2& Vec2::operator+=(const cx_float fT)
	{
		v.x += fT;
		v.y += fT;
		return *this;
	}

	inline Vec2& Vec2::operator-=(const cx_float fT)
	{
		v.x -= fT;
		v.y -= fT;
		return *this;
	}

	inline Vec2& Vec2::operator*=(const cx_float fT)
	{
		v.x *= fT;
		v.y *= fT;
		return *this;
	}

	inline Vec2& Vec2::operator/=(const cx_float fT)
	{
		v.x /= fT;
		v.y /= fT;
		return *this;
	}

	inline bool Vec2::operator==(const Vec2 &other) const
	{
		return (v.x == other.v.x) && (v.y == other.v.y);
	}

	inline bool Vec2::operator!=(const Vec2 &other) const
	{
		return !(*this == other);
	}

	inline cx_float Vec2::dot(const Vec2 &other) const
	{
		return cx_vec2_dot(v, other.v);
	}

	inline cx_float Vec2::cross(const Vec2 &other) const
	{
		return cx_vec2_cross(v, other.v);
	}

	inline cx_float Vec2::distance(const Vec2 &other) const
	{
		return (*this - other).mag();
	}

	inline cx_float Vec2::mag_sq() const
	{
		return cx_vec2_mag_sq(v);
	}

	inline cx_float Vec2::mag() const
	{
		return cx_vec2_mag(v);
	}

	inline Vec2 Vec2::normalize() const
	{
		return Vec2(cx_vec2_normalize(v));
	}

	inline Vec2 Vec2::rotate(const cx_float angle) const
	{
		return Vec2(cx_vec2_rotate(v, angle));
	}

	inline cx_float Vec2::angle(const Vec2 &other) const
	{
		return cx_vec2_angle(v, other.v);
	}

	inline Vec2 Vec2::proj(const Vec2 &other) const
	{
		return cx_vec2_proj(v, other.v);
	}

	inline Vec2 Vec2::reflect(const Vec2 &other) const
	{
		return cx_vec2_reflect(v, other.v);
	}

	inline void Vec2::print() const
	{
		cx_vec2_print(v);
	}


	// const cx_float& Vec3::x() const
	// {
	// 	return v.x;
	// }

	// const cx_float& Vec3::y() const
	// {
	// 	return v.y;
	// }

	// const cx_float& Vec3::z() const
	// {
	// 	return v.z;
	// }

	inline Vec3 Vec3::set(const cx_float x, const cx_float y, const cx_float z) const
	{
		return Vec3(cx_vec3_set(x, y, z));
	}

	inline cx_vec3 Vec3::get() const
	{
		return v;
	}

	const cx_float *Vec3::data() const
	{
		return v.vec;
	}

	Vec3 Vec3::zero()
	{
		return Vec3(cx_vec3_zero());
	}

	Vec3 Vec3::operator-() const
	{
		return Vec3(cx_vec3_negate(v));
	}

	Vec3 Vec3::operator+(const Vec3 &other) const
	{
		return Vec3(cx_vec3_add(v, other.v));
	}

	Vec3 Vec3::operator-(const Vec3 &other) const
	{
		return Vec3(cx_vec3_sub(v, other.v));
	}

	Vec3 Vec3::operator+(const cx_float fT) const
	{
		return Vec3(cx_vec3_addf(v, fT));
	}

	Vec3 Vec3::operator-(const cx_float fT) const
	{
		return Vec3(cx_vec3_subf(v, fT));
	}

	Vec3 Vec3::operator*(const cx_float fT) const
	{
		return Vec3(cx_vec3_mulf(v, fT));
	}

	Vec3 operator*(const cx_float fT, const Vec3 &vec)
	{
		return vec * fT;
	}

	Vec3 Vec3::operator/(const cx_float fT) const
	{
		return Vec3(cx_vec3_divf(v, fT));
	}

	Vec3& Vec3::operator+=(const Vec3 &other)
	{
		v.x += other.v.x;
		v.y += other.v.y;
		v.z += other.v.z;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3 &other)
	{
		v.x -= other.v.x;
		v.y -= other.v.y;
		v.z -= other.v.z;
		return *this;
	}

	Vec3& Vec3::operator+=(const cx_float fT)
	{
		v.x += fT;
		v.y += fT;
		v.z += fT;
		return *this;
	}

	Vec3& Vec3::operator-=(const cx_float fT)
	{
		v.x -= fT;
		v.y -= fT;
		v.z -= fT;
		return *this;
	}

	Vec3& Vec3::operator*=(const cx_float fT)
	{
		v.x *= fT;
		v.y *= fT;
		v.z *= fT;
		return *this;
	}

	inline Vec3& Vec3::operator/=(const cx_float fT)
	{
		v.x /= fT;
		v.y /= fT;
		v.z /= fT;
		return *this;
	}

	inline bool Vec3::operator==(const Vec3 &other) const
	{
		return (v.x == other.v.x) && (v.y == other.v.y) && (v.z == other.v.z);
	}

	inline bool Vec3::operator!=(const Vec3 &other) const
	{
		return !(*this == other);
	}

	inline cx_float Vec3::dot(const Vec3 &other) const
	{
		return cx_vec3_dot(v, other.v);
	}

	inline Vec3 Vec3::cross(const Vec3 &other) const
	{
		return Vec3(cx_vec3_cross(v, other.v));
	}

	inline cx_float Vec3::distance(const Vec3 &other) const
	{
		return (*this - other).mag();
	}

	inline cx_float Vec3::mag_sq() const
	{
		return cx_vec3_mag_sq(v);
	}

	inline cx_float Vec3::mag() const
	{
		return cx_vec3_mag(v);
	}

	Vec3 Vec3::normalize() const
	{
		return Vec3(cx_vec3_normalize(v));
	}

	inline cx_float Vec3::angle(const Vec3 &other) const
	{
		return cx_vec3_angle(v, other.v);
	}

	inline void Vec3::print()
	{
		cx_vec3_print(v);
	}



	// inline const cx_float& Vec4::x() const
	// {
	// 	return v.x;
	// }

	// inline const cx_float& Vec4::y() const
	// {
	// 	return v.y;
	// }

	// inline const cx_float& Vec4::z() const
	// {
	// 	return v.z;
	// }

	// inline const cx_float& Vec4::w() const
	// {
	// 	return v.w;
	// }

	inline Vec4 Vec4::set(const cx_float x, const cx_float y, const cx_float z, const cx_float w) const
	{
		return Vec4(cx_vec4_set(x, y, z, w));
	}

	inline cx_vec4 Vec4::get() const
	{
		return v;
	}

	const cx_float *Vec4::data() const
	{
		return v.vec;
	}

	Vec4 Vec4::zero()
	{
		return Vec4(cx_vec4_zero());
	}

	inline Vec4 Vec4::operator-() const
	{
		return Vec4(cx_vec4_negate(v));
	}

	inline Vec4 Vec4::operator+(const Vec4 &other) const
	{
		return Vec4(cx_vec4_add(v, other.v));
	}

	inline Vec4 Vec4::operator-(const Vec4 &other) const
	{
		return Vec4(cx_vec4_sub(v, other.v));
	}

	inline Vec4 Vec4::operator+(const cx_float fT) const
	{
		return Vec4(cx_vec4_addf(v, fT));
	}

	inline Vec4 Vec4::operator-(const cx_float fT) const
	{
		return Vec4(cx_vec4_subf(v, fT));
	}

	inline Vec4 Vec4::operator*(const cx_float fT) const
	{
		return Vec4(cx_vec4_mulf(v, fT));
	}

	Vec4 operator*(const cx_float fT, const Vec4 &vec)
	{
		return vec * fT;
	}

	inline Vec4 Vec4::operator/(const cx_float fT) const
	{
		return Vec4(cx_vec4_divf(v, fT));
	}

	inline Vec4& Vec4::operator+=(const Vec4 &other)
	{
		v.x += other.v.x;
		v.y += other.v.y;
		v.z += other.v.z;
		v.w += other.v.w;
		return *this;
	}

	inline Vec4& Vec4::operator-=(const Vec4 &other)
	{
		v.x -= other.v.x;
		v.y -= other.v.y;
		v.z -= other.v.z;
		v.w -= other.v.w;
		return *this;
	}

	inline Vec4& Vec4::operator+=(const cx_float fT)
	{
		v.x += fT;
		v.y += fT;
		v.z += fT;
		v.w += fT;
		return *this;
	}

	inline Vec4& Vec4::operator-=(const cx_float fT)
	{
		v.x -= fT;
		v.y -= fT;
		v.z -= fT;
		v.w -= fT;
		return *this;
	}

	inline Vec4& Vec4::operator*=(const cx_float fT)
	{
		v.x *= fT;
		v.y *= fT;
		v.z *= fT;
		v.w *= fT;
		return *this;
	}

	inline Vec4& Vec4::operator/=(const cx_float fT)
	{
		v.x /= fT;
		v.y /= fT;
		v.z /= fT;
		v.w /= fT;
		return *this;
	}

	inline bool Vec4::operator==(const Vec4 &other) const
	{
		return (v.x == other.v.x) && (v.y == other.v.y) && (v.z == other.v.z) && (v.w == other.v.w);
	}

	inline bool Vec4::operator!=(const Vec4 &other) const
	{
		return !(*this == other);
	}

	inline cx_float Vec4::dot(const Vec4 &other) const
	{
		return cx_vec4_dot(v, other.v);
	}

	inline Vec4 Vec4::cross(const Vec4 &other) const
	{
		return Vec4(cx_vec4_cross(v, other.v));
	}

	inline cx_float Vec4::distance(const Vec4 &other) const
	{
		return (*this - other).mag();
	}

	inline cx_float Vec4::mag_sq() const
	{
		return cx_vec4_mag_sq(v);
	}

	inline cx_float Vec4::mag() const
	{
		return cx_vec4_mag(v);
	}

	inline Vec4 Vec4::normalize() const
	{
		return Vec4(cx_vec4_normalize(v));
	}

	inline void Vec4::print()
	{
		cx_vec4_print(v);
	}



	Mat2 Mat2::set(const cx_float m00, const cx_float m01,
					const cx_float m10, const cx_float m11)
	{
		return Mat2(cx_mat2_set(m00, m01,
								m10, m11));
	}

	inline cx_mat2 Mat2::get() const
	{
		return m;
	}

	const cx_float *Mat2::data() const
	{
		return m.m;
	}

	Mat2 Mat2::zero()
	{
		return Mat2(cx_mat2_zero());
	}

	Mat2 Mat2::identity()
	{
		return Mat2(cx_mat2_identity());
	}

	Mat2 Mat2::rotation(const cx_float angle)
	{
		return Mat2(cx_mat2_rotation(angle));
	}

	inline Mat2 Mat2::operator+(const Mat2 &other) const
	{
		return Mat2(cx_mat2_add(m, other.m));
	}

	inline Mat2 Mat2::operator-(const Mat2 &other) const
	{
		return Mat2(cx_mat2_sub(m, other.m));
	}

	inline Mat2 Mat2::operator*(const cx_float fT) const
	{
		return Mat2(cx_mat2_mulf(m, fT));
	}

	inline Mat2 Mat2::operator/(const cx_float fT) const
	{
		return Mat2(cx_mat2_divf(m, fT));
	}

	inline Mat2 Mat2::operator+=(const Mat2 &other)
	{
		const cx_mat2 m1 = other.get();
		m.m00 += m1.m00;
		m.m01 += m1.m01;
		m.m10 += m1.m10;
		m.m11 += m1.m11;
		return *this;
	}

	inline Mat2 Mat2::operator-=(const Mat2 &other)
	{
		const cx_mat2 m1 = other.get();
		m.m00 -= m1.m00;
		m.m01 -= m1.m01;
		m.m10 -= m1.m10;
		m.m11 -= m1.m11;
		return *this;
	}

	inline Mat2 Mat2::operator*(const Mat2 &other) const
	{
		return Mat2(cx_mat2_mul(m, other.m));
	}

	inline Vec2 Mat2::operator*(const Vec2 &other) const
	{
		const cx_vec2 v = other.get();
		return Vec2(cx_mat2_vec2_mul(m, v));
	}

	Mat2 operator*(const cx_float fT, const Mat2 m)
	{
		return m * fT;
	}

	inline cx_float Mat2::det() const
	{
		return cx_mat2_det(m);
	}

	inline Mat2 Mat2::transpose() const
	{
		return Mat2(cx_mat2_transpose(m));
	}

	inline Mat2 Mat2::inverse() const
	{
		return Mat2(cx_mat2_inverse(m));
	}

	inline cx_float Mat2::trace() const
	{
		return cx_mat2_trace(m);
	}

	inline Vec2 Mat2::rotate(const Vec2 &other, const cx_float angle) const
	{
		const cx_vec2 v = other.get();
		return Vec2(cx_mat2_rotate(v, angle));
	}

	inline bool Mat2::isOrthogonal() const
	{
		return cx_mat2_is_orthogonal(m);
	}

	inline void Mat2::print() const
	{
		cx_mat2_print(m);
	}


	inline cx_mat3 Mat3::get() const
	{
		return m;
	}

	const cx_float *Mat3::data() const
	{
		return m.m;
	}

	Mat3 Mat3::zero()
	{
		return Mat3(cx_mat3_zero());
	}

	Mat3 Mat3::identity()
	{
		return Mat3(cx_mat3_identity());
	}

	Mat3 Mat3::translation(const cx_float tx, const cx_float ty)
	{
		return Mat3(cx_mat3_translation(tx, ty));
	}

	Mat3 Mat3::scaling(const cx_float sx, const cx_float sy, const cx_float sz)
	{
		return Mat3(cx_mat3_scaling(sx, sy, sz));
	}

	Mat3 Mat3::shearX(const cx_float shx)
	{
		return Mat3(cx_mat3_shear_x(shx));
	}

	Mat3 Mat3::shearY(const cx_float shy)
	{
		return Mat3(cx_mat3_shear_y(shy));
	}

	Mat3 Mat3::shear(const cx_float shx, const cx_float shy)
	{
		return Mat3(cx_mat3_shear(shx, shy));
	}

	Mat3 Mat3::reflectionX()
	{
		return Mat3(cx_mat3_reflection_x());
	}

	Mat3 Mat3::reflectionY()
	{
		return Mat3(cx_mat3_reflection_y());
	}

	Mat3 Mat3::reflectionZ()
	{
		return Mat3(cx_mat3_reflection_z());
	}

	inline Mat3 Mat3::operator+(const Mat3 &other) const
	{
		const cx_mat3 v = other.get();
		return Mat3(cx_mat3_add(m, v));
	}

	inline Mat3 Mat3::operator-(const Mat3 &other) const
	{
		const cx_mat3 v = other.get();
		return Mat3(cx_mat3_sub(m, v));
	}

	inline Mat3 Mat3::operator*(const cx_float fT) const
	{
		return Mat3(cx_mat3_mulf(m, fT));
	}

	Mat3 operator*(const cx_float fT, const Mat3 m)
	{
		return m * fT;
	}

	inline Mat3 Mat3::operator/(const cx_float fT) const
	{
		return Mat3(cx_mat3_divf(m, fT));
	}

	inline Mat3 Mat3::operator+=(const Mat3 &other)
	{
		const cx_mat3 m1 = other.get();
		m.m00 += m1.m00;
		m.m01 += m1.m01;
		m.m02 += m1.m02;
		m.m10 += m1.m10;
		m.m11 += m1.m11;
		m.m12 += m1.m12;
		m.m20 += m1.m20;
		m.m21 += m1.m21;
		m.m22 += m1.m22;
		return *this;
	}

	inline Mat3 Mat3::operator-=(const Mat3 &other)
	{
		const cx_mat3 m1 = other.get();
		m.m00 -= m1.m00;
		m.m01 -= m1.m01;
		m.m02 -= m1.m02;
		m.m10 -= m1.m10;
		m.m11 -= m1.m11;
		m.m12 -= m1.m12;
		m.m20 -= m1.m20;
		m.m21 -= m1.m21;
		m.m22 -= m1.m22;
		return *this;
	}

	inline Mat3 Mat3::operator*(const Mat3 &other) const
	{
		return Mat3(cx_mat3_mul(m, other.m));
	}

	inline Vec3 Mat3::operator*(const Vec3 &other) const
	{
		const cx_vec3 v = other.get();
		return Vec3(cx_mat3_vec3_mul(m, v));
	}

	inline cx_float Mat3::det(void) const
	{
		return cx_mat3_det(m);
	}

	inline Mat3 Mat3::transpose() const
	{
		return Mat3(cx_mat3_transpose(m));
	}

	inline Mat3 Mat3::inverse(void) const
	{
		return Mat3(cx_mat3_inverse(m));
	}

	inline cx_float Mat3::trace(void) const
	{
		return cx_mat3_trace(m);
	}

	Mat3 Mat3::rotationZ(const cx_float angle)
	{
		return Mat3(cx_mat3_rotation_z(angle));
	}

	Mat3 Mat3::rotationY(const cx_float angle)
	{
		return Mat3(cx_mat3_rotation_y(angle));
	}

	Mat3 Mat3::rotationX(const cx_float angle)
	{
		return Mat3(cx_mat3_rotation_x(angle));
	}

	Mat3 Mat3::eulerZYX(const cx_float psi, const cx_float theta, const cx_float phi)
	{
		return Mat3(cx_mat3_rotation_euler_zyx(psi, theta, phi));
	}

	Mat3 Mat3::eulerXYZ(const cx_float phi, const cx_float theta, const cx_float psi)
	{
		return Mat3(cx_mat3_rotation_euler_xyz(phi, theta, psi));
	}

	inline void Mat3::print(void) const
	{
		cx_mat3_print(m);
	}


	Mat4 Mat4::set(const cx_float m00, const cx_float m01, const cx_float m02, const cx_float m03,
				const cx_float m10, const cx_float m11, const cx_float m12, const cx_float m13,
				const cx_float m20, const cx_float m21, const cx_float m22, const cx_float m23,
				const cx_float m30, const cx_float m31, const cx_float m32, const cx_float m33)
	{
		return Mat4(cx_mat4_set(m00, m01, m02, m03,
								m10, m11, m12, m13,
								m20, m21, m22, m23,
								m30, m31, m32, m33));
	}

	cx_mat4 Mat4::get() const
	{
		return m;
	}

	const cx_float *Mat4::data() const
	{
		return m.m;
	}

	Mat4 Mat4::zero()
	{
		return Mat4(cx_mat4_zero());
	}

	Mat4 Mat4::identity()
	{
		return Mat4(cx_mat4_identity());
	}

	Mat4 Mat4::translation(const cx_float tx, const cx_float ty, const cx_float tz)
	{
		return Mat4(cx_mat4_translation(tx, ty, tz));
	}

	Mat4 Mat4::scaling(const cx_float sx, const cx_float sy, const cx_float sz)
	{
		return Mat4(cx_mat4_scaling(sx, sy, sz));
	}

	Mat4 Mat4::shearX(const cx_float sy, const cx_float sz)
	{
		return Mat4(cx_mat4_shear_x(sy, sz));
	}

	Mat4 Mat4::shearY(const cx_float sx, const cx_float sz)
	{
		return Mat4(cx_mat4_shear_y(sx, sz));
	}

	Mat4 Mat4::shearZ(const cx_float sx, const cx_float sy)
	{
		return Mat4(cx_mat4_shear_z(sx, sy));
	}

	Mat4 Mat4::shear(const cx_float sxy, const cx_float sxz,
						const cx_float syx, const cx_float syz,
						const cx_float szx, const cx_float szy)
	{
		return Mat4(cx_mat4_shear(sxy, sxz,
									syx, syz,
									szx, szy));
	}

	Mat4 Mat4::perspectiveLH_NO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar)
	{
		return Mat4(cx_mat4_perspectiveLH_NO(fov, aspect, znear, zfar));
	}

	Mat4 Mat4::perspectiveLH_ZO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar)
	{
		return Mat4(cx_mat4_perspectiveLH_ZO(fov, aspect, znear, zfar));
	}

	Mat4 Mat4::perspectiveRH_NO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar)
	{
		return Mat4(cx_mat4_perspectiveRH_NO(fov, aspect, znear, zfar));
	}

	Mat4 Mat4::perspectiveRH_ZO(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar)
	{
		return Mat4(cx_mat4_perspectiveRH_ZO(fov, aspect, znear, zfar));
	}

	Mat4 Mat4::perspective(const cx_float fov, const cx_float aspect, const cx_float znear, const cx_float zfar)
	{
		return Mat4(cx_mat4_perspective(fov, aspect, znear, zfar));
	}

	Mat4 orthogonalLH_NO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far)
	{
		return Mat4(cx_mat4_orthogonalLH_NO(left, right, bottom, top, z_near, z_far));
	}

	Mat4 Mat4::orthogonalRH_NO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far)
	{
		return Mat4(cx_mat4_orthogonalRH_NO(left, right, bottom, top, z_near, z_far));
	}

	Mat4 orthogonalLH_ZO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far)
	{
		return Mat4(cx_mat4_orthogonalLH_ZO(left, right, bottom, top, z_near, z_far));
	}

	Mat4 orthogonalRH_ZO(const cx_float left, const cx_float right, const cx_float bottom, const cx_float top, const cx_float z_near, const cx_float z_far)
	{
		return Mat4(cx_mat4_orthogonalLH_ZO(left, right, bottom, top, z_near, z_far));
	}

	Mat4 Mat4::lookAtLH(const Vec3 eye, const Vec3 center, const Vec3 up)
	{
		const cx_vec3 v1 = eye.get();
		const cx_vec3 v2 = center.get();
		const cx_vec3 v3 = up.get();

		return Mat4(cx_mat4_lookAtLH(v1, v2, v3));
	}

	Mat4 Mat4::lookAtRH(const Vec3 eye, const Vec3 center, const Vec3 up)
	{
		const cx_vec3 v1 = eye.get();
		const cx_vec3 v2 = center.get();
		const cx_vec3 v3 = up.get();

		return Mat4(cx_mat4_lookAtRH(v1, v2, v3));
	}

	Mat4 Mat4::lookAt(const Vec3 eye, const Vec3 center, const Vec3 up)
	{
		const cx_vec3 v1 = eye.get();
		const cx_vec3 v2 = center.get();
		const cx_vec3 v3 = up.get();

		return Mat4(cx_mat4_lookAt(v1, v2, v3));
	}

	Mat4 Mat4::operator+(const Mat4 &other) const
	{
		const cx_mat4 v = other.get();
		return Mat4(cx_mat4_add(m, v));
	}

	Mat4 Mat4::operator-(const Mat4 &other) const
	{
		const cx_mat4 v = other.get();
		return Mat4(cx_mat4_sub(m, v));
	}

	Mat4 Mat4::operator*(const cx_float fT) const
	{
		return Mat4(cx_mat4_mulf(m, fT));
	}

	Mat4 operator*(const cx_float fT, const Mat4& m)
	{
		return m * fT;
	}


	Mat4 Mat4::operator/(const cx_float fT) const
	{
		return Mat4(cx_mat4_divf(m, fT));
	}

	Mat4 Mat4::operator+=(const Mat4 &other)
	{
		const cx_mat4 m1 = other.get();
		m.m00 += m1.m00;
		m.m01 += m1.m01;
		m.m02 += m1.m02;
		m.m03 += m1.m03;
		m.m10 += m1.m10;
		m.m11 += m1.m11;
		m.m12 += m1.m12;
		m.m13 += m1.m13;
		m.m20 += m1.m20;
		m.m21 += m1.m21;
		m.m22 += m1.m22;
		m.m23 += m1.m23;
		m.m30 += m1.m30;
		m.m31 += m1.m31;
		m.m32 += m1.m32;
		m.m33 += m1.m33;
		return *this;
	}

	Mat4 Mat4::operator-=(const Mat4 &other)
	{
		const cx_mat4 m1 = other.get();
		m.m00 -= m1.m00;
		m.m01 -= m1.m01;
		m.m02 -= m1.m02;
		m.m03 -= m1.m03;
		m.m10 -= m1.m10;
		m.m11 -= m1.m11;
		m.m12 -= m1.m12;
		m.m13 -= m1.m13;
		m.m20 -= m1.m20;
		m.m21 -= m1.m21;
		m.m22 -= m1.m22;
		m.m23 -= m1.m23;
		m.m30 -= m1.m30;
		m.m31 -= m1.m31;
		m.m32 -= m1.m32;
		m.m33 -= m1.m33;
		return *this;
	}

	Mat4 Mat4::operator*(const Mat4 &other) const
	{
		return Mat4(cx_mat4_mul(m, other.m));
	}

	Vec4 Mat4::operator*(const Vec4 &other) const
	{
		const cx_vec4 v = other.get();
		return Vec4(cx_mat4_vec4_mul(m, v));
	}

	cx_float Mat4::det() const
	{
		return cx_mat4_det(m);
	}

	Mat4 Mat4::transpose() const
	{
		return Mat4(cx_mat4_transpose(m));
	}

	Mat4 Mat4::inverse() const
	{
		return Mat4(cx_mat4_inverse(m));
	}

	cx_float Mat4::trace() const
	{
		return cx_mat4_trace(m);
	}

	Mat4 Mat4::rotationZ(const cx_float angle)
	{
		return Mat4(cx_mat4_rotation_z(angle));
	}

	Mat4 Mat4::rotationY(const cx_float angle)
	{
		return Mat4(cx_mat4_rotation_y(angle));
	}

	Mat4 Mat4::rotationX(const cx_float angle)
	{
		return Mat4(cx_mat4_rotation_x(angle));
	}

	Mat4 Mat4::eulerZYX(const cx_float psi, const cx_float theta, const cx_float phi)
	{
		return Mat4(cx_mat4_rotation_euler_zyx(psi, theta, phi));
	}

	Mat4 Mat4::eulerXYZ(const cx_float phi, const cx_float theta, const cx_float psi)
	{
		return Mat4(cx_mat4_rotation_euler_xyz(phi, theta, psi));
	}

	Mat4 Mat4::fromQuat(const Quat& q)
	{
		const cx_quat p = q.get();
		return Mat4(cx_mat4_from_quat(p));
	}

	void Mat4::print()
	{
		cx_mat4_print(m);
	}


	inline const cx_float& Quat::x() const
	{
		return q.x;
	}

	inline const cx_float& Quat::y() const
	{
		return q.y;
	}

	inline const cx_float& Quat::z() const
	{
		return q.z;
	}

	inline const cx_float& Quat::w() const
	{
		return q.w;
	}

	Quat Quat::set(const cx_float x, const cx_float y, const cx_float z, const cx_float w)
	{
		return Quat(cx_quat_set(x, y, z, w));
	}

	inline cx_quat Quat::get() const
	{
		return q;
	}

	Quat Quat::zero()
	{
		return Quat(cx_quat_zero());
	}

	Quat Quat::identity()
	{
		return Quat(cx_quat_identity());
	}

	Quat Quat::fromAxisAngle(const cx_float x, const cx_float y, const cx_float z, const cx_float angle)
	{
		return Quat(cx_quat_set_from_axis_anglef3(x, y, z, angle));
	}

	Quat Quat::fromAxisAngle(const Vec3 axis, const cx_float angle)
	{
		const cx_vec3 v = axis.get();
		return Quat(cx_quat_set_from_axis_anglev3(v, angle));
	}

	Quat Quat::fromAxisAngle(const Vec4 axis, const cx_float angle)
	{
		const cx_vec4 v = axis.get();
		return Quat(cx_quat_set_from_axis_anglev4(v, angle));
	}

	inline Quat Quat::operator-() const
	{
		return Quat(cx_quat_negate(q));
	}

	inline Quat Quat::operator+(const Quat &other) const
	{
		const cx_quat q1 = other.get();
		return Quat(cx_quat_add(q, q1));
	}

	inline Quat Quat::operator-(const Quat &other) const
	{
		const cx_quat q1 = other.get();
		return Quat(cx_quat_sub(q, q1));
	}

	inline Quat Quat::operator*(const cx_float fT) const
	{
		return Quat(cx_quat_mulf(q, fT));
	}

	Quat operator*(const cx_float fT, const cx::Quat& q)
	{
		return q * fT;
	}

	inline Quat Quat::operator/(const cx_float fT) const
	{
		return Quat(cx_quat_divf(q, fT));
	}

	Quat Quat::operator*(const Quat &other) const
	{
		const cx_quat q1 = other.get();
		return Quat(cx_quat_mul(q, q1));
	}

	Vec3 operator*(const Quat& q, const Vec3 &other)
	{
		Quat vq(0.0f, other.x(), other.y(), other.z());
    	Quat rq = q * vq * q.conjugate();
    	return Vec3(rq.x(), rq.y(), rq.z());
	}


	inline bool Quat::operator==(const Quat &other) const
	{
		const cx_quat q1 = other.get();
		return ((q.x == q1.x) && (q.y == q1.y)
				&& (q.z == q1.z) && (q.w == q1.w));
	}

	inline bool Quat::operator!=(const Quat &other) const
	{
		return !(*this == other);
	}

	Quat Quat::normalize() const
	{
		return Quat(cx_quat_normalize(q));
	}

	inline cx_float Quat::mag() const
	{
		return cx_quat_mag(q);
	}

	Quat Quat::conjugate() const
	{
		return Quat(cx_quat_conjugate(q));
	}

	inline Quat Quat::inverse() const
	{
		return Quat(cx_quat_inverse(q));
	}

	inline Quat Quat::lerp(const Quat p, const cx_float t) const
	{
		const cx_quat q1 = p.get();
		return Quat(cx_quat_lerp(q, q1, t));
	}

	inline Quat Quat::nlerp(const Quat p, const cx_float t) const
	{
		const cx_quat q1 = p.get();
		return Quat(cx_quat_nlerp(q, q1, t));
	}

	inline Quat Quat::slerp(const Quat p, const cx_float t) const
	{
		const cx_quat q1 = p.get();
		return Quat(cx_quat_slerp(q, q1, t));
	}

	inline cx_float Quat::dot(const Quat p) const
	{
		const cx_quat q1 = p.get();
		return cx_quat_dot(q, q1);
	}

	Vec3 Quat::rotate(const Vec3 v) const
	{
		const cx_vec3 v1 = v.get();
		return Vec3(cx_quat_vec3_rotate(q, v1));
	}

	Vec4 Quat::rotate(const Vec4 v) const
	{
		const cx_vec4 v1 = v.get();
		return Vec4(cx_quat_vec4_rotate(q, v1));
	}

	inline void Quat::print() const
	{
		cx_quat_print(q);
	}


	inline cx_float rk2(cx_float (* f)(cx_float, cx_float), const cx_float x, const cx_float y, const cx_float h = epsilon)
	{
		return cx_rk2(f, x, y, h);
	}

	inline cx_float rk4(cx_float (* f)(cx_float, cx_float), const cx_float x, const cx_float y, const cx_float h = epsilon)
	{
		return cx_rk4(f, x, y, h);
	}

	inline std::vector<std::complex<cx_float>> fft(const std::vector<std::complex<cx_float>> input)
	{
		const int N = input.size();
		std::vector<cx_complex> in(N);
		std::vector<cx_complex> out(N);

		for(int i = 0; i < N; i++)
			in[i] = input[i].real() + input[i].imag() * I;

		cx_fft(in.data(), out.data(), N);

		std::vector<std::complex<cx_float>> result(N);
		for(int i = 0; i < N; i++)
			result[i] = std::complex<cx_float>(crealf(out[i]), cimagf(out[i]));

		return result;
	}

	inline std::vector<std::complex<cx_float>> ifft(const std::vector<std::complex<cx_float>> input)
	{
		const int N = input.size();
		std::vector<cx_complex> in(N);
		std::vector<cx_complex> out(N);

		for(int i = 0; i < N; i++)
			in[i] = input[i].real() + input[i].imag() * I;

		cx_ifft(in.data(), out.data(), N);

		std::vector<std::complex<cx_float>> result(N);
		for(int i = 0; i < N; i++)
			result[i] = std::complex<cx_float>(crealf(out[i]), cimagf(out[i]));

		return result;
	}

	inline std::vector<std::complex<cx_float>> fft(const std::vector<cx_float> input)
	{
		const int N = input.size();
		std::vector<cx_complex> in(N);
		std::vector<cx_complex> out(N);

		for(int i = 0; i < N; i++)
			in[i] = input[i] + 0.0 * I;

		cx_fft(in.data(), out.data(), N);

		std::vector<std::complex<cx_float>> result(N);
		for(int i = 0; i < N; i++)
			result[i] = std::complex<cx_float>(crealf(out[i]), cimagf(out[i]));

		return result;
	}
#endif
}
