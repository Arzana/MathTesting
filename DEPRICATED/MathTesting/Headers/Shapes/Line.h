#pragma once
#include "Core\Vector2.h"

struct Line
{
	const Vector2 v1, v2;

	Line(Vector2 v1, Vector2 v2)
		: v1(v1), v2(v2)
	{}

	bool Overlaps(Line other) const;
	bool Intersection(Line other, Vector2 *result) const;
};