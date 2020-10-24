#pragma once
#include "Sprite.h"
#include <list>

class Scene
{

public:

	Scene();
	virtual ~Scene();

	virtual void Update();
	virtual void Render();


};

