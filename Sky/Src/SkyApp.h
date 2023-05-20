#pragma once

#include "SkyUtility.h"

namespace Sky
{
	class SKY_API SkyApp
	{
	public:

		virtual void OnUpdate() = 0;

		void Run();

	private:



	};
}
