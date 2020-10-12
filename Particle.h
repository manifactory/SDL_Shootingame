#pragma once
#include "SDL.h"
#include <vector>


struct particleProp
{
	SDL_FPoint pos, velo;
	float mass;
	float life;
};

class Particle
{
	std::vector<particleProp> pArray;

public:
	Particle();
	~Particle();

	void Add(int amount, particleProp form);
	void Update();
	void Render();
};

