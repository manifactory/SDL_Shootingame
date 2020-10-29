#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadTexture(path);
	flip = SDL_FLIP_NONE;

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	setSize((float)width, (float)height);

	srcRect.w = destRect.w = getSize().x;
	srcRect.h = destRect.h = getSize().y;
}

Sprite::Sprite(const char* path, float sizeM) : Sprite(path)
{
	setSizeMul(sizeM);

	destRect.w = getSize().x * getSizeMul().x;
	destRect.h = getSize().y * getSizeMul().y;
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

SDL_Texture* Sprite::getTexture()
{
	return tex;
}


void Sprite::Render()
{
	/*textureManager::Draw(tex, srcRect, destRect);*/
	textureManager::Draw(tex, srcRect, destRect, getAngle(), { (int)getCenterByPixel().x, (int)getCenterByPixel().y }, flip);
}
