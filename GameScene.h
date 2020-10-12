#pragma once
#include "Scene.h"
#include "Audio.h"
#include <list>
#include "Animation.h"

class GameScene :
	public Scene
{
private:
	std::list<Sprite*> bulletList;
	std::list<Animation*> obstacleList;

	float timer;
	float obstacleTimer;
	float bulletTimer;
public:
	GameScene();
	~GameScene();

	void Update();
	void Render();
};

