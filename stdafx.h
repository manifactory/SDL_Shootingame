#pragma once

#define WindowHeight 800
#define WindowWidth 800

#define SAFE_REALEASE(p) {if(p) {p->Release(); (p) = NULL;}}
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[](p); (p) = nullptr;}}


#include<iostream>
#include "stdafx.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include "InputManager.h"
#include "TextureManager.h"
#include "SceneManager.h"

#include "Game.h"


extern SceneManager* sceneManager;
extern InputManager* inputManager;

extern double DeltaTime;
extern float Timer;

extern int sound_channel;

extern SDL_FPoint cameraPos;
extern SDL_Rect windowViewRect;

extern bool visibleRect;

