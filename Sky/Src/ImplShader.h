#pragma once

namespace Sky
{
	class ImplShader
	{
	public:
		virtual void Activate() = 0;

		virtual void Pass2FloatValues(const std::string& name, float val1, float val2) = 0;
		virtual void Pass2FloatValues(std::string&& name, float val1, float val2) = 0;

		virtual ~ImplShader() {};
	};
}