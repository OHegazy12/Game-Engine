#include "Sky.h"
#include <iostream>
#include <functional>

class S23_Game_App : public Sky::SkyApp
{
public:

	S23_Game_App()
	{
		SetKeyPressedCallback([this](const Sky::KeyPressed& e) {MyKeyPressedFunc(e); });
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(unit);
		renderer.Draw(enemy);
	}

	void MyKeyPressedFunc(const Sky::KeyPressed& e)
	{
		if (e.GetKeyCode() == Sky_KEY_RIGHT)
		{
			unit.UpdateXCoord(20);
		}
		else if (e.GetKeyCode() == Sky_KEY_LEFT)
		{
			unit.UpdateXCoord(-20);
		}
	}

private:
	Sky::Renderer renderer;

	Sky::Unit unit{ "../Assets/Images/test.png", {100, 100} };
	Sky::Unit enemy{ "../Assets/Images/enemy.png", {500, 100} };
	Sky::Image back{ "../Assets/Images/back.png" };
};

SKY_GAME_START(S23_Game_App);