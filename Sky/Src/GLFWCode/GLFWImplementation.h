#pragma once

#include "pch.h"
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"
namespace Sky
{
	class GLFWImplementation : public WindowImplementation
	{
	public:
		virtual void createWindow(int width, int height, const std::string& windowName) override;
		virtual void createWindow(int width, int height, const std::string&& windowName) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;


		virtual int getWidth() const override;
		virtual int getHeight() const override;

	private:

		GLFWwindow* mWindow{ nullptr };
	};
}