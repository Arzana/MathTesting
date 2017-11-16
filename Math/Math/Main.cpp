#include "Core\Matrix4_Functions.h"

using namespace DeJong;

int main(void)
{
	Matrix3 a = rotation(PI2);
	Matrix3 b = inverse(a);
	Vector2 v = Vect2::UnitX * a;
	Vector2 u = v * b;

	Matrix4 A = rotationZ(PI2);
	Matrix4 B = inverse(A);
	Vector4 V = Vect4::UnitX * A;
	Vector4 U = V * B;

	return 0;
}