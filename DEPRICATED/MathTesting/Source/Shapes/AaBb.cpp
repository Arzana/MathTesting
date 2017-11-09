#include "Shapes\AaBb.h"
#include "Core\Math.h"

const AaBb AaBb::Empty = AaBb(Vector2());

bool AaBb::AreColliding(AaBb other) const
{
	if (min(Right(), other.Right()) < max(Left(), other.Left())) return false;
	return min(Top(), other.Top()) >= max(Bottom(), other.Bottom());
}

bool AaBb::Contains(Vector2 v) const
{
	return v.X >= Left() && v.X <= Right() && v.Y >= Bottom() && v.Y <= Top();
}

AaBb AaBb::GetOverlap(AaBb other) const
{
	float xl = max(Left(), other.Left());
	float xs = min(Right(), other.Right());
	if (xs < xl) return Empty;

	float yl = max(Bottom(), other.Bottom());
	float ys = min(Top(), other.Top());
	if (ys < yl) return Empty;

	return AaBb(xl, ys, xs - xl, yl - ys);
}