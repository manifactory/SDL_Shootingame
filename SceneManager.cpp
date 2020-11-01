#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	currentScene = nullptr;
}

SceneManager::~SceneManager()
{
	if (currentScene)
		delete(currentScene);
	currentScene = nullptr;
}

void SceneManager::Update()
{
	currentScene->Update();
}

void SceneManager::Render()
{
	currentScene->Render();
}

void SceneManager::ChangeScene(Scene* scene)
{
	if (currentScene)
		currentScene->~Scene();
	currentScene = nullptr;

	currentScene = scene;
}

Scene* SceneManager::getCurrentScene()
{
	return currentScene;
}
