#include "stdafx.h"
#include "Game.h"
#include "Windows.h"

double DeltaTime = 0;
double Timer = 0;

int main(int argc, char* argv[])
{
	LARGE_INTEGER NOW, LAST, frequency;

	QueryPerformanceCounter(&LAST);
	QueryPerformanceFrequency(&frequency);

	std::cout<<(double)frequency.QuadPart << std::endl;

	Game game;
	game.init("teestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);

	while (game.running())
	{
		LAST = NOW;
		QueryPerformanceCounter(&NOW);
		DeltaTime = (double)(NOW.QuadPart - LAST.QuadPart) / (double)frequency.QuadPart;
		//std::cout << DeltaTime << std::endl;

		game.handleEvents();
		game.update();
		game.render();
	}

	game.clean();

	return 0;
}