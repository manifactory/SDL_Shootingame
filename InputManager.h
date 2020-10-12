#pragma once
#include "SDL.h"

#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

class InputManager
{
private:
	SDL_Event* eventPool;
	bool keyEvent[123];
	bool beforeKey[123];
	bool currentKey[123];
public:
	InputManager(SDL_Event* event);
	~InputManager();

	void keyEventUpdate();
	void keyStateUpdate();
	int getKeyState(int sdlk);

	SDL_Point getMousePos();

	SDL_Event* getEventPoll();
};
