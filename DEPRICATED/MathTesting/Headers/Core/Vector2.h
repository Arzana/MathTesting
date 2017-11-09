#pragma once

struct Vector2
{
public:
	const static Vector2 Zero;
	const static Vector2 UnitX;
	const static Vector2 UnitY;
	const static Vector2 One;

	float X;
	float Y;

	Vector2(void)
		: X(0), Y(0)
	{}

	Vector2(float value)
		: X(value), Y(value)
	{}

	Vector2(float x, float y)
		: X(x), Y(y)
	{}

	inline Vector2 operator -(void) const
	{
		return Vector2(-X, -Y);
	}

	inline Vector2 operator -(Vector2 other) const
	{
		return Vector2(X - other.X, Y - other.Y);
	}

	inline Vector2 operator +(Vector2 other) const
	{
		return Vector2(X + other.X, Y + other.Y);
	}

	inline Vector2 operator *(float scalar) const
	{
		return Vector2(X * scalar, Y * scalar);
	}

	inline Vector2 operator *(Vector2 scalar) const
	{
		return Vector2(X * scalar.X, Y * scalar.Y);
	}

	inline Vector2 operator /(float scalar) const
	{
		return Vector2(X / scalar, Y / scalar);
	}

	inline Vector2 operator /(Vector2 scalar) const
	{
		return Vector2(X / scalar.X, Y / scalar.Y);
	}

	inline Vector2 operator -=(Vector2 other)
	{
		X -= other.X;
		Y -= other.Y;
		return *this;
	}

	inline Vector2 operator +=(Vector2 other)
	{
		X += other.X;
		Y += other.Y;
		return *this;
	}

	inline Vector2 operator *=(float scalar)
	{
		X *= scalar;
		Y *= scalar;
		return *this;
	}

	inline Vector2 operator *=(Vector2 scalar)
	{
		X *= scalar.X;
		Y *= scalar.Y;
		return *this;
	}

	inline Vector2 operator /=(float scalar)
	{
		X /= scalar;
		Y /= scalar;
		return *this;
	}

	inline Vector2 operator /=(Vector2 scalar)
	{
		X /= scalar.X;
		Y /= scalar.Y;
		return *this;
	}

	inline bool operator ==(Vector2 other) const
	{
		return X == other.X && Y == other.Y;
	}

	inline bool operator !=(Vector2 other) const
	{
		return X != other.X || Y != other.Y;
	}
};

inline Vector2 operator *(float scalar, Vector2 value)
{
	return value * scalar;
}

inline Vector2 operator /(float scalar, Vector2 value)
{
	return value / scalar;
}