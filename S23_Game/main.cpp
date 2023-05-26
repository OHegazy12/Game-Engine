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
		renderer.Draw(slime);
		renderer.Draw(slime2);
		renderer.Draw(slime3);

		if (Sky::UnitsOverlap(unit, slime))
		{
			slime.SetCoords({ 1000, 1000 });
		}

		if (Sky::UnitsOverlap(unit, slime2))
		{
			slime2.SetCoords({ 1000, 1000 });
		}

		if (Sky::UnitsOverlap(unit, slime3))
		{
			slime3.SetCoords({ 1000, 1000 });
		}

		if (Sky::UnitsOverlap(unit, slime) && Sky::UnitsOverlap(unit, slime2) && Sky::UnitsOverlap(unit, slime3))
		{

		}
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
		else if (e.GetKeyCode() == Sky_KEY_A)
		{
			unit.UpdateXCoord(-20);
		}
		else if (e.GetKeyCode() == Sky_KEY_D)
		{
			unit.UpdateXCoord(20);
		}
	}

private:
	Sky::Renderer renderer;

	Sky::Unit unit{ "../Assets/Images/test.png", {100, 100} };
	Sky::Unit slime{ "../Assets/Images/slime.png", {300, 100} };
	Sky::Unit slime2{ "../Assets/Images/slime2.png", {500, 100} };
	Sky::Unit slime3{ "../Assets/Images/slime3.png", {700, 100} };
	Sky::Image back{ "../Assets/Images/back.png" };
};

SKY_GAME_START(S23_Game_App);