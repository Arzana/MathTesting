#include "Shapes\Wedge.h"
#include "Core\Math.h"

bool Wedge::Contains(Vector2 v) const
{
	if (dist(pos, v) <= rad)
	{
		float a = angle(normalize(v), dir);
		float b = theta / 2;
		return a <= b && a >= -b;
	}

	return false;
}