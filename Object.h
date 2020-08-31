#pragma once
#include "Transform.h"
#include <list>

class Object :
    public Transform
{
protected:
    Object* parent;

    SDL_Rect srcRect, destRect;

    std::list<Object*> childList;
public:
    Object();
    ~Object();

    virtual void Update();
    virtual void Render();

    void setParent(Object* parent);

    void AddChild(Object* child);
    void RemoveChild(Object* child);

    bool intersectRect(SDL_Rect* target);
    bool pointInRect(SDL_FPoint* p);
    bool pointInRect(SDL_Point* p);

    SDL_Rect getRect();
};

