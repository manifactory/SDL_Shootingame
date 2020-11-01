#pragma once
#include "SDL2_ttf-2.0.15/include/SDL_ttf.h"
#include "TextureManager.h"

class Text
{
private:
	std::string* text;
	TTF_Font* font;

public:
	Text();
	~Text();

	void setText(std::string* t);
};

