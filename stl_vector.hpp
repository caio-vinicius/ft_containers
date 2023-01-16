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
        explicit vector(const allocator_type &alloc = allocator_type()): v(NULL), _alloc(alloc), _size(0), _capacity(0) {};
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n) {
            v = _alloc.allocate(n);
            for (size_type i = 0; i < n; ++i)
                _alloc.construct(&v[i], val);
        };
        template <typename InputIterator>
        vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
            size_type i = 0;
            for (InputIterator it = first; it != last; i++)
                it++;
            _size = i;
            _capacity = i;
            v = _alloc.allocate(i);
            for (size_type j = 0; first != last; j++) {
                _alloc.construct(&v[j], *first);
                first++;
            }
        }
        vector(const vector& x) {
            _size = x._size;
            _capacity = x._capacity;
            v = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(&v[i], x.v[i]);
        }
        ~vector() {
            if (v) {
                _alloc.destroy(v);
                _alloc.deallocate(v, _size);
            }
        };
        // iterators
        iterator begin() {return (iterator(v));};
        const_iterator begin() const {return (const_iterator(v));};
        iterator end() {return (empty() ? begin() : iterator(v + _size));};
        const_iterator end() const {return (empty() ? begin() : iterator(v + _size));};
        reverse_iterator rbegin() {return (reverse_iterator(iterator(v + (_size - 1))));};
        const_reverse_iterator rbegin() const {return (const_reverse_iterator(v + (_size - 1)));};
        reverse_iterator rend() {return (reverse_iterator(iterator(v)));};
        const_reverse_iterator rend() const {return const_reverse_iterator(iterator(v));};
        // capacity
        size_type size() const {return (_size);};
        size_type max_size() const {return (_alloc.max_size());};
        void resize(size_type n, value_type val = value_type()) {
            if (n < _size) {
                for (size_type i = 0; n + i < _size ; i++)
                    _alloc.destroy(&v[n + i]);
            } else {
                for (size_type i = 0, j = _size; j + i < n; i++)
                    push_back(val);
            }
            _size = n;
        };
        size_type capacity() const {return (_capacity);};
        bool empty() const {return (_size == 0);};
        void reserve (size_type n) {
            if (n > _capacity) {
                value_type *new_v;
                _capacity = n;
                new_v = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(&new_v[i], v[i]);
                this->~vector();
                v = new_v;
            }
        };
        // element access
        reference operator[](size_type n) {return (v[n]);};
        const_reference operator[](size_type n) const {return v[n];};
        reference at(size_type n) {
            if (n >= _size)
                throw std::out_of_range("n >= _size");
            return (v[n]);
        };
        const_reference at(size_type n) const {
            if (n >= _size)
                throw std::out_of_range("n >= _size");
            return (v[n]);
        };
        reference front() {return (*v);};
        const_reference front() const {return (*v);};
        reference back() {return (*(end() - 1));};
        const_reference back() const {return (*(end() - 1));};

        // modifiers
        template <class InputIterator>
        void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
            size_type n = ft::distance(first, last);
            reserve(n);
            for (size_type i = 0; i < _size; i++) {
                _alloc.destroy(&v[i]);
                if (i < n)
                    _alloc.construct(&v[i], *first++);
            }
            for (size_type i = 0; i + _size < n; i++)
                _alloc.construct(&v[i + _size], *first++);
            _size = n;
        };
        void assign(size_type n, const value_type& val) {
            reserve(n);
            for (size_type i = 0; i < _size; i++) {
                _alloc.destroy(&v[i]);
                if (i < n)
                    _alloc.construct(&v[i], val);
            }
            for (size_type i = 0; i + _size < n; i++)
                _alloc.construct(&v[i + _size], val);
            _size = n;
        };
        void push_back(const value_type& val) {
            if (_size == _capacity) {
                reserve(_capacity * 2);
                _alloc.construct(&v[_size], val);
            } else
                _alloc.construct(&v[_size], val);
            _size++;
        };
        void pop_back() {
            if (_size > 0) {
                _alloc.destroy(&v[_size]);
                _size--;
            }
        };
        iterator insert(iterator position, const value_type& val) {
            size_type i = 0;
            for (iterator it = begin(); it != position; it++)
                i++;
            if (_size == _capacity) {
                reserve(_capacity * 2);
                position = iterator(&v[i]);
            }
            for (iterator it = end(); position != it; it--)
                *it = *(it - 1);
            *position = val;
            _size++;
            return (position);
        }
        void insert(iterator position, size_type n, const value_type& val) {
            for(size_type i = 0; i < n; i++)
                position = insert(position, val);
        };
        template <class InputIterator>
        void insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
            size_type first_position = 0, last_position = 0;
            for (iterator it = begin(); it != last; it++) {
                if (it == first)
                    first_position = last_position;
                last_position++;
            }
            for (size_type gap = last_position - first_position; gap; gap--) {
                position = insert(position, *(begin() + first_position));
                first_position += 2;
            }
        }
        iterator erase(iterator position) {
            _alloc.destroy(&*position);
            for (iterator it = position; it != end(); it++)
                *it = *(it + 1);
            _size--;
            return (position);
        };
        iterator erase(iterator first, iterator last) {
            for (iterator it = first; it != last; it++)
                _alloc.destroy(&*it);
            for (iterator it = first; it != end(); it++)
                *it = *(it + ft::distance(first, last));
            _size -= ft::distance(first, last);
            return (first);
        };
        void swap(vector& x) {
            value_type *tmp_v = v;
            size_type tmp_size = _size;
            size_type tmp_capacity = _capacity;
            v = x.v;
            _size = x._size;
            _capacity = x._capacity;
            x.v = tmp_v;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
        };
        void clear() {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&v[i]);
            _size = 0;
        };
        // allocator
        allocator_type get_allocator() const {return (_alloc);};
    private:
        T *v;
        allocator_type _alloc;
        size_type _size;
        size_type _capacity;
    };
}

#endif
