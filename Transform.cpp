#include "Transform.h"

Transform::Transform()
{
	position = new Vector2D();
	velocity = new Vector2D();
}

Transform::~Transform()
{
	delete(position);
	delete(velocity);
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
