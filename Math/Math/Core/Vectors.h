#pragma once
#include "Vector2_Functions.h"
#include "Vector3_Functions.h"
#include "Vector4_Functions.h"

namespace DeJong
{
	/* Converts a three dimentional vector into a two dimentional vector. */
	_Check_return_ inline Vector2 toVect2(_In_ Vector3 v)
	{
		return Vector2(v.X, v.Y);
	}

	/* Converts a four dimentional vector into a two dimentional vector. */
	_Check_return_ inline Vector2 toVect2(_In_ Vector4 v)
	{
		return Vector2(v.X, v.Y);
	}

	/* Initializes a new instance of a three dimentional vector from a specified two dimentional vector and a specific z value. */
	_Check_return_ inline Vector3 toVect3(_In_ Vector2 v, _In_ float z)
	{
		return Vector3(v.X, v.Y, z);
	}

	/* Converts a four dimentional vector into a three dimetional vector. */
	_Check_return_ inline Vector3 toVect3(_In_ Vector4 v)
	{
		return Vector3(v.X, v.Y, v.Z);
	}

	/* Initializes a new instance of a four dimentional vector from a specified two dimentional vector and specific z and w values. */
	_Check_return_ inline Vector4 toVect4(_In_ Vector2 v, _In_ float z, _In_ float w)
	{
		return Vector4(v.X, v.Y, z, w);
	}

	/* Initializes a new instance of a four dimentional vector from a specified three dimentional vector and a specific w value. */
	_Check_return_ inline Vector4 toVect4(_In_ Vector3 v, _In_ float w)
	{
		return Vector4(v.X, v.Y, v.Z, w);
	}
}