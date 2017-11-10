#pragma once
#include <sal.h> 
#include "Configuration.h"

namespace DeJong
{
	/* Defines a three dimentional vector. */
	typedef struct Vector3
	{
		/* [0, 0, 0] */
		const static Vector3 Zero;
		/* [1, 0, 0] */
		const static Vector3 UnitX;
		/* [0, 1, 0] */
		const static Vector3 UnitY;
		/* [0, 0, 1] */
		const static Vector3 UnitZ;
		/* [1, 1, 1] */
		const static Vector3 One;
		/* [1, 0, 0] */
		const static Vector3 Right;
		/* [-1, 0, 0] */
		const static Vector3 Left;
		/* [0, 1, 0] */
		const static Vector3 Up;
		/* [0, -1, 0] */
		const static Vector3 Down;
#if defined(RIGHT_HAND)
		/* [0, 0, 1] */
		const static Vector3 Backward;
		/* [0, 0, -1] */
		const static Vector3 Forward;
#endif
#if defined(LEFT_HAND)
		/* [0, 0, 1] */
		const static Vector3 Forward;
		/* [0, 0, -1] */
		const static Vector3 Backward;
#endif

		/* The X component of the vector. */
		float X;
		/* The Y component of the vector. */
		float Y;
		/* The Z component of the vector. */
		float Z;

		/* Initializes a new instance of a three dimentional vector with all componenets set to zero. */
		Vector3(void)
			: X(0), Y(0), Z(0)
		{}

		/* Initializes a new instance of a three dimentional vector with all components set to a specific value. */
		Vector3(_In_ float value)
			: X(value), Y(value), Z(value)
		{}

		/* Initializes a new instance of a three dimentional vector with all components specified. */
		Vector3(_In_ float x, _In_ float y, _In_ float z)
			: X(x), Y(y), Z(z)
		{}

		/* Initializes a new instance of a three dimentional vector from a predefined vector. */
		Vector3(_In_ const Vector3 &value)
			: X(value.X), Y(value.Y), Z(value.Z)
		{}

		/* Negates the source vector. */
		_Check_return_ inline Vector3 operator -(void) const
		{
			return Vector3(-X, -Y, -Z);
		}

		/* Subtracts the input vector from the source vector. */
		_Check_return_ inline Vector3 operator -(_In_ Vector3 other) const
		{
			return Vector3(X - other.X, Y - other.Y, Z - other.Z);
		}

		/* Adds the input vector from the source vector. */
		_Check_return_ inline Vector3 operator +(_In_ Vector3 other) const
		{
			return Vector3(X + other.X, Y + other.Y, Z + other.Z);
		}

		/* Multiplies the source vector by a specified scalar value. */
		_Check_return_ inline Vector3 operator *(_In_ float scalar) const
		{
			return Vector3(X * scalar, Y * scalar, Z * scalar);
		}

		/* Multiplies the source vector by a specified scalar vector. */
		_Check_return_ inline Vector3 operator *(_In_ Vector3 scalar) const
		{
			return Vector3(X * scalar.X, Y * scalar.Y, Z * scalar.Z);
		}

		/* Divides the source vector by a specified scalar value. */
		_Check_return_ inline Vector3 operator /(_In_ float scalar) const
		{
			return Vector3(X / scalar, Y / scalar, Z / scalar);
		}

		/* Divides the source vector by a specified scalar vector. */
		_Check_return_ inline Vector3 operator /(_In_ Vector3 scalar) const
		{
			return Vector3(X / scalar.X, Y / scalar.Y, Z / scalar.Z);
		}

		/* Subtracts the input vector from the source vector. */
		inline Vector3 operator -=(_In_ Vector3 other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;
			return *this;
		}

		/* Adds the input vector from the source vector. */
		inline Vector3 operator +=(_In_ Vector3 other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			return *this;
		}

		/* Multiplies the source vector by a specified scalar value. */
		inline Vector3 operator *=(_In_ float scalar)
		{
			X *= scalar;
			Y *= scalar;
			Z *= scalar;
			return *this;
		}

		/* Multiplies the source vector by a specified scalar vector. */
		inline Vector3 operator *=(_In_ Vector3 scalar)
		{
			X *= scalar.X;
			Y *= scalar.Y;
			Z *= scalar.Z;
			return *this;
		}

		/* Divides the source vector by a specified scalar value. */
		inline Vector3 operator /=(_In_ float scalar)
		{
			X /= scalar;
			Y /= scalar;
			Z /= scalar;
			return *this;
		}

		/* Divides the source vector by a specified scalar vector. */
		inline Vector3 operator /=(_In_ Vector3 scalar)
		{
			X /= scalar.X;
			Y /= scalar.Y;
			Z /= scalar.Z;
			return *this;
		}

		/* Checks whether the input vector is equal to the source vector. */
		_Check_return_ inline bool operator ==(_In_ Vector3 other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z;
		}

		/* Checks whether the input vector is different from the source vector. */
		_Check_return_ inline bool operator !=(_In_ Vector3 other) const
		{
			return X != other.X || Y != other.Y || Z != other.Z;
		}
	} Vect3;

	/* Multiplies the input vector by a specified scalar value. */
	_Check_return_ inline Vector3 operator *(_In_ float scalar, _In_ Vector3 value)
	{
		return value * scalar;
	}
}