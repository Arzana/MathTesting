#pragma once
#include "Core\Vector2.h"
#include "Graphics\Color.h"

struct Bitmap
{
public:
	Bitmap(void);
	Bitmap(size_t width, size_t height);
	Bitmap(size_t width, size_t height, Color *data);
	Bitmap(const Bitmap& other);
	~Bitmap(void);

	Bitmap& operator=(const Bitmap& other);

	Color GetPixel(size_t x, size_t y) const;
	byte GetRed(size_t x, size_t y) const;
	byte GetGreen(size_t x, size_t y) const;
	byte GetBlue(size_t x, size_t y) const;
	byte GetAlpha(size_t x, size_t y) const;
	size_t GetWidth(void) const;
	size_t GetHeight(void) const;
	Vector2 GetSize(void) const;

	Bitmap* FlipVertical(void) const;
	Bitmap* FlipHorizontal(void) const;

	void SetPixel(size_t x, size_t y, Color pixel);
	void Clear(void);
	void Clear(Color color);

private:
	size_t w, h;
	Color *data;

	void CheckRange(size_t x, size_t y) const;
};