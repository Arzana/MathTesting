#pragma once
#include "Core\Vector2.h"

struct Triangle
{
	Vector2 v1, v2, v3;

	Triangle(void)
		: v1(), v2(), v3()
	{}

	Triangle(Vector2 v1, Vector2 v2, Vector2 v3)
		: v1(v1), v2(v2), v3(v3)
	{}

	bool Contains(Vector2 v);
};