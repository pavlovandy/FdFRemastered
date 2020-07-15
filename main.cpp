#include "MathTypes/vec4.h"
#include "MathTypes/mat4.h"
#include "parser.h"
#include "triangle.h"
#include "viewport.h"
#include "screen.h"
#include "sdl-library.h"
#include <cassert>
#include "MathTypes/PlaneMath.h"
#include <iostream>

#define MAINRENDER

int main() {
#ifdef MAINRENDER
	Map mapstruct;
	std::vector<std::vector<int >>&     map = mapstruct.parsedMap;
	Parser::parseFile(mapstruct, "kappa");

	std::vector<std::vector<vec4<float>>> transformedMap(map.size());
	for (unsigned i = 0; i < map.size(); i++)
		transformedMap[i].resize(map[i].size());
	Screen      screen;
	SDL_Library library;

	bool quit = false;
	bool changes = true;
	bool clicked = false;
	Viewport    viewport(vec3<float>(1, 1, 1), vec3<float>(0 ,0 , 0));
	while (!quit) {
		if (changes) {
			//black
			std::fill(screen.pixels.begin(), screen.pixels.end(), 0);
			std::fill(screen.zbuff.begin(), screen.zbuff.end(), 255);

			//triangles
			viewport.Transform(mapstruct, transformedMap);
			//project triangles
			screen.ProjectOn(transformedMap);
			library.RedrawCanvas(screen.pixels);

			//project edges
			screen.ProjectOn(transformedMap, library.renderer);
			SDL_RenderPresent(library.renderer);
			changes = false;
		}
		while (SDL_PollEvent(&library.ev_)) {
			switch (library.ev_.type) {
				case SDL_QUIT:  quit = true; break;
				case SDL_KEYDOWN:
					switch (library.ev_.key.keysym.sym) {
						case SDLK_ESCAPE:
							quit = true;
							break;
						case    SDLK_z:
							viewport.AddRotation(vec3<float>(20, 0, 0));
							changes = true;
							break;
						case    SDLK_x:
							viewport.AddRotation(vec3<float>(0, 20, 0));
							changes = true;
							break;

						case    SDLK_c:
							viewport.AddRotation(vec3<float>(0, 0, 20));
							changes = true;
							break;

						case    SDLK_o:
							library.TakeScreenShot(screen.pixels);
							changes = true;
							break;
					};
					break;
				case SDL_MOUSEBUTTONDOWN:
					clicked = true;
					break;
				case SDL_MOUSEBUTTONUP:
					clicked = false;
					break;
				case SDL_MOUSEMOTION:
					if (clicked) {
						changes = true;
					}
					break;
			}
		}
	}
#else
	Plane   p1 = Math::createPlaneFromDots(vec3<float>(0, 0, 10), vec3<float>(1, 1, 10), vec3<float>(2, 3, 10));
	std::cout << p1.normal.x << " " << p1.normal.y << " " << p1.normal.z << "\n";
	std::cout << p1.d << std::endl;


#endif
	return 0;
}
