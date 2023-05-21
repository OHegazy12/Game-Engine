#include "Sky.h"
#include <iostream>

class S23_Game_App : public Sky::SkyApp
{
public:

	S23_Game_App()
	{
		Sky::GameWindow::Init();
		Sky::GameWindow::createWindow(800, 600, "Test Name");
	}

	virtual void OnUpdate() override
	{

		
	}
};

SKY_GAME_START(S23_Game_App);