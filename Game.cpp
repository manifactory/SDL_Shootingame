#include "stdafx.h"
#include "Game.h"
#include "Sprite.h"
#include "MainScene.h"
#include "GameScene.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

InputManager* inputManager;
SceneManager* sceneManager;

Scene* mainScene;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialised" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	inputManager = new InputManager(&Game::event);
	sceneManager = new SceneManager();

	mainScene = new MainScene();

	sceneManager->ChangeScene(mainScene);
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	inputManager->keyEventUpdate();
}

void Game::update()
{
	inputManager->keyStateUpdate();
	sceneManager->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	sceneManager->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}