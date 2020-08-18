#pragma once
#include "SDL.h"
class Transform
{
private:
	SDL_Point* position, * velocity, * size;

public:
	Transform();
	~Transform();

	void update();

	void setPos(float x, float y);
	void setPos(SDL_Point* p);
	SDL_Point* getPos();

	void setVelo(float x, float y);
	void setVelo(SDL_Point* p);
	SDL_Point* getVelo();

	void setSize(float x, float y);
	void setSize(SDL_Point* p);
	SDL_Point* getSize();
};

