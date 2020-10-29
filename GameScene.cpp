#include "stdafx.h"
#include "GameScene.h"
#include "MainScene.h"
#include <Windows.h>


GameScene::GameScene()
{
	srand(GetTickCount());
	Timer = obstacleTimer = bulletTimer = 0;

	Player = new Sprite("assets/player.png", 1.5f);
	Player->setPos(WindowWidth/2,WindowHeight/2);

	//Scope = new Sprite();

	bgm = new Audio("assets/bgm.ogg", true, 2048);
	bgm->Play();

	shoot_sound = new Audio("assets/shoot1.wav", false, 2048);
	shoot_sound->setVolume(10);

	hit_sound = new Audio("assets/hit.wav", false, 2048);
	hit_sound->setVolume(15);

	Explosion_sound = new Audio("assets/Explosion.wav", false, 2048);
	Explosion_sound->setVolume(20);

	asteroid_jump = new Audio("assets/jump.wav", false, 2048);
	asteroid_jump->setVolume(20);
}

GameScene::~GameScene()
{
	SAFE_DELETE(Player);
	SAFE_DELETE(bgm);
	SAFE_DELETE(shoot_sound);
	SAFE_DELETE(hit_sound);
	SAFE_DELETE(Explosion_sound);
	SAFE_DELETE(asteroid_jump);

	for (auto& obstacle : obstacleList) {
		SAFE_DELETE(obstacle);
	}

	for (auto& bullet : bulletList) {
		SAFE_DELETE(bullet);
	}
}

void GameScene::Update()
{

	if (inputManager->getKeyState(SDLK_a) == KEY_ON) {
		Player->setVelo(Player->getVelo().x - moveSpeed * DeltaTime, Player->getVelo().y);
	}
	if (inputManager->getKeyState(SDLK_d) == KEY_ON) {
		Player->setVelo(Player->getVelo().x + moveSpeed * DeltaTime, Player->getVelo().y);
	}
	if (inputManager->getKeyState(SDLK_w) == KEY_ON) {
		Player->setVelo(Player->getVelo().x, Player->getVelo().y - moveSpeed * DeltaTime);
	}
	if (inputManager->getKeyState(SDLK_s) == KEY_ON) {
		Player->setVelo(Player->getVelo().x, Player->getVelo().y + moveSpeed * DeltaTime);
	}
	Player->setVelo(Player->Lerp(Player->getVelo(), {0.0f, 0.0f}, DeltaTime * moveDrag));
	//std::cout << Player->getVelo().x << ", " << Player->getVelo().y << std::endl;
	

	/*if (Player->getPos().x + Player->getRect().w / 2 > WindowWidth) {
		Player->setVelo(0, Player->getVelo().y);
		Player->setPos(WindowWidth - Player->getRect().w / 2, Player->getPos().y);
	}
	else if (Player->getPos().x - Player->getRect().w / 2 < 0) {
		Player->setVelo(0, Player->getVelo().y);
		Player->setPos(0 + Player->getRect().w / 2, Player->getPos().y);
	}
	else if (Player->getPos().y + Player->getRect().h / 2 > WindowHeight) {
		Player->setVelo(Player->getVelo().x, 0);
		Player->setPos(Player->getPos().x, WindowHeight - Player->getRect().h / 2);
	}
	else if (Player->getPos().y - Player->getRect().h / 2 < 0) {
		Player->setVelo(Player->getVelo().x, 0);
		Player->setPos(Player->getPos().x, 0 + Player->getRect().h / 2);
	}
	else
	{
		Player->setPos(Player->Lerp(Player->getPos(), {(float)inputManager->getMousePos().x, (float)inputManager->getMousePos().y}, DeltaTime * moveDrag));
	}*/

	cameraPos = { Player->getPos().x - WindowWidth / 2,Player->getPos().y - WindowHeight / 2 };

	if (inputManager->getKeyState(SDLK_m) == KEY_DOWN)
	{
		bgm->Pause();
	}

	
	if (Timer - obstacleTimer > obstacleInterval) {
		obstacleTimer = Timer;
		obstacleList.push_back(new Obstacle(0.3f));
		obstacleList.back()->AddFrame("assets/a.png");
		obstacleList.back()->AddFrame("assets/d.png");
		/*if (rand() % 2 - 1)
		{
			obstacleList.back()->AddFrame("assets/c.png");
			obstacleList.back()->AddFrame("assets/d.png");
		}
		else
		{
			obstacleList.back()->AddFrame("assets/a.png");
			obstacleList.back()->AddFrame("assets/b.png");
		}*/
		obstacleList.back()->isPlay = false;

		float O_Size = ((float)(rand() % 200) / 100.0f + 1.0f);
		obstacleList.back()->setSizeMul(O_Size);
		obstacleList.back()->Update();
		obstacleList.back()->setHP((int)O_Size * 50);
		obstacleList.back()->setPos(rand() % WindowWidth, -obstacleList.back()->getRect().h);
		obstacleList.back()->setVelo(rand() % 40 - 20 , rand() % 500 + 50);
	}

	if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(SDL_BUTTON_LEFT)) {
		if (Timer - bulletTimer > shootInterval) {
			bulletTimer = Timer;
			bulletList.push_back(new Sprite("assets/bullet.png"));
			bulletList.back()->setSizeMul(6.0f);
			bulletList.back()->setPos(Player->getPos().x + ((rand()%100)/10.0f+10.0f) * shootHoleIsLeft, Player->getPos().y- Player->getRect().h/4);
			bulletList.back()->setVelo(0.0f, -bulletSpeed);
			//Player->setVelo(Player->getVelo().x + 500.0f * -shootHoleIsLeft, Player->getVelo().y +20.0f);
			shootHoleIsLeft *= -1;
			shoot_sound->Play();
		}
	}

	Player->Update();

	if (bulletList.size() != 0)
		for (auto iter = bulletList.begin(); iter != bulletList.end(); iter++) {
			(*iter)->setVelo((*iter)->getVelo().x, (*iter)->Lerp((*iter)->getVelo().y, 0.0f, DeltaTime * 7.0f));
			(*iter)->setSizeMul((*iter)->getSizeMul().x, (*iter)->getVelo().y / -3000.0f * 6.0f);
			(*iter)->Update();

			if ((*iter)->getPos().y < 0 - (*iter)->getSize().y || (*iter)->getVelo().y > -100.0f) {

				SAFE_DELETE(*iter);
				iter = bulletList.erase(iter);

				if (iter == bulletList.end()) {
					break;
				}
			}
		}

	if (obstacleList.size() != 0)
		for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
			(*iter)->setAngle((*iter)->getAngle() + 100.0f * DeltaTime);
			(*iter)->Update();

			if (((*iter)->getPos().y > WindowHeight + (*iter)->getSize().y * (*iter)->getSizeMul().y) || ((*iter)->getPos().y < - (*iter)->getSize().y * (*iter)->getSizeMul().y)) {

				SAFE_DELETE(*iter);
				iter = obstacleList.erase(iter);
				asteroid_jump->Play();

			}
			else if(Player->intersectRect(&(*iter)->getRect())){

				hit_sound->Play();

				SAFE_DELETE(*iter);
				iter = obstacleList.erase(iter);

			}
			else {
				for (auto iter_b = bulletList.begin(); iter_b != bulletList.end(); iter_b++) {
					if ((*iter)->intersectRect(&(*iter_b)->getRect())) {

						(*iter)->SetFrame(1);
						(*iter)->isPlay = true;
						(*iter)->getKnockbackBySize();
						hit_sound->Play();
						if ((*iter)->getDamage(1)<=0)
						{
							Explosion_sound->Play();
							SAFE_DELETE(*iter);
							iter = obstacleList.erase(iter);

							if (iter == obstacleList.end())
								break;
						}

						SAFE_DELETE(*iter_b);
						iter_b = bulletList.erase(iter_b);

						if (iter_b == bulletList.end())
							break;
					}
				}
			}
			if (iter == obstacleList.end()) {
				break;
			}
		}


	if (inputManager->getKeyState(SDLK_ESCAPE) == KEY_ON)
	{
		sceneManager->ChangeScene(new MainScene());
	}
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
