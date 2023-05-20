#pragma once

#include "SkyUtility.h"
#include "Image.h"
#include "Shader.h"
#include "ImplRenderer.h"

namespace Sky
{
	class SKY_API Renderer
	{
	public:
		void Draw(Image& image, Shader& shader, int xCoord, int yCoord);
		void Draw(Image& image, int xCoord, int yCoord);


	private:
		ImplRenderer* mImplementation{ nullptr };


	};

}