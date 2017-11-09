#include "Shapes\Rect.h"
#include "Shapes\Line.h"
#include "Core\Math.h"

Vector2 Rect::LeftMost() const
{
	Vector2 lowestX = v1;
	if (v2.X < lowestX.X) lowestX = v2;
	if (v3.X < lowestX.X) lowestX = v3;
	if (v4.X < lowestX.X) lowestX = v4;
	return lowestX;
}

Vector2 Rect::RightMost() const
{
	Vector2 highestX = v1;
	if (v2.X > highestX.X) highestX = v2;
	if (v3.X > highestX.X) highestX = v3;
	if (v4.X > highestX.X) highestX = v4;
	return highestX;
}

Vector2 Rect::TopMost() const
{
	Vector2 lowestY = v1;
	if (v2.Y < lowestY.Y) lowestY = v2;
	if (v3.Y < lowestY.Y) lowestY = v3;
	if (v4.Y < lowestY.Y) lowestY = v4;
	return lowestY;
}

Vector2 Rect::BottomMost() const
{
	Vector2 highestY = v1;
	if (v2.Y > highestY.Y) highestY = v2;
	if (v3.Y > highestY.Y) highestY = v3;
	if (v4.Y > highestY.Y) highestY = v4;
	return highestY;
}

bool Rect::AreColliding(Rect * other) const
{
	/* Get the normals of the 2 cubes */
	Vector2 n1x = rot * Vector2::UnitX;
	Vector2 n1y = rot * Vector2::UnitY;
	Vector2 n2x = rot * Vector2::UnitX;

	/* Project the first cube on its normal */
	Line p11x(n1x * dot(n1x, LeftMost()), n1x * dot(n1x, RightMost()));
	Line p11y(n1y * dot(n1y, TopMost()), n1y * dot(n1y, BottomMost()));

	/* Project the second cube on the first cubes normal */
	Line p21x(n1x * dot(n1x, other->LeftMost()), n1x * dot(n1x, other->RightMost()));
	Line p21y(n1y * dot(n1y, other->TopMost()), n1y * dot(n1y, other->BottomMost()));

	/* Check for overlap */
	if (!p11x.Overlaps(p21x)) return false;
	if (!p11y.Overlaps(p21y)) return false;

	if (n1x != n2x)
	{
		Vector2 n2y = rot * Vector2::UnitY;

		/* Project the first cube on the second cubes normal */
		Line p12x(n2x * dot(n2x, LeftMost()), n2x * dot(n2x, RightMost()));
		Line p12y(n2y * dot(n2y, TopMost()), n2y * dot(n2y, BottomMost()));

		/* Project the second cube on its normal */
		Line p22x(n2x * dot(n2x, other->LeftMost()), n2x * dot(n2x, other->RightMost()));
		Line p22y(n2y * dot(n2y, other->TopMost()), n2y * dot(n2y, other->BottomMost()));

		/* Check for overlap */
		if (!p12x.Overlaps(p22x)) return false;
		if (!p12y.Overlaps(p22y)) return false;
	}

	return true;
}
