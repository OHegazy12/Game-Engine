#include "pch.h"
#include "OpenGLRenderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Sky
{
	OpenGLRenderer::OpenGLRenderer()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			SKY_ERROR("Failed to initialize GLAD");
			return;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		int edata[] = {
				0, 1, 3,
				1, 2, 3
		};

		glGenVertexArrays(1, &mVAO);
		glGenBuffers(1, &mVBO);
		glGenBuffers(1, &mEBO);

		glBindVertexArray(mVAO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edata), edata, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	void OpenGLRenderer::Draw(Image& image, TextureBox texCoords, Shader& shader, ScreenCoord coords)
	{
		float vdata[] = {
				coords.xCoord, coords.yCoord, texCoords.xTexCoord / float(image.GetWidth()), texCoords.yTexCoord / float(image.GetHeight()),
				coords.xCoord, coords.yCoord + image.GetHeight(), texCoords.xTexCoord / float(image.GetWidth()), (texCoords.yTexCoord + texCoords.texHeight) / float(image.GetHeight()),
				coords.xCoord + image.GetWidth(), coords.yCoord + image.GetHeight(), (texCoords.xTexCoord + texCoords.texWidth) / float(image.GetWidth()), (texCoords.yTexCoord + texCoords.texHeight) / float(image.GetHeight()),
				coords.xCoord + image.GetWidth(), coords.yCoord, (texCoords.xTexCoord + texCoords.texWidth) / float(image.GetWidth()), texCoords.yTexCoord / float(image.GetHeight())
		};

		glBindVertexArray(mVAO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vdata), vdata, GL_STATIC_DRAW);

		image.Activate();
		shader.Activate();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void OpenGLRenderer::Clear()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}


