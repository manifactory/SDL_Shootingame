#pragma once
#include <locale.h>
#include "SDL_ttf.h"
#include "TextureManager.h"

class Text
{
private:
	const Uint16* text;
	TTF_Font* font;
	SDL_Color color;

	SDL_Rect src, dest;
	SDL_Texture* tex;
	SDL_Surface* text_surface;

	SDL_FPoint pos;

public:
	Text(const char* path, int pt);
	~Text();

	void setText(const wchar_t* t);
	void setColor(SDL_Color c);
	void texUpdate();

	void setPos(float x, float y);
	void setPos(SDL_FPoint p);
	SDL_FPoint getPos();

	void Render();
};

