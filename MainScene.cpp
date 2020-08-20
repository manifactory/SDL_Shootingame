#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"



MainScene::MainScene()
{
	PlayButton = new Animation(0);
	PlayButton->AddFrame("assets/P_button3.png");
	PlayButton->AddFrame("assets/P_button2.png");
	PlayButton->AddFrame("assets/P_button1.png");
	PlayButton->isPlay = false;
	PlayButton->setSize(PlayButton->getSize()->x * 10.0f, PlayButton->getSize()->y * 10.0f);
	PlayButton->setPos(WindowWidth / 2, WindowHeight / 2);
}

MainScene::~MainScene()
{
	SAFE_DELETE(PlayButton);
}

void MainScene::Update()
{
	PlayButton->Update();

	PlayButton->SetFrame(0);
	if (PlayButton->pointInRect(&inputManager->getMousePos()))
	{
		PlayButton->SetFrame(1);
		if (inputManager->getEventPoll()->type == SDL_MOUSEBUTTONDOWN)
		{
			PlayButton->SetFrame(2);
		}
		if (inputManager->getEventPoll()->type == SDL_MOUSEBUTTONUP)
		{
			PlayButton->SetFrame(1);
			sceneManager->ChangeScene(new GameScene());
		}
	}
}

void MainScene::Render()
{
	SDL_SetRenderDrawColor(Game::renderer, 255, 200, 0, 255);
	PlayButton->Render();
}
