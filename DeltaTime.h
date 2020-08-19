#pragma once
#include "SDL.h"

class DeltaTime {
private:
    float beforeTime;
    float currentTime;
    float dTime;

public:
    DeltaTime();
    ~DeltaTime();

    void updateDeltaTime();
    float getDeltaTime();
};