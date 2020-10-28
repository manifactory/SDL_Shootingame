#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadTexture(path);
	flip = SDL_FLIP_NONE;

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	Transform::setSize((float)width, (float)height);

	srcRect.w = (float)width;
	srcRect.h = (float)height;

	destRect.w = getSize().x;
	destRect.h = getSize().y;

	setCenter(destRect.w / 2, destRect.h / 2);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(tex);
	tex = nullptr;
}

void Sprite::setFlip(SDL_RendererFlip f)
{
	flip = f;
}

SDL_RendererFlip Sprite::getFlip()
{
	return flip;
}


void Sprite::Render()
{
	/*textureManager::Draw(tex, srcRect, destRect);*/
	textureManager::Draw(tex, srcRect, destRect, getAngle(), { (int)getCenter().x, (int)getCenter().y }, flip);
}
