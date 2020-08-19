#include "stdafx.h"
#include "Audio.h"

Audio::Audio(const char* path, bool isMusic, int chunkSize)
{
	//Initialize SDL_mixer 
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, chunkSize) < 0) {
		std::cout<<Mix_GetError()<<std::endl;
	}
	
	this->isMusic = isMusic;

	if (isMusic)
	{
		music = Mix_LoadMUS(path);
		if (music == NULL) {
			std::cout << Mix_GetError() << std::endl;
		}
	}
	else{
		wave = Mix_LoadWAV(path);
	}

}

Audio::~Audio()
{
	if (isMusic)
	{
		Mix_FreeMusic(music);
	}
	else {
		Mix_FreeChunk(wave);
	}

	Mix_CloseAudio();
}

void Audio::Play()
{
	if (isMusic) {
			Mix_PlayMusic(music, -1);
	}
	else {
			Mix_PlayChannel(-1, wave, 0);
	}
}

void Audio::Pause()
{
	if (isMusic) {
		if (!Mix_PlayingMusic())
		{
			Mix_PlayMusic(music, -1);
		}
		else if (Mix_PausedMusic())
		{
			Mix_ResumeMusic();
		}
		else {
			Mix_PauseMusic();
		}
	}
	else {
		if (Mix_Playing(-1)) {
			Mix_PlayChannel(-1, wave, 0);
		}
		else if (Mix_Paused(-1))
		{
			Mix_Resume(-1);
		}
		else {
			Mix_Pause(-1);
		}
	}
}

void Audio::Stop()
{
	if (isMusic) {
		Mix_HaltMusic();
	}
	else {
		Mix_HaltChannel(-1);
	}
}

void Audio::setVolume(int v)
{
	if (isMusic) {
		Mix_VolumeMusic(v);
	}
	else {
		Mix_Volume(-1, v);
	}
}
