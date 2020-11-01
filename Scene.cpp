#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	backgroundColor = { 0,0,0,255 };
}

Scene::~Scene()
{
}


void Scene::Update()
{
}

void Scene::Render()
{
	SDL_SetRenderDrawColor(Game::renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
}

void Scene::setBGColor(SDL_Color bgColor)
{
	backgroundColor = bgColor;
}

SDL_Color Scene::getBGColor()
{
	return backgroundColor;
}
