#pragma once
#include "Vector3_Functions.h"
#include "Matrix3_Functions.h"
#include "Matrix4.h"

namespace DeJong
{
	/* Creates a rotation matrix around the three base axis. */
	_Check_return_ Matrix4 yawPitchRoll(_In_ float yaw, _In_ float pitch, _In_ float roll)
	{
		return rotationZ(roll) * rotationY(yaw) * rotationX(pitch);
	} 

	/* Creates a frustrum projection matrix. */
	_Check_return_ Matrix4 frustrum(_In_ float fovY, _In_ float aspr, _In_ float front, _In_ float back)
	{
		const float tangent = tanf(aspr * 0.5f);
		const float a = recip(aspr * tangent);
		const float f = recip(tangent);
		const float k = -(back + front) / (back - front);
		const float l = -(2.0f * back * front) / (back - front);
#if defined(RIGHT_HAND)
		const float o = -1;
#endif
#if defined(LEFT_HAND)
		const float o = 1;
#endif
		return Matrix4(a, 0, 0, 0, 0, f, 0, 0, 0, 0, k, l, 0, 0, o, 0);
	}

	/* Creates a frustrum projection matrix. */
	_Check_return_ Matrix4 frustrum(_In_ float top, _In_ float bottom, _In_ float left, _In_ float right, _In_ float front, _In_ float back)
	{
		const float a = (2.0f * front) / (right - left);
		const float f = (2.0f * front) / (top - bottom);
		const float c = (right + left) / (right - left);
		const float g = (top + bottom) / (top - bottom);
		const float k = -(back + front) / (back - front);
		const float l = -(2.0f * back * front) / (back - front);
#if defined(RIGHT_HAND)
		const float o = -1;
#endif
#if defined(LEFT_HAND)
		const float o = 1;
#endif

		return Matrix4(a, 0, c, 0, 0, f, g, 0, 0, 0, k, l, 0, 0, o, 0);
	}

	/* Creates a orthographic projection matrix. */
	_Check_return_ Matrix4 ortho(_In_ float width, _In_ float height, _In_ float front, _In_ float back)
	{
		const float a = 2.0f / width;
		const float f = 2.0f / height;
		const float k = 2.0f / (back - front);
		const float l = -(back + front) / (back - front);

		return Matrix4(a, 0, 0, -1, 0, f, 0, -1, 0, 0, k, l, 0, 0, 0, 0);
	}

	/* Creates a orthographic projection matrix. */
	_Check_return_ Matrix4 ortho(_In_ float top, _In_ float bottom, _In_ float left, _In_ float right, _In_ float front, _In_ float back)
	{
		const float a = 2.0f / (right - left);
		const float f = 2.0f / (top - bottom);
		const float k = 2.0f / (back - front);
		const float d = -(right + left) / (right - left);
		const float h = -(top + bottom) / (top - bottom);
		const float l = -(back + front) / (back - front);

		return Matrix4(a, 0, 0, d, 0, f, 0, h, 0, 0, k, l, 0, 0, 0, 0);
	}

	/* Creates a rotation matrix that specifies rotation around a specified axis. */
	_Check_return_ Matrix4 rotation(_In_ Vector3 axis, _In_ float rads)
	{
		const float cc = cosf(rads);
		const float ss = sinf(rads);
		const float xx = sqr(axis.X);
		const float xy = axis.X * axis.Y;
		const float xz = axis.X * axis.Z;
		const float yy = sqr(axis.Y);
		const float yz = axis.Y * axis.Z;
		const float zz = sqr(axis.Z);
		const float omc = 1 - cc;

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

	/* Creates a rotation matrix that specifies rotation around the X axis. */
	_Check_return_ Matrix4 rotationX(_In_ float rads)
	{
		const float c = cosf(rads);
		const float s = sinf(rads);
		return Matrix4(1, 0, 0, 0, 0, c, -s, 0, 0, s, c, 0, 0, 0, 0, 1);
	}

	/* Creates a rotation matrix that specifies rotation around the Y axis. */
	_Check_return_ Matrix4 rotationY(_In_ float rads)
	{
		const float c = cosf(rads);
		const float s = sinf(rads);
		return Matrix4(c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1);
	}

	/* Creates a rotation matrix that specifies rotation around the Z axis. */
	_Check_return_ Matrix4 rotationZ(_In_ float rads)
	{
		const float c = cosf(rads);
		const float s = sinf(rads);
		return Matrix4(c, -s, 0, 0, s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	}

	/* Creates a scalar matrix. */
	_Check_return_ Matrix4 scale3D(_In_ float scalar)
	{
		return Matrix4(scalar, 0, 0, 0, 0, scalar, 0, 0, 0, 0, scalar, 0, 0, 0, 0, 1);
	}

	/* Creates a scalar matrix. */
	_Check_return_ Matrix4 scale(_In_ Vector3 scalar)
	{
		return Matrix4(scalar.X, 0, 0, 0, 0, scalar.Y, 0, 0, 0, 0, scalar.Z, 0, 0, 0, 0, 1);
	}

	/* Creates a translation matrix. */
	_Check_return_ Matrix4 translation(_In_ Vector3 offset)
	{
		return Matrix4(1, 0, 0, offset.X, 0, 1, 0, offset.Y, 0, 0, 1, offset.Z, 0, 0, 0, 1);
	}

	/* Composes a full view matrix. */
	_Check_return_ Matrix4 view(_In_ float scalar, _In_ float yaw, _In_ float pitch, _In_ float roll, _In_ Vector3 offset)
	{
		return translation(offset) * yawPitchRoll(yaw, pitch, roll) * scale3D(scalar);
	}

	/* Creates a camera lookat matrix. */
	_Check_return_ Matrix4 lookat(_In_ Vector3 position, _In_ Vector3 target, _In_ Vector3 up)
	{
		const Vector3 axisZ = normalize(target - position);
		const Vector3 axisX = normalize(cross(up, axisZ));
		const Vector3 axisY = cross(axisZ, axisX);

		const float d = -dot(axisX, position);
		const float h = -dot(axisY, position);
		const float l = -dot(axisZ, position);

		return Matrix4(axisX.X, axisX.Y, axisX.Z, d, axisY.X, axisY.Y, axisY.Z, h, axisZ.X, axisZ.Y, axisZ.Z, l, 0, 0, 0, 1);
	}

	/* Creates a camera lookat matrix. */
	_Check_return_ inline Matrix4 lookat(_In_ Vector3 position, _In_ const Matrix4 &m)
	{
		return lookat(position, m.GetForward(), m.GetUp());
	}

	/* Transposes the specified matrix. */
	_Check_return_ Matrix4 transpose(_In_ const Matrix4 &m)
	{
		return Matrix4(m.GetA(), m.GetE(), m.GetI(), m.GetM(),
					   m.GetB(), m.GetF(), m.GetJ(), m.GetN(),
					   m.GetC(), m.GetG(), m.GetK(), m.GetO(),
					   m.GetD(), m.GetH(), m.GetL(), m.GetP());
	}

	/* Gets the determinant of the specified matrix. */
	_Check_return_ float det(_In_ const Matrix4 &m)
	{
		const Matrix3 m1 = Matrix3(m.GetF(), m.GetG(), m.GetH(), m.GetJ(), m.GetK(), m.GetL(), m.GetN(), m.GetO(), m.GetP());
		const Matrix3 m2 = Matrix3(m.GetE(), m.GetG(), m.GetH(), m.GetI(), m.GetK(), m.GetL(), m.GetM(), m.GetO(), m.GetP());
		const Matrix3 m3 = Matrix3(m.GetE(), m.GetF(), m.GetH(), m.GetI(), m.GetJ(), m.GetL(), m.GetM(), m.GetN(), m.GetP());
		const Matrix3 m4 = Matrix3(m.GetE(), m.GetF(), m.GetG(), m.GetI(), m.GetJ(), m.GetK(), m.GetM(), m.GetN(), m.GetO());
		return m.GetA() * det(m1) - m.GetB() * det(m2) + m.GetC() * det(m3) - m.GetD() * det(m4);
	}

	/* Calculates the cofactor matrix of the specified matrix. */
	_Check_return_ Matrix4 cofactor(_In_ const Matrix4 &m)
	{
		const Matrix3 m11 = Matrix3(m.GetF(), m.GetG(), m.GetH(), m.GetJ(), m.GetK(), m.GetL(), m.GetN(), m.GetO(), m.GetP());
		const Matrix3 m12 = Matrix3(m.GetE(), m.GetG(), m.GetH(), m.GetI(), m.GetK(), m.GetL(), m.GetM(), m.GetO(), m.GetP());
		const Matrix3 m13 = Matrix3(m.GetE(), m.GetF(), m.GetH(), m.GetI(), m.GetJ(), m.GetL(), m.GetM(), m.GetN(), m.GetP());
		const Matrix3 m14 = Matrix3(m.GetE(), m.GetF(), m.GetG(), m.GetI(), m.GetJ(), m.GetK(), m.GetM(), m.GetN(), m.GetO());
		const Matrix3 m21 = Matrix3(m.GetB(), m.GetC(), m.GetD(), m.GetJ(), m.GetK(), m.GetL(), m.GetN(), m.GetO(), m.GetP());
		const Matrix3 m22 = Matrix3(m.GetA(), m.GetC(), m.GetD(), m.GetI(), m.GetK(), m.GetL(), m.GetM(), m.GetO(), m.GetP());
		const Matrix3 m23 = Matrix3(m.GetA(), m.GetB(), m.GetD(), m.GetI(), m.GetJ(), m.GetL(), m.GetM(), m.GetN(), m.GetP());
		const Matrix3 m24 = Matrix3(m.GetA(), m.GetB(), m.GetC(), m.GetI(), m.GetJ(), m.GetK(), m.GetM(), m.GetN(), m.GetO());
		const Matrix3 m31 = Matrix3(m.GetB(), m.GetC(), m.GetD(), m.GetF(), m.GetG(), m.GetH(), m.GetN(), m.GetO(), m.GetP());
		const Matrix3 m32 = Matrix3(m.GetA(), m.GetC(), m.GetD(), m.GetE(), m.GetG(), m.GetH(), m.GetM(), m.GetO(), m.GetP());
		const Matrix3 m33 = Matrix3(m.GetA(), m.GetB(), m.GetD(), m.GetE(), m.GetF(), m.GetH(), m.GetM(), m.GetN(), m.GetP());
		const Matrix3 m34 = Matrix3(m.GetA(), m.GetB(), m.GetC(), m.GetE(), m.GetF(), m.GetG(), m.GetM(), m.GetN(), m.GetO());
		const Matrix3 m41 = Matrix3(m.GetB(), m.GetC(), m.GetD(), m.GetE(), m.GetF(), m.GetG(), m.GetJ(), m.GetK(), m.GetL());
		const Matrix3 m42 = Matrix3(m.GetA(), m.GetC(), m.GetD(), m.GetE(), m.GetG(), m.GetH(), m.GetI(), m.GetK(), m.GetL());
		const Matrix3 m43 = Matrix3(m.GetA(), m.GetB(), m.GetD(), m.GetE(), m.GetF(), m.GetH(), m.GetI(), m.GetJ(), m.GetK());
		const Matrix3 m44 = Matrix3(m.GetA(), m.GetB(), m.GetC(), m.GetE(), m.GetF(), m.GetG(), m.GetI(), m.GetJ(), m.GetK());

		return Matrix4(det(m11), -det(m12), det(m13), -det(m14),
					   -det(m21), det(m22), -det(m23), det(m24),
					   det(m31), -det(m32), det(m33), -det(m34),
					   -det(m41), det(m42), -det(m43), det(m44));
	}

	/* Calculates the adjugate of the specified matrix. */
	_Check_return_ Matrix4 adj(_In_ const Matrix4 &m)
	{
		return transpose(cofactor(m));
	}

	/* Calculates the inverse of the specified matrix. */
	_Check_return_ Matrix4 inverse(_In_ const Matrix4 &m)
	{
		return recip(det(m)) * adj(m);
	}
}