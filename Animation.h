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
    
public:
    bool isPlay;
    bool isRepeat;

    std::vector<Sprite*> spriteVector;

    Animation(float frameTime);
    ~Animation();

    void Update();
    void Render();

    void AddFrame(const char* path);

    void SetFrame(int frame);
    int GetFrame();
};
