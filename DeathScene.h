#pragma once
#include "Scene.h"
class DeathScene :
	public Scene
{
public:
	DeathScene();
	~DeathScene();
	void Update();
	void Render();
};

