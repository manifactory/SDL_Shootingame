#include "stdafx.h"
#include "Game.h"
#include "Windows.h"

double DeltaTime;
float Timer;

float s_Timer = 0.0f;

bool isMove = false;

int main(int argc, char* argv[])
{

	LARGE_INTEGER beforeInterval, currentInterval, Frequency;

	QueryPerformanceCounter(&beforeInterval);
	QueryPerformanceCounter(&currentInterval);
	QueryPerformanceFrequency(&Frequency);

	Game game;
	game.init("teestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, 0);

    Uint8 previous_Event = 0;

	while (game.running())
	{
        //SDL_WINDOWEVENT
		/*if (game.event.type == SDL_WINDOWEVENT)
		{
            if(previous_Event != game.event.window.event)
			    switch (game.event.window.event)
			    {
                case SDL_WINDOWEVENT_SHOWN:
                    SDL_Log("Window %d shown", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_HIDDEN:
                    SDL_Log("Window %d hidden", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_EXPOSED:
                    SDL_Log("Window %d exposed", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_MOVED:
                    SDL_Log("Window %d moved to %d,%d",
                        game.event.window.windowID, game.event.window.data1,
                        game.event.window.data2);
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                    SDL_Log("Window %d resized to %dx%d",
                        game.event.window.windowID, game.event.window.data1,
                        game.event.window.data2);
                    break;
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    SDL_Log("Window %d size changed to %dx%d",
                        game.event.window.windowID, game.event.window.data1,
                        game.event.window.data2);
                    break;
                case SDL_WINDOWEVENT_MINIMIZED:
                    SDL_Log("Window %d minimized", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_MAXIMIZED:
                    SDL_Log("Window %d maximized", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_RESTORED:
                    SDL_Log("Window %d restored", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_ENTER:
                    SDL_Log("Mouse entered window %d",
                        game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_LEAVE:
                    SDL_Log("Mouse left window %d", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    SDL_Log("Window %d gained keyboard focus",
                        game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    SDL_Log("Window %d lost keyboard focus",
                        game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_CLOSE:
                    SDL_Log("Window %d closed", game.event.window.windowID);
                    break;
    #if SDL_VERSION_ATLEAST(2, 0, 5)
                case SDL_WINDOWEVENT_TAKE_FOCUS:
                    SDL_Log("Window %d is offered a focus", game.event.window.windowID);
                    break;
                case SDL_WINDOWEVENT_HIT_TEST:
                    SDL_Log("Window %d has a special hit test", game.event.window.windowID);
                    break;
    #endif
                default:
                    SDL_Log("Window %d got unknown game.event %d",
                        game.event.window.windowID, game.event.window.event);
                    break;
			    }
            previous_Event = game.event.window.event;
		}*/


		QueryPerformanceCounter(&currentInterval);
		LONGLONG interval = (currentInterval.QuadPart - beforeInterval.QuadPart);
		DeltaTime = (double)interval / (double)Frequency.QuadPart;
		beforeInterval = currentInterval;

		Timer += (float)DeltaTime;
		if ((Timer - s_Timer) >= 1.0f)
		{
			std::cout << "FPS : " << (1.0f / (float)(DeltaTime * 1000))*1000.0f << std::endl;
			s_Timer = Timer;
		}

		game.handleEvents();
		game.update();
		game.render();

	}

	game.clean();

	return 0;
}