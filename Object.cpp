#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	Transform::setSize(0, 0);
	Transform::setPos(0, 0);
	Transform::setVelo(0, 0);

	srcRect.w = Transform::getSize()->x;
	srcRect.h = Transform::getSize()->y;
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

	srcRect.h = (int)getSize()->x;;
	srcRect.w = (int)getSize()->y;;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = (int)getPos()->x - srcRect.w / 2;
	destRect.y = (int)getPos()->y - srcRect.h / 2;

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