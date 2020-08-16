#pragma once
#include "Vector2D.h"
class Transform
{
private:
	Vector2D *position, *velocity;

public:
	Transform();
	~Transform();

	void setPos(float x, float y);
	Vector2D* getPos();

	void setVelo(float x, float y);
	Vector2D* getVelo();
};

