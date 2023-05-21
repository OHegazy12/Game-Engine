#pragma once

#include "pch.h"
#include "SkyUtility.h"


constexpr int FPS{ 60 };

namespace Sky
{
	class SKY_API SkyApp
	{
	public:

		virtual void OnUpdate() = 0;

		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

	};
}
