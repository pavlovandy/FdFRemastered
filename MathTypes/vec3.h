//
// Created by Arin on 04/04/2020.
//

#ifndef FDFREMASTERED_VEC3_H
#define FDFREMASTERED_VEC3_H

#include "vec4.h"
#include "assert.h"
template <typename T>
struct vec3 {
	union {
		struct {
			T x;
			T y;
			T z;
		};
		T   coord[3];
	};

	constexpr vec3(T a = 0, T b = 0, T c = 0) :
		x(a), y(b), z(c)
	{}

	inline vec3(const vec4<T>& from) :
			x(from.x), y(from.y), z(from.z)
	{}

	constexpr inline const T& operator[](unsigned ind) const {
		return coord[ind];
	}

	inline T& operator[](unsigned ind) {
		return coord[ind];
	}
};

template <typename T>
constexpr inline vec3<T>    operator+(const vec3<T>& rhs, const vec3<T>& lhs) {
	return {rhs.x + lhs.x,
		    rhs.y + lhs.y,
		    rhs.z + lhs.z};
}

template <typename T>
constexpr inline vec3<T>    operator-(const vec3<T>& rhs, const vec3<T>& lhs) {
	return {rhs.x - lhs.x,
		    rhs.y - lhs.y,
		    rhs.z - lhs.z};
}

template <typename T>
constexpr inline T    operator*(const vec3<T>& rhs, const vec3<T>& lhs) {
	return  rhs.x * lhs.x +
			rhs.y * lhs.y +
			rhs.z * lhs.z;
}

template <typename T>
constexpr inline vec3<T>    cross(const vec3<T>& rhs, const vec3<T>& lhs) {
	return {rhs.y * lhs.z - rhs.z * lhs.y,
		    rhs.z * lhs.x - rhs.x * lhs.z,
		    rhs.x * lhs.y - rhs.y * lhs.x};
}

template <typename T>
constexpr inline vec3<T>    operator-(const vec3<T>& self) {
	return {-self.x, -self.y, -self.z};
}

template <typename T, typename V>
constexpr inline vec3< decltype(std::declval<T>() * std::declval<V>()) >    operator*(V v, const vec3<T>& self) {
	return {v * self.x, v * self.y, v * self.z};
}

template <typename T, typename V>
constexpr inline vec3< decltype(std::declval<T>() * std::declval<V>()) >    operator*(const vec3<T>& self, V v) {
	return v * self;
}

template <typename T, typename V>
constexpr inline vec3< decltype(std::declval<T>() / std::declval<V>()) >    operator/(const vec3<T>& self, V v) {
	assert(v != 0);
	return self  * (1 / v);
}

#endif //FDFREMASTERED_VEC3_H
