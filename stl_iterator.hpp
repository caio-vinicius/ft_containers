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
    typedef typename ft::iterator_traits<T*>::value_type			value_type;
    typedef typename ft::iterator_traits<T*>::difference_type		difference_type;
    typedef typename ft::iterator_traits<T*>::pointer				pointer;
    typedef typename ft::iterator_traits<T*>::reference				reference;
    typedef typename ft::iterator_traits<T*>::iterator_category		iterator_category;

    normal_iterator(void) : _p(NULL) {};
    explicit normal_iterator(T *p) : _p(p) {};
    ~normal_iterator() {};
    normal_iterator(normal_iterator const &src) : _p(src._p) {};
    normal_iterator &operator=(normal_iterator const &rhs) {
      _p = rhs._p;
      return (*this);
    };

    bool operator==(normal_iterator const &rhs) {return _p == rhs._p;};
    bool operator!=(normal_iterator const &rhs) {return _p != rhs._p;};
    bool operator<(normal_iterator const &rhs) {return _p < rhs._p;};
    bool operator>(normal_iterator const &rhs) {return _p > rhs._p;};
    bool operator<=(normal_iterator const &rhs) {return _p <= rhs._p;};
    bool operator>=(normal_iterator const &rhs) {return _p >= rhs._p;};
    normal_iterator operator+(int const rhs) {return (normal_iterator(_p + rhs));};
    normal_iterator operator-(int const rhs) {return (normal_iterator(_p - rhs));};
    T &operator*() const {return *_p;};
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
    T& operator[](int const &n) {return (this->_p[n]);};
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

      iterator_type base() const {return (*i);};
      reference operator*() const {return (*i);};
      reverse_iterator operator+(difference_type n) const {return (reverse_iterator(i - n));};
      reverse_iterator operator-(difference_type n) const {return (reverse_iterator(i + n));};
      reverse_iterator &operator++() {
        --i;
        return (*this);
      };
      reverse_iterator  operator++(int) {
        reverse_iterator rev_it(*this);
        --*this;
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
      reverse_iterator  operator--(int) {
        reverse_iterator rev_it(*this);
        ++*this;
        return (rev_it);
      };
      pointer operator->() const {return &(operator*());};
      reference operator[](difference_type n) const {return (this->i[n]);};
  };
}

#endif