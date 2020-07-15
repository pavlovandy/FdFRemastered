//
// Created by Arin on 04/04/2020.
//

#ifndef FDFREMASTERED_MAT4_H
#define FDFREMASTERED_MAT4_H

#include <utility>
#include <cmath>
#include "vec4.h"
#include "vec3.h"

constexpr double ToRad = M_PI / 180.;
constexpr double ToDegree = 1. / ToRad;

template <typename T>
struct mat4 {
	T   element[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
public:
	constexpr inline const T& operator[](unsigned ind) const {
		return element[ind];
	}

	inline T& operator[](unsigned ind) {
		return element[ind];
	}
};

template <typename T>
constexpr inline mat4<T> operator+(const mat4<T>& rhs, const mat4<T>& lhs) {
	mat4<T>    res;
	for (unsigned i = 0; i < 16; i++)
		res[i] = rhs[i] + lhs[i];
	return res;
}

template <typename T>
constexpr inline mat4<T> operator-(const mat4<T>& rhs, const mat4<T>& lhs) {
	mat4<T>    res;
	for (unsigned i = 0; i < 16; i++)
		res[i] = rhs[i] - lhs[i];
	return res;
}

template <typename T, typename V>
inline mat4< decltype(std::declval<T>() + std::declval<V>()) > operator*(const mat4<T>& rhs, const mat4<V>& lhs) {
	mat4<T>    res;
	for (unsigned i = 0; i < 16; i += 4)
		for (unsigned j = 0; j < 4; j++)
			for (unsigned k = 0; k < 4; k++)
				res[i + j] += (rhs[i + k] * lhs[(k << 2u) + j]);
	return res;
}

template <typename T>
constexpr inline mat4<T>     ScaleMatrix(const vec3<T>& ScaleVector) {
	mat4<T>    mat;
	mat[0] = ScaleVector.x;
	mat[5] = ScaleVector.y;
	mat[10] = ScaleVector.z;
	mat[15] = 1;
	return mat;
}

template <typename T>
constexpr inline mat4<T>     TranslateMatrix(const vec3<T>& TranslateVector) {
	mat4<T>    mat;
	mat[0] = 1;
	mat[5] = 1;
	mat[10] = 1;
	mat[3] = TranslateVector.x;
	mat[7] = TranslateVector.y;
	mat[11] = TranslateVector.z;
	mat[15] = 1;
	return mat;
}

template <typename T>
constexpr inline mat4<T>     RotationMatrix(const vec3<T>& Angles) {
	mat4<T> mat;
	T A     = cos(Angles.x);
	T B     = sin(Angles.x);
	T C     = cos(Angles.y);
	T D     = sin(Angles.y);
	T E     = cos(Angles.z);
	T F     = sin(Angles.z);
	T AD    = A * D;
	T BD    = B * D;

	mat[0]  =   C * E;
	mat[1]  =  -C * F;
	mat[2]  =   D;
	mat[4]  =  BD * E + A * F;
	mat[5]  = -BD * F + A * E;
	mat[6]  =  -B * C;
	mat[8]  = -AD * E + B * F;
	mat[9]  =  AD * F + B * E;
	mat[10] =   A * C;
	mat[15] = 1;
	return mat;
}

template <typename T>
constexpr inline mat4<T>     RotationMatrix(T angle, const vec3<T>& Axis) {
	mat4<T>    mat;
	T u = Axis.x;
	T v = Axis.y;
	T w = Axis.z;

	angle = angle * ToRad;
	T rcos = cos(angle);
	T rsin = sin(angle);
	mat[0] =      rcos + u*u*(1-rcos);
	mat[1] =  w * rsin + v*u*(1-rcos);
	mat[2] = -v * rsin + w*u*(1-rcos);
	mat[4] = -w * rsin + u*v*(1-rcos);
	mat[5] =      rcos + v*v*(1-rcos);
	mat[6] =  u * rsin + w*v*(1-rcos);
	mat[8] =  v * rsin + u*w*(1-rcos);
	mat[9] = -u * rsin + v*w*(1-rcos);
	mat[10] =      rcos + w*w*(1-rcos);
	mat[15] = 1;
	return mat;
}

template <typename T>
constexpr inline mat4<T>     Transpose(const mat4<T>& matToTranspose) {
	mat4<T>    mat;
	for (unsigned i = 0; i < 4; i++)
		for (unsigned j = 0; j < 4; j++)
			mat[(i << 2) + j] = matToTranspose[(j << 2) + i];
	return mat;
}

template <typename T, typename V>
constexpr inline vec4< decltype(std::declval<T>() * std::declval<V>()) >     TransformVector(const mat4<T>& mat, const vec4<V> vec) {
	vec4<T> res;
	for (unsigned i = 0; i < 4; i++)
		for (unsigned j = 0; j < 4; j++)
			res[i] += mat[(i << 2) + j] * vec[j];
	return res;
}

template <typename T, typename V>
constexpr inline vec4< decltype(std::declval<T>() * std::declval<V>()) >     operator*(const mat4<T>& mat, const vec4<V> vec) {
	return TransformVector(mat, vec);
}

template <typename T, typename V>
constexpr inline mat4< decltype(std::declval<T>() * std::declval<V>()) >     operator*(const mat4<T>& mat, V lhs) {
	mat4<T> res;
	for (int i = 0; i < 16; i++)
		res[i] = mat[i] * lhs;
	return res;
}

template <typename T, typename V>
constexpr inline mat4< decltype(std::declval<T>() * std::declval<V>()) >     operator*(V lhs, const mat4<T>& mat) {
	return mat * lhs;
}

template <typename T>
constexpr inline mat4< T >     operator-(const mat4<T>& mat) {
	mat4<T>     res;
	for (int i = 0; i < 16; i++)
		res[i] = -mat[i];
	return res;
}

//template <typename T, typename V>
//inline vec4< decltype(std::declval<T>() * std::declval<V>()) >     operator*(const mat4<T>& mat, const vec4<V> vec) {
//	return TransformVector(mat, vec);
//}

// add it later mb
//template <typename T>
//inline mat4<T>     RotationYawMatrix(T angle) {
//	mat4<T>    mat;
//	T rcos     = cos(angle);
//	T rsin     = sin(angle);
//	return mat;
//}
//template <typename T>
//inline mat4<T>     RotationPitchMatrix(T angle) {
//	mat4<T>    mat;
//	T rcos     = cos(angle);
//	T rsin     = sin(angle);
//	return mat;
//}
//template <typename T>
//inline mat4<T>     RotationRollMatrix(T angle) {
//	mat4<T>    mat;
//	T rcos     = cos(angle);
//	T rsin     = sin(angle);
//	return mat;
//}

#endif //FDFREMASTERED_MAT4_H
