#pragma once
#include "TextureManager.h"
#include "Object.h"

class Sprite :public Object
{
private:
	SDL_Texture* tex;
	


public:
	Sprite(const char* path);
	~Sprite();

	void Render();

};

