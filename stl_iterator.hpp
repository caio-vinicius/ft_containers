/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STL_ITERATOR_HPP
# define STL_ITERATOR_HPP

#include <iterator>

#include "stl_iterator_base_types.hpp"

namespace ft {
    template <typename T>
    class normal_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
    private:
        T *_p;
    public:
        typedef typename ft::iterator_traits<T*>::value_type            value_type;
        typedef typename ft::iterator_traits<T*>::difference_type       difference_type;
        typedef typename ft::iterator_traits<T*>::pointer               pointer;
        typedef typename ft::iterator_traits<T*>::reference             reference;
        typedef typename ft::iterator_traits<T*>::iterator_category     iterator_category;

        normal_iterator(void) : _p(NULL) {};
        explicit normal_iterator(T *p) : _p(p) {};
        ~normal_iterator() {};
        normal_iterator(const normal_iterator &src) : _p(src._p) {};
        normal_iterator &operator=(const normal_iterator &rhs) {
            _p = rhs._p;
            return (*this);
        };

        bool operator==(const normal_iterator &rhs) const {return _p == rhs._p;};
        bool operator!=(const normal_iterator &rhs) const {return _p != rhs._p;};
        bool operator<(const normal_iterator &rhs) const {return _p < rhs._p;};
        bool operator>(const normal_iterator &rhs) const {return _p > rhs._p;};
        bool operator<=(const normal_iterator &rhs) const {return _p <= rhs._p;};
        bool operator>=(const normal_iterator &rhs) const {return _p >= rhs._p;};
        normal_iterator operator+(difference_type rhs) const {return (normal_iterator(_p + rhs));};
        normal_iterator operator-(difference_type rhs) const {return (normal_iterator(_p - rhs));};
        reference operator*() const {return *_p;};
        normal_iterator &operator+=(int const rhs) {
            _p += rhs;
            return (*this);
        };
        normal_iterator &operator-=(int const rhs) {
            _p -= rhs;
            return (*this);
        };
        normal_iterator operator++() {
            ++_p;
            return (*this);
        };
        normal_iterator operator++(int) {
            normal_iterator rai(*this);
            ++*this;
            return (rai);
        };
        normal_iterator operator--() {
            --_p;
            return (*this);
        };
        normal_iterator operator--(int) {
            normal_iterator rai(*this);
            --*this;
            return (rai);
        };
        T& operator[](difference_type n) const {return (this->_p[n]);};
    };

    template <typename Iterator>
    class reverse_iterator {
        private:
            Iterator i;
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;

            reverse_iterator(void) : i(NULL) {};
            explicit reverse_iterator(iterator_type it) : i(it) {};
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter> &rev_it) : i(rev_it.i) {}
            ~reverse_iterator() {};
            reverse_iterator &operator=(reverse_iterator const &rhs) {
                i = rhs.i;
                return (*this);
            };

            iterator_type base() const {return (i);};
            reference operator*() const {
                Iterator it = i;
                return (*--it);
            };
            reverse_iterator operator+(difference_type n) const {return (reverse_iterator(i - n));};
            reverse_iterator operator-(difference_type n) const {return (reverse_iterator(i + n));};
            reverse_iterator &operator++() {
                --i;
                return (*this);
            };
            reverse_iterator    operator++(int) {
                reverse_iterator rev_it(*this);
                --i;
                return (rev_it);
            };
            reverse_iterator &operator+=(difference_type n) {
                i -= n;
                return (*this);
            };
            reverse_iterator &operator-=(difference_type n) {
                i += n;
                return (*this);
            };
            reverse_iterator &operator--() {
                ++i;
                return (*this);
            };
            reverse_iterator    operator--(int) {
                reverse_iterator rev_it(*this);
                ++i;
                return (rev_it);
            };
            pointer operator->() const {return (&(operator*()));};
            reference operator[](difference_type n) const {return (*operator+(n));};
    };

    template<class InputIterator>
    typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
        typename std::iterator_traits<InputIterator>::difference_type i = 0;
        for (; first != last; i++, first++) {};
        return (i);
    }
}

#endif
