#pragma once

typedef signed char			int8;
typedef unsigned char		uint8;
typedef signed short		int16;
typedef unsigned short		uint16;
typedef signed int			int32;
typedef unsigned int		uint32;
typedef signed long long	int64;
typedef unsigned long long	uint64;

/* Euler's constant */
constexpr float E = 2.71828182845904523536f;
/* The circle constant. */
constexpr float PI = 3.14159265358979323846f;
/* PI multiplied by two. */
constexpr float TAU = PI * 2;
/* PI divided by two. */
constexpr float PI2 = PI / 2;
/* PI divided by four */
constexpr float PI4 = PI / 4;
/* Pythagoras's constant. */
constexpr float SQRT2 = 1.41421356237309504880f;
/*Convertes degrees to radians. */
constexpr float	DEG2RAD = PI / 180.0f;
/* Converts radians to degrees. */
constexpr float	RAD2DEG = 180.0f / PI;
/* Smallest float unit. */
constexpr float EPSILON = 0.00000000001f;