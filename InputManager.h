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

	bool mouseButtonPress = false;
public:
	InputManager(SDL_Event* event);
	~InputManager();

	void updateKeyEvent();
	void updateKeyState();
	int getKeyState(int sdlk);
	void updateMouseButtonState();
	int getMouseButtonState();

	SDL_Point getMousePos();

	SDL_Event* getEventPoll();
};
