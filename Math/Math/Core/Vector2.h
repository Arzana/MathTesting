#pragma once
#include <sal.h>

/* Defines a two dimentional vector. */
typedef struct Vector2
{
	/* [0, 0] */
	const static Vector2 Zero;
	/* [1, 0] */
	const static Vector2 UnitX;
	/* [0, 1] */
	const static Vector2 UnitY;
	/* [1, 1] */
	const static Vector2 One;

	/* The X component of the vector. */
	float X;
	/* The Y component of the vector. */
	float Y;

	/* Initializes a new instance of a two dimentional vector with both components set to zero. */
	Vector2(void)
		: X(0), Y(0)
	{}

	/* Initializes a new instance of a two dimentional vector with both components set to a specific value. */
	Vector2(float value)
		: X(value), Y(value)
	{}

	/* Initializes a new instance of a two dimentional vector with both components specified. */
	Vector2(float x, float y)
		: X(x), Y(y)
	{}

	/* Delete default copy constructor because copying a vector by refrence would be slower then copying it by value. */
	Vector2(const Vector2 &value)
		: X(value.X), Y(value.Y)
	{}

	/* Negates the source vector. */
	_Check_return_ inline Vector2 operator -(void) const
	{
		return Vector2(-X, -Y);
	}

	/* Subtracts the input vector from the source vector. */
	_Check_return_ inline Vector2 operator -(_In_ Vector2 other) const
	{
		return Vector2(X - other.X, Y - other.Y);
	}

	/* Adds the input vector to the source vector. */
	_Check_return_ inline Vector2 operator +(_In_ Vector2 other) const
	{
		return Vector2(X + other.X, Y + other.Y);
	}

	/* Multiplies the source vector by a specified scalar value. */
	_Check_return_ inline Vector2 operator *(_In_ float scalar) const
	{
		return Vector2(X * scalar, Y * scalar);
	}

	/* Multiplies the source vector by a specified scalar vector. */
	_Check_return_ inline Vector2 operator *(_In_ Vector2 scalar) const
	{
		return Vector2(X * scalar.X, Y * scalar.Y);
	}

	/* Divides the source vector by a specified scalar value. */
	_Check_return_ inline Vector2 operator /(_In_ float scalar) const
	{
		return Vector2(X / scalar, Y / scalar);
	}

	/* Divides the source vector by a specified scalar vector. */
	_Check_return_ inline Vector2 operator /(_In_ Vector2 scalar) const
	{
		return Vector2(X / scalar.X, Y / scalar.Y);
	}

	/* Subtracts the input vector from the source vector. */
	inline Vector2 operator -=(_In_ Vector2 other)
	{
		X -= other.X;
		Y -= other.Y;
		return *this;
	}

	/* Adds the input vector to the source vector. */
	inline Vector2 operator +=(_In_ Vector2 other)
	{
		X += other.X;
		Y += other.Y;
		return *this;
	}

	/* Multiplies the source vector by a specified scalar value. */
	inline Vector2 operator *=(_In_ float scalar)
	{
		X *= scalar;
		Y *= scalar;
		return *this;
	}

	/* Multiplies the source vector by a specified scalar vector. */
	inline Vector2 operator *=(_In_ Vector2 scalar)
	{
		X *= scalar.X;
		Y *= scalar.Y;
		return *this;
	}

	/* Divides the source vector by a specified scalar value. */
	inline Vector2 operator /=(_In_ float scalar)
	{
		X /= scalar;
		Y /= scalar;
		return *this;
	}

	/* Divides the source vector by a specified scalar vector. */
	inline Vector2 operator /=(_In_ Vector2 scalar)
	{
		X /= scalar.X;
		Y /= scalar.Y;
		return *this;
	}

	/* Checks whether the input vector is equal to the source vector. */
	_Check_return_ inline bool operator ==(_In_ Vector2 other) const
	{
		return X == other.X && Y == other.Y;
	}

	/* Checks whether the input vector is different from the source vector. */
	_Check_return_ inline bool operator !=(_In_ Vector2 other) const
	{
		return X != other.X || Y != other.Y;
	}
} Vect2;

/* Multiplies the input vector by a specified scalar value. */
_Check_return_ inline Vector2 operator *(_In_ float scalar, _In_ Vector2 value)
{
	return value * scalar;
}