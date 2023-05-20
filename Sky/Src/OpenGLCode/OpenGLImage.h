#pragma once

#include "pch.h"
#include "../ImplImage.h"

namespace Sky
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imageFile);
		OpenGLImage(std::string&& imageFile);
		~OpenGLImage();

		void Activate();

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		unsigned int texture1{ 0 };
		int width, height, nrChannels{ 0 };

	};
}