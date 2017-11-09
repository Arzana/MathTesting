#pragma once
#include "Core\Vector2.h"

struct AaBb
{
	const static AaBb Empty;

	Vector2 pos, size;

	AaBb(Vector2 size)
		: pos(Vector2::Zero), size(size)
	{}

	AaBb(Vector2 pos, Vector2 size)
		: pos(pos), size(size)
	{}

	AaBb(float x, float y, float w, float h)
		: pos(x, y), size(w, h)
	{}

	inline float Top(void) const
	{
		return size.Y > 0 ? pos.Y : pos.Y + size.Y;
	}
	inline float Right(void) const
	{
		return size.X > 0 ? pos.X + size.X : pos.X;
	}
	inline float Bottom(void) const
	{
		return size.Y > 0 ? pos.Y + size.Y : pos.Y;
	}
	inline float Left(void) const
	{
		return size.X > 0 ? pos.X : pos.X + size.X;
	}

	bool AreColliding(AaBb other) const;
	bool Contains(Vector2 v) const;
	AaBb GetOverlap(AaBb other) const;
};