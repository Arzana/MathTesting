#pragma once
#include "Core\Matrix3.h"

struct Rect
{
	Vector2 v1, v2, v3, v4;
	const Matrix3 rot;

	Rect(Vector2 pos, Vector2 size, float rot)
		: v1(pos),
		v2(pos + Vector2::UnitX * size),
		v3(pos + Vector2::UnitY * size),
		v4(pos + size),
		rot(Matrix3::Rotation(rot))
	{
		if (rot != 0)
		{
			v1 = this->rot * v1;
			v2 = this->rot * v2;
			v3 = this->rot * v3;
			v4 = this->rot * v4;
		}
	}

	Vector2 LeftMost() const;
	Vector2 RightMost() const;
	Vector2 TopMost() const;
	Vector2 BottomMost() const;

	bool AreColliding(Rect *other) const;
};