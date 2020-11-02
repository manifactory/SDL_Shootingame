#pragma once
#include "SDL2_ttf-2.0.15/include/SDL_ttf.h"
#include "TextureManager.h"

class Text
{
private:
	const char* text;
	TTF_Font* font;
	SDL_Color color;

public:
	Text(const char* path, int pt);
	~Text();

	void setText(const char* t);
	void setColor(SDL_Color c);
	void texUpdate();
	void Render();
};

