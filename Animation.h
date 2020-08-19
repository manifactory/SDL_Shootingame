#include "Sprite.h"
#include <vector>

class Animation :
    public Object
{
private:
    int maxFrame;
    int currentFrame;
    int fps;

    float timeChecker;

    std::vector<Sprite*> spriteVector;
public:
    bool isPlay;

    Animation(int fps);
    ~Animation();

    void Update();
    void Render();

    void AddFrame(const char* path);

    void SetFrame(int frame);
    int GetFrame();
};
