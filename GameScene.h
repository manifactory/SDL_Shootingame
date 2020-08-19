#pragma once
#include "Scene.h"
#include "Audio.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void Update();
	void Render();
};

