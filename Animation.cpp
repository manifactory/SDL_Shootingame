#include "stdafx.h"
#include "Animation.h"


Animation::Animation(int fps)
{

	isPlay = true;

	this->fps = fps;
	maxFrame = currentFrame = 0;
}

Animation::~Animation()
{
	for (auto& sprite : spriteVector) {
		SAFE_DELETE(sprite);
	}
}

void Animation::Render()
{
	if (maxFrame > 0){
		spriteVector[currentFrame]->Render();
	}
	else {
		spriteVector[0]->Render();
	}
}

void Animation::Update() 
{
	Object::Update();
	timeChecker += DeltaTime;

	if(isPlay)
		if (timeChecker > 1.f / fps) {
			timeChecker = 0;
			currentFrame++;
			if (currentFrame == maxFrame) {
				currentFrame = 0;
			}
		}
}

void Animation::AddFrame(const char* path)
{
	spriteVector.push_back(new Sprite(path));
	
	AddChild(spriteVector[maxFrame]);
	
	if (maxFrame == 0)
	{
		this->setSize(spriteVector[maxFrame]->getSize());
	}

	maxFrame++;
}

void Animation::SetFrame(int frame)
{
	if (frame < maxFrame) {
		currentFrame = frame;
	}
	else {
		currentFrame = 0;
		std::cout << "out of maxframe!" << std::endl;
	}
}

int Animation::GetFrame()
{
	return currentFrame;
}
