#include "stdafx.h"
#include "Text.h"

Text::Text(const char* path, int pt)
{
	color = { 0,0,0 };
	font = TTF_OpenFont(path, pt);
}

Text::~Text()
{
	TTF_CloseFont(font);
	font = nullptr;
}

void Text::setText(const char* t)
{
	text = t;
	texUpdate();
}

void Text::setColor(SDL_Color c)
{
	color = c;
	texUpdate();
}

void Text::texUpdate()
{
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text, color);
	tex = SDL_CreateTextureFromSurface(Game::renderer, text_surface);
	SDL_FreeSurface(text_surface);

	int width, height;
	SDL_QueryTexture(tex, NULL, NULL, &width, &height);
	src, dest = { 0,0,width,height };
}

void Text::Render()
{
	
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
