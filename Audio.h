#pragma once
#include "SDL.h"
#include "SDL_mixer.h"

class Audio
{
private:
	Mix_Music* music;
	Mix_Chunk* wave;

	bool isMusic;
public:
	Audio(const char* path, bool isMusic, int chunkSize);
	~Audio();

	void Play();
	void Pause();
	void Stop();
};

