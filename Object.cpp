#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	parent = nullptr;

	Transform::setSize(0, 0);
	Transform::setPos(0, 0);
	Transform::setVelo(0, 0);

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
	}

	destRect.w = getSize()->x;
	destRect.h = getSize()->y;
	destRect.x = (int)getPos()->x - destRect.w / 2;
	destRect.y = (int)getPos()->y - destRect.h / 2;


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

bool Object::pointInRect(SDL_Point* p)
{
	return SDL_PointInRect(p, &this->destRect);
}

SDL_Rect Object::getRect()
{
	return destRect;
}
