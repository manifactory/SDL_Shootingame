#include "Sprite.h"

Sprite::Sprite(const char* path, int x, int y, int w, int h)
{
	Transform::setPos(x, y);
	
	

	tex = textureManager::loadTexture(path);

	SDL_QueryTexture(tex, NULL, NULL, &srcRect.w, &srcRect.h);
	srcRect.x = srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = destRect.y = 0;
}

Sprite::~Sprite()
{
	
}

void Sprite::Update()
{

}

void Sprite::Render()
{
	textureManager::Draw(tex, srcRect, destRect);
}
