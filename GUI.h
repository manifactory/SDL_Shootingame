#pragma once
#include "Animation.h"

#define Button_Default_Frame 0
#define Button_Over_Frame 1
#define Button_On_Frame 2

class Button :
    public Animation
{
private:
    bool isClick = false;
public:
    Button(std::string path[3], float fps);
    ~Button();

    bool getButtonState();

    void Update();
};

