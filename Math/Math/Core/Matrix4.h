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

		/* Transforms the specified three dimentional vector with the specified matrix. */
		_Check_return_ Vector4 operator *(_In_ Vector3 v) const;
		/* Transforms a specified four dimentional vector with the specified matrix. */
		_Check_return_ Vector4 operator *(_In_ Vector4 v) const;
		/* Multiplies two matrices and return their product. */
		_Check_return_ Matrix4 operator *(_In_ const Matrix4 &m) const;
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
#if defined(COLUMN_MAJOR)
			return Vector3(Column3.X, Column3.Y, Column3.Z);
#endif
#if defined(ROW_MAJOR)
			return Vector3(Row1.Z, Row2.Z, Row3.Z);
#endif
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
#if defined(COLUMN_MAJOR)
			return Vector3(Column3.X, Column3.Y, Column3.Z);
#endif
#if defined(ROW_MAJOR)
			return Vector3(Row1.Z, Row2.Z, Row3.Z);
#endif
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
#if defined(COLUMN_MAJOR)
			return Vector3(Column1.X, Column1.Y, Column1.Z);
#endif
#if defined(ROW_MAJOR)
			return Vector3(Row1.X, Row2.X, Row3.X);
#endif
		}

		/* Gets a vector that defines the up direction or this matrix. */
		_Check_return_ inline Vector3 GetUp(void) const
		{
#if defined(COLUMN_MAJOR)
			return Vector3(Column2.X, Column2.Y, Column2.Z);
#endif
#if defined(ROW_MAJOR)
			return Vector3(Row1.Y, Row2.Y, Row3.Y);
#endif
		}

		/* Gets the translation of this matrix. */
		_Check_return_ inline Vector3 GetTranslation(void) const
		{
#if defined(COLUMN_MAJOR)
			return Vector3(Column4.X, Column4.Y, Column4.Z);
#endif
#if defined (ROW_MAJOR)
			return Vector3(Row1.W, Row2.W, Row3.W);
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
}