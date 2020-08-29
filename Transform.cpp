#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	position = new Vector2D();
	velocity = new Vector2D();
	size = new Vector2D();
	sizeM = new Vector2D();

	position->x = position->y = 0;
	velocity->x = velocity->y = 0;
	size->x = size->y = 0;
	sizeM->x = sizeM->y = 1;
}

Transform::~Transform()
{
	SAFE_DELETE(position);
	SAFE_DELETE(velocity);
	SAFE_DELETE(size);
	SAFE_DELETE(sizeM);
}

void Transform::update()
{
	position->x += ((double)velocity->x * DeltaTime);
	position->y += ((double)velocity->y * DeltaTime);
}

void Transform::setPos(float x, float y)
{
	position->x = x;
	position->y = y;
}

void Transform::setPos(Vector2D* p)
{
	position->x = p->x;
	position->y = p->y;
}

Vector2D* Transform::getPos()
{
	return position;
}

void Transform::setVelo(float x, float y)
{
	velocity->x = x;
	velocity->y = y;
}

void Transform::setVelo(Vector2D* p)
{
	velocity->x = p->x;
	velocity->y = p->y;
}

Vector2D* Transform::getVelo()
{
	return velocity;
}

void Transform::setSize(float x, float y)
{
	size->x = x;
	size->y = y;
}

void Transform::setSize(Vector2D* p)
{
	size->x = p->x;
	size->y = p->y;
}


Vector2D* Transform::getSize()
{
	return size;
}

void Transform::setSIzeMul(float m)
{
	sizeM->x = m;
	sizeM->y = m;
}

void Transform::setSIzeMul(float x, float y)
{
	sizeM->x = x;
	sizeM->y = y;
}

void Transform::setSIzeMul(Vector2D* p)
{
	sizeM = p;
}

Vector2D* Transform::getSIzeMul()
{
	return sizeM;
}

