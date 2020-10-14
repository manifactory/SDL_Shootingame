#pragma once
#include "SDL.h"
class Transform
{
private:
	SDL_FPoint position;
	SDL_FPoint velocity;
	SDL_FPoint size;
	SDL_FPoint sizeM;

public:
	

	Transform();
	~Transform();

	void update();

	void setPos(float x, float y);
	void setPos(SDL_FPoint p);
	SDL_FPoint getPos();

	void setVelo(float x, float y);
	void setVelo(SDL_FPoint p);
	SDL_FPoint getVelo();

	void setSize(float x, float y);
	void setSize(SDL_FPoint p);
	SDL_FPoint getSize();

	void setSIzeMul(float m);
	void setSIzeMul(float x, float y);
	void setSIzeMul(SDL_FPoint p);
	SDL_FPoint getSIzeMul();

	float Lerp(float value1, float value2, float amount);
	SDL_FPoint Lerp(SDL_FPoint point1, SDL_FPoint point2, float amount);
};

