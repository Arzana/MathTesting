#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Graphics\Color.h"

namespace type_checking
{
	/*
		Base struct
	 */
	template <class _Ty, _Ty _Val>
	struct integral_constant
	{
		static constexpr _Ty value = _Val;

		typedef integral_constant<_Ty, _Val> type;

		constexpr operator _Ty() const noexcept
		{
			return value;
		}

		constexpr _Ty operator()() const noexcept
		{
			return value;
		}
	};

	typedef integral_constant<bool, true> allowed_type;
	typedef integral_constant<bool, false> illegal_type;

	/*
		Is rational int constrict
	*/

	template <class _Ty>
	struct _Is_rational_int
		: illegal_type
	{};

	template <>
	struct _Is_rational_int<signed char>
		: allowed_type
	{};

	template <>
	struct _Is_rational_int<short>
		: allowed_type
	{};

	template <>
	struct _Is_rational_int<int>
		: allowed_type
	{};

	template <>
	struct _Is_rational_int<long long>
		: allowed_type
	{};

	/*
		Is rational floating point constrict
	*/

	template <class _Ty>
	struct _Is_rational_float
		: illegal_type
	{};

	template <>
	struct _Is_rational_float<float>
		: allowed_type
	{};

	template <>
	struct _Is_rational_float<double>
		: allowed_type
	{};

	template <>
	struct _Is_rational_float<long double>
		: allowed_type
	{};

	/*
		Is vector constrict
	*/

	template <class _Ty>
	struct _Is_vector
		: integral_constant<int, 0>
	{};

	template <>
	struct _Is_vector<Vector2>
		: integral_constant<int, 2>
	{};

	template <>
	struct _Is_vector<Vector3>
		: integral_constant<int, 3>
	{};

	template <>
	struct _Is_vector<Vector4>
		: integral_constant<int, 4>
	{};

	/*
		Is color constrict
	*/

	template <class _Ty>
	struct _Is_color
		: illegal_type
	{};

	template <>
	struct _Is_color<Color>
		: allowed_type
	{};
}

namespace type_specific
{
	using namespace type_checking;

	typedef integral_constant<int, 0> zero;

	/*
		Minimum value type specifier.
	*/

	template <class _Ty>
	struct _Min_value
		: zero
	{};

	template <>
	struct _Min_value<signed char>
		: integral_constant<int, -128>
	{};

	template <>
	struct _Min_value<unsigned char>
		: zero
	{};

	template <>
	struct _Min_value<signed short>
		: integral_constant<int, -32768>
	{};

	template <>
	struct _Min_value<unsigned short>
		: zero
	{};

	template <>
	struct _Min_value<signed int>
		: integral_constant<int, -2147483647 - 1>
	{};

	template <>
	struct _Min_value<unsigned int>
		: zero
	{};

	template <>
	struct _Min_value<signed long long>
		: integral_constant<signed long long, -9223372036854775807i64 - 1>
	{};

	template <>
	struct _Min_value<unsigned long long>
		: zero
	{};

	/*
		Maximum value type specifier.
	*/

	template <class _Ty>
	struct _Max_value
		: zero
	{};

	template <>
	struct _Max_value<signed char>
		: integral_constant<int, 127>
	{};

	template <>
	struct _Max_value<unsigned char>
		: integral_constant<int, 255>
	{};

	template <>
	struct _Max_value<signed short>
		: integral_constant<int, 32767>
	{};

	template <>
	struct _Max_value<unsigned short>
		: integral_constant<int, 65535>
	{};

	template <>
	struct _Max_value<signed int>
		: integral_constant<int, 2147483647>
	{};

	template <>
	struct _Max_value<unsigned int>
		: integral_constant<long long, 4294967295>
	{};

	template <>
	struct _Max_value<signed long long>
		: integral_constant<long long, 9223372036854775807>
	{};

	template <>
	struct _Max_value<unsigned long long>
		: integral_constant<unsigned long long, 18446744073709551615>
	{};

	/*
		Number of bits type specifier
	*/

	template <class _Ty>
	struct _Bit_count
		: zero
	{};

	template <>
	struct _Bit_count<signed char>
		: integral_constant<int, 8>
	{};

	template <>
	struct _Bit_count<unsigned char>
		: _Bit_count<signed char>
	{};

	template <>
	struct _Bit_count<signed short>
		: integral_constant<int, 16>
	{};

	template <>
	struct _Bit_count<unsigned short>
		: _Bit_count<signed short>
	{};

	template <>
	struct _Bit_count<signed int>
		: integral_constant<int, 32>
	{};

	template <>
	struct _Bit_count<unsigned int>
		: _Bit_count<signed int>
	{};

	template <>
	struct _Bit_count<signed long long>
		: integral_constant<int, 64>
	{};

	template <>
	struct _Bit_count<unsigned long long>
		: _Bit_count<signed long long>
	{};

	/*
		Integer representation specifier	
	*/

	template <class _Ty>
	struct _Int_repr
	{
		typedef _Ty type;
	};

	template <>
	struct _Int_repr<float>
	{
		typedef unsigned int type;
	};

	template <>
	struct _Int_repr<double>
	{
		typedef unsigned long long type;
	};
}

namespace type_modification
{
	template <class _Ty>
	struct remove_const
	{
		typedef _Ty type;
	};

	template <class _Ty>
	struct remove_const<const _Ty>
	{
		typedef _Ty type;
	};

	template <class _Ty>
	struct remove_volatile
	{
		typedef _Ty type;
	};

	template <class _Ty>
	struct remove_volatile<volatile _Ty>
	{
		typedef _Ty type;
	};

	template <class _Ty>
	struct remove_cv
	{
		typedef typename remove_const<typename remove_volatile<_Ty>::type>::type type;
	};

	template <class _Ty>
	struct _Make_unsigned
	{
		typedef _Ty type;
	};

	template <>
	struct _Make_unsigned<signed char>
	{
		typedef unsigned char type;
	};

	template <>
	struct _Make_unsigned<signed short>
	{
		typedef unsigned short type;
	};

	template <>
	struct _Make_unsigned<signed int>
	{
		typedef unsigned int type;
	};

	template <>
	struct _Make_unsigned<signed long long>
	{
		typedef unsigned long long type;
	};
}

namespace std
{
	template <typename _Ty>
	struct is_rational_int
		: type_checking::_Is_rational_int<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct is_rational_float
		: type_checking::_Is_rational_float<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct is_rational
		: type_checking::integral_constant<bool, is_rational_int<_Ty>::value || is_rational_float<_Ty>::value>
	{};

	template <typename _Ty>
	struct is_vector
		: type_checking::_Is_vector<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct is_dimensional
		: type_checking::integral_constant<bool, is_arithmetic<_Ty>::value || (is_vector<_Ty>::value != 0)>
	{};

	template <typename _Ty>
	struct is_color
		: type_checking::_Is_color<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct min_value
		: type_specific::_Min_value<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct max_value
		: type_specific::_Max_value<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct bit_count
		: type_specific::_Bit_count<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct int_repr
		: type_specific::_Int_repr<typename type_modification::remove_cv<_Ty>::type>
	{};

	template <typename _Ty>
	struct make_unsigned
		: type_modification::_Make_unsigned<typename type_modification::remove_cv<_Ty>::type>
	{};
}