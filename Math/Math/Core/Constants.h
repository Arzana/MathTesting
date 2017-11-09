#pragma once

typedef signed char			int8;
typedef unsigned char		uint8;
typedef signed short		int16;
typedef unsigned short		uint16;

#if defined(_WIN16)
typedef signed long int		int32;
typedef unsigned long int	uint32;
#else
typedef signed int			int32;
typedef unsigned int		uint32;
#endif

typedef signed long long	int64;
typedef unsigned long long	uint64;

/* unsigned char. */
typedef uint8				byte;
/* Unsigned char. */
typedef uint8				octet;

/* Euler's constant. */
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

/* Converts the integer litteral to an signed char on compile time. */
_Check_return_ constexpr int8 operator ""_i8(_In_ uint64 value)
{
	return static_cast<int8>(value);
}

/* Converts the integer litteral to an unsigned char on compile time. */
_Check_return_ constexpr uint8 operator ""_ui8(_In_ uint64 value)
{
	return static_cast<uint8>(value);
}

/* Converts the integer litteral to an unsigned char on compile time. */
_Check_return_ constexpr int16 operator ""_i16(_In_ uint64 value)
{
	return static_cast<int16>(value);
}

/* Converts the integer litteral to an unsigned char on compile time. */
_Check_return_ constexpr uint16 operator ""_ui16(_In_ uint64 value)
{
	return static_cast<uint16>(value);
}

/* Converts literal degrees to radians on compile time. */
_Check_return_ constexpr float operator ""_deg(_In_ long double value)
{
	return static_cast<float>(value * DEG2RAD);
}