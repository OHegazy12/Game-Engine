#include "pch.h"
#include "SkyApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "std_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"

namespace Sky
{
	void SkyApp::Run()
	{
		Renderer renderer;

		Image pic{ "../Assets/Images/test.png" };
		pic.Activate();

		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl",
		"../Assets/Shaders/DefaultFragmentShader.glsl" };

		sProgram.Pass2FloatValues("screenSize", GameWindow::getWidth(), GameWindow::getHeight());

		mNextFrameTime = std::chrono::steady_clock::now();
		 
		while (true)
		{
			renderer.Clear();

			renderer.Draw(pic, { 200, 100 });

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Sky::GameWindow::SwapBuffers();
			Sky::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}


	}


}