#include "stdafx.h"
#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
	beforeTime = dTime = 0;
	currentTime = SDL_GetTicks();
}

DeltaTime::~DeltaTime()
{
}

void DeltaTime::updateDeltaTime()
{
	beforeTime = currentTime;
	currentTime = SDL_GetTicks();
	dTime = currentTime - beforeTime;
}

float DeltaTime::getDeltaTime()
{
	return dTime;
}
