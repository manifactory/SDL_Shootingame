#pragma once
#include "Scene.h"
class MainScene :
	public Scene
{
private:
	Sprite* Title;
	Sprite* PlayButton;
	Sprite* SettingButton;
public:
	MainScene();
	~MainScene();

	void Update();
	void Render();
};

