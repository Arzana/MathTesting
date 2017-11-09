#pragma once
#include "Vector3.h"
#include "Vector4.h"

constexpr bool IS_RIGHT_HANDED = true;

/*
Defines a 4x4 square matrix that can be used to transform 3-dimentional vectors.

	  C1 C2 C3 C4
R1	| A  B  C  D |
R2	| E  F  G  H |
R3	| I  J  K  L |
R4	| M  N  O  P |
*/
struct Matrix4
{
public:
	/* Defines the identity matrix, a matrix that does nothing. */
	const static Matrix4 Identity;

	Matrix4(void)
		: Column1(Vector4::Zero), Column2(Vector4::Zero), Column3(Vector4::Zero), Column4(Vector4::Zero)
	{}

	/*
	Transforms a specified 3d vector with the matrix and gives the output 4d homogeonous vector.
	*/
	Vector4 operator *(Vector3 vector) const;
	/*
	Multiplies two matrices and returns their product.
	This is not commutative!.
	*/
	Matrix4 operator *(Matrix4 other) const;
	/*
	Multiplies two matrixes and saves their product in the left matrix.
	This is not commutative!
	*/
	Matrix4 operator *=(Matrix4 other);
	/* Checks whether two matrices are equal.  */
	bool operator ==(Matrix4 other) const;
	/* Checks whether two matrices are different. */
	bool operator !=(Matrix4 other) const;

	/* Creates a rotation matrix around the tree base axis. */
	static Matrix4 YawPitchRoll(float yaw, float pitch, float roll);
	/* Creates a frustrum projection matrix. */
	static Matrix4 Frustrum(float fovY, float aspr, float front, float back);
	/* Creates a frustrum projection matrix. */
	static Matrix4 Frustrum(float top, float bottom, float left, float right, float front, float back);
	/* Creates a orthographic projection matrix. */
	static Matrix4 Ortho(float width, float height, float front, float back);
	/* Creates a orthographic projection matrix. */
	static Matrix4 Ortho(float left, float right, float top, float bottom, float front, float back);
	/* Creates a matrix that defines a specified rotation around a specified axis. */
	static Matrix4 Rotation(Vector3 axis, float rads);
	/* Creates a matrix that defines a specified rotation around the x axis. */
	static Matrix4 RotationX(float rads);
	/* Creates a matrix that defines a specified rotation around the y axis. */
	static Matrix4 RotationY(float rads);
	/* Creates a matrix that defines a specified rotation around the z axis. */
	static Matrix4 RotationZ(float rads);
	/* Creates a scalar matrix on the tree major dimentions. */
	static Matrix4 Scale(float scalar);
	/* Creates a scalar matrix with a specified scale for each of the tree major dimentions. */
	static Matrix4 Scale(Vector3 scalar);
	/* Creates a affine translation matrix. */
	static Matrix4 Translation(Vector3 offset);
	/* Composes a full view matrix with a specified scale, rotation (around z axis) and offset. */
	static Matrix4 View(float scalar, float rotation, Vector3 offset);
	/* Creates a camera lookat matrix. */
	static Matrix4 LookAt(Vector3 position, Vector3 target, Vector3 up);
	/* Creates a camera lookat matrix. */
	inline static Matrix4 LookAt(Vector3 position, Matrix4 transform)
	{
		return LookAt(position, transform.GetForward(), transform.GetUp());
	}

	/* Gets a vector that defines the backwards direction for the matrix. */
	inline Vector3 GetBackward(void) const
	{
		return -GetForward();
	}
	/* Gets a vector that defines the downwards direction for the matrix. */
	inline Vector3 GetDown(void) const
	{
		return -GetUp();
	}
	/* Gets a vector that defines the forwards direction for the matrix. */
	inline Vector3 GetForward(void) const
	{
		return Vector3(Column3.X, Column3.Y, Column3.Z);
	}
	/* Gets a vector that defines the left direction for the matrix. */
	inline Vector3 GetLeft(void) const
	{
		return -GetRight();
	}
	/* Gets a vector that defines the right direction for the matrix. */
	inline Vector3 GetRight(void) const
	{
		return Vector3(Column1.X, Column1.Y, Column1.Z);
	}
	/* Gets a vector that defines the up direction for the matrix. */
	inline Vector3 GetUp(void) const
	{
		return Vector3(Column2.X, Column2.Y, Column2.Z);
	}
	/* Gets the translation of the matrix. */
	inline Vector3 GetTranslation(void) const
	{
		return Vector3(Column4.X, Column4.Y, Column4.Z);
	}
	/* Gets the transpose of the matrix. */
	Matrix4 GetTranspose(void) const;
	/* Normalizes the matrix. */
	void Normalize(void);

private:
	friend Vector4 operator *(Matrix4 m, Vector4 v);

	Vector4 Column1;
	Vector4 Column2;
	Vector4 Column3;
	Vector4 Column4;

	Matrix4(Vector4 column1, Vector4 column2, Vector4 column3, Vector4 column4)
		: Column1(column1), Column2(column2), Column3(column3), Column4(column4)
	{}

	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
		: Column1(a, e, i, m), Column2(b, f, j, n), Column3(c, g, k, o), Column4(d, h, l, p)
	{}
};

inline Vector4 operator *(Vector3 vector, Matrix4 matrix)
{
	return matrix * vector;
}