#include "pch.h"
#include "OpenGLImage.h"
#include "glad/glad.h"
#include "std_image.h"
#include "Shader.h"

Sky::OpenGLImage::OpenGLImage(const std::string& imageFile)
{
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(imageFile.c_str(), &width, &height, &nrChannels, 0);

	if (data == nullptr)
	{
		std::cout << "ERROR: Image reading has failed" << std::endl;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

Sky::OpenGLImage::OpenGLImage(std::string&& imageFile)
{
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("../Assets/Images/test.png", &width, &height, &nrChannels, 0);

	if (data == nullptr)
	{
		std::cout << "ERROR: Image reading has failed" << std::endl;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

Sky::OpenGLImage::~OpenGLImage()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1, &texture1);
}

void Sky::OpenGLImage::Activate()
{
	glBindTexture(GL_TEXTURE_2D, texture1);
}

int Sky::OpenGLImage::GetWidth() const
{
	return width;
}

int Sky::OpenGLImage::GetHeight() const
{
	return height;
}
