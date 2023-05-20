#pragma once

#include "pch.h"
#include "SkyUtility.h"
#include "ImplImage.h"

namespace Sky
{
	class SKY_API Image
	{
	public:
		Image(const std::string& imageFile);
		Image(const std::string&& imageFile);

		void Activate();

		int GetWidth() const;
		int GetHeight() const;

	private:
		std::unique_ptr<ImplImage> mImplementation;
	};


}