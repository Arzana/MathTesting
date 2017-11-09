#pragma once
#include <cmath>
#include "Constants.h"

/* Forcing use of non-c abs function. */
#define abs _Abs

#pragma region SQR
/* Raises the input value to the power of two. */
_Check_return_ inline int32 sqr(_In_ int8 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int32 sqr(_In_ uint8 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int32 sqr(_In_ int16 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int32 sqr(_In_ uint16 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int32 sqr(_In_ int32 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int32 sqr(_In_ uint32 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int64 sqr(_In_ int64 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline int64 sqr(_In_ uint64 value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline float sqr(_In_ float value)
{
	return value * value;
}

/* Raises the input value to the power of two. */
_Check_return_ inline double sqr(_In_ double value)
{
	return value * value;
}
#pragma endregion

#pragma region CUBE
/* Raises the input value to the power of three. */
_Check_return_ inline int32 cube(_In_ int8 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int32 cube(_In_ uint8 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int32 cube(_In_ int16 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int32 cube(_In_ uint16 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int32 cube(_In_ int32 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int32 cube(_In_ uint32 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int64 cube(_In_ int64 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline int64 cube(_In_ uint64 value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline float cube(_In_ float value)
{
	return value * value * value;
}

/* Raises the input value to the power of three. */
_Check_return_ inline double cube(_In_ double value)
{
	return value * value * value;
}
#pragma endregion

#pragma region ABS
/* Returns the absolute (positive) value of the input value. */
_Check_return_ inline int32 _Abs(_In_ int8 value)
{
	uint8 mask = value >> 7;
	return (value ^ mask) + (mask & 1);
}

/* Returns the absolute (positive) value of the input value. */
_Check_return_ inline int32 _Abs(_In_ int16 value)
{
	uint16 mask = value >> 15;
	return (value ^ mask) + (mask & 1);
}

/* Returns the absolute (positive) value of the input value. */
_Check_return_ inline int32 _Abs(_In_ int32 value)
{
	uint32 mask = value >> 31;
	return (value ^ mask) + (mask & 1);
}

/* Returns the absolute (positive) value of the input value. */
_Check_return_ inline int64 _Abs(_In_ int64 value)
{
	uint64 mask = value >> 63;
	return (value ^ mask) + (mask & 1);
}

/* Returns the absolute (positive) value of the input value. */
_Check_return_ inline float _Abs(_In_ float value)
{
	uint32 iv = reinterpret_cast<const uint32&>(value);
	iv &= 0x7FFFFFFF;
	return reinterpret_cast<const float&>(iv);
}

/* Returns the absolute (positive) value of the input value. */
_Check_return_ inline double _Abs(_In_ double value)
{
	uint64 iv = reinterpret_cast<const uint64&>(value);
	iv &= 0x7FFFFFFFFFFFFFFFULL;
	return reinterpret_cast<const double&>(iv);
}
#pragma endregion

#pragma region MAX
/* Returns the highest of the two input values. */
_Check_return_ inline int8 max(_In_ int8 first, _In_ int8 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline uint8 max(_In_ uint8 first, _In_ uint8 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline int16 max(_In_ int16 first, _In_ int16 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline uint16 max(_In_ uint16 first, _In_ uint16 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline int32 max(_In_ int32 first, _In_ int32 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline uint32 max(_In_ uint32 first, _In_ uint32 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline int64 max(_In_ int64 first, _In_ int64 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline uint64 max(_In_ uint64 first, _In_ uint64 second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline float max(_In_ float first, _In_ float second)
{
	return first > second ? first : second;
}

/* Returns the highest of the two input values. */
_Check_return_ inline double max(_In_ double first, _In_ double second)
{
	return first > second ? first : second;
}
#pragma endregion

#pragma region MIN
/* Returns the lowest of the two input values. */
_Check_return_ inline int8 min(_In_ int8 first, _In_ int8 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline uint8 min(_In_ uint8 first, _In_ uint8 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline int16 min(_In_ int16 first, _In_ int16 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline uint16 min(_In_ uint16 first, _In_ uint16 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline int32 min(_In_ int32 first, _In_ int32 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline uint32 min(_In_ uint32 first, _In_ uint32 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline int64 min(_In_ int64 first, _In_ int64 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline uint64 min(_In_ uint64 first, _In_ uint64 second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline float min(_In_ float first, _In_ float second)
{
	return first < second ? first : second;
}

/* Returns the lowest of the two input values. */
_Check_return_ inline double min(_In_ double first, _In_ double second)
{
	return first < second ? first : second;
}
#pragma endregion

#pragma region CLAMP
/* Returns the input value restriced to a specific range.  */
_Check_return_ inline int8 clamp(_In_ int8 value, _In_ int8 lower, _In_ int8 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline uint8 clamp(_In_ uint8 value, _In_ uint8 lower, _In_ uint8 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline int16 clamp(_In_ int16 value, _In_ int16 lower, _In_ int16 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline uint16 clamp(_In_ uint16 value, _In_ uint16 lower, _In_ uint16 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline int32 clamp(_In_ int32 value, _In_ int32 lower, _In_ int32 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline uint32 clamp(_In_ uint32 value, _In_ uint32 lower, _In_ uint32 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline int64 clamp(_In_ int64 value, _In_ int64 lower, _In_ int64 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline uint64 clamp(_In_ uint64 value, _In_ uint64 lower, _In_ uint64 higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline float clamp(_In_ float value, _In_ float lower, _In_ float higher)
{
	return max(lower, min(higher, value));
}

/* Returns the input value restriced to a specific range.  */
_Check_return_ inline double clamp(_In_ double value, _In_ double lower, _In_ double higher)
{
	return max(lower, min(higher, value));
}
#pragma endregion

#pragma region FLT PARTS
/* Returns the integer part of the input value. */
_Check_return_ inline int32 ipart(_In_ float value)
{
	return static_cast<int32>(floorf(value));
}

/* Returns the fractional part of the input value. */
_Check_return_ inline float fpart(_In_ float value)
{
	return value - floorf(value);
}
#pragma endregion

#pragma region RECTIFY
/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline int8 rectify(_In_ int8 value)
{
	return max(0_i8, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline uint8 rectify(_In_ uint8 value)
{
	return max(0_ui8, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline int16 rectify(_In_ int16 value)
{
	return max(0_i16, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline uint16 rectify(_In_ uint16 value)
{
	return max(0_ui16, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline int32 rectify(_In_ int32 value)
{
	return max(0, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline uint32 rectify(_In_ uint32 value)
{
	return max(0u, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline int64 rectify(_In_ int64 value)
{
	return max(0LL, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline uint64 rectify(_In_ uint64 value)
{
	return max(0ULL, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline float rectify(_In_ float value)
{
	return max(0.0f, value);
}

/* Rectifies the input value clamping it between zero and itself. */
_Check_return_ inline double rectify(_In_ double value)
{
	return max(0.0, value);
}
#pragma endregion