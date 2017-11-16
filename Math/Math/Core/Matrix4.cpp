#include "Matrix4.h"

using namespace DeJong;

/*
|1 0 0 0|
|0 1 0 0|
|0 0 1 0|
|0 0 0 1|
*/
const Matrix4 Matrix4::Identity = Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

Matrix4 DeJong::Matrix4::operator*(float scalar) const
{
#if defined(COLUMN_MAJOR)
	return Matrix4(Column1 * scalar, Column2 * scalar, Column3 * scalar, Column4 * scalar);
#endif
#if defined(ROW_MAJOR)
	return Matrix4(Row1 * scalar, Row2 * scalar, Row3 * scalar, Row4 * scalar);
#endif
}

Vector4 DeJong::Matrix4::operator*(Vector3 v) const
{
#if defined(COLUMN_MAJOR)
	return v.X * Column1 + v.Y * Column2 + v.Z * Column3 + Column4;
#endif
#if defined(ROW_MAJOR)
	return Vector4(v.X * Row1.X + v.Y * Row1.Y + v.Z * Row1.Z + Row1.W,
				   v.X * Row2.X + v.Y * Row2.Y + v.Z * Row2.Z + Row2.W,
				   v.X * Row3.X + v.Y * Row3.Y + v.Z * Row3.Z + Row3.W,
				   v.X * Row4.X + v.Y * Row4.Y + v.Z * Row4.Z + Row4.W);
#endif
}

Vector4 DeJong::Matrix4::operator*(Vector4 v) const
{
#if defined(COLUMN_MAJOR)
	return v.X * Column1 + v.Y * Column2 + v.Z * Column3 + v.W * Column4;
#endif
#if defined(ROW_MAJOR)
	return Vector4(v.X * Row1.X + v.Y * Row1.Y + v.Z * Row1.Z + v.W * Row1.W,
				   v.X * Row2.X + v.Y * Row2.Y + v.Z * Row2.Z + v.W * Row2.W,
				   v.X * Row3.X + v.Y * Row3.Y + v.Z * Row3.Z + v.W * Row3.W,
				   v.X * Row4.X + v.Y * Row4.Y + v.Z * Row4.Z + v.W * Row4.W);
#endif
}

Matrix4 DeJong::Matrix4::operator*(const Matrix4 & m) const
{
#if defined(COLUMN_MAJOR)
	return Matrix4(m * Column1, m * Column2, m * Column3, m * Column4);
#endif
#if defined(ROW_MAJOR)
	const float a = Row1.X * m.Row1.X + Row1.Y * m.Row2.X + Row1.Z * m.Row3.X + Row1.W * m.Row4.X;
	const float b = Row1.X * m.Row1.Y + Row1.Y * m.Row2.Y + Row1.Z * m.Row3.Y + Row1.W * m.Row4.Y;
	const float c = Row1.X * m.Row1.Z + Row1.Y * m.Row2.Z + Row1.Z * m.Row3.Z + Row1.W * m.Row4.Z;
	const float d = Row1.X * m.Row1.W + Row1.Y * m.Row2.W + Row1.Z * m.Row3.W + Row1.W * m.Row4.W;
	const float e = Row2.X * m.Row1.X + Row2.Y * m.Row2.X + Row2.Z * m.Row3.X + Row2.W * m.Row4.X;
	const float f = Row2.X * m.Row1.Y + Row2.Y * m.Row2.Y + Row2.Z * m.Row3.Y + Row2.W * m.Row4.Y;
	const float g = Row2.X * m.Row1.Z + Row2.Y * m.Row2.Z + Row2.Z * m.Row3.Z + Row2.W * m.Row4.Z;
	const float h = Row2.X * m.Row1.W + Row2.Y * m.Row2.W + Row2.Z * m.Row3.W + Row2.W * m.Row4.W;
	const float i = Row3.X * m.Row1.X + Row3.Y * m.Row2.X + Row3.Z * m.Row3.X + Row3.W * m.Row4.X;
	const float j = Row3.X * m.Row1.Y + Row3.Y * m.Row2.Y + Row3.Z * m.Row3.Y + Row3.W * m.Row4.Y;
	const float k = Row3.X * m.Row1.Z + Row3.Y * m.Row2.Z + Row3.Z * m.Row3.Z + Row3.W * m.Row4.Z;
	const float l = Row3.X * m.Row1.W + Row3.Y * m.Row2.W + Row3.Z * m.Row3.W + Row3.W * m.Row4.W;
	const float _m = Row4.X * m.Row1.X + Row4.Y * m.Row2.X + Row4.Z * m.Row4.X + Row4.W * m.Row4.X;
	const float n = Row4.X * m.Row1.Y + Row4.Y * m.Row2.Y + Row4.Z * m.Row4.Y + Row4.W * m.Row4.Y;
	const float o = Row4.X * m.Row1.Z + Row4.Y * m.Row2.Z + Row4.Z * m.Row4.Z + Row4.W * m.Row4.Z;
	const float p = Row4.X * m.Row1.W + Row4.Y * m.Row2.W + Row4.Z * m.Row4.W + Row4.W * m.Row4.W;
	return Matrix4(a, b, c, d, e, f, g, h, i, j, k, l, _m, n, o, p);
#endif
}

bool DeJong::Matrix4::operator==(const Matrix4 & m) const
{
#if defined(COLUMN_MAJOR)
	return Column1 == m.Column1 && Column2 == m.Column2 && Column3 == m.Column3 && Column4 == m.Column4;
#endif
#if defined(ROW_MAJOR)
	return Row1 == m.Row1 && Row2 == m.Row2 && Row3 == m.Row3 && Row4 == m.Row4;
#endif
}

bool DeJong::Matrix4::operator!=(const Matrix4 & m) const
{
#if defined(COLUMN_MAJOR)
	return Column1 != m.Column1 || Column2 != m.Column2 || Column3 != m.Column3 || Column4 != m.Column4;
#endif
#if defined(ROW_MAJOR)
	return Row1 != m.Row1 || Row2 != m.Row2 || Row3 != m.Row3 || Row4 != m.Row4;
#endif
}