//
// Created by Arin on 05/04/2020.
//

#include "sdl-library.h"
#include <stdexcept>

SDL_Library::SDL_Library()  {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 || TTF_Init() == -1 || IMG_Init(IMG_INIT_JPG) != IMG_INIT_JPG)
		throw std::runtime_error(SDL_GetError());
	if (!(window_ = SDL_CreateWindow("FdF Remastered", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)))
		throw std::runtime_error(SDL_GetError());
	if (!(font_ = TTF_OpenFont("resources/ComicNeue-Regular.ttf", 20)))
		throw std::runtime_error(SDL_GetError());
	if (!(renderer = SDL_CreateRenderer(window_, -1, 0)))
		throw std::runtime_error(SDL_GetError());
	if (!(texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT)))
		throw std::runtime_error(SDL_GetError());
}

SDL_Library::~SDL_Library() {
	TTF_CloseFont(font_);
	SDL_DestroyWindow(window_);
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture_);
	IMG_Quit();
	SDL_Quit();
}