#pragma once
#include "Vector2D.h"
class Transform
{
private:
	Vector2D *position, *velocity, *size;

public:
	Transform();
	~Transform();

	void update();

	void setPos(float x, float y);
	Vector2D* getPos();

	void setVelo(float x, float y);
	Vector2D* getVelo();

	void setSize(float x, float y);
	Vector2D* getSize();
};

