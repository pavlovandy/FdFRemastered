//
// Created by Arin on 05/04/2020.
//

#ifndef FDFREMASTERED_SCREEN_H
#define FDFREMASTERED_SCREEN_H

#include "sdl-library.h"
#include "MathTypes/vec4.h"
#include "MathTypes/vec3.h"
#include "triangle.h"
#include <iostream>
class Screen {
public:
	Screen() {
		zbuff.reserve(WIN_WIDTH * WIN_HEIGHT);
		pixels.reserve(WIN_WIDTH * WIN_HEIGHT);
	}

	inline void    DrawPixel(unsigned x, unsigned y, unsigned color) {
		if (x < WIN_WIDTH && y < WIN_HEIGHT)
			pixels[y * WIN_WIDTH + x] = color;
	}

	void    ProjectOnScreen(std::vector<vec4<float>>&    vertices) {
		for (unsigned vert = 0; vert - 1 < vertices.size(); vert++) {

		}
	}

	//test function
	void    ProjectOn(const std::vector<std::vector<vec4<float>>>&    vertices, SDL_Renderer* render);
	void    ProjectOn(const std::vector<std::vector<vec4<float>>>&    vertices);

	void    DrawCartesianCoordBasis(SDL_Renderer* render, const std::vector<vec4<float>>&    vertices);

	void    DrawTriangle(const Triangle& t, unsigned color);

	std::vector<unsigned >  zbuff;
	std::vector<unsigned >  pixels;


private:

	inline void    ManageZbuffAndPixels(int x, int y, int z, unsigned color) {
		static int a = 0;
		if (x < 0 || x >= (int)WIN_WIDTH)
			return ;


		if (y < 0 || y >= (int)WIN_HEIGHT)
			return ;
		int indx = y * WIN_WIDTH + x;
		//if (z < (int)zbuff[indx]) {
		pixels[indx] = color;
		//zbuff[indx] = z;
		//}
	}
};


#endif //FDFREMASTERED_SCREEN_H
