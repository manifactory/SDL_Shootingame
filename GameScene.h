#pragma once
#include "Scene.h"
#include "Audio.h"
#include <list>
#include "Animation.h"


class Obstacle :
	public Animation
{
private:
	int hp;

public:
	Obstacle(float frameTime) : Animation(frameTime)
	{
		hp = 10;
	};
	~Obstacle() {};

	int getDamage(int amount)
	{
		hp -= amount;
		return hp;
	}

	void setHP(int amount)
	{
		hp = amount;
	}

	int getHP()
	{
		return hp;
	}

	void getKnockbackBySize()
	{
		this->setVelo(this->getVelo().x, this->getVelo().y - (4.0f - this->getSizeMul().x) * 5.0f);
	}
};

class GameScene :
	public Scene
{
private:
	std::list<Sprite*> bulletList;
	std::list<Obstacle*> obstacleList;

	Sprite* Player;
	Sprite* Scope;

	Audio* bgm;
	Audio* shoot_sound;
	Audio* hit_sound;
	Audio* Explosion_sound;
	Audio* asteroid_jump;

	int shootHoleIsLeft = 1;

	float moveSpeed = 3000.0f;
	float moveDrag = 5.0f;

	float shootInterval = 0.01f;
	float bulletSpeed = 3000.0f;

	float obstacleInterval = 0.2f;

	float obstacleTimer;
	float bulletTimer;

public:
	GameScene();
	~GameScene();

	void Update();
	void Render();
};
