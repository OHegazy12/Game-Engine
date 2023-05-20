#pragma once

#include "pch.h"
#include"../ImplShader.h"

namespace Sky
{
	class OpenGLShader : public ImplShader
	{
	public:
		OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		OpenGLShader(std::string&& vertexFile, std::string&& fragmentFile);
		~OpenGLShader();

		virtual void Activate() override;

		virtual void Pass2FloatValues(const std::string& name, float val1, float val2) override;
		virtual void Pass2FloatValues(std::string&& name, float val1, float val2) override;
	private:
		unsigned int mProgram{ 0 };
	};
}