#include "Graphics\Color.h"
#include "Core\Math.h"

constexpr uint OFFSET_R = 24;
constexpr uint OFFSET_G = 16;
constexpr uint OFFSET_B = 8;
constexpr uint OFFSET_A = 0;

constexpr uint MASK_R = 8 << OFFSET_R;
constexpr uint MASK_G = 8 << OFFSET_G;
constexpr uint MASK_B = 8 << OFFSET_B;
constexpr uint MASK_A = 8 << OFFSET_A;

inline byte toByte(int value)
{
	return static_cast<byte>(value);
}

inline byte bpart(float value)
{
	return toByte(ipart(value));
}

const Color Color::Transparent = Color();
const Color Color::Black = Color(MASK_A);
const Color Color::Red = Color(MASK_A | MASK_R);
const Color Color::Green = Color(MASK_A | MASK_G);
const Color Color::Blue = Color(MASK_A | MASK_B);
const Color Color::Cyan = Color(MASK_A | MASK_G | MASK_B);
const Color Color::Magenta = Color(MASK_A | MASK_R | MASK_B);
const Color Color::Yellow = Color(MASK_A | MASK_R | MASK_G);
const Color Color::White = Color(MASK_A | MASK_R | MASK_G | MASK_B);

Color::Color(void)
	: packed(0)
{}

Color::Color(uint packed)
	: packed(packed)
{}

Color::Color(byte r, byte g, byte b)
	: packed(MASK_A)
{
	packed |= (r << OFFSET_R) | (g << OFFSET_G) | (b << OFFSET_B);
}

Color::Color(byte r, byte g, byte b, byte a)
{
	packed |= (r << OFFSET_R) | (g << OFFSET_G) | (b << OFFSET_B) | (a << OFFSET_A);
}

Color::Color(float r, float g, float b)
	: Color(bpart(r * 255), bpart(g * 255), bpart(b * 255))
{}

Color::Color(float r, float g, float b, float a)
	: Color(bpart(r * 255), bpart(g * 255), bpart(b * 255), bpart(a * 255))
{}

Color::Color(Vector3 values)
	: Color(values.X, values.Y, values.Z)
{}

Color::Color(Vector4 values)
	: Color(values.X, values.Y, values.Z, values.W)
{}

Color Color::operator+(Color other) const
{
	return Color(toByte(GetRed() + other.GetRed()),
				 toByte(GetGreen() + other.GetGreen()),
				 toByte(GetBlue() + other.GetBlue()),
				 toByte(GetAlpha() + other.GetAlpha()));
}

Color Color::operator-(Color other) const
{
	return Color(toByte(GetRed() - other.GetRed()),
				 toByte(GetGreen() - other.GetGreen()),
				 toByte(GetBlue() - other.GetBlue()),
				 toByte(GetAlpha() - other.GetAlpha()));
}

Color Color::operator*(float scalar) const
{
	return Color(bpart(GetRed() * scalar),
				 bpart(GetGreen() * scalar),
				 bpart(GetBlue() * scalar),
				 bpart(GetAlpha() * scalar));
}

Color Color::operator/(float scalar) const
{
	return Color(bpart(GetRed() / scalar),
				 bpart(GetGreen() / scalar),
				 bpart(GetBlue() / scalar),
				 bpart(GetAlpha() / scalar));
}

bool Color::operator==(Color other) const
{
	return other.packed == packed;
}

bool Color::operator!=(Color other) const
{
	return other.packed != packed;
}

Color Color::FromNonPremultiplied(byte r, byte g, byte b, byte a)
{
	float alphaScale = a / 255.0f;
	return Color(bpart(r * alphaScale), bpart(g * alphaScale), bpart(b * alphaScale), a);
}

Color Color::FromNonPremultiplied(Color color)
{
	float alphaScale = color.GetAlpha() / 255.0f;
	byte r = bpart(color.GetRed() * alphaScale);
	byte g = bpart(color.GetGreen() * alphaScale);
	byte b = bpart(color.GetBlue() * alphaScale);
	return Color(r, g, b, color.GetAlpha());
}

Color Color::FromNonPremultiplied(Vector4 color)
{
	return Color(color.X * color.W, color.Y * color.W, color.Z * color.W, color.W);
}

byte Color::GetRed(void) const
{
	return (packed & MASK_R) >> OFFSET_R;
}

byte Color::GetGreen(void) const
{
	return (packed & MASK_G) >> OFFSET_G;
}

byte Color::GetBlue(void) const
{
	return (packed & MASK_B) >> OFFSET_B;
}

byte Color::GetAlpha(void) const
{
	return (packed & MASK_A) >> OFFSET_A;
}

uint Color::GetPacked(void) const
{
	return packed;
}