#include "pch.h"
#include "Unit.h"

Sky::Unit::Unit(const std::string& image, ScreenCoord coords) : mImage(image), mPosition(coords)
{
}

Sky::Unit::Unit(const std::string&& image, ScreenCoord coords) : mImage(image), mPosition(coords)
{
}

int Sky::Unit::GetWidth() const
{
	return mImage.GetWidth();
}

int Sky::Unit::GetHeight() const
{
	return mImage.GetHeight();
}

Sky::ScreenCoord Sky::Unit::GetCoords() const
{
	return mPosition;
}

void Sky::Unit::SetCoords(ScreenCoord newCoords)
{
	mPosition = newCoords;
}

void Sky::Unit::UpdateXCoord(int amount)
{
	mPosition.xCoord += amount;
}

void Sky::Unit::UpdateYCoord(int amount)
{
	mPosition.yCoord += amount;
}

bool Sky::UnitsOverlap(const Unit& a, const Unit& b)
{
	int left_a{ a.mPosition.xCoord };
	int right_a{ a.mPosition.xCoord + a.mImage.GetWidth()};
	int left_b{ b.mPosition.xCoord };
	int right_b{ b.mPosition.xCoord + b.mImage.GetWidth()};

	bool x_intersection{ (left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b) };

	int bot_a{ a.mPosition.yCoord };
	int top_a{ a.mPosition.yCoord + a.mImage.GetHeight()};
	int bot_b{ b.mPosition.yCoord };
	int top_b{ b.mPosition.yCoord + b.mImage.GetHeight()};

	bool y_intersection{ (bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b) };

	return x_intersection and y_intersection;
}
