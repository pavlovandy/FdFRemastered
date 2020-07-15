//
// Created by Arin on 05/04/2020.
//

//					Triangle    triangle{vertices[i][j],
//					                     vertices[i][j + 1],
//					                     vertices[i + 1][j]};
//                  triangle = {vertices[i][j + 1], vertices[i + 1][j], vertices[i + 1][j + 1]};


#include "screen.h"
#include <cassert>
#include <iostream>


void    Screen::DrawTriangle(const Triangle& t, unsigned color) {
	int     minx = WIN_WIDTH - 1, miny = WIN_HEIGHT - 1;
	int     maxx = 0, maxy = 0;

	for (int i = 0;  i < 3; i++) {
		if (t[i].x < minx) minx = t[i].x;
		if (t[i].y < miny) miny = t[i].y;
		if (t[i].x > maxx) maxx = t[i].x;
		if (t[i].y > maxy) maxy = t[i].y;
	}

	auto edgeFunction = [](const vec3<float> &a, const vec3<float> &b, const vec3<float> &c)
			{
				return (c[0] - a[0]) * (b[1] - a[1]) - (c[1] - a[1]) * (b[0] - a[0]);
			};

	float inverseArea = 1.f / edgeFunction(t[0], t[1], t[2]);
	for (int y = miny; y <= maxy; ++y) {
		for (int x = minx; x <= maxx; ++x) {
			vec3<float> p = {x + 0.5f, y + 0.5f};

			float w0 = edgeFunction(t[1], t[2], p);
			float w1 = edgeFunction(t[2], t[0], p);
			float w2 = edgeFunction(t[0], t[1], p);
			if (w0 >= 0 && w1 >= 0 && w2 >= 0 && inverseArea > 0) {
//				w0 *= inverseArea;
//				w1 *= inverseArea;
//				w2 *= inverseArea;
				float z = -1;
				ManageZbuffAndPixels(x, y, z, color);
			}
			else if (w0 < 0 && w1 < 0 && w2 < 0 && inverseArea < 0)
			{
				float z = -1;
				ManageZbuffAndPixels(x, y, z, color);
			}

		}
	}
}


void    Screen::DrawCartesianCoordBasis(SDL_Renderer* render, const std::vector<vec4<float>>&    vertices) {
	assert(vertices.size() == 4);
	SDL_SetRenderDrawColor(render, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(render, vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y);
	SDL_SetRenderDrawColor(render, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(render, vertices[0].x, vertices[0].y, vertices[2].x, vertices[2].y);
	SDL_SetRenderDrawColor(render, 0, 0, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(render, vertices[0].x, vertices[0].y, vertices[3].x, vertices[3].y);
}

int         findRegion(const vec4<float >& dot) {
	if (dot.x < 0) {
		if ((dot.y < 0))
			return 1;
		else if ((dot.y >= WIN_HEIGHT))
			return 2;
	}
	else if (dot.x >= WIN_WIDTH) {
		if ((dot.y < 0))
			return 4;
		else if ((dot.y >= WIN_HEIGHT))
			return 8;
	}
	if (dot.z < 0)
		return 16;
	return 0;
}

void    Screen::ProjectOn(const std::vector<std::vector<vec4<float>>>&    vertices) {
	for (int i = 0; i < (int)vertices.size() - 1; i++) {
		for (int j = 0; j < (int)vertices[i].size() - 1; j++) {
			if (j != (int)vertices[i + 1].size()) {
				if (findRegion(vertices[i][j])) {
					static int a = 0;
					std::cout << a++ << std::endl;
					continue;
				}
//				else
//					std::cout << vertices[i][j].x << " " << vertices[i][j].y << std::endl;

				Triangle    triangle = {vertices[i][j], vertices[i][j + 1], vertices[i + 1][j]};
				DrawTriangle(triangle, 0xaaff73);
				if (j + 1 != (int)vertices[i + 1].size()) {
					triangle = {vertices[i][j + 1], vertices[i + 1][j + 1], vertices[i + 1][j]};
					DrawTriangle(triangle, 0xccff11);
				}
			}
		}
	}
}

void    Screen::ProjectOn(const std::vector<std::vector<vec4<float>>>&    vertices, SDL_Renderer* render) {
	for (int i = 0; i < (int)vertices.size() - 1; i++) {
		for (int j = 0; j < (int)vertices[i].size() - 1; j++) {
			if (j != (int)vertices[i + 1].size()) {
				if (findRegion(vertices[i][j]))
					continue;
				SDL_Point   trianglePoints[4] = {
						{(int)vertices[i][j].x, (int)vertices[i][j].y},
						{(int)vertices[i][j + 1].x, (int)vertices[i][j + 1].y},
						{(int)vertices[i + 1][j].x, (int)vertices[i + 1][j].y},
						{(int)vertices[i][j].x, (int)vertices[i][j].y}
				};
				SDL_SetRenderDrawColor(render, 140, 140, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderDrawLines(render, trianglePoints, 4);
				if (j + 1 != static_cast<int>(vertices[i + 1].size())) {
					SDL_Point   trianglePoints[4] = {
							{(int)vertices[i][j + 1].x, (int)vertices[i][j + 1].y},
							{(int)vertices[i + 1][j].x, (int)vertices[i + 1][j].y},
							{(int)vertices[i + 1][j + 1].x, (int)vertices[i + 1][j + 1].y},
							{(int)vertices[i][j + 1].x, (int)vertices[i][j + 1].y}
					};
					SDL_SetRenderDrawColor(render, 255, 140, 140, SDL_ALPHA_OPAQUE);
					SDL_RenderDrawLines(render, trianglePoints, 4);
				}
			}
		}
	}
}