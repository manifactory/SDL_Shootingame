#include "stdafx.h"
#include "GameScene.h"

Sprite* Player;
Audio* bgm;
Audio* walk_sound;

GameScene::GameScene()
{
	Player = new Sprite("assets/Sprite-0001.png");
	Player->setPos(0,0);
	Player->setSize(Player->getSize()->x * 3, Player->getSize()->y * 3);

	bgm = new Audio("assets/Taishi - bluefieldcreator (152kbit_Opus).wav", true, 2048);
}

GameScene::~GameScene()
{
	delete(Player);
	Player = nullptr;
	SAFE_DELETE(bgm);
	bgm = nullptr;
}

void GameScene::Update()
{
	if (inputManager->getKeyState(SDLK_SPACE) == KEY_DOWN) {
		bgm->Play();
	}
	if (inputManager->getKeyState(SDLK_a) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x - 5.0f, Player->getVelo()->y);
	}
	if (inputManager->getKeyState(SDLK_d) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x + 5.0f, Player->getVelo()->y);
	}
	if (inputManager->getKeyState(SDLK_w) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x, Player->getVelo()->y - 5.0f);
	}
	if (inputManager->getKeyState(SDLK_s) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x, Player->getVelo()->y + 5.0f);
	}
	Player->setVelo(Player->getVelo()->x * 0.8f, Player->getVelo()->y * 0.8f);

	Player->Update();

}

void GameScene::Render()
{
	Player->Render();
}
