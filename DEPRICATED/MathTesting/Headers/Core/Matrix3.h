#pragma once
#include "Vector2.h"
#include "Vector3.h"

/*
Defines a 3x3 square matrix that can be used to transforms 2-dimentional vectors.

      C1 C2 C3
R1	| A  B  C |
R2	| D  E  F |
R3	| G  H  I |
*/
struct Matrix3
{
public:
	/* Defines the identity matrix, a matrix that does nothing. */
	const static Matrix3 Identity;

	/* Initializes a new instance of a matrix with all its components set to zero. */
	Matrix3(void)
		: Column1(Vector3::Zero), Column2(Vector3::Zero), Column3(Vector3::Zero)
	{}

	/* 
	Transforms a specified 2d vector with the matrix and gives the output 3d vector.
	The added 3rd dimention is ignored.
	*/
	Vector2 operator *(Vector2 vector) const;
	/* 
	Multiplies two matrices and returns their product.
	This is not commutative!
	*/
	Matrix3 operator *(Matrix3 other) const;
	/*
	Multiplies two matrixes and saves their product in the left matrix.
	This is not commutative!
	*/
	Matrix3 operator *=(Matrix3 other);
	/* Checks whether two matrices are equal.  */
	bool operator ==(Matrix3 other) const;
	/* Checks whether two matrices are different. */
	bool operator !=(Matrix3 other) const;

	/* 
	Creates a rotation matrix.
	The matrix defines a rotation around the z axis 
	by a gives value specified in radians.
	*/
	static Matrix3 Rotation(float rads);
	/*
	Creates a scalar matrix.
	The matrix defines a scale of all values.
	*/
	static Matrix3 Scale(float scalar);
	/*
	Creates a scalar matrix.
	The matrix defines a scale of the x and y components.
	*/
	static Matrix3 Scale(Vector2 scalar);
	/* 
	Creates a translation matrix. 
	The matrix defines a affine transformation of the x and y components.
	*/
	static Matrix3 Translation(Vector2 offset);
	/* Composes a full view matrix with a specified scale, rotation and offset. */
	static Matrix3 View(float scalar, float rotation, Vector2 offset);

	/* Gets the translation of the matrix. */
	inline Vector2 GetTranslation(void) const
	{
		return Vector2(Column3.X, Column3.Y);
	}
	/* Gets the transpose of the matrix. */
	Matrix3 GetTranspose(void) const;
private:
	friend Vector3 operator*(Matrix3 m, Vector3 v);

	Vector3 Column1;
	Vector3 Column2;
	Vector3 Column3;

	Matrix3(Vector3 column1, Vector3 column2, Vector3 column3)
		: Column1(column1), Column2(column2), Column3(column3)
	{}

	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
		: Column1(a, d, g), Column2(b, e, h), Column3(c, f, i)
	{}
};

inline Vector2 operator *(Vector2 vector, Matrix3 matrix)
{
	return matrix * vector;
}