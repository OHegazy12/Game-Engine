#pragma once

#include "SkyUtility.h"

namespace Sky
{
	class SKY_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;


	private:
		int mKeyCode;


	};

	class SKY_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;


	private:
		int mKeyCode;


	};

	class SKY_API WindowClosed
	{
	};
}