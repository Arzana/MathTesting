#pragma once
#include "Vector2_Functions.h"
#include "Matrix3.h"

namespace DeJong
{
	/* Creates a 3x3 rotation matrix. */
	_Check_return_ Matrix3 rotation(_In_ float rads)
	{
		const float c = cosf(rads);
		const float s = sinf(rads);
		return Matrix3(c, -s, 0, s, c, 0, 0, 0, 1);
	}

	/* Creates a 3x3 scalar matrix. */
	_Check_return_ Matrix3 scale2D(_In_ float scalar)
	{
		return Matrix3(scalar, 0, 0, 0, scalar, 0, 0, 0, scalar);
	}

	/* Creates a 3x3 scalar matrix. */
	_Check_return_ Matrix3 scale(_In_ Vector2 scalar)
	{
		return Matrix3(scalar.X, 0, 0, 0, scalar.Y, 0, 0, 0, 1);
	}

	/* Creates a 3x3 translation matrix. */
	_Check_return_ Matrix3 translation(_In_ Vector2 offset)
	{
		return Matrix3(1, 0, offset.X, 0, 1, offset.Y, 0, 0, 1);
	}

	/* Composes a full view matrix. */
	_Check_return_ Matrix3 view(_In_ float scalar, _In_ float rads, _In_ Vector2 offset)
	{
		const float c = cosf(rads) * scalar;
		const float s = sinf(rads) * scalar;
		const float x = offset.X * scalar;
		const float y = offset.Y * scalar;
		return Matrix3(c, -s, x, s, c, y, 0, 0, scalar);
	}

	/* Transposes the specified matrix. */
	_Check_return_ Matrix3 transpose(_In_ Matrix3 &m)
	{
		return Matrix3(m.GetA(), m.GetD(), m.GetG(),
					   m.GetB(), m.GetE(), m.GetH(),
					   m.GetC(), m.GetF(), m.GetI());
	}

	/* Gets the determinant of the specified matrix. */
	_Check_return_ float det(_In_ const Matrix3 &m)
	{
		const float aei = m.GetA() * m.GetE() * m.GetI();
		const float bfg = m.GetB() * m.GetF() * m.GetG();
		const float cdh = m.GetC() * m.GetD() * m.GetH();
		const float ceg = m.GetC() * m.GetE() * m.GetG();
		const float bdi = m.GetB() * m.GetD() * m.GetI();
		const float afh = m.GetA() * m.GetF() * m.GetH();
		return aei + bfg + cdh - ceg - bdi - afh;
	}

	/* Calculates the cofactor matrix of the specified matrix. */
	_Check_return_ Matrix3 cofactor(_In_ const Matrix3 &m)
	{
		const float a = det(m.GetE(), m.GetF(), m.GetH(), m.GetI());
		const float b = -det(m.GetD(), m.GetF(), m.GetG(), m.GetI());
		const float c = det(m.GetD(), m.GetE(), m.GetG(), m.GetH());
		const float d = -det(m.GetB(), m.GetC(), m.GetH(), m.GetI());
		const float e = det(m.GetA(), m.GetC(), m.GetG(), m.GetI());
		const float f = -det(m.GetA(), m.GetB(), m.GetG(), m.GetH());
		const float g = det(m.GetB(), m.GetC(), m.GetE(), m.GetF());
		const float h = -det(m.GetA(), m.GetC(), m.GetD(), m.GetF());
		const float i = det(m.GetA(), m.GetB(), m.GetD(), m.GetE());
		return Matrix3(a, b, c, d, e, f, g, h, i);
	}

	/* Calculates the adjugate of the specified matrix. */
	_Check_return_ Matrix3 adj(_In_ const Matrix3 &m)
	{
		return transpose(cofactor(m));
	}

	/* Calculates the inverse of the specified matrix. */
	_Check_return_ Matrix3 inverse(_In_ const Matrix3 &m)
	{
		return recip(det(m)) * adj(m);
	}
}