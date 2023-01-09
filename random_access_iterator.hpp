/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator>

#include "iterator_traits.hpp"

namespace ft {
  template <typename T>
  class random_access_iterator : public std::iterator<ft::random_access_iterator_tag, T> {
  private:
    T *_p;
  public:
    random_access_iterator(void) : _p(NULL) {};
    random_access_iterator(T *p) : _p(p) {};
    ~random_access_iterator() {};
    random_access_iterator(random_access_iterator const &src) : _p(src._p) {};
    random_access_iterator &operator=(random_access_iterator const &rhs) {
      _p = rhs._p;
      return (*this);
    };

    bool operator==(random_access_iterator const &rhs) {return _p == rhs._p;};
    bool operator!=(random_access_iterator const &rhs) {return _p != rhs._p;};
    bool operator<(random_access_iterator const &rhs) {return _p < rhs._p;};
    bool operator>(random_access_iterator const &rhs) {return _p > rhs._p;};
    bool operator<=(random_access_iterator const &rhs) {return _p <= rhs._p;};
    bool operator>=(random_access_iterator const &rhs) {return _p >= rhs._p;};
    random_access_iterator operator+(int const rhs) {return (random_access_iterator(_p + rhs));};
    random_access_iterator operator-(int const rhs) {return (random_access_iterator(_p - rhs));};
    T &operator*() const {return *_p;};
    random_access_iterator &operator+=(int const rhs) {
      _p += rhs;
      return (*this);
    };
    random_access_iterator &operator-=(int const rhs) {
      _p -= rhs;
      return (*this);
    };
    random_access_iterator operator++() {
      ++_p;
      return (*this);
    };
    random_access_iterator operator++(int) {
      random_access_iterator rai(*this);
      ++*this;
      return (rai);
    };
    random_access_iterator operator--() {
      --_p;
      return (*this);
    };
    random_access_iterator operator--(int) {
      random_access_iterator rai(*this);
      --*this;
      return (rai);
    };
    T& operator[](int const &n) {return (this->_p[n]);};
  };
}

#endif
