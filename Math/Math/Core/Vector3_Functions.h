#pragma once
#include "Vector3.h"
#include "Basics.h"
#include "Interpolation.h"

namespace DeJong
{
	/* Returns the absolute (positive) value of the input vector. */
	_Check_return_ inline Vector3 _Abs(_In_ Vector3 v)
	{
		return Vector3(abs(v.X), abs(v.Y), abs(v.Z));
	}

	/* Returns the input vector resticted to a specified range. */
	_Check_return_ inline Vector3 clamp(_In_ Vector3 v, _In_ Vector3 lower, _In_ Vector3 higher)
	{
		return Vector3(clamp(v.X, lower.X, higher.X), clamp(v.Y, lower.Y, higher.Y), clamp(v.Z, lower.Z, higher.Z));
	}

	/* Returns the cross product of the two specified vectors. */
	_Check_return_ inline Vector3 cross(_In_ Vector3 v, _In_ Vector3 w)
	{
		return Vector3(v.Y * w.Z - v.Z * w.Y,
					   v.Z * w.X - v.X * w.Z,
					   v.X * w.Y - v.Y * w.X);
	}

	/* Returns the dot product of the two specified vectors. */
	_Check_return_ inline float dot(_In_ Vector3 v, _In_ Vector3 w)
	{
		return v.X * w.X + v.Y * w.Y + v.Z * w.Z;
	}

	/* Returns the length of the specified vector squared. */
	_Check_return_ inline float lengthsqrd(_In_ Vector3 v)
	{
		return dot(v, v);
	}

	/* Returns the length of the specified vector. */
	_Check_return_ inline float length(_In_ Vector3 v)
	{
		return sqrt(lengthsqrd(v));
	}

	/* Returns the distance between the two specified vectors. */
	_Check_return_ inline float dist(_In_ Vector3 v, _In_ Vector3 w)
	{
		return length(w - v);
	}

	/* Returns the absolute distance between the two specified vectors. */
	_Check_return_ inline float adist(_In_ Vector3 v, _In_ Vector3 w)
	{
		return abs(dist(v, w));
	}

	/* Returns a vector that defines the highest value from each matching pair of components. */
	_Check_return_ inline Vector3 max(_In_ Vector3 v, _In_ Vector3 w)
	{
		return Vector3(max(v.X, w.X), max(v.Y, w.Y), max(v.Z, w.Z));
	}

	/* Returns a vector that defines the lowest value from each matching pair of components. */
	_Check_return_ inline Vector3 min(_In_ Vector3 v, _In_ Vector3 w)
	{
		return Vector3(min(v.X, w.X), min(v.Y, w.Y), min(v.Z, w.Z));
	}

	/* Normalizes the specified vector reducing its magnitude to one. */
	_Check_return_ inline Vector3 normalize(_In_ Vector3 v)
	{
		return v * recip(length(v));
	}

	/* Returns the reflection vector of the input vector and normal. */
	_Check_return_ inline Vector3 reflect(_In_ Vector3 v, _In_ Vector3 n)
	{
		return v - 2.0f * dot(v, n) * n;
	}

	/* Rectifies the input vector clamping it between zero and itself for all components. */
	_Check_return_ inline Vector3 rectify(_In_ Vector3 v)
	{
		return Vector3(rectify(v.X), rectify(v.Y), rectify(v.Z));
	}

	/* Performs linear interpolation between two specified points with a specified amount. */
	_Check_return_ inline Vector3 lerp(_In_ Vector3 low, _In_ Vector3 high, _In_ float a)
	{
		return Vector3(lerp(low.X, high.X, a), lerp(low.Y, high.Y, a), lerp(low.Z, high.Z, a));
	}

	/* Performs inverse linear interpolation between two specified points with a specified point. */
	_Check_return_ inline float invLerp(_In_ Vector3 low, _In_ Vector3 high, _In_ Vector3 v)
	{
		const Vector3 d = high - low;
		return dot(v - low, d) / lengthsqrd(d);
	}

	/* Performs cubic hermite spline interpolation with specified lower and higher bounds and derivatives. */
	_Check_return_ inline Vector3 hermite(_In_ Vector3 low, _In_ Vector3 lowdir, _In_ Vector3 high, _In_ Vector3 highdir, _In_ float a)
	{
		return Vector3(hermite(low.X, lowdir.X, high.X, highdir.X, a), hermite(low.Y, lowdir.Y, high.Y, highdir.Y, a), hermite(low.Z, lowdir.Z, high.Z, highdir.Z, a));
	}

	/*
	Performs cubic hermite spline interpolation with specified lower and higher bounds.
	Derivatives = 0.
	*/
	_Check_return_ inline Vector3 hermite(_In_ Vector3 low, _In_ Vector3 high, _In_ float a)
	{
		return Vector3(hermite(low.X, high.X, a), hermite(low.Y, high.Y, a), hermite(low.Z, high.Z, a));
	}

	/* Performs cubic catmull rom spline interpolation with specified points. */
	_Check_return_ inline Vector3 catmullrom(_In_ Vector3 first, _In_ Vector3 second, _In_ Vector3 third, _In_ Vector3 forth, _In_ float a)
	{
		return Vector3(catmullrom(first.X, second.X, third.X, forth.X, a), catmullrom(first.Y, second.Y, third.Y, forth.Y, a), catmullrom(first.Z, second.Z, third.Z, forth.Z, a));
	}
}