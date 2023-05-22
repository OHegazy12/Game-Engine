#pragma once
#include "pch.h"
#include "SkyEvents.h"

namespace Sky
{
	class WindowImplementation
	{
	public:
		virtual void createWindow(int width, int height, const std::string& windowName) = 0;
		virtual void createWindow(int width, int height, const std::string&& windowName) = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) = 0;

		virtual void SetWindowCloseCallback(std::function<void()> callbackFunc) = 0;

		virtual ~WindowImplementation() {};
	};
}