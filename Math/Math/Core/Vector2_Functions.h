#pragma once
#include "Vector2.h"
#include "Basics.h"
#include "Interpolation.h"

namespace DeJong
{
	/* Returns the absolute (positive) value of the input vector. */
	_Check_return_ inline Vector2 _Abs(_In_ Vector2 v)
	{
		return Vector2(abs(v.X), abs(v.Y));
	}

	/* Converts the specified vector to an angle in radians. */
	_Check_return_ inline float angle(_In_ Vector2 v)
	{
		return atan2(v.Y, v.X);
	}

	/* Returns the angle (in radians) between the two specified vectors. */
	_Check_return_ inline float angle(_In_ Vector2 v, _In_ Vector2 w)
	{
		return angle(w) - angle(v);
	}

	/* Returns the input vector restricted to a specified range. */
	_Check_return_ inline Vector2 clamp(_In_ Vector2 v, _In_ Vector2 lower, _In_ Vector2 higher)
	{
		return Vector2(clamp(v.X, lower.X, higher.X), clamp(v.Y, lower.Y, higher.Y));
	}

	/* Returns the area of the parallelogram that v and w define. */
	_Check_return_ inline float det(_In_ Vector2 v, _In_ Vector2 w)
	{
		return v.X * w.Y - v.Y * w.X;
	}

	/* Returns the dot product of the two specified vectors. */
	_Check_return_ inline float dot(_In_ Vector2 v, _In_ Vector2 w)
	{
		return v.X * w.X + v.Y * w.Y;
	}

	/* Returns the length of the specified vector squared. */
	_Check_return_ inline float lengthsqrd(_In_ Vector2 v)
	{
		return dot(v, v);
	}

	/* Returns the length of the specified vector. */
	_Check_return_ inline float length(_In_ Vector2 v)
	{
		return sqrt(lengthsqrd(v));
	}

	/* Returns the distance between the two specified vectors. */
	_Check_return_ inline float dist(_In_ Vector2 v, _In_ Vector2 w)
	{
		return length(w - v);
	}

	/* Returns the absolute distance between the two specified vectors. */
	_Check_return_ inline float adist(_In_ Vector2 v, _In_ Vector2 w)
	{
		return abs(dist(v, w));
	}

	/* Returns a vector that defines the highest value from each matching pair of components. */
	_Check_return_ inline Vector2 max(_In_ Vector2 v, _In_ Vector2 w)
	{
		return Vector2(max(v.X, w.X), max(v.Y, w.Y));
	}

	/* Returns a vector that defines the lowest value from each matching pair of components. */
	_Check_return_ inline Vector2 min(_In_ Vector2 v, _In_ Vector2 w)
	{
		return Vector2(min(v.X, w.X), min(v.Y, w.Y));
	}

	/* Normalizes the specified reducing its magnitude to one. */
	_Check_return_ inline Vector2 normalize(_In_ Vector2 v)
	{
		return v * recip(length(v));
	}

	/* Returns the reflection vector of the input vector and normal.  */
	_Check_return_ inline Vector2 reflect(_In_ Vector2 v, _In_ Vector2 n)
	{
		return v - 2.0f * dot(v, n) * n;
	}

	/* Rectifies the input vector clamping it between zero and itself for both components. */
	_Check_return_ inline Vector2 rectify(_In_ Vector2 v)
	{
		return Vector2(rectify(v.X), rectify(v.Y));
	}

	/* Performs linear interpolation between two specified points with a specified amount. */
	_Check_return_ inline Vector2 lerp(_In_ Vector2 low, _In_ Vector2 high, _In_ float a)
	{
		return Vector2(lerp(low.X, high.X, a), lerp(low.X, high.X, a));
	}

	/* Performs inverse linear interpolation between two specified points with a specified point. */
	_Check_return_ inline float invLerp(_In_ Vector2 low, _In_ Vector2 high, _In_ Vector2 v)
	{
		const Vector2 d = high - low;
		return dot(v - low, d) / lengthsqrd(d);
	}

	/* Performs cubic hermite spline interpolation with specified lower and higher bounds and derivatives. */
	_Check_return_ inline Vector2 hermite(_In_ Vector2 low, _In_ Vector2 lowdir, _In_ Vector2 high, _In_ Vector2 highdir, _In_ float a)
	{
		return Vector2(hermite(low.X, lowdir.X, high.X, highdir.X, a), hermite(low.Y, lowdir.Y, high.Y, highdir.Y, a));
	}

	/* 
	Performs cubic hermite spline interpolation with specified lower and higher bounds.
	Derivatives = 0.
	*/
	_Check_return_ inline Vector2 hermite(_In_ Vector2 low, _In_ Vector2 high, _In_ float a)
	{
		return Vector2(hermite(low.X, high.X, a), hermite(low.Y, high.Y, a));
	}

	/* Performs cubic catmull rom spline interpolation with specified points. */
	_Check_return_ inline Vector2 catmullrom(_In_ Vector2 first, _In_ Vector2 second, _In_ Vector2 third, _In_ Vector2 forth, _In_ float a)
	{
		return Vector2(catmullrom(first.X, second.X, third.X, forth.X, a), catmullrom(first.Y, second.Y, third.Y, forth.Y, a));
	}
}