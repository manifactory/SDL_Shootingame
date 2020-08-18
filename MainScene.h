#pragma once
#include "Scene.h"
#include "Animation.h"

class MainScene :
	public Scene
{
private:
	Sprite* Title;
	Animation* PlayButton;
	Sprite* SettingButton;
public:
	MainScene();
	~MainScene();

	void Update();
	void Render();
};

