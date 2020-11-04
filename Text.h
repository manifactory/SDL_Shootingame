#pragma once
#include "SDL_ttf.h"
#include "TextureManager.h"

class Text
{
private:
	const char* text;
	TTF_Font* font;
	SDL_Color color;

	SDL_Rect src, dest;
	SDL_Texture* tex;
	SDL_Surface* text_surface;

	SDL_FPoint pos;

public:
	Text(const char* path, int pt);
	~Text();

	void setText(const char* t);
	void setColor(SDL_Color c);
	void texUpdate();

	void setPos(float x, float y);
	void setPos(SDL_FPoint p);
	SDL_FPoint getPos();

	void Render();
};

