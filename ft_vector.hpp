/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <vector>
#include <iterator>

//#include "random_access_iterator.hpp"

namespace ft {
  template <typename T, typename Alloc = std::allocator<T> >
  class vector {
    public:
      // member types
      typedef T value_type;
      typedef Alloc allocator_type;
      typedef typename allocator_type::reference reference;
      typedef typename allocator_type::const_reference const_reference;
      typedef typename allocator_type::pointer pointer;
      typedef typename allocator_type::const_pointer const_pointer;
      typedef ft::RandomAccessIterator<value_type> *iterator;
      typedef ft::RandomAccessIterator<value_type> *const_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
      typedef typename std::size_t size_type;
      // member functions

      // iterators
      std::iterator<T, vector> begin();
      const_iterator begin() const;
      // capacity
      size_type size() const;
      size_type max_size() const;
      void resize(size_type n, value_type val = value_type());
      size_type capacity() const;
      bool empty() const;
      void reserve (size_type n);

      // element access
      reference operator[] (size_type n);
      const_reference operator[] (size_type n) const;
      reference at (size_type n);
      const_reference at (size_type n) const;
      reference front();
      const_reference front() const;
      reference back();
      const_reference back() const;

      // modifiers
      void assign(size_type n, const value_type& val);
      void push_back(const value_type& val);
      void pop_back();
      void insert(iterator position, size_type n, const value_type& val);
      iterator erase(iterator position);
      iterator erase(iterator first, iterator last);
      void swap(vector& x);
      void clear();

      // allocator
      allocator_type get_allocator() const;
  };
}
