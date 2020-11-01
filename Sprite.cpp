#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(const char* path)
{
	tex = textureManager::loadIMGTexture(path);
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
	SDL_Color bgc = sceneManager->getCurrentScene()->getBGColor();
	/*textureManager::Draw(tex, srcRect, destRect);*/
	textureManager::Draw(tex, srcRect, destRect, getAngle(), { (int)getCenterByPixel().x, (int)getCenterByPixel().y }, flip);
	if (visibleRect)
	{
		SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(Game::renderer, &destRect);
		SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 255);
		SDL_RenderDrawPointF(Game::renderer, getRect().x + getCenterByPixel().x, getRect().y + getCenterByPixel().y);
	}
	SDL_SetRenderDrawColor(Game::renderer, bgc.r, bgc.g, bgc.b, bgc.a);
}
