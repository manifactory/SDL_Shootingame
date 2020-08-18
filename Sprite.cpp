#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadTexture(path);

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &height, &width);

	Transform::setSize((float)width, (float)height);
	Transform::setPos(0, 0);
	Transform::setVelo(0, 0);

	srcRect.w = Transform::getSize()->x;
	srcRect.h = Transform::getSize()->y;
	srcRect.x = srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = destRect.y = 0;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(tex);
}

void Sprite::Update()
{
	Transform::update();

	srcRect.h = (int)Transform::getSize()->x;;
	srcRect.w = (int)Transform::getSize()->y;;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = (int)Transform::getPos()->x;
	destRect.y = (int)Transform::getPos()->y;
}

void Sprite::Render()
{
	textureManager::Draw(tex, srcRect, destRect);
}

SDL_Rect Sprite::getRect()
{
	return destRect;
}


bool Sprite::intersectRect(Sprite* target)
{
	SDL_Rect r;
	return SDL_IntersectRect(&this->destRect, &target->destRect, &r);
}

bool Sprite::pointInRect(SDL_Point* p)
{
	return SDL_PointInRect(p, &this->destRect);
}
