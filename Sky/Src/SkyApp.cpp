#include "pch.h"
#include "SkyApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"

namespace Sky
{
	SkyApp::SkyApp()
	{
		GameWindow::Init();
		GameWindow::createWindow(1280, 700, "Sky Game");

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

	void SkyApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Sky::GameWindow::SwapBuffers();
			Sky::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void SkyApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		 GameWindow::getGameWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void SkyApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::getGameWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void SkyApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::getGameWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void SkyApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}


}