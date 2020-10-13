#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	position.x = position.y = 0.0f;
	velocity.x = velocity.y = 0.0f;
	size.x = size.y = 0.0f;
	sizeM.x = sizeM.y = 1.0f;
}

Transform::~Transform()
{
}

void Transform::update()
{
	position.x += ((float)velocity.x * (float)DeltaTime);
	position.y += ((float)velocity.y * (float)DeltaTime);
}

void Transform::setPos(float x, float y)
{
	position.x = x;
	position.y = y;
}

void Transform::setPos(SDL_FPoint p)
{
	position.x = p.x;
	position.y = p.y;
}

SDL_FPoint Transform::getPos()
{
	return position;
}

void Transform::setVelo(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

void Transform::setVelo(SDL_FPoint p)
{
	velocity.x = p.x;
	velocity.y = p.y;
}

SDL_FPoint Transform::getVelo()
{
	return velocity;
}


void Transform::setSize(float x, float y)
{
	size.x = x;
	size.y = y;
}

void Transform::setSize(SDL_FPoint p)
{
	size.x = p.x;
	size.y = p.y;
}


SDL_FPoint Transform::getSize()
{
	return size;
}

void Transform::setSIzeMul(float m)
{
	sizeM.x = m;
	sizeM.y = m;
}

void Transform::setSIzeMul(float x, float y)
{
	sizeM.x = x;
	sizeM.y = y;
}

void Transform::setSIzeMul(SDL_FPoint p)
{
	sizeM = p;
}

SDL_FPoint Transform::getSIzeMul()
{
	return sizeM;
}

float Transform::Lerp(float value1, float value2, float amount)
{
	return float(value1 + ((float)(value2 - value1) * amount));
}