#include "stdafx.h"
#include "textureManager.h"

SDL_Texture* textureManager::loadIMGTexture(const char* path)
{
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

//void textureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
//{
//	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
//}

void textureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, double angle, SDL_Point center, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, angle, &center, flip);
}
