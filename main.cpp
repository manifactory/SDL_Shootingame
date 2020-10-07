#include "stdafx.h"
#include "Game.h"
#include "Windows.h"

double DeltaTime;

int main(int argc, char* argv[])
{

	LARGE_INTEGER beforeInterval, currentInterval, Frequency;

	QueryPerformanceCounter(&beforeInterval);
	QueryPerformanceCounter(&currentInterval);
	QueryPerformanceFrequency(&Frequency);

	Game game;
	game.init("teestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);


	while (game.running())
	{

		QueryPerformanceCounter(&currentInterval);
		LONGLONG interval = (currentInterval.QuadPart - beforeInterval.QuadPart);
		DeltaTime = (double)interval / (double)Frequency.QuadPart;
		beforeInterval = currentInterval;

		std::cout << DeltaTime << std::endl;

		game.handleEvents();
		game.update();
		game.render();

	}

	game.clean();

	return 0;
}