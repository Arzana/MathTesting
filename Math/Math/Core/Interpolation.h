#pragma once
#include <sal.h>
#include "Basics.h"

namespace DeJong
{
	/* Performs linear interpolation between two specified point with a specified amount. */
	_Check_return_ inline float lerp(_In_ float low, _In_ float high, _In_ float a)
	{
		return low + (high - low) * a;
	}

	/* Performs inverse linear interpolation between two point with a specified point. */
	_Check_return_ inline float invLerp(_In_ float low, _In_ float high, _In_ float v)
	{
		return (v - low) / (high - low);
	}

	/* Performs cubic hermite spline interpolation with specified lower and higher bounds and derivatives. */
	_Check_return_ inline float hermite(_In_ float low, _In_ float lowdir, _In_ float high, _In_ float highdir, _In_ float a)
	{
		return low + (2.0f * low - 2.0f * high + highdir + lowdir) * cube(a) + (3.0f * high - 3.0f * low - 2.0f * lowdir - highdir) * sqr(a) + lowdir * a;
	}

	/* 
	Performs cubic hermite spline intermolation with specified lower and higher bounds.
	Derivatives = 0.
	*/
	_Check_return_ inline float hermite(_In_ float low, _In_ float high, _In_ float a)
	{
		return low + sqr(a) * ((2.0f * low - 2.0f * high) * a + 3.0f * high - 3.0f * low);
	}

	/*
	Performs cubic hermite spline interpolation.
	Derivatives = 0.
	Lower bound = 0.
	Higher bound = 1.
	*/
	_Check_return_ inline float hermite(_In_ float a)
	{
		return sqr(a) * (3.0f - 2.0f * a);
	}

	/* Performs smoothstep interpolation. */
	_Check_return_ inline float smoothstep(_In_ float a)
	{
		return hermite(a);
	}
}