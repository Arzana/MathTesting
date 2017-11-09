#include "Core\Matrix4.h"
#include "Core\Math.h"

/*
I have replaced Vector4::UnitX with a new vector because the C++ static initialization
order is determined at random but when I force a load by constructing a new vector this is fixed.
*/
const Matrix4 Matrix4::Identity = Matrix4(Vector4(1, 0, 0, 0), Vector4::UnitY, Vector4::UnitZ, Vector4::UnitW);

Vector4 Matrix4::operator*(Vector3 vector) const
{
	return vector.X * Column1 + vector.Y * Column2 + vector.Z * Column3 + Column4;
}

Vector4 operator*(Matrix4 m, Vector4 v)
{
	return v.X * m.Column1 + v.Y * m.Column2 + v.Z * m.Column3 + v.W * m.Column4;
}

Matrix4 Matrix4::operator*(Matrix4 other) const
{
	return Matrix4(
		other * Column1,
		other * Column2,
		other * Column3,
		other * Column4);
}

Matrix4 Matrix4::operator*=(Matrix4 other)
{
	return *this = *this * other;
}

bool Matrix4::operator==(Matrix4 other) const
{
	return Column1 == other.Column1 && Column2 == other.Column2 && Column3 == other.Column3 && Column4 == other.Column4;
}

bool Matrix4::operator!=(Matrix4 other) const
{
	return Column1 != other.Column1 || Column2 != other.Column2 || Column3 != other.Column3 || Column4 != other.Column4;
}

Matrix4 Matrix4::YawPitchRoll(float yaw, float pitch, float roll)
{
	Matrix4 result = RotationZ(roll);
	result *= RotationY(yaw);
	return result * RotationX(pitch);
}

Matrix4 Matrix4::Frustrum(float fovY, float aspr, float front, float back)
{
	const float tangent = tanf(fovY / 2.0f);

	float a = 1.0f / (aspr * tangent);
	float f = 1.0f / tangent;
	float k = -(back + front) / (back - front);
	float l = -(2.0f * back * front) / (back - front);

	return Matrix4(a, 0, 0, 0, 0, f, 0, 0, 0, 0, k, l, 0, 0, 1, 0);
}

Matrix4 Matrix4::Frustrum(float top, float bottom, float left, float right, float front, float back)
{
	float a = (2.0f * front) / (right - left);
	float f = (2.0f * front) / (top - bottom);
	float c = (right + left) / (right - left);
	float g = (top + bottom) / (top - bottom);
	float k = -(back + front) / (back - front);
	float l = -(2.0f * back * front) / (back - front);

	return Matrix4(a, 0, c, 0, 0, f, g, 0, 0, 0, k, l, 0, 0, -1, 0);
}

Matrix4 Matrix4::Ortho(float width, float height, float front, float back)
{
	float a = 2.0f / width;
	float f = 2.0f / height;
	float k = 2.0f / (back - front);
	float l = -(back + front) / (back - front);

	return Matrix4(a, 0, 0, -1, 0, f, 0, -1, 0, 0, k, l, 0, 0, 0, 0);
}

Matrix4 Matrix4::Ortho(float left, float right, float top, float bottom, float front, float back)
{
	float a = 2.0f / (right - left);
	float f = 2.0f / (top - bottom);
	float k = 2.0f / (back - front);
	float d = -(right + left) / (right - left);
	float h = -(top + bottom) / (top - bottom);
	float l = -(back + front) / (back - front);

	return Matrix4(a, 0, 0, d, 0, f, 0, h, 0, 0, k, l, 0, 0, 0, 0);
}

Matrix4 Matrix4::Rotation(Vector3 axis, float rads)
{
	float cc = cosf(rads);
	float ss = sinf(rads);
	float xx = square(axis.X);
	float xy = axis.X * axis.Y;
	float xz = axis.X * axis.Z;
	float yy = square(axis.Y);
	float yz = axis.Y * axis.Z;
	float zz = square(axis.Z);
	float omc = 1 - cc;

	float a = xx * omc + cc;
	float b = xy * omc - axis.Z * ss;
	float c = xz * omc + axis.Y * ss;
	float e = xy * omc + axis.Z * ss;
	float f = yy * omc + cc;
	float g = yz * omc - axis.X * ss;
	float i = xz * omc - axis.Y * ss;
	float j = yz * omc + axis.X * ss;
	float k = zz * omc + cc;
	
	return Matrix4(a, b, c, 0, e, f, g, 0, i, j, k, 0, 0, 0, 0, 1);
}

Matrix4 Matrix4::RotationX(float rads)
{
	float c = cosf(rads);
	float s = sinf(rads);

	return Matrix4(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
}

Matrix4 Matrix4::RotationY(float rads)
{
	float c = cosf(rads);
	float s = cosf(rads);

	return Matrix4(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
}

Matrix4 Matrix4::RotationZ(float rads)
{
	float c = cosf(rads);
	float s = cosf(rads);

	return Matrix4(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

Matrix4 Matrix4::Scale(float scalar)
{
	return Matrix4(scalar, 0, 0, 0, 0, scalar, 0, 0, 0, 0, scalar, 0, 0, 0, 0, 1);
}

Matrix4 Matrix4::Scale(Vector3 scalar)
{
	return Matrix4(scalar.X, 0, 0, 0, 0, scalar.Y, 0, 0, 0, 0, scalar.Z, 0, 0, 0, 0, 1);
}

Matrix4 Matrix4::Translation(Vector3 offset)
{
	return Matrix4(1, 0, 0, offset.X, 0, 1, 0, offset.Y, 0, 0, 1, offset.Z, 0, 0, 0, 1);
}

Matrix4 Matrix4::View(float scalar, float rotation, Vector3 offset)
{
	float c = cosf(rotation) * scalar;
	float s = sinf(rotation) * scalar;
	float x = offset.X * scalar;
	float y = offset.Y * scalar;
	float z = offset.Z * scalar;

	return Matrix4(c, -s, 0, x, s, c, 0, y, 0, 0, scalar, z, 0, 0, 0, 1);
}

Matrix4 Matrix4::LookAt(Vector3 position, Vector3 target, Vector3 up)
{
	Vector3 axisZ = normalize(target - position);
	Vector3 axisX = normalize(cross(up, axisZ));
	Vector3 axisY = cross(axisZ, axisX);

	float d = -dot(axisX, position);
	float h = -dot(axisY, position);
	float l = -dot(axisZ, position);

	return Matrix4(axisX.X, axisX.Y, axisX.Z, d, axisY.X, axisY.Y, axisY.Z, h, axisZ.X, axisZ.Y, axisZ.Z, l, 0, 0, 0, 1);
}

Matrix4 Matrix4::GetTranspose(void) const
{
	return Matrix4(Column1.X, Column1.Y, Column1.Z, Column1.W, 
				   Column2.X, Column2.Y, Column2.Z, Column2.W, 
				   Column3.X, Column3.Y, Column3.Z, Column3.W,
				   Column4.X, Column4.Y, Column4.Z, Column4.W);
}

void Matrix4::Normalize(void) 
{
	Column1 = normalize(Column1);
	Column2 = normalize(Column2);
	Column3 = normalize(Column3);
}
