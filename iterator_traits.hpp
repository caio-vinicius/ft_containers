/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iterator>
#include <cstddef>

namespace ft {
	struct random_access_iterator_tag {};

	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef random_access_iterator_tag iterator_category;
	};
}

#endif
