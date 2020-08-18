#pragma once
#include "Scene.h"

class SceneManager
{
private:
	Scene* currentScene;
public:
	SceneManager();
	~SceneManager();

	void Update();
	void Render();

	void ChangeScene(Scene* scene);
};

