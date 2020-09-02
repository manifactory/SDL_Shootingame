#include "stdafx.h"
#include "GameScene.h"
#include <Windows.h>

Sprite* Player;
Audio* bgm;
Audio* shoot_sound;

int shootHoleIsLeft = 1;

GameScene::GameScene()
{
	srand(GetTickCount());
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

	for (auto& obstacle : obstacleList) {
		SAFE_DELETE(obstacle);
	}

	for (auto& bullet : bulletList) {
		SAFE_DELETE(bullet);
	}
}

void GameScene::Update()
{
	timer += DeltaTime;

	if (inputManager->getKeyState(SDLK_a) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x - 10.0f, Player->getVelo()->y);
	}
	if (inputManager->getKeyState(SDLK_d) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x + 10.0f, Player->getVelo()->y);
	}
	if (inputManager->getKeyState(SDLK_w) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x, Player->getVelo()->y - 10.0f);
	}
	if (inputManager->getKeyState(SDLK_s) == KEY_ON) {
		Player->setVelo(Player->getVelo()->x, Player->getVelo()->y + 10.0f);
	}
	Player->setVelo(Player->getVelo()->x * 0.99f, Player->getVelo()->y * 0.99f);
	//std::cout << Player->getVelo()->x << ", " << Player->getVelo()->y << std::endl;

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


	
	if (timer - obstacleTimer > 0.4f) {
		obstacleTimer = timer;
		obstacleList.push_back(new Sprite("assets/a.png"));
		obstacleList.back()->setPos(rand() % WindowWidth, 0.0f);
		obstacleList.back()->setSize(obstacleList.back()->getSize()->x * 0.1f, obstacleList.back()->getSize()->y * 0.1f);
		obstacleList.back()->setVelo(0, 200);
	}

	if (inputManager->getKeyState(SDLK_SPACE) == KEY_ON) {
		if (timer - bulletTimer > 0.05f) {
			bulletTimer = timer;
			bulletList.push_back(new Sprite("assets/splashbullet.png"));
			bulletList.back()->setPos(Player->getPos()->x + 15.0f * shootHoleIsLeft, Player->getPos()->y-20.0f);
			Player->setVelo(Player->getVelo()->x + 500.0f * -shootHoleIsLeft, Player->getVelo()->y +20.0f);
			shootHoleIsLeft *= -1;
			bulletList.back()->setVelo(0, -2000 + rand() % 50);
		}
	}
	if (obstacleList.size() != 0)
		for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
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
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
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
