#include "stdafx.h"
#include "GUI.h"

Button::Button(std::string path[3], float fps) :Animation(fps)
{
	this->AddFrame(path[0].c_str()); //Button_Default_Frame
	this->AddFrame(path[1].c_str()); //Button_Over_Frame
	this->AddFrame(path[2].c_str()); //Button_On_Frame
}

Button::~Button()
{
}

bool Button::getButtonState()
{
	return isClick;
}

void Button::Update()
{
	Animation::Update();

	this->SetFrame(Button_Default_Frame);
	if(this->pointInRect(inputManager->getMousePos()))
	{
		this->SetFrame(Button_Over_Frame);
		isClick = false;
		if (inputManager->getMouseButtonState())
		{
			this->SetFrame(Button_On_Frame);
		}
		if (inputManager->getEventPoll()->type == SDL_MOUSEBUTTONUP)
		{
			this->SetFrame(Button_Over_Frame);
			isClick = true;
		}
	}
	
}
