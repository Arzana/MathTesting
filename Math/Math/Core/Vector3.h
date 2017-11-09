#pragma once
#include <sal.h>

#define RIGHT_HAND
//#define LEFT_HAND

#if defined(RIGHT_HAND) && defined(LEFT_HAND)
#error Cannot define right and left handed coordinate system!
#endif
#if !defined(RIGHT_HAND) && !defined(LEFT_HAND)
#error Must define either a right or left handed coordinate system!
#endif

/* Defines a three dimentional vector. */
typedef struct Vector3
{
	/* [0, 0, 0] */
	const static Vector3 Zero;
	/* [1, 0, 0] */
	const static Vector3 UnitX;
	/* [0, 1, 0] */
	const static Vector3 UnitY;
	/* [0, 0, 1] */
	const static Vector3 UnitZ;
	/* [1, 1, 1] */
	const static Vector3 One;
	/* [1, 0, 0] */
	const static Vector3 Right;
	/* [-1, 0, 0] */
	const static Vector3 Left;
	/* [0, 1, 0] */
	const static Vector3 Up;
	/* [0, -1, 0] */
	const static Vector3 Down;
#if defined(RIGHT_HAND)
	/* [0, 0, 1] */
	const static Vector3 Backward;
	/* [0, 0, -1] */
	const static Vector3 Forward;
#endif
#if defined(LEFT_HAND)
	/* [0, 0, 1] */
	const static Vector3 Forward;
	/* [0, 0, -1] */
	const static Vector3 Backward;
#endif

	float X;
	float Y;
	float Z;
} Vect3;