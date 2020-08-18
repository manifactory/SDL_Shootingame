#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	position = new SDL_Point();
	velocity = new SDL_Point();
	size = new SDL_Point();
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

SDL_Point* Transform::getPos()
{
	return position;
}

void Transform::setVelo(float x, float y)
{
	velocity->x = x;
	velocity->y = y;
}

SDL_Point* Transform::getVelo()
{
	return velocity;
}

void Transform::setSize(float x, float y)
{
	size->x = x;
	size->y = y;
}


SDL_Point* Transform::getSize()
{
	return size;
}
