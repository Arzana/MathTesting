#pragma once
#include "Core\Math.h"

struct Vertex2
{
	Vector4 Position;
	Vector4 Color;
	Vector2 TextureCoordinate;

	Vertex2(void)
	{}

	Vertex2(Vector4 color, Vector2 textureCoordinate)
		: Position(), Color(color), TextureCoordinate(textureCoordinate)
	{}

	Vertex2(Vector2 position, struct Color color, Vector2 textureCoordinate)
		: Position(toVector4(position)), Color(toVector4(color)), TextureCoordinate(textureCoordinate)
	{}
};