#include "textureManager.h"

SDL_Texture* textureManager::loadTexture(const char* path)
{
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void textureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
