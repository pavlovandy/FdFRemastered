//
// Created by Arin on 04/04/2020.
//

#ifndef FDFREMASTERED_TRIANGLE_H
#define FDFREMASTERED_TRIANGLE_H

#include <array>
#include "MathTypes/vec3.h"

struct Triangle {
public:
	std::array<vec3<float>, 3>  vertices;

	inline const vec3<float>& operator[](unsigned indx) const {
		return vertices[indx];
	}

	inline vec3<float>& operator[](unsigned indx)  {
		return vertices[indx];
	}
};



#endif //FDFREMASTERED_TRIANGLE_H
