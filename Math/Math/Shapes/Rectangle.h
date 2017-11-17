#pragma once
#include "Core\Basics.h"
#include "Core\Vector2.h"
#include "Configuration.h"

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

		/* Checks whether the input rectangle is equal to the source rectangle. */
		_Check_return_ inline bool operator ==(_In_ Rectangle other) const
		{
			return Position == other.Position && Size == other.Size;
		}

		/* Checks whether the input rectangle is different from the source rectangle. */
		_Check_return_ inline bool operator !=(_In_ Rectangle other) const
		{
			return Position != other.Position || Size != other.Size;
		}

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

		/* Gets the Y coordinate of the top of the rectangle. */
		_Check_return_ inline float GetTop(void) const
		{
#if defined(TOP_ORIGIN)
			return Size.Y > 0.0f ? Position.Y : (Position.Y + Size.Y);
#endif
#if defined(BOTTOM_ORIGIN)
			return Size.Y > 0.0f ? (Position.Y + Size.Y) : Position.Y;
#endif
		}

		/* Gets the Y coordinate of the bottom of the rectangle. */
		_Check_return_ inline float GetBottom(void) const
		{
#if defined(TOP_ORIGIN)
			return Size.Y > 0.0f ? (Position.Y + Size.Y) : Position.Y;
#endif
#if defined(BOTTOM_ORIGIN)
			return Size.Y > 0.0f ? Position.Y : (Position.Y + Size.Y);
#endif
		}

		/* Gets the X coordinate of the right of the rectangle. */
		_Check_return_ inline float GetRight(void) const
		{
#if defined(TOP_ORIGIN)
			return Size.X > 0.0f ? (Position.X + Size.X) : Position.X;
#endif
#if defined(BOTTOM_ORIGIN)
			return Size.X > 0.0f ? Position.X : (Position.X + Size.X);
#endif
		}

		/* Gets the X coordinate of the left of the rectangle. */
		_Check_return_ inline float GetLeft(void) const
		{
#if defined(TOP_ORIGIN)
			return Size.X > 0.0f ? Position.X : (Position.X + Size.X);
#endif
#if defined(BOTTOM_ORIGIN)
			return Size.X > 0.0f ? (Position.X + Size.X) : Position.X;
#endif
		}

		/* Pushes the edges of the rectangle out by a specified amount. */
		void Inflate(_In_ float horizontal, _In_ float vertical);
	} Rect;
}