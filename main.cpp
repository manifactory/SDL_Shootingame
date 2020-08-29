#include "stdafx.h"
#include "Game.h"

double DeltaTime = 0;
double Timer = 0;

int main(int argc, char* argv[])
{
	Uint64 NOW = 0;
	Uint64 LAST = SDL_GetTicks();

	Game game;
	game.init("teestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);

	while (game.running())
	{
		NOW = SDL_GetTicks();
		DeltaTime = (double)((NOW - LAST) / 1000.0f);
		//std::cout << DeltaTime << std::endl;

		game.handleEvents();
		game.update();
		game.render();

		LAST = NOW;
	}

	game.clean();

	return 0;
}