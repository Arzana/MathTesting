#pragma once
#include "Vector4.h"
#include "Basics.h"

namespace DeJong
{
	/* Returns the absolute (positive) value of the input vector. */
	_Check_return_ inline Vector4 _Abs(_In_ Vector4 v)
	{
		return Vector4(abs(v.X), abs(v.Y), abs(v.Z), abs(v.W));
	}

	/* Returns the input vector restricted to a specified range. */
	_Check_return_ inline Vector4 clamp(_In_ Vector4 v, _In_ Vector4 lower, _In_ Vector4 higher)
	{
		return Vector4(clamp(v.X, lower.X, higher.X), clamp(v.Y, lower.Y, higher.Y), clamp(v.Z, lower.Z, higher.Z), clamp(v.W, lower.W, higher.W));
	}

	/* Returns the dot product of the two specified vectors. */
	_Check_return_ inline float dot(_In_ Vector4 v, _In_ Vector4 w)
	{
		return v.X * w.X + v.Y * w.Y + v.Z * w.Z + v.W * w.W;
	}

	/* Returns the length of the specified vector squared. */
	_Check_return_ inline float lengthsqrd(_In_ Vector4 v)
	{
		return dot(v, v);
	}

	/* Returns the length of the specified vector. */
	_Check_return_ inline float length(_In_ Vector4 v)
	{
		return sqrt(lengthsqrd(v));
	}

	/* Returns the distance between the two specified vectors. */
	_Check_return_ inline float dist(_In_ Vector4 v, _In_ Vector4 w)
	{
		return length(w - v);
	}

	/* Returns the absolute distance between the two specified vectors. */
	_Check_return_ inline float adist(_In_ Vector4 v, _In_ Vector4 w)
	{
		return abs(dist(v, w));
	}

	/* Returns a vector that defines the highest value from each matching pair of components. */
	_Check_return_ inline Vector4 max(_In_ Vector4 v, _In_ Vector4 w)
	{
		return Vector4(max(v.X, w.X), max(v.Y, w.Y), max(v.Z, w.Z), max(v.W, w.W));
	}

	/* Returns a vector that defines the lowest value from each matching pair of components. */
	_Check_return_ inline Vector4 min(_In_ Vector4 v, _In_ Vector4 w)
	{
		return Vector4(min(v.X, w.X), min(v.Y, w.Y), min(v.Z, w.Z), min(v.W, w.W));
	}

	/* Normalizes the specified vector reducing its magnitude to one. */
	_Check_return_ inline Vector4 normalize(_In_ Vector4 v)
	{
		return v * recip(length(v));
	}

	/* Returns the reflection vector of the input vector and normal. */
	_Check_return_ inline Vector4 reflect(_In_ Vector4 v, _In_ Vector4 n)
	{
		return v - 2.0f * dot(v, n) * n;
	}

	/* Rectifies the input vector clamping it between zero and itself for all components. */
	_Check_return_ inline Vector4 rectify(_In_ Vector4 v)
	{
		return Vector4(rectify(v.X), rectify(v.Y), rectify(v.Z), rectify(v.W));
	}
}