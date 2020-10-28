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
	~Sprite();

	void setFlip(SDL_RendererFlip f);
	SDL_RendererFlip getFlip();

	void Render();

};


