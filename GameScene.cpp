#include "stdafx.h"
#include "GameScene.h"
#include "DeltaTime.h"
#include <Windows.h>

Sprite* Player;
Audio* bgm;
Audio* shoot_sound;

DeltaTime* dTIme;

GameScene::GameScene()
{
	srand(GetTickCount());

	dTIme = new DeltaTime();
	timer = obstacleTimer = bulletTimer = 0;

	Player = new Sprite("assets/player.png");
	Player->setPos(WindowWidth/2,WindowHeight/2);
	Player->setSize(Player->getSize()->x*0.06f, Player->getSize()->y*0.06f);

	//bgm = new Audio("assets/Taishi - bluefieldcreator (152kbit_Opus).wav", true, 2048);
	//bgm->Play();
}

GameScene::~GameScene()
{
	SAFE_DELETE(Player);
	//SAFE_DELETE(bgm);
	SAFE_DELETE(dTIme);

	for (auto& obstacle : obstacleList) {
		SAFE_DELETE(obstacle);
	}

	for (auto& bullet : bulletList) {
		SAFE_DELETE(bullet);
	}
}

void GameScene::Update()
{
	dTIme->updateDeltaTime();
	timer += dTIme->getDeltaTime();

	if (inputManager->getKeyState(SDLK_a) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x - 2.0f, Player->getVelo()->y);
	}
	if (inputManager->getKeyState(SDLK_d) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x + 2.0f, Player->getVelo()->y);
	}
	if (inputManager->getKeyState(SDLK_w) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x, Player->getVelo()->y - 2.0f);
	}
	if (inputManager->getKeyState(SDLK_s) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x, Player->getVelo()->y + 2.0f);
	}
	Player->setVelo(Player->getVelo()->x * 0.98f, Player->getVelo()->y * 0.98f);

	Player->Update();

	if (Player->getPos()->x + Player->getSize()->x/2 > WindowWidth) {
		Player->setVelo(0, Player->getVelo()->y);
		Player->setPos(WindowWidth - Player->getSize()->x/2, Player->getPos()->y);
	}
	if (Player->getPos()->x - Player->getSize()->x / 2 < 0) {
		Player->setVelo(0, Player->getVelo()->y);
		Player->setPos(0+ Player->getSize()->x / 2, Player->getPos()->y);
	}
	if (Player->getPos()->y + Player->getSize()->y / 2 > WindowHeight) {
		Player->setVelo(Player->getVelo()->x, 0);
		Player->setPos(Player->getPos()->x, WindowHeight - Player->getSize()->y/2);
	}
	if (Player->getPos()->y - Player->getSize()->y / 2 < 0) {
		Player->setVelo(Player->getVelo()->x, 0);
		Player->setPos(Player->getPos()->x, 0 + Player->getSize()->y/2);
	}

	if (timer - obstacleTimer > 400.0f) {
		obstacleTimer = timer;
		obstacleList.push_back(new Sprite("assets/a.png"));
		obstacleList.back()->setPos(rand() % WindowWidth, 0.0f);
		obstacleList.back()->setSize(obstacleList.back()->getSize()->x * 0.1f, obstacleList.back()->getSize()->y * 0.1f);
		obstacleList.back()->setVelo(0, (rand() % 3000)/1000 +1);
	}

	if (inputManager->getKeyState(SDLK_SPACE) == KEY_ON) {
		if (timer - bulletTimer > 50.0f) {
			bulletTimer = timer;
			bulletList.push_back(new Sprite("assets/splashbullet.png"));
			bulletList.back()->setPos(Player->getPos());
			bulletList.back()->setVelo(0, -20.0f);
		}
	}
	if (obstacleList.size() != 0)
		for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
			(*iter)->setVelo(-Player->getVelo()->x / ((*iter)->getVelo()->y + 5), (*iter)->getVelo()->y);
			(*iter)->Update();

			if (((*iter)->getPos()->y > WindowHeight + (*iter)->getSize()->y)) {

				SAFE_DELETE(*iter);
				iter=obstacleList.erase(iter);
			}
			else if(Player->intersectRect(&(*iter)->getRect())){
				SAFE_DELETE(*iter);
				iter = obstacleList.erase(iter);
			}
			else {
				for (auto iter_b = bulletList.begin(); iter_b != bulletList.end(); iter_b++) {
					if ((*iter)->intersectRect(&(*iter_b)->getRect())) {
						SAFE_DELETE(*iter);
						iter = obstacleList.erase(iter);
						break;
					}
				}
			}
			if (iter == obstacleList.end()) {
				break;
			}
		}

	if(bulletList.size()!=0)
		for (auto iter = bulletList.begin(); iter != bulletList.end(); iter++) {
			(*iter)->Update();

			if ((*iter)->getPos()->y < 0 - (*iter)->getSize()->y) {

				SAFE_DELETE(*iter);
				iter=bulletList.erase(iter);

				if (iter == bulletList.end()) {
					break;
				}
			}
		}

	Player->Update();

}

void GameScene::Render()
{
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	for (auto bullet : bulletList)
	{
		bullet->Render();
	}
	for (auto obstacle : obstacleList)
	{
		obstacle->Render();
	}
	Player->Render();
}
