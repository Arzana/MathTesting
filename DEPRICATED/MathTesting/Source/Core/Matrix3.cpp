#include <cmath>
#include "Core\Matrix3.h"

/* 
I have replaced Vector3::UnitX with a new vector because the C++ static initialization
order is determined at random but when I force a load by constructing a new vector this is fixed.
*/
const Matrix3 Matrix3::Identity = Matrix3(Vector3(1, 0, 0), Vector3::UnitY, Vector3::UnitZ);

Vector2 Matrix3::operator*(Vector2 vector) const
{
	return Vector2(vector.X * Column1.X + vector.Y * Column2.X + Column3.X,
				   vector.X * Column1.Y + vector.Y * Column2.Y + Column3.Y);
}

Vector3 operator*(Matrix3 m, Vector3 v)
{
	return v.X * m.Column1 + v.Y * m.Column2 + v.Z * m.Column3;
}

Matrix3 Matrix3::operator*(Matrix3 other) const
{
	return Matrix3(
		other * Column1,
		other * Column2,
		other * Column3);
}

Matrix3 Matrix3::operator*=(Matrix3 other)
{
	return *this = *this * other;
}

bool Matrix3::operator==(Matrix3 other) const
{
	return Column1 == other.Column1 && Column2 == other.Column2 && Column3 == other.Column3;
}

bool Matrix3::operator!=(Matrix3 other) const
{
	return Column1 != other.Column1 || Column2 != other.Column2 || Column3 != other.Column3;
}

Matrix3 Matrix3::Rotation(float rads)
{
	float c = cosf(rads);
	float s = sinf(rads);

	return Matrix3(c, -s, 0, s, c, 0, 0, 0, 1);
}

Matrix3 Matrix3::Scale(float scalar)
{
	return Matrix3(scalar, 0, 0, 0, scalar, 0, 0, 0, scalar);
}

Matrix3 Matrix3::Scale(Vector2 scalar)
{
	return Matrix3(scalar.X, 0, 0, 0, scalar.Y, 0, 0, 0, 1);
}

Matrix3 Matrix3::Translation(Vector2 offset)
{
	return Matrix3(1, 0, offset.X, 0, 1, offset.Y, 0, 0, 1);
}

Matrix3 Matrix3::View(float scalar, float rotation, Vector2 offset)
{
	float c = cosf(rotation) * scalar;
	float s = sinf(rotation) * scalar;
	float x = offset.X * scalar;
	float y = offset.Y * scalar;

	return Matrix3(c, -s, x, s, c, y, 0, 0, 1);
}

Matrix3 Matrix3::GetTranspose(void) const
{
	return Matrix3(Column1.X, Column1.Y, Column1.Z, Column2.X, Column2.Y, Column2.Z, Column3.X, Column3.Y, Column3.Z);
}