#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
	position.x = position.y = 0.0f;
	velocity.x = velocity.y = 0.0f;
	size.x = size.y = 0.0f;
	sizeM.x = sizeM.y = 1.0f;
	center.x = center.y = 0.5f;

	angle = 0;
}

Transform::~Transform()
{
}

void Transform::update()
{
	position.x += ((float)velocity.x * (float)DeltaTime);
	position.y += ((float)velocity.y * (float)DeltaTime);
	//add torque, rotation per minuite;
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

void Transform::setSizeMul(float m)
{
	sizeM.x = m;
	sizeM.y = m;
}

void Transform::setSizeMul(float x, float y)
{
	sizeM.x = x;
	sizeM.y = y;
}

void Transform::setSizeMul(SDL_FPoint p)
{
	sizeM = p;
}

SDL_FPoint Transform::getSizeMul()
{
	return sizeM;
}

void Transform::setCenter(float x, float y)
{
	center.x = x;
	center.y = y;
}

void Transform::setCenter(SDL_FPoint p)
{
	center.x = p.x;
	center.y = p.y;
}

SDL_FPoint Transform::getCenter()
{
	return center;
}

void Transform::setCenterByPixel(float x, float y)
{
	center.x = size.x * sizeM.x / x;
	center.y = size.y * sizeM.y / y;
}

void Transform::setCenterByPixel(SDL_FPoint p)
{
	center.x = size.x * sizeM.x / p.x;
	center.y = size.y * sizeM.y / p.y;
}

SDL_FPoint Transform::getCenterByPixel()
{
	return { size.x * sizeM.x * center.x, size.y * sizeM.y * center.y };
}

void Transform::setAngle(double a)
{
	angle = a;
}

double Transform::getAngle()
{
	return angle;
}

float Transform::Lerp(float value1, float value2, float amount)
{
	return float(value1 + ((float)(value2 - value1) * amount));
}

SDL_FPoint Transform::Lerp(SDL_FPoint point1, SDL_FPoint point2, float amount)
{
	return { float(point1.x + ((float)(point2.x - point1.x) * amount)) , float(point1.y + ((float)(point2.y - point1.y) * amount)) };
}
