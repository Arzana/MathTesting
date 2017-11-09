#pragma once
#include "Core\Vector2.h"

struct Circle
{
	Vector2 pos;
	float rad;

	Circle(float rad)
		: pos(Vector2::Zero), rad(rad)
	{}

	Circle(Vector2 pos, float rad)
		: pos(pos), rad(rad)
	{}

	bool AreColliding(Circle other) const;
	bool Contains(Vector2 v) const;
	float GetIntersectionFactor(Circle other) const;
	float GetOverlap(Circle other) const;
};