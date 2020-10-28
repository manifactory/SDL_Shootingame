#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	parent = nullptr;

	srcRect.w = srcRect.h = 0;
	srcRect.x = srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = destRect.y = 0;
}

Object::~Object()
{
}

void Object::Update()
{
	Transform::update();

	if (parent != nullptr) {
		this->setPos(parent->getPos());
		this->setVelo(parent->getVelo());
		this->setSize(parent->getSize());
		this->setSIzeMul(parent->getSIzeMul());
		this->setCenter(parent->getCenter());
		this->setAngle(parent->getAngle());
	}

	destRect.w = getSize().x * getSIzeMul().x;
	destRect.h = getSize().y * getSIzeMul().y;
	destRect.x = getPos().x - destRect.w / 2;
	destRect.y = getPos().y - destRect.h / 2;

	setCenter(destRect.w / 2, destRect.h / 2);

	for (auto& child : childList) {
		child->Update();
	}
}

void Object::Render()
{
}

void Object::setParent(Object* parent)
{
	this->parent = parent;
}


void Object::AddChild(Object* child)
{
	childList.push_back(child);
	child->parent = this;
}

void Object::RemoveChild(Object* child)
{
	childList.remove(child);
	child->parent = nullptr;
}


bool Object::intersectRect(SDL_Rect* target)
{
	SDL_Rect r;
	return SDL_IntersectRect(&this->destRect, target, &r);
}

bool Object::pointInRect(SDL_FPoint* p)
{
	SDL_Point p1;
	p1.x = p->x;
	p1.y = p->y;
	return SDL_PointInRect(&p1, &this->destRect);
}

bool Object::pointInRect(SDL_Point* p)
{
	return SDL_PointInRect(p, &this->destRect);
}

SDL_Rect Object::getRect()
{
	return destRect;
}
