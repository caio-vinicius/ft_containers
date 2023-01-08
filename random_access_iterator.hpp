/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include <iterator>

namespace ft {
  template <typename T>
  class RandomAccessIterator : public std::iterator<std::random_access_iterator_tag, T> {
  private:
    T *_p;
  public:
    RandomAccessIterator(void) : _p(NULL) {};
    RandomAccessIterator(T *p) : _p(p) {};
    ~RandomAccessIterator() {};
    RandomAccessIterator(RandomAccessIterator const &src) : _p(src._p) {};
    RandomAccessIterator &operator=(RandomAccessIterator const &rhs) {
      _p = rhs._p;
      return (*this);
    };

    bool operator==(RandomAccessIterator const &rhs) {return _p == rhs._p;};
    bool operator!=(RandomAccessIterator const &rhs) {return _p != rhs._p;};
    bool operator<(RandomAccessIterator const &rhs) {return _p < rhs._p;};
    bool operator>(RandomAccessIterator const &rhs) {return _p > rhs._p;};
    bool operator<=(RandomAccessIterator const &rhs) {return _p <= rhs._p;};
    bool operator>=(RandomAccessIterator const &rhs) {return _p >= rhs._p;};
    RandomAccessIterator operator+(int const rhs) {return (RandomAccessIterator(_p + rhs));};
    RandomAccessIterator operator-(int const rhs) {return (RandomAccessIterator(_p - rhs));};
    RandomAccessIterator &operator+=(int const rhs) {
      _p += rhs;
      return (*this);
    };
    RandomAccessIterator &operator-=(int const rhs) {
      _p -= rhs;
      return (*this);
    };
    T &operator*() {return *_p;};
    RandomAccessIterator operator++() {
      ++_p;
      return (*this);
    };
    RandomAccessIterator operator++(int) {
      RandomAccessIterator rai(*this);
      ++*this;
      return (rai);
    };
    RandomAccessIterator operator--() {
      --_p;
      return (*this);
    };
    RandomAccessIterator operator--(int) {
      RandomAccessIterator rai(*this);
      --*this;
      return (rai);
    };
    T& operator[](int const &n) {return (this->_p[n]);};
  };
}
