/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_VECTOR_HPP
# define STL_VECTOR_HPP

#include <iostream>
#include <vector>
#include <iterator>

#include "stl_iterator.hpp"
#include "stl_type_traits.hpp"

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
      typedef ft::normal_iterator<value_type> iterator;
      typedef ft::normal_iterator<const value_type> const_iterator;
      typedef ft::reverse_iterator<iterator> reverse_iterator;
      typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
      typedef typename std::size_t size_type;
      // member functions

      explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), v(NULL), _size(0), _capacity(0) {};
      explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n) {
        v = _alloc.allocate(n);
        for (size_type i = 0; i < n; ++i)
          _alloc.construct(&v[i], val);
      };
      template <typename InputIterator>
      vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
        size_type i = 0;
        for (typename ft::vector<value_type>::iterator it = first; it != last; i++)
          it++;
        _size = i;
        _capacity = i;
        v = _alloc.allocate(i);
        for (size_type j = 0; first != last; j++) {
          _alloc.construct(&v[j], *first);
          first++;
        }
      }
      vector(const vector& x) {};
      ~vector() {
        _alloc.destroy(v);
        _alloc.deallocate(v, _size);
      };
      // iterators
      iterator begin() {return (iterator(v));};
      const_iterator begin() const {return (const_iterator(v));};
      iterator end() {return (empty() ? begin() : iterator(v + _size));};
      const_iterator end() const {return (empty() ? begin() : iterator(v + _size));};
      reverse_iterator rbegin() {return (reverse_iterator(iterator(v + (_size - 1))));};
      const_reverse_iterator rbegin() const {return (const_reverse_iterator(v + (_size - 1)));};
      reverse_iterator rend() {return (reverse_iterator(iterator(v)));};
      const_reverse_iterator rend() const {const_reverse_iterator(iterator(v));};
      // capacity
      size_type size() const {return (_size);};
      size_type max_size() const {return (_alloc.max_size());};
      void resize(size_type n, value_type val = value_type());
      size_type capacity() const {return (_capacity);};
      bool empty() const {return (_size == 0);};
      void reserve (size_type n);

      // element access
      reference operator[] (size_type n) {return (v[n]);};
      const_reference operator[] (size_type n) const;
      reference at (size_type n);
      const_reference at (size_type n) const;
      reference front();
      const_reference front() const;
      reference back();
      const_reference back() const;

      // modifiers
      void assign(size_type n, const value_type& val);
      void push_back(const value_type& val) {
          if (_size == _capacity) {
            value_type *new_v;
            _capacity = _capacity * 2;
            new_v = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; i++)
              _alloc.construct(&new_v[i], v[i]);
            _alloc.construct(&new_v[_size], val);
            // be careful
            this->~vector();
            v = new_v;
          } else
            _alloc.construct(&v[_size], val);
          _size++;
      };
      void pop_back();
      void insert(iterator position, size_type n, const value_type& val);
      iterator erase(iterator position);
      iterator erase(iterator first, iterator last);
      void swap(vector& x);
      void clear();

      // allocator
      allocator_type get_allocator() const;
    private:
      T *v;
      allocator_type _alloc;
      size_type _size;
      size_type _capacity;
  };
}

#endif
