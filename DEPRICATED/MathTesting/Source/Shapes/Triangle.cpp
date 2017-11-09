#include "Shapes\Triangle.h"
#include "Core\Math.h"

bool Triangle::Contains(Vector2 v)
{
	Vector2 w1 = v2 - v1;
	Vector2 w2 = v3 - v1;
	Vector2 p = v - v1;

	float r = determinant(w1, w2);
	float s = determinant(p, w2) / r;
	float t = determinant(w1, p) / r;

	return (s >= 0 && t >= 0 && (s + t) <= 1);
}