#pragma once
#include "TextureManager.h"
#include "Transform.h"

class Sprite :public Transform
{
private:
	SDL_Texture* tex;
	SDL_Rect srcRect, destRect;


public:
	Sprite(const char* path);
	~Sprite();

	void Update();
	void Render();

	SDL_Rect getRect();

	bool intersectRect(Sprite* target);
	bool pointInRect(SDL_Point* p);

};

