/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_TYPE_TRAITS_HPP
# define STL_TYPE_TRAITS_HPP

namespace ft {
		template <bool, typename T = void>
				struct enable_if {};

		template <typename T>
				struct enable_if<true, T> {typedef T type;};

		template <typename T, T v>
				struct integral_constant {
						static const T value = v;
						typedef T value_type;
						typedef integral_constant<T, v> type;
						operator T() {return (v);};
				};

		typedef integral_constant<bool, true> true_type;
		typedef integral_constant<bool, false> false_type;

		template<typename T>
				struct is_integral : false_type {};

		template<> struct is_integral<bool> : true_type {};
		template<> struct is_integral<char> : true_type {};
		template<> struct is_integral<wchar_t> : true_type {};
		template<> struct is_integral<signed char> : true_type {};
		template<> struct is_integral<short int> : true_type {};
		template<> struct is_integral<int> : true_type {};
		template<> struct is_integral<long int> : true_type {};
		template<> struct is_integral<unsigned char> : true_type {};
		template<> struct is_integral<unsigned short int> : true_type {};
		template<> struct is_integral<unsigned int> : true_type {};
		template<> struct is_integral<unsigned long int> : true_type {};
}

#endif
