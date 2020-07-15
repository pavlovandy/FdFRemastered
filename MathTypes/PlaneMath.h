//
// Created by Arin on 17/05/2020.
//

#ifndef FDFREMASTERED_PLANEMATH_H
#define FDFREMASTERED_PLANEMATH_H

#include "vec3.h"

struct Plane {
	vec3<float> normal;
	float   d;
};

namespace   Math {
	template <typename VEC>
	inline bool        isBehind(const Plane & plane, VEC dot) {
		//totaly uncheckable
		return  -(plane.normal.x * dot.x + plane.normal.y * dot.y + plane.normal.z * dot.z) > plane.d;
	}

	template <typename VEC>
	inline Plane       createPlaneFromDots(VEC d1, VEC d2, VEC d3) {
		Plane res;




		auto l1 = d2 - d1;
		auto l2 = d3 - d1;
		res.normal = cross(l1, l2); // todo check
		res.d = -(res.normal.x * d1.x + res.normal.y * d1.y + res.normal.z * d1.z);
		return res;
	}
};

#endif //FDFREMASTERED_PLANEMATH_H
