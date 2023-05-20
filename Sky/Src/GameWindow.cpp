#include "pch.h"
#include "GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace Sky
{
	void GameWindow::Init()
	{
		if (!mInstance)
		{
			mInstance = std::unique_ptr<GameWindow> (new GameWindow);
		}
	}
	std::unique_ptr<GameWindow>& GameWindow::getGameWindow()
	{
		return mInstance;
	}
	void GameWindow::createWindow(int width, int height, const std::string& windowName)
	{
		mInstance -> mImplementation->createWindow(width, height, windowName);
	}
	void GameWindow::createWindow(int width, int height, std::string&& windowName)
	{
		mInstance -> mImplementation->createWindow(width, height, std::move(windowName));
	}
	void GameWindow::SwapBuffers()
	{
		mInstance->mImplementation->SwapBuffers();
	}
	void GameWindow::PollEvents()
	{
		mInstance->mImplementation->PollEvents();
	}
	int GameWindow::getWidth() 
	{
		return mInstance -> mImplementation -> getWidth();
	}
	int GameWindow::getHeight() 
	{
		return mInstance -> mImplementation -> getHeight();
	}
	GameWindow::~GameWindow()
	{
		if (mImplementation != nullptr)
		{
			delete mImplementation;
		}
	}
	GameWindow::GameWindow()
	{
#ifdef SKY_GLFW
		mImplementation = new GLFWImplementation;
#else
	#ERROR_only_GLFW_is_supported
#endif 
	}
}