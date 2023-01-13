/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_TYPE_TRAITS_HPP
# define STL_TYPE_TRAITS_HPP

namespace ft {
  template <bool, typename T = void>
  struct enable_if {};

  template <typename T>
  struct enable_if<true, T> {typedef T type;};

  template<typename T>
  struct is_integral;
}

#endif
