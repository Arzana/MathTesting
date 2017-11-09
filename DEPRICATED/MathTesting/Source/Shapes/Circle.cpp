#include "Shapes\Circle.h"
#include "Core\Math.h"

bool Circle::AreColliding(Circle other) const
{
	return dist(pos, other.pos) < rad + other.rad;
}

bool Circle::Contains(Vector2 v) const
{
	return dist(pos, v) <= rad;
}

float Circle::GetIntersectionFactor(Circle other) const
{
	return max(0.0f, (rad + other.rad) / 2 - dist(pos, other.pos));
}

float Circle::GetOverlap(Circle other) const
{
	// Get the distance to the other circle.
	float d = dist(pos, other.pos);
	if (d >= rad + other.rad) return 0;

	// Get the squares of both radii to reduce computation.
	float r1s = square(rad);
	float r2s = square(other.rad);

	// Get the height of the triangles.
	float h1 = (square(d) - r2s + r1s) / (2 * d);
	float h2 = d - h1;

	// Get the base of the traingles.
	float b1 = sqrt(r1s - square(h1));
	float b2 = sqrt(r2s - square(h2));

	// Get the angle of the intersection.
	float angle = asin(b1 / rad);

	// caclulate the areas of overlap.
	float a1 = angle * r1s - b1 * h1;
	float a2 = angle * r2s - b2 * h2;

	return a1 + a2;
}