#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadTexture(path);

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	Transform::setSize((float)width, (float)height);

	srcRect.w = (float)width;
	srcRect.h = (float)height;

	destRect.w = getSize().x;
	destRect.h = getSize().y;
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
