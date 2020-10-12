#include "stdafx.h"
#include "Game.h"
#include "Windows.h"

double DeltaTime;
float Timer;

float s_Timer = 0.0f;

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

		Timer += (float)DeltaTime;
		if ((Timer - s_Timer) >= 1.0f)
		{
			std::cout << "FPS : " << (1.0f / (float)(DeltaTime * 1000000))*1000.0f << std::endl;
			s_Timer = Timer;
		}

		game.handleEvents();
		game.update();
		game.render();

	}

	game.clean();

	return 0;
}