#pragma once
#include <sal.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Configuration.h"

namespace DeJong
{
	/*
	Defines a 3x3 square matrix.
	| A  B  C |
	| D  E  F |
	| G  H  I |
	*/
	struct Matrix3
	{
	public:
		/* Defines a matrix with no transformations included. */
		const static Matrix3 Identity;

		/* Initializes a new instance of a 3x3 square matrix with all components set to zero. */
		Matrix3(void)
#if defined(COLUMN_MAJOR)
			: Column1(), Column2(), Column3()
#endif
#if defined(ROW_MAJOR)
			: Row1(), Row2(), Row3()
#endif
		{}

		/* Initializes a new instance of a 3x3 square matrix from a predefined matrix. */
		Matrix3(_In_ const Matrix3 &value)
#if defined(COLUMN_MAJOR)
			: Column1(value.Column1), Column2(value.Column2), Column3(value.Column3)
#endif
#if defined(ROW_MAJOR)
			: Row1(value.Row1), Row2(value.Row2), Row3(value.Row3)
#endif
		{}

		/* Scales the matrix by a constant. */
		_Check_return_ Matrix3 operator *(_In_ float scalar) const;
		/* Transforms the specified two dimentional vector with the specified matrix. */
		_Check_return_ Vector2 operator *(_In_ Vector2 v) const;
		/* Transforms a specified three dimentional vector with the specified matrix. */
		_Check_return_ Vector3 operator *(_In_ Vector3 v) const;
		/* Multiplies two matrices and return their product. */
		_Check_return_ Matrix3 operator *(_In_ const Matrix3 &m) const;
		/* Scales the matrix by a constant and stores the result in the matrix. */
		inline const Matrix3& operator *=(_In_ float scalar)
		{
			return *this = (*this * scalar);
		}
		/* Multiples two matrices and stores their product in the left matrix. */
		inline const Matrix3& operator *=(_In_ const Matrix3 &m)
		{
			return *this = (*this * m);
		}
		/* Checks whether two matrices are equal. */
		_Check_return_ bool operator ==(_In_ const Matrix3 &m) const;
		/* Checks whether two matrices are different. */
		_Check_return_ bool operator !=(_In_ const Matrix3 &m) const;

		/* Returns the translation transform of the matrix. */
		_Check_return_ inline Vector2 GetTranslation(void) const
		{
			return Vector2(GetC(), GetF());
		}

		/* Gets the value at [0, 0]. */
		_Check_return_ inline float GetA(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column1.X;
#endif
#if defined(ROW_MAJOR)
			return Row1.X;
#endif
		}

		/* Gets the value at [0, 1]. */
		_Check_return_ inline float GetB(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column2.X;
#endif
#if defined(ROW_MAJOR)
			return Row1.Y;
#endif
		}

		/* Gets the value at [0, 2]. */
		_Check_return_ inline float GetC(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column3.X;
#endif
#if defined(ROW_MAJOR)
			return Row1.Z;
#endif
		}

		/* Gets the value at [1, 0]. */
		_Check_return_ inline float GetD(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column1.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.X;
#endif
		}

		/* Gets the value at [1, 1]. */
		_Check_return_ inline float GetE(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column2.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.Y;
#endif
		}

		/* Gets the value at [1, 2]. */
		_Check_return_ inline float GetF(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column3.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.Z;
#endif
		}

		/* Gets the value at [2, 0]. */
		_Check_return_ inline float GetG(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column1.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.X;
#endif
		}

		/* Gets the value at [2, 1]. */
		_Check_return_ inline float GetH(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column2.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.Y;
#endif
		}

		/* Gets the value at [2, 2]. */
		_Check_return_ inline float GetI(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column3.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.Z;
#endif
		}

	private:
		friend Matrix3 rotation(float);
		friend Matrix3 scale2D(float);
		friend Matrix3 scale(Vector2);
		friend Matrix3 translation(Vector2);
		friend Matrix3 view(float, float, Vector2);
		friend Matrix3 transpose(Matrix3&);
		friend Matrix3 cofactor(const Matrix3&);
		friend float det(const struct Matrix4&);
		friend struct Matrix4 cofactor(const struct Matrix4&);

#if defined(COLUMN_MAJOR)
		Vector3 Column1, Column2, Column3;

		Matrix3(_In_ Vector3 c1, _In_ Vector3 c2, _In_ Vector3 c3)
			: Column1(c1), Column2(c2), Column3(c3)
		{}
#endif
#if defined(ROW_MAJOR)
		Vector3 Row1, Row2, Row3;
#endif

		Matrix3(_In_ float a, _In_ float b, _In_ float c, _In_ float d, _In_ float e, _In_ float f, _In_ float g, _In_ float h, _In_ float i)
#if defined(COLUMN_MAJOR)
			: Column1(a, d, g), Column2(b, e, h), Column3(c, f, i)
#endif
#if defined(ROW_MAJOR)
			: Row1(a, b, c), Row2(d, e, f), Row3(g, h, i)
#endif
		{}
	};

	/* Scales the matrix by a constant. */
	_Check_return_ inline Matrix3 operator *(_In_ float scalar, _In_ const Matrix3 &m)
	{
		return m * scalar;
	}

	/* Transforms the specified two dimentional vector with the specified matrix. */
	_Check_return_ inline Vector2 operator *(_In_ Vector2 v, _In_ const Matrix3 &m)
	{
		return m * v;
	}

	/* Transforms the specified two dimentional vector with the specified matrix. */
	inline Vector2 operator *=(_In_ Vector2 v, _In_ const Matrix3 &m)
	{
		return v = (m * v);
	}
}