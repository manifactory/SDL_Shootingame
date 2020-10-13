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
};

class GameScene :
	public Scene
{
private:
	std::list<Sprite*> bulletList;
	std::list<Obstacle*> obstacleList;

	float timer;
	float obstacleTimer;
	float bulletTimer;
public:
	GameScene();
	~GameScene();

	void Update();
	void Render();
};
