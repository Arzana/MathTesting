#pragma once
#include "Rectangle.h"

namespace DeJong
{
	/* Gets if the specified source rectangle contains a specified point.  */
	_Check_return_ bool contains(_In_ Rectangle source, _In_ Vector2 point)
	{
		if (source.GetLeft() < point.X && source.GetRight() > point.X)
		{
#if defined(TOP_ORIGIN)
			return source.GetTop() < point.Y && source.GetBottom() > point.Y;
#endif
#if defined(BOTTOM_ORIGIN)
			return source.GetTop() > point.Y && source.GetBottom() < point.Y;
#endif
		}

		return false;
	}

	/* Gets if the specified source rectangle fully contains the specified other rectangle. */
	_Check_return_ bool contains(_In_ Rectangle source, _In_ Rectangle other)
	{
		if (source.GetLeft() < other.GetLeft() && source.GetRight() > other.GetRight())
		{
#if defined(TOP_ORIGIN)
			return source.GetTop() < other.GetTop() && source.GetBottom() > other.GetBottom();
#endif
#if defined(BOTTOM_ORIGIN)
			return source.GetTop() > other.GetTop() && source.GetBottom() < other.GetBottom();
#endif
		}

		return false;
	}

	/* Calculates a rectangle that defines the area where the specified rectanges overlap. */
	_Check_return_ Rectangle overlap(_In_ Rectangle source, _In_ Rectangle other)
	{
		const float xl = max(source.GetLeft(), other.GetLeft());
		const float xs = min(source.GetRight(), other.GetRight());
		if (xs < xl) return Rectangle::Empty;

#if defined(TOP_ORIGIN)
		const float yl = max(source.GetTop(), other.GetTop());
		const float ys = min(source.GetBottom(), other.GetBottom());
#endif
#if defined(BOTTOM_ORIGIN)
		const float yl = min(source.GetTop(), other.GetTop());
		const float ys = max(source.GetBottom(), other.GetBottom());
#endif
		if (ys < yl) return Rectangle::Empty;

#if defined(TOP_ORIGIN)
		return Rectangle(xl, yl, xs - xl, ys - yl);
#endif
#if defined(BOTTOM_ORIGIN)
		return Rectangle(xl, yl, xs - xl, yl - ys);
#endif
	}

	/* Creates a rectangle that exaclty contains the two specified rectangles. */
	_Check_return_ Rectangle merge(_In_ Rectangle source, _In_ Rectangle other)
	{
		const float r = max(source.GetRight(), other.GetRight());
		const float l = min(source.GetLeft(), other.GetLeft());

#if defined(TOP_ORIGIN)
		const float t = min(source.GetTop(), other.GetTop());
		const float b = max(source.GetBottom(), other.GetBottom());

		return Rectangle(l, t, r - l, b - t);
#endif
#if defined(BOTTOM_ORIGIN)
		const float t = max(source.GetTop(), other.GetTop());
		const float b = min(source.GetBottom(), other.GetBottom());

		return Rectangle(l, t, r - l, t - b);
#endif
	}
}