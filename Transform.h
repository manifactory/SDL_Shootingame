#pragma once
#include "SDL.h"
class Transform
{
private:
	SDL_FPoint position;
	SDL_FPoint velocity;
	SDL_FPoint size;
	SDL_FPoint sizeM;
	SDL_FPoint center;

	double angle;


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

	void setSizeMul(float m);
	void setSizeMul(float x, float y);
	void setSizeMul(SDL_FPoint p);
	SDL_FPoint getSizeMul();

	void setCenter(float x, float y);
	void setCenter(SDL_FPoint p);
	SDL_FPoint getCenter();

	void setAngle(double a);
	double getAngle();

	float Lerp(float value1, float value2, float amount);
	SDL_FPoint Lerp(SDL_FPoint point1, SDL_FPoint point2, float amount);
};

