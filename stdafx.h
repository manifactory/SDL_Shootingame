#pragma once

#define WindowHeight 720
#define WindowWidth 1280

#define SAFE_REALEASE(p) {if(p) {p->Release(); (p) = NULL;}}
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[](p); (p) = nullptr;}}

#include "InputManager.h"
#include "TextureManager.h"
#include "SceneManager.h"

extern SceneManager* sceneManager;
extern InputManager* inputManager;

extern double DeltaTime;
extern float Timer;

