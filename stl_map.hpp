/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_MAP_HPP
# define STL_MAP_HPP

#include "tests.hpp"
#include "stl_utility.hpp"
#include "stl_functional.hpp"

namespace ft {

    template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const Key, T> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::iterator iterator;
            typedef typename allocator_type::const_iterator const_iterator;
            typedef typename allocator_type::reverse_iterator reverse_iterator;
            typedef typename allocator_type::const_reverse_iterator const_reverse_iterator;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type size_type;

            class value_compare : public ft::binary_function<value_type, value_type, bool> {
                friend class map<Key, T, Compare, Alloc>;
                protected:
                    Compare comp;
                    value_compare(Compare c) : comp(c) {}
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;

                    bool operator()(const value_type &x, const value_type &y) const {
                        return comp(x.first, y.first);
                    }
            };

            // Constructors
            map(): _size(0), _comp(), _alloc() {};
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _size(0), _comp(comp), _alloc(alloc) {};
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _comp(comp), _alloc(alloc) {
                insert(first, last);
            }
            map(const map &x): _size(0), _comp(x._comp), _alloc(x._alloc) {};

            // Destructor
            ~map();

            // Operators
            map &operator=(const map &x);

            // Iterators
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;

            // Capacity
            bool empty() const;
            size_type size() const;
            size_type max_size() const;

            // Element access
            mapped_type &operator[](const key_type &k);

            // Modifiers
            ft::pair<iterator, bool> insert(const value_type &val);
            iterator insert(iterator position, const value_type &val);
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);
            void erase(iterator position);
            size_type erase(const key_type &k);
            void erase(iterator first, iterator last);
            void swap(map &x);
            void clear();

            // Observers
            key_compare key_comp() const {
                return (_comp);
            };
            value_compare value_comp() const {
                return value_compare(_comp);
            }

            // Operations
            iterator find(const key_type &k);
            const_iterator find(const key_type &k) const;
            size_type count(const key_type &k) const;
            iterator lower_bound(const key_type &k);
            const_iterator lower_bound(const key_type &k) const;
            iterator upper_bound(const key_type &k);
            const_iterator upper_bound(const key_type &k) const;
            pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
            pair<iterator, iterator> equal_range(const key_type &k);

            // Allocator
            allocator_type get_allocator() const;


        private:
            size_type _size;
            key_compare _comp;
            allocator_type _alloc;
    };
}

#endif
