#pragma once
#include "TextureManager.h"
#include "Object.h"

#define SPRITE_PATH 1
#define SPRITE_SURFACE 2

class Sprite :public Object
{
private:
	SDL_Texture* tex;
	SDL_RendererFlip flip;

public:
	Sprite();
	Sprite(const char* path);
	Sprite(SDL_Surface* tempSurface);
	Sprite(const char* path, float sizeM);
	~Sprite();

	void setFlip(SDL_RendererFlip f);
	SDL_RendererFlip getFlip();

	SDL_Texture* getTexture();

	void Render();

};


