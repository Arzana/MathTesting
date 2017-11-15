#pragma once
#include <cmath>
#include "Matrix3.h"

namespace DeJong
{
	/* Creates a 3x3 rotation matrix. */
	_Check_return_ inline Matrix3 rotation(_In_ float rads)
	{
		const float c = cosf(rads);
		const float s = sinf(rads);
		return Matrix3(c, -s, 0, s, c, 0, 0, 0, 1);
	}

	/* Creates a 3x3 scalar matrix. */
	_Check_return_ inline Matrix3 scale2D(_In_ float scalar)
	{
		return Matrix3(scalar, 0, 0, 0, scalar, 0, 0, 0, scalar);
	}

	/* Creates a 3x3 scalar matrix. */
	_Check_return_ inline Matrix3 scale(_In_ Vector2 scalar)
	{
		return Matrix3(scalar.X, 0, 0, 0, scalar.Y, 0, 0, 0, 1);
	}

	/* Creates a 3x3 translation matrix. */
	_Check_return_ inline Matrix3 translation(_In_ Vector2 offset)
	{
		return Matrix3(1, 0, offset.X, 0, 1, offset.Y, 0, 0, 1);
	}

	/* Composes a full view matrix. */
	_Check_return_ inline Matrix3 view(_In_ float scalar, _In_ float rads, _In_ Vector2 offset)
	{
		const float c = cosf(rads) * scalar;
		const float s = sinf(rads) * scalar;
		const float x = offset.X * scalar;
		const float y = offset.Y * scalar;
		return Matrix3(c, -s, x, s, c, y, 0, 0, scalar);
	}
}