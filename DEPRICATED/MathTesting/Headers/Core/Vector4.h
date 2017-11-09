#pragma once

struct Vector4
{
public:
	const static Vector4 Zero;
	const static Vector4 UnitX;
	const static Vector4 UnitY;
	const static Vector4 UnitZ;
	const static Vector4 UnitW;
	const static Vector4 One;

	float X;
	float Y;
	float Z;
	float W;

	Vector4(void)
		: X(0), Y(0), Z(0), W(0)
	{}

	Vector4(float value)
		: X(value), Y(value), Z(value), W(value)
	{}

	Vector4(float x, float y, float z, float w)
		: X(x), Y(y), Z(z), W(w)
	{}

	inline Vector4 operator -(void) const
	{
		return Vector4(-X, -Y, -Z, -W);
	}

	inline Vector4 operator -(Vector4 other) const
	{
		return Vector4(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
	}

	inline Vector4 operator +(Vector4 other) const
	{
		return Vector4(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
	}

	inline Vector4 operator *(float scalar) const
	{
		return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar);
	}

	inline Vector4 operator *(Vector4 other) const
	{
		return Vector4(X * other.X, Y * other.Y, Z * other.Z, W * other.W);
	}

	inline Vector4 operator /(float scalar) const
	{
		return Vector4(X / scalar, Y / scalar, Z / scalar, W / scalar);
	}

	inline Vector4 operator /(Vector4 other) const
	{
		return Vector4(X / other.X, Y / other.Y, Z / other.Z, W / other.W);
	}

	inline Vector4 operator -=(Vector4 other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
		W -= other.W;
		return *this;
	}

	inline Vector4 operator +=(Vector4 other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;
		W += other.W;
		return *this;
	}

	inline Vector4 operator *=(float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;
		W *= scalar;
		return *this;
	}

	inline Vector4 operator *=(Vector4 other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;
		W *= other.W;
		return *this;
	}

	inline Vector4 operator /=(float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;
		W /= scalar;
		return *this;
	}

	inline Vector4 operator /=(Vector4 other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;
		W /= other.W;
		return *this;
	}

	inline bool operator ==(Vector4 other) const
	{
		return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
	}

	inline bool operator !=(Vector4 other) const
	{
		return X != other.X || Y != other.Y || Z != other.Z || W != other.W;
	}
};

inline Vector4 operator *(float scalar, Vector4 value)
{
	return value * scalar;
}

inline Vector4 operator /(float scalar, Vector4 value)
{
	return value / scalar;
}