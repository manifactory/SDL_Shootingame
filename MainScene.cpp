#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"




MainScene::MainScene()
{
	std::string b[3] = { "assets/P_button3.png" , "assets/P_button2.png" , "assets/P_button1.png" };
	PlayButton = new Button(b, 0.0f);
	PlayButton->isPlay = false;
	PlayButton->setSIzeMul(10.0f);
	PlayButton->setPos(WindowWidth / 2 - 300.0f, WindowHeight / 2);

	btn_move_timer = Timer;
	isMoveLeft = true;
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

	if (PlayButton->getButtonState())
	{
		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
		sceneManager->ChangeScene(new GameScene());
	}
}

void MainScene::Render()
{
	SDL_SetRenderDrawColor(Game::renderer, 255, 200, 0, 255);
	PlayButton->Render();
}
