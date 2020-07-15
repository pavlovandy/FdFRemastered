//
// Created by Arin on 04/04/2020.
//

#ifndef FDFREMASTERED_VEC4_H
#define FDFREMASTERED_VEC4_H

#include <utility>
template <typename T>
struct vec4 {
	union {
		struct {
			T x;
			T y;
			T z;
			T w;
		};
		T   coord[4];
	};

	constexpr vec4(T a = 0, T b = 0, T c = 0, T d = 0) :
		x(a), y(b), z(c), w(d)
	{}

	constexpr inline T& operator[](unsigned ind) {
		return coord[ind];
	}

	constexpr inline T operator[](unsigned ind) const {
		return coord[ind];
	}
};

template <typename T>
constexpr inline vec4<T>    operator+(const vec4<T>& rhs, const vec4<T>& lhs) {
	return {rhs.x + lhs.x,
		    rhs.y + lhs.y,
		    rhs.z + lhs.z,
		    rhs.w + lhs.w};
}

template <typename T>
constexpr inline vec4<T>    operator-(const vec4<T>& rhs, const vec4<T>& lhs) {
	return {rhs.x - lhs.x,
		    rhs.y - lhs.y,
		    rhs.z - lhs.z,
		    rhs.w - lhs.w};
}

template <typename T>
constexpr inline T    operator*(const vec4<T>& rhs, const vec4<T>& lhs) {
	return  rhs.x * lhs.x +
			rhs.y * lhs.y +
			rhs.z * lhs.z;
}

template <typename T>
constexpr inline vec4<T>    cross(const vec4<T>& rhs, const vec4<T>& lhs) {
	return {rhs.y * lhs.z - rhs.z * lhs.y,
		    rhs.z * lhs.x - rhs.x * lhs.z,
		    rhs.x * lhs.y - rhs.y * lhs.x,
		    0};
}

template <typename T>
constexpr inline vec4<T>    operator-(const vec4<T>& self) {
	return {-self.x, -self.y, -self.z, -self.w};
}

template <typename T, typename V>
constexpr inline vec4< decltype(std::declval<T>() + std::declval<V>()) >    operator*(V v, const vec4<T>& self) {
	return {v * self.x, v * self.y, v * self.z, v * self.w};
}

template <typename T, typename V>
constexpr inline vec4< decltype(std::declval<T>() + std::declval<V>()) >    operator*(const vec4<T>& self, V v) {
	return v * self;
}

template < typename T>
constexpr auto ZeroVector = vec4<T>{0, 0, 0, 0};

#endif //FDFREMASTERED_VEC4_H
