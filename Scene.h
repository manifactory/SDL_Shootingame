#pragma once
#include "Sprite.h"
#include <list>

class Scene
{
private:
	SDL_Color backgroundColor;

public:

	Scene();
	virtual ~Scene();

	virtual void Update();
	virtual void Render();

	void setBGColor(SDL_Color bgColor);
	SDL_Color getBGColor();
};

