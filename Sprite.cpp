#include "Sprite.h"

Sprite::Sprite(const char* path, int x, int y, int w, int h)
{
	tex = textureManager::loadTexture(path);

	int width, height;

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	Transform::setSize((float)width, (float)height);

	srcRect.w = Transform::getSize()->x;
	srcRect.h = Transform::getSize()->y;
	srcRect.x = srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = destRect.y = 0;

	Transform::setPos(x, y);
	Transform::setVelo(0, 0);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(tex);
}

void Sprite::Update()
{
	srcRect.h = Transform::getSize()->x;;
	srcRect.w = Transform::getSize()->y;;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = Transform::getPos()->x;
	destRect.y = Transform::getPos()->y;
}

void Sprite::Render()
{
	textureManager::Draw(tex, srcRect, destRect);
}

void Sprite::setSize(float size)
{
	Transform::setSize(Transform::getSize()->x * size, Transform::getSize()->y * size);
}