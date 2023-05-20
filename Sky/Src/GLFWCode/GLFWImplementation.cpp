#include"pch.h"
#include "GLFWImplementation.h"

namespace Sky
{
	void GLFWImplementation::createWindow(int width, int height, const std::string& windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}
	void GLFWImplementation::createWindow(int width, int height, const std::string&& windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);
	}
	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}
	int GLFWImplementation::getWidth() const
	{
		int height{ 0 }, width{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}
	int GLFWImplementation::getHeight() const
	{
		int height{ 0 }, width{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}
}