#pragma once
#include "SDL.h"
class Transform
{
private:
	SDL_FPoint* position, * velocity, * size, *sizeM;

public:
	

	Transform();
	~Transform();

	void update();

	void setPos(float x, float y);
	void setPos(SDL_FPoint* p);
	SDL_FPoint* getPos();

	void setVelo(float x, float y);
	void setVelo(SDL_FPoint* p);
	SDL_FPoint* getVelo();

	void setSize(float x, float y);
	void setSize(SDL_FPoint* p);
	SDL_FPoint* getSize();

	void setSIzeMul(float m);
	void setSIzeMul(float x, float y);
	void setSIzeMul(SDL_FPoint* p);
	SDL_FPoint* getSIzeMul();
};

