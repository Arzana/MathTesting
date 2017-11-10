#pragma once
#include <sal.h>

namespace DeJong
{
	/* Defines a four dimentioal vector. */
	typedef struct Vector4
	{
		/* [0, 0, 0, 0] */
		const static Vector4 Zero;
		/* [1, 0, 0, 0] */
		const static Vector4 UnitX;
		/* [0, 1, 0, 0] */
		const static Vector4 UnitY;
		/* [0, 0, 1, 0] */
		const static Vector4 UnitZ;
		/* [0, 0, 0, 1] */
		const static Vector4 UnitW;
		/* [1, 1, 1, 1] */
		const static Vector4 One;

		/* The X component of the vector. */
		float X;
		/* The Y component of the vector. */
		float Y;
		/* The Z component of the vector. */
		float Z;
		/* The W component of the vector. */
		float W;

		/* Initializes a new instance of a four dimentional vector with all components set to zero. */
		Vector4(void)
			: X(0), Y(0), Z(0), W(0)
		{}

		/* Initializes a new instance of a four dimentional vector with all components set to s specific value. */
		Vector4(_In_ float value)
			: X(value), Y(value), Z(value), W(value)
		{}

		/* Initializes a new instance of a four dimentioanl vector with all components specified. */
		Vector4(_In_ float x, _In_ float y, _In_ float z, _In_ float w)
			: X(x), Y(y), Z(z), W(w)
		{}

		/* Initializes a new instance of a four dimentional vector from a predefined vector. */
		Vector4(_In_ const Vector4 &value)
			: X(value.X), Y(value.Y), Z(value.Z), W(value.W)
		{}

		/* Negates the source vector. */
		_Check_return_ inline Vector4 operator -(void) const
		{
			return Vector4(-X, -Y, -Z, -W);
		}

		/* Subtracts the input vector from the source vector. */
		_Check_return_ inline Vector4 operator -(_In_ Vector4 other) const
		{
			return Vector4(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
		}

		/* Adds the input vector to the source vector. */
		_Check_return_ inline Vector4 operator +(_In_ Vector4 other) const
		{
			return Vector4(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
		}

		/* Multiplies the source vector by a specified scalar value. */
		_Check_return_ inline Vector4 operator *(_In_ float scalar) const
		{
			return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar);
		}

		/* Mutiplies the source vector by a specified scalar vector. */
		_Check_return_ inline Vector4 operator *(_In_ Vector4 scalar) const
		{
			return Vector4(X * scalar.X, Y * scalar.Y, Z * scalar.Z, W * scalar.W);
		}

		/* Divides the source vector by a specified scalar value. */
		_Check_return_ inline Vector4 operator /(_In_ float scalar) const
		{
			return Vector4(X / scalar, Y / scalar, Z / scalar, W / scalar);
		}

		/* Divides the source vector by a specified scalar vector. */
		_Check_return_ inline Vector4 operator /(_In_ Vector4 scalar) const
		{
			return Vector4(X / scalar.X, Y / scalar.Y, Z / scalar.Z, W / scalar.W);
		}

		/* Subtracts the input vector from the source vector. */
		inline Vector4 operator -=(_In_ Vector4 other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;
			W -= other.W;
			return *this;
		}

		/* Adds the input vector to the source vector. */
		inline Vector4 operator +=(_In_ Vector4 other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			W += other.W;
			return *this;
		}

		/* Multiplies the source vector by a specified scalar value. */
		inline Vector4 operator *=(_In_ float scalar)
		{
			X *= scalar;
			Y *= scalar;
			Z *= scalar;
			W *= scalar;
			return *this;
		}

		/* Multiplies the source vector by a specified scalar vector. */
		inline Vector4 operator *=(_In_ Vector4 scalar)
		{
			X *= scalar.X;
			Y *= scalar.Y;
			Z *= scalar.Z;
			W *= scalar.W;
			return *this;
		}

		/* Divides the source vector by a specified scalar value. */
		inline Vector4 operator /=(_In_ float scalar)
		{
			X /= scalar;
			Y /= scalar;
			Z /= scalar;
			W /= scalar;
			return *this;
		}

		/* Divides the source vector by a specified scalar vector. */
		inline Vector4 operator /=(_In_ Vector4 scalar)
		{
			X /= scalar.X;
			Y /= scalar.Y;
			Z /= scalar.Z;
			W /= scalar.W;
			return *this;
		}

		/* Checks whether the input vector is equal to the source vector. */
		_Check_return_ inline bool operator ==(_In_ Vector4 other) const
		{
			return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
		}

		/* Checks whether the input vector is different from the source vector. */
		_Check_return_ inline bool operator !=(_In_ Vector4 other) const
		{
			return X != other.X || Y != other.Y || Z != other.Z || W != other.W;
		}

	} Vect4;

	/* Multiplies the input vector by a specified scalar value. */
	_Check_return_ inline Vector4 operator *(_In_ float scalar, _In_ Vector4 value)
	{
		return value * scalar;
	}
}