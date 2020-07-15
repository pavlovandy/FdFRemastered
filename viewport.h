//
// Created by Arin on 05/04/2020.
//

#ifndef FDFREMASTERED_VIEWPORT_H
#define FDFREMASTERED_VIEWPORT_H

#include "MathTypes/mat4.h"
#include "MathTypes/vec4.h"
#include "MathTypes/vec3.h"
#include <vector>

struct Viewport {
public:
	Viewport(vec3<float> v, vec3<float> r) : vertex(v), rotation(VectorOfAngleToRadians(r)) {
		CreateTransformMatrix();
		fov = 90 * ToRad;
	}

	void    CreateTransformMatrix();
	//FDF transform
	void    Transform(const class Map& map, std::vector<std::vector<vec4<float>>>& OutArray);

	//dot -> dot
	void    Transform(std::vector<vec4<float>>& OutArray);

	void    AddRotation(const vec3<float>& r);
	void    SetRotation(const vec3<float>& r);
	void    TranslateVertex(const vec3<float>& v);
	void    SetVertexLocation(const vec3<float>& l);

	void    Clipping();

private:
	static inline vec3<float>  VectorOfAngleToRadians(const vec3<float>& r) {
		return r * (float)ToRad;
	}

	mat4<float> transformationMatrix;
	vec3<float> vertex;
	vec3<float> rotation;
	float   fov;
};

#endif //FDFREMASTERED_VIEWPORT_H
