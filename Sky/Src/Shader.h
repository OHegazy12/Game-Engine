#pragma once

#include "pch.h"
#include "SkyUtility.h"
#include "ImplShader.h"

namespace Sky
{
	class SKY_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(const std::string&& vertexFile, const std::string&& fragmentFile);

		void Activate();

		void Pass2FloatValues(const std::string& name, float val1, float val2);
		void Pass2FloatValues(std::string&& name, float val1, float val2);
	
	private:
		std::unique_ptr<ImplShader> mImplementation;




	};

}