/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>

#include <vector>
#include <iterator>

// #include "ft_vector.hpp"
#include "stl_iterator.hpp"

void normal_iterator_tests(void) {
    std::cout << "=== RANDOM ACCESS ITERATOR ===" << std::endl;
    // ============
    std::cout << "1. Operator *" << std::endl;
    std::cout << "--> First value of iterator is 5 but should be 404." << std::endl;

    int array[6] = {5, 4, 8, 0, 9, 10};
    ft::normal_iterator<int> it(array);

    int t = 404;
    *it = t;
    if (*it == 404)
      std::cout << "[OK]";
    else
      std::cout << "[KO]";
    std::cout << std::endl;
    // ============

    std::cout << "2. Operator ++a a++ --a a--" << std::endl;
    std::cout << "--> Array has 5,4,8,0,9,10 should print 5480" << std::endl;

    int array2[6] = {5, 4, 8, 0, 9, 10};
    ft::normal_iterator<int> it2(array2);
    std::cout << *it2;
    it2++;
    std::cout << *it2++;
    std::cout << *it2;
    std::cout << *++it2 << std::endl;
    // ============

    std::cout << "3. Operator []" << std::endl;
    std::cout << "--> Array has 5,4,8,0,9,10" << std::endl;

    int array3[6] = {5, 4, 8, 0, 9, 10};
    ft::normal_iterator<int> it3(array3);
    if (it3[0] == 5 && it3[1] == 4 && it3[2] == 8)
      std::cout << "[OK]";
    else
      std::cout << "[KO]";
    std::cout << std::endl;
}

void reverse_iterator_tests(void) {
    int array3[6] = {5, 4, 8, 0, 9, 10};
    ft::normal_iterator<int> it3(array3);
    ft::reverse_iterator<ft::normal_iterator<int> > rev_it(it3);
    std::cout << *rev_it << std::endl;
}

void ft_containers(void) {
  //normal_iterator_tests();
  reverse_iterator_tests();
}

int main(void) {
  ft_containers();
  return (0);
}
