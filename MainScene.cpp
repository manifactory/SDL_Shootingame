#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"


float btn_move_timer = Timer;
bool isMoveLeft = true;

MainScene::MainScene()
{
	PlayButton = new Animation(0.0f);
	PlayButton->AddFrame("assets/P_button3.png");
	PlayButton->AddFrame("assets/P_button2.png");
	PlayButton->AddFrame("assets/P_button1.png");
	PlayButton->isPlay = false;
	PlayButton->setSIzeMul(10.0f);
	PlayButton->setPos(WindowWidth / 2 - 300.0f, WindowHeight / 2);
}

MainScene::~MainScene()
{
	SAFE_DELETE(PlayButton);
}

void MainScene::Update()
{
	if (Timer - btn_move_timer > 1.0f)
	{
		std::cout << "X : " << PlayButton->getPos().x << std::endl;
		if (isMoveLeft)
		{
			PlayButton->setVelo(1000.0f, 0.0f);
		}
		else
		{
			PlayButton->setVelo(-1000.0f, 0.0f);
		}
		isMoveLeft = !isMoveLeft;
		btn_move_timer = Timer;
	}
	PlayButton->setVelo(PlayButton->Lerp(PlayButton->getVelo(), { 0.0f, 0.0f }, DeltaTime));

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
			SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
			sceneManager->ChangeScene(new GameScene());
		}
	}
}

void MainScene::Render()
{
	SDL_SetRenderDrawColor(Game::renderer, 255, 200, 0, 255);
	PlayButton->Render();
}
