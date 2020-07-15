//
// Created by Arin on 05/04/2020.
//

#include <iostream>
#include "viewport.h"
#include "sdl-library.h"
#include "Map.h"

void    Viewport::AddRotation(const vec3<float>& r) {
	rotation = rotation + VectorOfAngleToRadians(r);
}

void    Viewport::SetRotation(const vec3<float>& r) {
	rotation = VectorOfAngleToRadians(r);
}

void    Viewport::TranslateVertex(const vec3<float>& v) {
	vertex = vertex + v;
}

void    Viewport::SetVertexLocation(const vec3<float>& l) {
	vertex = l;
}

void    Viewport::CreateTransformMatrix() {
	static mat4<float>   viewportTransformation = TranslateMatrix(vec3<float>(WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f, 1 / 2.f)) *
	                                                 ScaleMatrix(vec3<float>(WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f, 1.f / 2));
	//just for test reasons
	static auto   AdditionalScale = ScaleMatrix(vec3<float>(1, 1, 1) / 2.f);

	transformationMatrix = viewportTransformation * AdditionalScale * Transpose(RotationMatrix(rotation)) * TranslateMatrix(vertex);
}

void    Viewport::Transform(const Map& map, std::vector<std::vector<vec4<float>>>& OutArray) {

	auto shift_to_MiddleTranslateMatrix = TranslateMatrix(vec3<float>(-map.averageX, -map.averageY, -map.averageZ));
	CreateTransformMatrix();
	transformationMatrix = transformationMatrix * shift_to_MiddleTranslateMatrix;

	for (int i = 0; i < (int)map.parsedMap.size(); i++) {
		for (int j = 0; j < (int)map.parsedMap[i].size(); j++) {
			OutArray[i][j] = transformationMatrix * vec4<float>(i, j, map.parsedMap[i][j], 1);
		}
	}
}

void    Viewport::Transform(std::vector<vec4<float>>& OutArray) {
	for (int i = 0; i < (int)OutArray.size(); i++) {
			OutArray[i] = transformationMatrix * OutArray[i];
	}
}