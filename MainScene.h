#pragma once
#include "Scene.h"
#include "Animation.h"
#include "GUI.h"

class MainScene :
	public Scene
{
private:
	float btn_move_timer;
	bool isMoveLeft;
	Sprite* Title;
	Button* PlayButton;
public:
	MainScene();
	~MainScene();

	void Update();
	void Render();
};

