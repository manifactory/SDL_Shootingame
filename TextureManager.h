#pragma once
//#include  "Game.h"

class textureManager {
public:
	static SDL_Texture* loadIMGTexture(const char* path);
	//static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point center, SDL_RendererFlip flip);
};