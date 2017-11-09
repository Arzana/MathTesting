#pragma once
#include <cmath>
#include "Core\TypeChecking.h"
#include "Core\Math_Constants.h"

#define abs				_Abs
#define square(x)		((x) * (x))
#define cube(x)			((x) * (x) * (x))

/*
Returns the absolute (positive) value of the specified value.
Works with rational numbers and vectors.
*/
template <typename N>	// abs is already defined so I changed the name to _Abs to avoid naming problems
N _Abs(N value);		// using another name and overload defines (is that is even a propper term) is a hack to me but it creates the best result.

/*
Converts the specified vector to an angle (in radians).
*/
float angle(Vector2 value);

/*
Returns the angle (in radians) between the two specified vectors.
*/
float angle(Vector2 value1, Vector2 value2);

/*
Returns the value clamped between two specified points.
Works with integer numbers, floating point numbers and vectors.
*/
template <typename N>
N clamp(N value, N min, N max);

/*
The cross product returns a vector that is orthogonal to both input vectors
and with a magnitude that specifies the volume of the parallelopiped that value1 and value2 define.
*/
Vector3 cross(Vector3 value1, Vector3 value2);

/*
Returns the area of the parallelogram that value1 and value2 define.
*/
float determinant(Vector2 value1, Vector2 value2);

/*
Returns the distance between two vectors.
*/
template <typename V>
float dist(V value1, V value2);

/*
Returns the dot product of the two specified vectors.
The dot product projects a vector on another vector
and returns the length of the resulting vector.

Works only with vectors.

Propperties:
- dot == 0: value1 and value2 are orthogonal.
- dot > 0:	value1 and value2 are pointing in the same direction.
- dot < 0:	value1 and value2 are pointing in the opposite direction.
*/
template <typename V>
float dot(V value1, V value2);

/*
Performs a Hermite spline interpolation.
Works with floating point numbers and vectors.
*/
template <typename N, typename R>
R hermite(N value1, N tangent1, N value2, N tangent2, float amount);

/*
Performs inversed linear interpolation between two points with a specifed value.
Works with integer numbers, floating point numbers and vectors.
*/
template <typename N>
float invLerp(N value1, N value2, N value);

/*
Returns the integer part of the specified value.
*/
int ipart(float value);

/*
Returns whether the specified value is between or equal to zero and one.
*/
bool isUnit(float value);

/*
Returns the length of the specified vector.
Works only with vectors.
*/
template <typename V>
float length(V value);

/*
Performs linear interpolation between two point with a specified value.
Works with integer numbers, floating point numbers, vectors and colors.
*/
template <typename N>
N lerp(N value1, N value2, float amount);

/*
Returns the highest value of the two specified arguments.
Works with integer numbers, floating point numbers and vectors.
*/
template <typename N>
N max(N value1, N value2);

/*
Returns the lowest value of the two specified arguments.
Works with integer numbers, floating point numbers and vectors.
*/
template <typename N>
N min(N value1, N value2);

/*
Normalizes the specified vector so the magnitude is reduced to one.
Works only with vectors.
*/
template <typename V>
V normalize(V value);

/*
Calculates the reflected vector with the specified normal.
Works only with vectors.
*/
template <typename V>
V reflect(V value, V normal);

/*
Rectifies the specified value clamping it between zero and itself.
Works with integer numbers, floating point numbers and vectors.
*/
template <typename N>
N rectify(N value);

/*
Clamps the specified value between zero and one.
Works with integer numbers, floating point numbers and vectors.
*/
template <typename N, typename R>
R sigmoid(N value);

/*
Performs cubic interpolation between two point with a specific value.
Works with floating point numbers and vectors.
*/
template <typename N>
N smoothStep(N value1, N value2, float amount);

/*
Convertes a specified value to a 2d vector.
Works with vectors of higher dimention.
*/
template <typename V>
Vector2 toVector2(V value);

/*
Converts a specified value to a 3d vector.
Works with vectors and colors.
*/
template <typename V>
Vector3 toVector3(V value);

/*
Converts a specified value to a 4d vector.
Works with vectors and colors.
*/
template <typename V>
Vector4 toVector4(V value);

#pragma region IMPLEMENTATION

#define inv_arg_exc(arg, func)			"argument " #arg " of function " #func " is invalid!"
#define assert(exc)						static_assert(false, exc)

template <typename N>
N _Abs(N value)
{
	if constexpr (std::is_rational_int<N>::value)
	{
		std::make_unsigned<N>::type mask = value >> std::bit_count<N>::value - 1;
		return (value ^ mask) + (mask & 1);
	}
	else if constexpr (std::is_rational_float<N>::value)
	{
		std::int_repr<N>::type v = reinterpret_cast<const std::int_repr<N>::type&>(value);
		v &= std::max_value<typename std::int_repr<N>::type>::value >> 1;
		return reinterpret_cast<const N&>(v);
	}
	else if constexpr (std::is_vector<N>::value == 2)
	{
		return Vector2(abs(value.X), abs(value.Y));
	}
	else if constexpr (std::is_vector<N>::value == 3)
	{
		return Vector3(abs(value.X), abs(value.Y), abs(value.Z));
	}
	else if constexpr (std::is_vector<N>::value == 4)
	{
		return Vector4(abs(value.X), abs(value.Y), abs(value.Z), abs(value.W));
	}
	else
	{
		assert(inv_arg_exc(N, abs));
	}
}

template <typename N>
N clamp(N value, N min, N max)
{
	if constexpr (std::is_arithmetic<N>::value)
	{
		return value < min ? min : (value > max ? max : value);
	}
	else if constexpr (std::is_vector<N>::value == 2)
	{
		return Vector2(clamp(value.X, min.X, max.X), clamp(value.Y, min.Y, max.Y));
	}
	else if constexpr (std::is_vector<N>::value == 3)
	{
		return Vector3(clamp(value.X, min.X, max.X), clamp(value.Y, min.Y, max.Y), clamp(value.Z, min.Z, max.Z));
	}
	else if constexpr (std::is_vector<N>::value == 4)
	{
		return Vector4(clamp(value.X, min.X, max.X), clamp(value.Y, min.Y, max.Y), clamp(value.Z, min.Z, max.Z), clamp(value.W, min.W, max.W));
	}
	else
	{
		assert(inv_arg_exc(N, clamp));
	}
}

template <typename V>
float dist(V value1, V value2)
{
	if constexpr (std::is_vector<V>::value != 0)
	{
		return length(value2 - value1);
	}
	else
	{
		assert(inv_arg_exc(V, dist));
	}
}

template <typename V>
float dot(V value1, V value2)
{
	if constexpr (std::is_vector<V>::value == 2)
	{
		return value1.X * value2.X + value1.Y * value2.Y;
	}
	else if constexpr (std::is_vector<V>::value == 3)
	{
		return value1.X * value2.X + value1.Y * value2.Y + value1.Z * value2.Z;
	}
	else if constexpr (std::is_vector<V>::value == 4)
	{
		return value1.X * value2.X + value1.Y * value2.Y + value1.Z * value2.Z + value1.W * value2.W;
	}
	else
	{
		assert(inv_arg_exc(V, dot));
	}
}

template<typename N>
inline N hermite(N value1, N tangent1, N value2, N tangent2, float amount)
{
	if constexpr (std::is_arithmetic<N>::value)
	{
		if (amount == 0.0f) return value1;
		if (amount == 1.0f) return value2;

		double v1 = value1, v2 = value2, t1 = tangent1, t2 = tangent2, a = amount;
		double result =
			(2 * v1 - 2 * v2 + t2 + t1) * cube(a) +
			(3 * v2 - 3 * v1 - 2 * t1 - t2) * square(a) +
			t1 * a + v1;
		return static_cast<float>(result);
	}
	else if constexpr (std::is_vector<N>::value == 2)
	{
		return Vector2(
			hermite(value1.X, tangent1.X, value2.X, tangent2.X, amount),
			hermite(value1.Y, tangent1.Y, value2.Y, tangent2.Y, amount));
	}
	else if constexpr (std::is_vector<N>::value == 3)
	{
		return Vector3(
			hermite(value1.X, tangent1.X, value2.X, tangent2.X, amount),
			hermite(value1.Y, tangent1.Y, value2.Y, tangent2.Y, amount),
			hermite(value1.Z, tangent1.Z, value2.Z, tangent2.Z, amount));
	}
	else if constexpr (std::is_vector<N>::value == 4)
	{
		return Vector4(
			hermite(value1.X, tangent1.X, value2.X, tangent2.X, amount),
			hermite(value1.Y, tangent1.Y, value2.Y, tangent2.Y, amount),
			hermite(value1.Z, tangent1.Z, value2.Z, tangent2.Z, amount),
			hermite(value1.W, tangent1.W, value2.W, tangent2.W, amount));
	}
}

template <typename N>
float invLerp(N value1, N value2, N value)
{
	if constexpr (std::is_arithmetic<N>::value)
	{
		return (value - value1) / (value2 - value1);
	}
	else if constexpr (std::is_vector<N>::value != 0)
	{
		N ab = value2 - value1;
		N av = value - value1;
		return dot(av, ab) / dot(ab, ab);
	}
	else
	{
		assert(inv_arg_exc(N, invLerp));
	}
}

template <typename V>
float length(V value)
{
	if constexpr (std::is_vector<V>::value != 0)
	{
		return sqrt(dot(value, value));
	}
	else
	{
		assert(inv_arg_exc(V, length));
	}
}

template <typename N>
N lerp(N value1, N value2, float amount)
{
	if constexpr (std::is_dimensional<N>::value)
	{
		return static_cast<N>(value1 + (value2 - value1) * amount);
	}
	else if constexpr (std::is_color<N>::value)
	{
		byte r = lerp(c1.GetRed(), c2.GetRed(), amount);
		byte g = lerp(c1.GetGreen(), c2.GetGreen(), amount);
		byte b = lerp(c1.GetBlue(), c2.GetBlue(), amount);
		byte a = lerp(c1.GetAlpha(), c2.GetAlpha(), amount);
		return Color::FromNonPremultiplied(r, g, b, a);
	}
	else
	{
		assert(inv_arg_exc(N, lerp));
	}
}

template <typename N>
N max(N value1, N value2)
{
	if constexpr (std::is_arithmetic<N>::value)
	{
		return value1 > value2 ? value1 : value2;
	}
	else if constexpr (std::is_vector<N>::value == 2)
	{
		return Vector2(max(value1.X, value2.X), max(value1.Y, value2.Y));
	}
	else if constexpr (std::is_vector<N>::value == 3)
	{
		return Vector3(max(value1.X, value2.X), max(value1.Y, value2.Y), max(value1.Z, value2.Z));
	}
	else if constexpr (std::is_vector<N>::value == 4)
	{
		return Vector4(max(value1.X, value2.X), max(value1.Y, value2.Y), max(value1.Z, value2.Z), max(value1.W, value2.W));
	}
	else
	{
		assert(inv_arg_exc(N, max));
	}
}

template <typename N>
N min(N value1, N value2)
{
	if constexpr (std::is_arithmetic<N>::value)
	{
		return value1 < value2 ? value1 : value2;
	}
	else if constexpr (std::is_vector<N>::value == 2)
	{
		return Vector2(min(value1.X, value2.X), min(value1.Y, value2.Y));
	}
	else if constexpr (std::is_vector<N>::value == 3)
	{
		return Vector3(min(value1.X, value2.X), min(value1.Y, value2.Y), min(value1.Z, value2.Z));
	}
	else if constexpr (std::is_vector<N>::value == 4)
	{
		return Vector4(min(value1.X, value2.X), min(value1.Y, value2.Y), min(value1.Z, value2.Z), min(value1.W, value2.W));
	}
	else
	{
		assert(inv_arg_exc(N, max));
	}
}

template <typename V>
V normalize(V value)
{
	if constexpr (std::is_vector<V>::value != 0)
	{
		return value * (1.0f / length(value));
	}
	else
	{
		assert(inv_arg_exc(V, normalize));
	}
}

template <typename V>
V reflect(V value, V normal)
{
	if constexpr (std::is_vector<V>::value != 0)
	{
		return value - 2 * dot(value, normal) * normal;
	}
	else
	{
		assert(inv_arg_exc(V, reflect));
	}
}

template<typename N>
N rectify(N value)
{
	return max(0, value);
}

template<typename N, typename R>
R sigmoid(N value)
{
	if constexpr (std::is_arithmetic<N>::value)
	{
		return 1.0f / (1.0f + exp(-value));
	}
	else if constexpr (std::is_vector<N>::value == 2)
	{
		return Vector2(sigmoid(value.X), sigmoid(value.Y));
	}
	else if constexpr (std::is_vector<N>::value == 3)
	{
		return Vector3(sigmoid(value.X), sigmoid(value.Y), sigmoid(value.Z));
	}
	else if constexpr (std::is_vector<N>::value == 4)
	{
		return Vector4(sigmoid(value.X), sigmoid(value.Y), sigmoid(value.Z), sigmoid(value.W));
	}
	else
	{
		assert(inv_arg_exc(N, sigmoid));
	}
}

template<typename N>
inline N smoothStep(N value1, N value2, float amount)
{
	return hermite(value1, N(0.0f), value2, N(0.0f), amount);
}

template<typename V>
Vector2 toVector2(V value)
{
	if constexpr (std::is_vector<V>::value > 2)
	{
		return Vector2(value.X, value.Y);
	}
	else
	{
		assert(inv_arg_exc(V, toVector2));
	}
}

template<typename V>
Vector3 toVector3(V value)
{
	if constexpr (std::is_vector<V>::value == 2)
	{
		return Vector3(value.X, value.Y, 1);
	}
	else if constexpr (std::is_vector<V>::value > 3)
	{
		return Vector3(value.X, value.Y, value.Z);
	}
	else if constexpr (std::is_color<V>::value)
	{
		return Vector3(value.GetRed() / 255.0f, value.GetGreen() / 255.0f, value.GetBlue() / 255.0f);
	}
	else
	{
		assert(inv_arg_exc(V, toVector3))
	}
}

template<typename V>
Vector4 toVector4(V value)
{
	if constexpr (std::is_vector<V>::value == 2)
	{
		return Vector4(value.X, value.Y, 0, 1);
	}
	else if constexpr (std::is_vector<V>::value == 3)
	{
		return Vector4(value.X, value.Y, value.Z, 1);
	}
	else if constexpr (std::is_color<V>::value)
	{
		return Vector4(value.GetRed() / 255.0f, value.GetGreen() / 255.0f, value.GetBlue() / 255.0f, value.GetAlpha() / 255.0f);
	}
	else
	{
		assert(inv_arg_exc(V, toVector4));
	}
}

#undef inv_arg_exc
#undef assert

#pragma endregion