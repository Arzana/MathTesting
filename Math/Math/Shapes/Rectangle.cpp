#include "Rectangle.h"

using namespace DeJong;

const Rectangle Rectangle::Empty = Rectangle(Vector2(0, 0));

void DeJong::Rectangle::Inflate(float horizontal, float vertical)
{
	horizontal *= 0.5f;
	vertical *= 0.5f;

	if (Size.X > 0.0f)
	{
		Position.X -= horizontal;
		Size.Y += horizontal;
	}
	else
	{
		Position.X += horizontal;
		Size.X -= horizontal;
	}

	if (Size.Y > 0.0f)
	{
		Position.Y -= vertical;
		Size.Y += vertical;
	}
	else
	{
		Position.Y += vertical;
		Size.Y -= vertical;
	}
}