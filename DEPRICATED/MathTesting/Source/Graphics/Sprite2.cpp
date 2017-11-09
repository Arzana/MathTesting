#include "Graphics\Sprite2.h"

Sprite2::Sprite2(const char * path, Vector2 size)
	: Size(size), rotation(0), position(Vector3::UnitZ), scale(toVector3(size)), tint(Vector4::One)
{
	/* Initialize vertices. */
	vertices[0] = Vertex2(Vector4::One, Vector2::Zero);
	vertices[1] = Vertex2(Vector4::One, Vector2::UnitX);
	vertices[2] = Vertex2(Vector4::One, Vector2::UnitY);
	vertices[3] = Vertex2(Vector4::One, Vector2::One);
	SetOrigin(Vector2::Zero);

	/* Initialize UV coordinates. */
	SetBounds(Vector2::Zero, Vector2::One);

	//TODO: load texture and set id.
}

void Sprite2::SetRotation(float rads)
{
	rotation = rads;
}

void Sprite2::SetPosition(Vector2 position)
{
	this->position = Vector3(position.X, position.Y, 0);
}

void Sprite2::SetOrigin(Vector2 origin)
{
	/* Rectify input. */
	if (origin.X > 1.0f || origin.Y > 1.0f)
	{
		origin /= toVector2(scale);
	}

	/* Set property. */
	this->origin = origin;

	/* Calculate new points. */
	Vector2 bl = Vector2::Zero - origin;
	Vector2 br = Vector2::UnitX - origin;
	Vector2 tl = Vector2::UnitY - origin;
	Vector2 tr = Vector2::One - origin;

	/* Set points. */
	vertices[0].Position = toVector4(bl);
	vertices[1].Position = toVector4(br);
	vertices[2].Position = toVector4(tl);
	vertices[3].Position = toVector4(tr);
}

void Sprite2::SetBounds(Vector2 position, Vector2 size)
{
	/* Rectify input. */
	if (position.X > 1.0f || position.Y > 1.0f)
	{
		position /= toVector2(scale);
	}

	if (size.X > 1.0f || size.Y > 1.0f)
	{
		size /= toVector2(scale);
	}

	/* Set values. */
	UvMin = position;
	UvMax = position + size;
	UvScale = UvMax - UvMin;
	UvOffset = UvMin;
}

void Sprite2::SetTint(Color color)
{
	tint = toVector4(color);
}

void Sprite2::SetScale(Vector2 scale)
{
	this->scale = toVector3(scale);
}

uint Sprite2::GetId(void) const
{
	return id;
}

Matrix4 Sprite2::GetTransform(void) const
{
	return Matrix4::Scale(scale) * Matrix4::RotationZ(rotation) * Matrix4::Translation(position);
}

Vector4 Sprite2::GetTint(void) const
{
	return tint;
}

Vector2 Sprite2::GetUvScale(void) const
{
	return UvScale;
}

Vector2 Sprite2::GetUvOffset(void) const
{
	return UvOffset;
}
