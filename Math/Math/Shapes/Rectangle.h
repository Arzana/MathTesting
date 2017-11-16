#pragma once
#include "Core\Basics.h"
#include "Core\Vector2.h"

namespace DeJong
{
	/* Defines a non-rotated rectangle. */
	typedef struct Rectangle
	{
		/* Defines an empty rectangle at position [0, 0]. */
		const static Rectangle Empty;

		/* The positional components of the rectangle (top-left). */
		Vector2 Position;
		/* The size of the rectangle (can be negative). */
		Vector2 Size;

		/* Initializes a new instance of a rectangle with a specified size at position [0, 0]. */
		Rectangle(_In_ Vector2 size)
			: Position(), Size(size)
		{}

		/* Initializes a new instance of a rectangle with all components specified. */
		Rectangle(_In_ Vector2 position, _In_ Vector2 size)
			: Position(position), Size(size)
		{}

		/* Initializes a new instance of a rectangle with all components specified individualy. */
		Rectangle(_In_ float x, _In_ float y, _In_ float w, _In_ float h)
			: Position(x, y), Size(w, h)
		{}

		/* Initializes a new instance of a rectangle from a predefined rectangle. */
		Rectangle(_In_ const Rectangle &value)
			: Position(value.Position), Size(value.Size)
		{}

		/* Gets the absolute width of the rectangle. */
		_Check_return_ inline float GetWidth(void) const
		{
			return abs(Size.X);
		}

		/* Gets the absolute height of the rectangle. */
		_Check_return_ inline float GetHeight(void) const
		{
			return abs(Size.Y);
		}

	} Rect;
}