#pragma once

struct Vector3
{
public:
	const static Vector3 Zero;
	const static Vector3 UnitX;
	const static Vector3 UnitY;
	const static Vector3 UnitZ;
	const static Vector3 One;

	float X;
	float Y;
	float Z;

	Vector3(void)
		: X(0), Y(0), Z(0)
	{}

	Vector3(float value)
		: X(value), Y(value), Z(value)
	{}

	Vector3(float x, float y, float z)
		: X(x), Y(y), Z(z)
	{}

	inline Vector3 operator -(void) const
	{
		return Vector3(-X, -Y, -Z);
	}

	inline Vector3 operator -(Vector3 other) const
	{
		return Vector3(X - other.X, Y - other.Y, Z - other.Z);
	}

	inline Vector3 operator +(Vector3 other) const
	{
		return Vector3(X + other.X, Y + other.Y, Z + other.Z);
	}

	inline Vector3 operator *(float scalar) const
	{
		return Vector3(X * scalar, Y * scalar, Z * scalar);
	}

	inline Vector3 operator *(Vector3 scalar) const
	{
		return Vector3(X * scalar.X, Y * scalar.Y, Z * scalar.Z);
	}

	inline Vector3 operator /(float scalar) const
	{
		return Vector3(X / scalar, Y / scalar, Z / scalar);
	}

	inline Vector3 operator /(Vector3 scalar) const
	{
		return Vector3(X / scalar.X, Y / scalar.Y, Z / scalar.Z);
	}

	inline Vector3 operator -=(Vector3 other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
		return *this;
	}

	inline Vector3 operator +=(Vector3 other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;
		return *this;
	}

	inline Vector3 operator *=(float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;
		return *this;
	}

	inline Vector3 operator *=(Vector3 scalar)
	{
		X *= scalar.X;
		Y *= scalar.Y;
		Z *= scalar.Z;
		return *this;
	}

	inline Vector3 operator /=(float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;
		return *this;
	}

	inline Vector3 operator /=(Vector3 scalar)
	{
		X /= scalar.X;
		Y /= scalar.Y;
		Z /= scalar.Z;
		return *this;
	}

	inline bool operator ==(Vector3 other) const
	{
		return X == other.X && Y == other.Y && Z == other.Z;
	}

	inline bool operator !=(Vector3 other) const
	{
		return X != other.X || Y != other.Y || Z != other.Z;
	}
};

inline Vector3 operator *(float scalar, Vector3 value)
{
	return value * scalar;
}

inline Vector3 operator /(float scalar, Vector3 value)
{
	return value / scalar;
}