#include "Shapes\Line.h"
#include "Core\Math.h"

bool Line::Overlaps(Line other) const
{
	Vector2 d = other.v1 - v1;
	Vector2 r = v2 - v1;
	Vector2 s = other.v2 - other.v1;

	float rxs = determinant(r, s);
	float dxr = determinant(d, r);

	if (rxs == 0)
	{
		if (dxr == 0)
		{
			float rdr = dot(r, r);
			float t1 = dot(d, r) / rdr;
			float t2 = dot(other.v2 - v1, r) / rdr;
			return t2 - t1 > 0;
		}

		return false;
	}

	float t = determinant(d, s) / rxs;
	float u = dxr / rxs;
	return isUnit(t) && isUnit(u);
}

bool Line::Intersection(Line other, Vector2 * result) const
{
	Vector2 d = other.v1 - v1;
	Vector2 r = v2 - v1;
	Vector2 s = other.v2 - other.v1;

	float rxs = determinant(r, s);
	float dxr = determinant(d, r);

	if (rxs == 0)
	{
		if (dxr == 0)
		{
			float rdr = dot(r, r);
			float t1 = dot(d, r) / rdr;
			float t2 = dot(other.v2 - v1, r) / rdr;

			if (t2 - t1 > 0)
			{
				*result = other.v1;
				return true;
			}
		}

		return false;
	}

	float t = determinant(d, s) / rxs;
	float u = dxr / rxs;

	if (isUnit(t) && isUnit(u))
	{
		*result = v1 + t * r;
		return true;
	}

	return false;
}