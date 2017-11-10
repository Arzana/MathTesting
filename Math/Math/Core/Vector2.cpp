#include "Vector2.h"
#include <cmath>

using namespace DeJong;

const Vector2 Vector2::Zero = Vector2();
const Vector2 Vector2::UnitX = Vector2(1, 0);
const Vector2 Vector2::UnitY = Vector2(0, 1);
const Vector2 Vector2::One = Vector2(1);

Vector2 Vector2::Angle(float theta)
{
	return Vector2(cosf(theta), sinf(theta));
}
