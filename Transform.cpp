#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	position = new SDL_Point();
	velocity = new SDL_Point();
	size = new SDL_Point();

	position->x = position->y = 0;
	velocity->x = velocity->y = 0;
	size->x = size->y = 0;
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

void Transform::setPos(SDL_Point* p)
{
	position->x = p->x;
	position->y = p->y;
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

void Transform::setVelo(SDL_Point* p)
{
	velocity->x = p->x;
	velocity->y = p->y;
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

void Transform::setSize(SDL_Point* p)
{
	size->x = p->x;
	size->y = p->y;
}


SDL_Point* Transform::getSize()
{
	return size;
}
