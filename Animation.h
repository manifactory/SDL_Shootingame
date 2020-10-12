#pragma once
#include "Sprite.h"
#include <vector>

class Animation :
    public Object
{
private:
    int maxFrame;
    int currentFrame;

    float frameTime;
    float timeChecker;

    std::vector<Sprite*> spriteVector;
public:
    bool isPlay;
    bool isRepeat;

    Animation();
    Animation(float frameTime);
    ~Animation();

    void Update();
    void Render();

    void AddFrame(const char* path);

    void SetFrame(int frame);
    int GetFrame();
};
