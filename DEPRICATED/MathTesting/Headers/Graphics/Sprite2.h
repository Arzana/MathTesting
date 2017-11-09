#pragma once
#include "Core\Matrix4.h"
#include "Graphics\Vertex2.h"

struct Sprite2
{
public:
	const Vector2 Size;

	Sprite2(const char *path, Vector2 size);

	void SetRotation(float rads);
	void SetPosition(Vector2 position);
	void SetOrigin(Vector2 origin);
	void SetBounds(Vector2 position, Vector2 size);
	void SetTint(Color color);
	void SetScale(Vector2 scale);

	uint GetId(void) const;
	Matrix4 GetTransform(void) const;
	Vector4 GetTint(void) const;
	Vector2 GetUvScale(void) const;
	Vector2 GetUvOffset(void) const;

private:
	Vertex2 vertices[4];
	uint id;

	float rotation;
	Vector3 position;
	Vector2 origin;
	Vector3 scale;
	Vector4 tint;

	Vector2 UvMin;
	Vector2 UvMax;
	Vector2 UvScale;
	Vector2 UvOffset;
};