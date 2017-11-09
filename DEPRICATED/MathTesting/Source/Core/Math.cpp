#include "Core\Math.h"

float angle(Vector2 value)
{
	return atan2(value.Y, value.X);
}

float angle(Vector2 value1, Vector2 value2)
{
	return angle(value2) - angle(value1);
}

Vector3 cross(Vector3 value1, Vector3 value2)
{
	return Vector3(
		value1.Y * value2.Z - value1.Z * value2.Y,
		value1.Z * value2.X - value1.X * value2.Z,
		value1.X * value2.Y - value1.Y * value2.X);
}

float determinant(Vector2 value1, Vector2 value2)
{
	return value1.X * value2.Y - value1.Y * value2.X;
}

int ipart(float value)
{
	return static_cast<int>(floor(value));
}

bool isUnit(float value)
{
	return value >= 0 && value <= 1;
}