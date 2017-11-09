#include "Graphics\Bitmap.h"

Bitmap::Bitmap(void)
	: w(0), h(0), data(nullptr)
{}

Bitmap::Bitmap(size_t width, size_t height)
	: w(width), h(height), data(new Color[width * height])
{
	Clear();
}

Bitmap::Bitmap(size_t width, size_t height, Color * data)
	: w(width), h(height), data(data)
{}

Bitmap::Bitmap(const Bitmap & other)
	: w(other.w), h(other.h), data(new Color[other.w * other.h])
{
	for (size_t y = 0; y < h; y++)
	{
		for (size_t x = 0; x < w; x++)
		{
			size_t i = y * w + x;
			data[i] = other.data[i];
		}
	}
}

Bitmap::~Bitmap(void)
{
	if (data) delete[] data;
}

Bitmap & Bitmap::operator=(const Bitmap & other)
{
	return Bitmap(other);
}

Color Bitmap::GetPixel(size_t x, size_t y) const
{
	CheckRange(x, y);
	return data[y * w + x];
}

byte Bitmap::GetRed(size_t x, size_t y) const
{
	return GetPixel(x, y).GetRed();
}

byte Bitmap::GetGreen(size_t x, size_t y) const
{
	return GetPixel(x, y).GetGreen();
}

byte Bitmap::GetBlue(size_t x, size_t y) const
{
	return GetPixel(x, y).GetBlue();
}

byte Bitmap::GetAlpha(size_t x, size_t y) const
{
	return GetPixel(x, y).GetAlpha();
}

size_t Bitmap::GetWidth(void) const
{
	return w;
}

size_t Bitmap::GetHeight(void) const
{
	return h;
}

Vector2 Bitmap::GetSize(void) const
{
	return Vector2(static_cast<float>(w), static_cast<float>(h));
}

Bitmap * Bitmap::FlipVertical(void) const
{
	Color *result = new Color[w * h];

	for (size_t y1 = 0; y1 < h / 2; y1++)
	{
		size_t y2 = h - y1 - 1;

		for (size_t x = 0; x < w; x++)
		{
			size_t i1 = y1 * w + x;
			size_t i2 = y2 * w + x;

			Color temp = data[i2];
			data[i2] = data[i1];
			data[i1] = temp;
		}
	}

	return new Bitmap(w, h, result);
}

Bitmap * Bitmap::FlipHorizontal(void) const
{
	Color *result = new Color[w * h];

	for (size_t x1 = 0; x1 < w / 2; x1++)
	{
		size_t x2 = w - x1 - 1;

		for (size_t y = 0; y < h; y++)
		{
			size_t i1 = y * w + x1;
			size_t i2 = y * w + x2;

			Color temp = data[i2];
			data[i2] = data[i1];
			data[i1] = temp;
		}
	}

	return new Bitmap(w, h, result);
}

void Bitmap::SetPixel(size_t x, size_t y, Color pixel)
{
	CheckRange(x, y);
	data[y * w + x] = pixel;
}

void Bitmap::Clear(void)
{
	Clear(Color::Transparent);
}

void Bitmap::Clear(Color color)
{
	size_t size = w * h;
	for (size_t i = 0; i < size; i++)
	{
		data[i] = color;
	}
}

void Bitmap::CheckRange(size_t x, size_t y) const
{
	if (x > w || y > h) throw "Pixel position is out of range in bitmap access!";
	if (data == nullptr) throw "Cannot get or set data in empty bitmap!";
}