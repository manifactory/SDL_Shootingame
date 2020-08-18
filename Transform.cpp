#include "Transform.h"

Transform::Transform()
{
	position = new Vector2D();
	velocity = new Vector2D();
	size = new Vector2D();
}

Transform::~Transform()
{
	delete(position);
	position = nullptr;
	delete(velocity);
	velocity = nullptr;
	delete(size);
	size = nullptr;
}

void Transform::update()
{
	position->x += velocity->x;
	position->y += velocity->y;
}

void Transform::setPos(float x, float y)
{
	position->x = x;
	position->y = y;
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

Vector2D* Transform::getVelo()
{
	return velocity;
}

void Transform::setSize(float x, float y)
{
	size->x = x;
	size->y = y;
}


Vector2D* Transform::getSize()
{
	return size;
}