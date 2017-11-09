#pragma once
#include "Core\Vector2.h"

struct Wedge
{
	Vector2 pos, dir;
	float rad;
	float theta;

	Wedge(float rad, float theta)
		: pos(Vector2::Zero), dir(Vector2::UnitX), rad(rad), theta(theta)
	{}

	Wedge(Vector2 dir, float rad, float theta)
		: pos(Vector2::Zero), dir(dir), rad(rad), theta(theta)
	{}

	Wedge(Vector2 pos, Vector2 dir, float rad, float theta)
		: pos(pos), dir(dir), rad(rad), theta(theta)
	{}

	bool Contains(Vector2 v) const;
};