#include "stdafx.h"
#include "MainScene.h"
#include "GameScene.h"




MainScene::MainScene()
{
	SDL_SetRenderDrawColor(Game::renderer, 255, 200, 0, 255);
	std::string b[3] = { "assets/P_button3.png" , "assets/P_button2.png" , "assets/P_button1.png" };
	PlayButton = new Button(b, 0.0f);
	PlayButton->isPlay = false;
	PlayButton->setSIzeMul(10.0f);
	PlayButton->setPos(WindowWidth / 2 - 500.0f, WindowHeight / 2);
	PlayButton->setVelo(0.0f, 0.0f);

	btn_move_timer = Timer;
	isMoveLeft = true;
}

MainScene::~MainScene()
{
	SAFE_DELETE(PlayButton);
}

void MainScene::Update()
{

	if (inputManager->getKeyState(SDLK_a) == KEY_ON) {
		PlayButton->setAngle(PlayButton->getAngle() + 100.0f * DeltaTime);
	}
	if (inputManager->getKeyState(SDLK_d) == KEY_ON) {
		PlayButton->setAngle(PlayButton->getAngle() - 100.0f * DeltaTime);
	}
	

	if (Timer - btn_move_timer > 1.0f)
	{
		std::cout << "X : " << PlayButton->getPos().x << " Y : " << PlayButton->getPos().y << std::endl;
		isMoveLeft = !isMoveLeft;
		btn_move_timer = Timer;
	}
	PlayButton->setPos(PlayButton->Lerp(PlayButton->getPos(), { (float)WindowWidth / 2 - 500.0f + 1000.0f * (float)isMoveLeft, (float)WindowHeight / 2 }, (float)DeltaTime));
	


	PlayButton->Update();

	if (PlayButton->getButtonState())
	{
		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
		sceneManager->ChangeScene(new GameScene());
	}
}

void MainScene::Render()
{
	PlayButton->Render();
}
