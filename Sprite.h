#pragma once
#include "TextureManager.h"
#include "Object.h"

class Sprite :public Object
{
private:
	SDL_Texture* tex;
	SDL_RendererFlip flip;

public:
	Sprite(const char* path);
	Sprite(const char* path, float sizeM);
	~Sprite();

	void setFlip(SDL_RendererFlip f);
	SDL_RendererFlip getFlip();

	SDL_Texture* getTexture();

	void Render();

};


