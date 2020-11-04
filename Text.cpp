#include "stdafx.h"
#include "Text.h"

Text::Text(const char* path, int pt)
{
	color = { 0,0,0 };
	font = TTF_OpenFont(path, pt);
	if (!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	pos = { 0.0f, 0.0f };
}

Text::~Text()
{
	TTF_CloseFont(font);
	font = nullptr;
	SDL_FreeSurface(text_surface);
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
	int width, height;

	text_surface = TTF_RenderText_Solid(font, text, color);
	tex = SDL_CreateTextureFromSurface(Game::renderer, text_surface);

	SDL_QueryTexture(tex, NULL, NULL, &width, &height);

	src = { 0, 0, width, height };
	dest = { (int)pos.x, (int)pos.y, width, height };
}

void Text::setPos(float x, float y)
{
	pos = { x,y };
}

void Text::setPos(SDL_FPoint p)
{
	pos = p;
}

SDL_FPoint Text::getPos()
{
	return pos;
}

void Text::Render()
{
	
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
