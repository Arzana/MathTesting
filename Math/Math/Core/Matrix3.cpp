#include "Matrix3.h"

using namespace DeJong;

/*
|1 0 0|
|0 1 0|
|0 0 1|
*/
const Matrix3 Matrix3::Identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);

Vector2 DeJong::Matrix3::operator*(Vector2 v) const
{
#if defined(COLUMN_MAJOR)
	return Vector2(v.X * Column1.X + v.Y * Column2.X + Column3.X,
				   v.X * Column1.Y + v.Y * Column2.Y + Column3.Y);
#endif
#if defined(ROW_MAJOR)
	return Vector2(v.X * Row1.X + v.Y * Row1.Y + Row1.Z,
				   v.X * Row2.X + v.Y * Row2.Y + Row2.Z);
#endif
}

Vector3 DeJong::Matrix3::operator*(Vector3 v) const
{
#if defined(COLUMN_MAJOR)
	return v.X * Column1 + v.Y * Column2 + v.Z * Column3;
#endif
#if defined(ROW_MAJOR)
	return Vector3(v.X * Row1.X + v.Y * Row1.Y + v.Z * Row1.Z,
				   v.X * Row2.X + v.Y * Row2.Y + v.Z * Row2.Z,
				   v.X * Row3.X + v.Y * Row3.Y + v.Z * Row3.Z);
#endif
}

Matrix3 DeJong::Matrix3::operator*(const Matrix3 &m) const
{
#if defined(COLUMN_MAJOR)
	return Matrix3(m * Column1, m * Column2, m * Column3);
#endif
#if defined(ROW_MAJOR)
	const float a = Row1.X * m.Row1.X + Row1.Y * m.Row2.X + Row1.Z * m.Row3.X;
	const float b = Row1.X * m.Row1.Y + Row1.Y * m.Row2.Y + Row1.Z * m.Row3.Y;
	const float c = Row1.X * m.Row1.Z + Row1.Y * m.Row2.Z + Row1.Z * m.Row3.Z;
	const float d = Row2.X * m.Row1.X + Row2.Y * m.Row2.X + Row2.Z * m.Row3.X;
	const float e = Row2.X * m.Row1.Y + Row2.Y * m.Row2.Y + Row2.Z * m.Row3.Y;
	const float f = Row2.X * m.Row1.Z + Row2.Y * m.Row2.Z + Row2.Z * m.Row3.Z;
	const float g = Row3.X * m.Row1.X + Row3.Y * m.Row2.X + Row3.Z * m.Row3.X;
	const float h = Row3.X * m.Row1.Y + Row3.Y * m.Row2.Y + Row3.Z * m.Row3.Y;
	const float i = Row3.X * m.Row1.Z + Row3.Y * m.Row2.Z + Row3.Z * m.Row3.Z;
	return Matrix3(a, b, c, d, e, f, g, h, i);
#endif
}

bool DeJong::Matrix3::operator==(const Matrix3 &m) const
{
#if defined(COLUMN_MAJOR)
	return Column1 == m.Column1 && Column2 == m.Column2 && Column3 == m.Column3;
#endif
#if defined(ROW_MAJOR)
	return Row1 == m.Row1 && Row2 == m.Row2 && Row3 == m.Row3;
#endif
}

bool DeJong::Matrix3::operator!=(const Matrix3 &m) const
{
#if defined(COLUMN_MAJOR)
	return Column1 != m.Column1 || Column2 != m.Column2 || Column3 != m.Column3;
#endif
#if defined (ROW_MAJOR)
	return Row1 != m.Row1 || Row2 != m.Row2 || Row3 != m.Row3;
#endif
}
