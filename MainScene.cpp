#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"



MainScene::MainScene()
{
	PlayButton = new Sprite("assets/P_Button2.png");
	PlayButton->setSize(PlayButton->getSize()->x * 5, PlayButton->getSize()->y * 5);
	PlayButton->setPos(WindowWidth / 2 - PlayButton->getSize()->x/2, WindowHeight / 2 - PlayButton->getSize()->y/2);
	PlayButton->Update();
}

MainScene::~MainScene()
{
	SAFE_DELETE(PlayButton);
}

void MainScene::Update()
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (PlayButton->pointInRect(&inputManager->getMouseState()))
		{
			sceneManager->ChangeScene(new GameScene());
		}
	}
}

void MainScene::Render()
{
	PlayButton->Render();
}
