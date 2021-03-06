#include "stdafx.h"
#include "InputManager.h"
#include "SDL.h"

InputManager::InputManager(SDL_Event* event)
{
	this->eventPool = event;
	for (int i = 0; i < 123; i++) {
		keyEvent[i] = false;
		beforeKey[i] = 0;
		currentKey[i] = 0;
	}
}

InputManager::~InputManager()
{
}

void InputManager::updateKeyEvent()
{
	if (eventPool->type == SDL_KEYDOWN) {
		if (eventPool->key.keysym.sym < 123)
			keyEvent[eventPool->key.keysym.sym] = true;
	}
	if (eventPool->type == SDL_KEYUP) {
		if (eventPool->key.keysym.sym < 123)
			keyEvent[eventPool->key.keysym.sym] = false;
	}
}

void InputManager::updateKeyState()
{
	for (int i = 0; i < 123; i++) {
		beforeKey[i] = currentKey[i];
		currentKey[i] = keyEvent[i];
	}
	updateMouseButtonState();
}

int InputManager::getKeyState(int sdlk)
{
	if (beforeKey[sdlk] && currentKey[sdlk]) {
		return KEY_ON;
	}
	else if (!beforeKey[sdlk] && currentKey[sdlk]) {
		return KEY_DOWN;
	}
	else if (beforeKey[sdlk] && !currentKey[sdlk]) {
		return KEY_UP;
	}
	else {
		return KEY_NONE;
	}
}

void InputManager::updateMouseButtonState()
{
	if (eventPool->type == SDL_MOUSEBUTTONDOWN)
	{
		mouseButtonPress = true;
	}
	if (eventPool->type == SDL_MOUSEBUTTONUP)
	{
		mouseButtonPress = false;
	}
}

int InputManager::getMouseButtonState()
{
	return mouseButtonPress;
}

SDL_Point InputManager::getMousePos()
{
	SDL_Point mousePos;
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	return mousePos;
}

SDL_Event* InputManager::getEventPoll()
{
	return eventPool;
}
