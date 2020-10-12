#include "stdafx.h"
#include "Particle.h"

Particle::Particle()
{
}

Particle::~Particle()
{
}

void Particle::Add(int amount, particleProp form)
{
	for (int i = 0; i < amount; i++)
		this->pArray.push_back(form);
}
