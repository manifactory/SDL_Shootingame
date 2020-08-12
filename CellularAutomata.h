#pragma once
#include "SDL.h"

typedef struct vector_2d {
	float x;
	float y;
}vector_2d;

typedef struct particle_t {
	int id;
	float life_time;
	vector_2d velocity;
	SDL_Color color;
	bool has_been_updated;
}particle_t;

class CellularAutomata
{
public:
	CellularAutomata();
	~CellularAutomata();

	void init();
	particle_t update();
	void draw();

private:

};