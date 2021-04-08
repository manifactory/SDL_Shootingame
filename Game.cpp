#include "stdafx.h"
#include "Game.h"
#include "Sprite.h"
#include "MainScene.h"
#include "GameScene.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

InputManager* inputManager;
SceneManager* sceneManager;

int sound_channel = 0;

SDL_FPoint cameraPos = { 0.0f,0.0f };

SDL_Rect windowViewRect;

bool visibleRect = false;

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
			int w, h;
			std::cout << "Window created";
			SDL_GetWindowSize(window, &w, &h);
			std::cout << '(' << w << ',' << h << ')' << std::endl;
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

	if (TTF_Init() == -1)
	{
		isRunning = false;
	}
	
	inputManager = new InputManager(&Game::event);
	sceneManager = new SceneManager();

	sceneManager->ChangeScene(new MainScene());

	windowViewRect.w = WindowWidth;
	windowViewRect.h = WindowHeight;
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

	inputManager->updateKeyEvent();
}

void Game::update()
{
	if (event.type == SDL_KEYDOWN)
		if (event.key.keysym.sym == SDLK_F3)
			visibleRect = !visibleRect;
	windowViewRect.x = -(float)cameraPos.x;
	windowViewRect.y = -(float)cameraPos.y;

	inputManager->updateKeyState();
	sceneManager->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &windowViewRect);
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
