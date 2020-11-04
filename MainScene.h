#pragma once
#include "Scene.h"
#include "Animation.h"
#include "GUI.h"
#include "Text.h"

class MainScene :
	public Scene
{
private:
	float btn_move_timer;
	bool isMoveLeft;
	Text* Title;
	Button* PlayButton;

public:
	MainScene();
	~MainScene();

	void Update();
	void Render();
};

