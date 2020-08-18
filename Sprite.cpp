#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadTexture(path);

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &height, &width);

	Transform::setSize((float)width, (float)height);

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


void Sprite::Render()
{
	textureManager::Draw(tex, srcRect, destRect);
}
