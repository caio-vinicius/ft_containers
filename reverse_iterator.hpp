/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
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
      reference operator*() const {return *i;};
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
