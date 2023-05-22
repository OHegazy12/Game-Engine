#pragma once

#include "pch.h"
#include "SkyUtility.h"
#include "WindowImplementation.h"
#include "SkyEvents.h"

namespace Sky
{


	class SKY_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& getGameWindow();

		static void createWindow(int width, int height, const std::string& windowName);
		static void createWindow(int width, int height, std::string&& windowName);

		static void SwapBuffers();
		static void PollEvents();

		static int getWidth();
		static int getHeight();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		~GameWindow();
	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };
	};
}