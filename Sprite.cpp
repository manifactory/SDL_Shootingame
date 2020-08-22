#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadTexture(path);

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	Transform::setSize((float)width, (float)height);

	srcRect.w = width;
	srcRect.h = height;
	srcRect.x = srcRect.y = 0;

	destRect.w = getSize()->x;
	destRect.h = getSize()->y;
	destRect.x = destRect.y = 0;
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}


void Sprite::Render()
{
	textureManager::Draw(tex, srcRect, destRect);
}
