#pragma once
#include "TextureManager.h"
#include "Transform.h"

class Sprite :public Transform
{
private:
	SDL_Texture* tex;
	SDL_Rect srcRect, destRect;

	float size;

public:
	Sprite(const char* path, int x, int y, int w, int h);
	~Sprite();

	void Update();
	void Render();

	void setSize(float size);

};

