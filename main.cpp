/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include "catch.hpp"

#include <iostream>

#include <vector>
#include <iterator>

namespace ft {
  template <typename T, typename Alloc = std::allocator<T> >
  class vector {
    // member types
    typedef const T *const_iterator;
    // member functions

    // iterators
    std::iterator<T, vector> begin();
    const_iterator begin() const;
    // capacity
    // element access
    // modifiers
    // allocator
  };
}

void ft_containers(void) {
    std::vector<int> v;
    v.push_back(0);

    std::cout << *v.begin() << std::endl;
    std::cout << *(v.begin() + 1);
}

//int main(void) {
//    ft_containers();
//    return (0);
//}
