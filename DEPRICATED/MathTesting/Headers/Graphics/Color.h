#pragma once
#include "Core\Vector3.h"
#include "Core\Vector4.h"

typedef unsigned char byte;
typedef unsigned int uint;

struct Color
{
public:
	const static Color Transparent;
	const static Color Black;
	const static Color Red;
	const static Color Green;
	const static Color Blue;
	const static Color Cyan;
	const static Color Magenta;
	const static Color Yellow;
	const static Color White;

	Color(void);
	Color(uint packed);
	Color(byte r, byte g, byte b);
	Color(byte r, byte g, byte b, byte a);
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);
	Color(Vector3 values);
	Color(Vector4 values);

	Color operator +(Color other) const;
	Color operator -(Color other) const;
	Color operator *(float scalar) const;
	Color operator /(float scalar) const;
	bool operator ==(Color other) const;
	bool operator !=(Color other) const;

	static Color FromNonPremultiplied(byte r, byte g, byte b, byte a);
	static Color FromNonPremultiplied(Color color);
	static Color FromNonPremultiplied(Vector4 color);

	byte GetRed(void) const;
	byte GetGreen(void) const;
	byte GetBlue(void) const;
	byte GetAlpha(void) const;
	uint GetPacked(void) const;

private:
	uint packed;
};