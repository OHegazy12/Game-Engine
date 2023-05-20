#pragma once
#include "pch.h"

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

		virtual ~WindowImplementation() {};
	};
}