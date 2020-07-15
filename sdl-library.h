//
// Created by Arin on 05/04/2020.
//

#ifndef FDFREMASTERED_SDL_LIBRARY_H
#define FDFREMASTERED_SDL_LIBRARY_H


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <string>

#define SCREENSHOT

#ifdef SCREENSHOT
const std::size_t WIN_WIDTH = 1280;
const std::size_t WIN_HEIGHT = 640;
#else
const std::size_t WIN_WIDTH = 4096;
const std::size_t WIN_HEIGHT = 2048;
#endif

class SDL_Library {
public:
	SDL_Library();
	~SDL_Library();
	SDL_Library(const SDL_Library &) = delete;
	SDL_Library & operator=(const SDL_Library &) = delete;

	inline void RedrawCanvas(std::vector< unsigned >&   pixels) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, NULL);

		SDL_UpdateTexture(texture_, nullptr, pixels.data(), 4 * WIN_WIDTH);
		SDL_RenderCopy(renderer, texture_, nullptr, nullptr);
		SDL_RenderPresent(renderer);
	}

	inline void TakeScreenShot(const std::vector<unsigned> & pixels) {

//		(void *pixels, int width, int height, int depth, int pitch, Uint32 format);
		SDL_Surface*    surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)pixels.data(), WIN_WIDTH, WIN_HEIGHT, 32, WIN_WIDTH * 4, SDL_PIXELFORMAT_ARGB8888);
		std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		std::string data(std::ctime(&end_time));
		IMG_SaveJPG(surface, (std::string("Julia fractal : ") + data + std::string(".jpg")).c_str(), 100);
		SDL_FreeSurface(surface);
	}


public:
	SDL_Window* window_;
	SDL_Event   ev_;
	SDL_Texture*    texture_;
	SDL_Renderer*     renderer;
	TTF_Font*    font_;

	int    prevx{WIN_WIDTH / 2};
	int    prevy{WIN_HEIGHT / 2};
};


#endif //FDFREMASTERED_SDL_LIBRARY_H
