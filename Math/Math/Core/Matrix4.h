#pragma once
#include <sal.h>
#include "Vector3.h"
#include "Vector4.h"
#include "Configuration.h"

namespace DeJong
{
	/*
	Defines a 4x4 square matrix.
	| A  B  C  D |
	| E  F  G  H |
	| I  J  K  L |
	| M  N  O  P |
	*/
	struct Matrix4
	{
	public:
		/* Defines a matrix with no transformations included. */
		const static Matrix4 Identity;

		/* Initializes a new instance of a 4x4 square matrix with all components set to zero. */
		Matrix4(void)
#if defined(COLUMN_MAJOR)
			: Column1(), Column2(), Column3(), Column4()
#endif
#if defined(ROW_MAJOR)
			: Row1(), Row2(), Row3(), Row4()
#endif
		{}

		/* Initializes a new instance of a 4x4 square matrix from a predefined matrix. */
		Matrix4(_In_ const Matrix4 &value)
#if defined(COLUMN_MAJOR)
			: Column1(value.Column1), Column2(value.Column2), Column3(value.Column3), Column4(value.Column4)
#endif
#if defined(ROW_MAJOR)
			: Row1(value.Row1), Row2(value.Row2), Row3(value.Row3), Row4(value.Row4)
#endif
		{}

		/* Scales the matrix by a constant. */
		_Check_return_ Matrix4 operator *(_In_ float scalar) const;
		/* Transforms the specified three dimentional vector with the specified matrix. */
		_Check_return_ Vector4 operator *(_In_ Vector3 v) const;
		/* Transforms a specified four dimentional vector with the specified matrix. */
		_Check_return_ Vector4 operator *(_In_ Vector4 v) const;
		/* Multiplies two matrices and return their product. */
		_Check_return_ Matrix4 operator *(_In_ const Matrix4 &m) const;
		/* Scales the matrix by a constant and stores the result in the matrix. */
		inline const Matrix4& operator *=(_In_ float scalar)
		{
			return *this = (*this * scalar);
		}
		/* Multiples two matrices and stores their product in the left matrix. */
		inline const Matrix4& operator *=(_In_ const Matrix4 &m)
		{
			return *this = (*this * m);
		}
		/* Checks whether two matrices are equal. */
		_Check_return_ bool operator ==(_In_ const Matrix4 &m) const;
		/* Checks whether two matrices are different. */
		_Check_return_ bool operator !=(_In_ const Matrix4 &m) const;

		/* Gets a vector that defines the backwards direction for this matrix. */
		_Check_return_ inline Vector3 GetBackwards(void) const
		{
#if defined(RIGHT_HAND)
			return Vector3(GetC(), GetG(), GetK());
#endif
#if defined(LEFT_HAND)
			return -GetForward();
#endif
		}

		/* Gets a vector that defines the downwards direction for this matrix */
		_Check_return_ inline Vector3 GetDown(void) const
		{
			return -GetUp();
		}

		/* Gets a vector that defines the forward direction for this matrix. */
		_Check_return_ inline Vector3 GetForward(void) const
		{
#if defined(LEFT_HAND)
			return Vector3(GetC(), GetG(), GetK());
#endif
#if defined(RIGHT_HAND)
			return -GetBackwards();
#endif
		}

		/* Gets a vector that defines the left direction for this matrix. */
		_Check_return_ inline Vector3 GetLeft(void) const
		{
			return -GetRight();
		}

		/* Gets a vector that defines the right direction for this matrix. */
		_Check_return_ inline Vector3 GetRight(void) const
		{
			return Vector3(GetA(), GetE(), GetI());
		}

		/* Gets a vector that defines the up direction or this matrix. */
		_Check_return_ inline Vector3 GetUp(void) const
		{
			return Vector3(GetB(), GetF(), GetJ());
		}

		/* Gets the translation of this matrix. */
		_Check_return_ inline Vector3 GetTranslation(void) const
		{
			return Vector3(GetD(), GetH(), GetL());
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

		/* Gets the value at [0, 3]. */
		_Check_return_ inline float GetD(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column4.X;
#endif
#if defined(ROW_MAJOR)
			return Row1.W;
#endif
		}

		/* Gets the value at [1, 0]. */
		_Check_return_ inline float GetE(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column1.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.X;
#endif
		}

		/* Gets the value at [1, 1]. */
		_Check_return_ inline float GetF(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column2.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.Y;
#endif
		}

		/* Gets the value at [1, 2]. */
		_Check_return_ inline float GetG(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column3.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.Z;
#endif
		}

		/* Gets the value at [1, 3]. */
		_Check_return_ inline float GetH(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column4.Y;
#endif
#if defined(ROW_MAJOR)
			return Row2.W;
#endif
		}

		/* Gets the value at [2, 0]. */
		_Check_return_ inline float GetI(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column1.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.X;
#endif
		}

		/* Gets the value at [2, 1]. */
		_Check_return_ inline float GetJ(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column2.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.Y;
#endif
		}

		/* Gets the value at [2, 2]. */
		_Check_return_ inline float GetK(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column3.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.Z;
#endif
		}

		/* Gets the value at [2, 3]. */
		_Check_return_ inline float GetL(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column4.Z;
#endif
#if defined(ROW_MAJOR)
			return Row3.W;
#endif
		}

		/* Gets the value at [3, 0]. */
		_Check_return_ inline float GetM(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column1.W;
#endif
#if defined(ROW_MAJOR)
			return Row4.X;
#endif
		}

		/* Gets the value at [3, 1]. */
		_Check_return_ inline float GetN(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column2.W;
#endif
#if defined(ROW_MAJOR)
			return Row4.Y;
#endif
		}

		/* Gets the value at [3, 2]. */
		_Check_return_ inline float GetO(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column3.W;
#endif
#if defined(ROW_MAJOR)
			return Row4.Z;
#endif
		}

		/* Gets the value at [3, 3]. */
		_Check_return_ inline float GetP(void) const
		{
#if defined(COLUMN_MAJOR)
			return Column4.W;
#endif
#if defined(ROW_MAJOR)
			return Row4.W;
#endif
		}

	private:
		friend Matrix4 yawPitchRoll(float, float, float);
		friend Matrix4 frustrum(float, float, float, float);
		friend Matrix4 frustrum(float, float, float, float, float, float);
		friend Matrix4 ortho(float, float, float, float);
		friend Matrix4 ortho(float, float, float, float, float, float);
		friend Matrix4 rotation(Vector3, float);
		friend Matrix4 rotationX(float);
		friend Matrix4 rotationY(float);
		friend Matrix4 rotationZ(float);
		friend Matrix4 scale3D(float);
		friend Matrix4 scale(Vector3);
		friend Matrix4 translation(Vector3);
		friend Matrix4 view(float, float, float, float, Vector3);
		friend Matrix4 lookat(Vector3, Vector3, Vector3);
		friend Matrix4 transpose(const Matrix4&);
		friend Matrix4 cofactor(const Matrix4&);

#if defined(COLUMN_MAJOR)
		Vector4 Column1, Column2, Column3, Column4;

		Matrix4(_In_ Vector4 c1, _In_ Vector4 c2, _In_ Vector4 c3, _In_ Vector4 c4)
			: Column1(c1), Column2(c2), Column3(c3), Column4(c4)
		{}
#endif
#if defined(ROW_MAJOR)
		Vector4 Row1, Row2, Row3, Row4;
#endif

		Matrix4(_In_ float a, _In_ float b, _In_ float c, _In_ float d, _In_ float e, _In_ float f, _In_ float g, _In_ float h, _In_ float i, _In_ float j, _In_ float k, _In_ float l, _In_ float m, _In_ float n, _In_ float o, _In_ float p)
#if defined(COLUMN_MAJOR)
			: Column1(a, e, i, m), Column2(b, f, j, n), Column3(c, g, k, o), Column4(d, h, l, p)
#endif
#if defined(ROW_MAJOR)
			: Row1(a, b, c, d), Row2(e, f, g, h), Row3(i, j, k, l), Row4(m, n, o, p)
#endif
		{}
	};

	/* Scales the matrix by a constant. */
	_Check_return_ inline Matrix4 operator *(_In_ float scalar, const Matrix4 &m)
	{
		return m * scalar;
	}

	/* Transforms the specified three dimentional vector with the specified matrix. */
	_Check_return_ inline Vector4 operator *(_In_ Vector3 v, _In_ const Matrix4 &m)
	{
		return m * v;
	}

	/* Transforms the specified four dimentional vector with the specified matrix. */
	_Check_return_ inline Vector4 operator *(_In_ Vector4 v, _In_ const Matrix4 &m)
	{
		return m * v;
	}

	/* Transforms the specified four dimentional vector with the specified matrix. */
	inline Vector4 operator *=(_In_ Vector4 v, _In_ const Matrix4 &m)
	{
		return v = (m * v);
	}
}