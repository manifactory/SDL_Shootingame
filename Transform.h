#pragma once
#include "Vector2D.h"
class Transform
{
private:
	Vector2D* position, * velocity, * size, *sizeM;

public:
	

	Transform();
	~Transform();

	void update();

	void setPos(float x, float y);
	void setPos(Vector2D* p);
	Vector2D* getPos();

	void setVelo(float x, float y);
	void setVelo(Vector2D* p);
	Vector2D* getVelo();

	void setSize(float x, float y);
	void setSize(Vector2D* p);
	Vector2D* getSize();

	void setSIzeMul(float m);
	void setSIzeMul(float x, float y);
	void setSIzeMul(Vector2D* p);
	Vector2D* getSIzeMul();
};

