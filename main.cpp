/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>

#include <vector>
#include <iterator>

#include "stl_vector.hpp"
#include "stl_iterator.hpp"
#include "test.hpp"

void stl_vector_tests(void) {
    std::vector<int> second(4, 100);
    for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << second.max_size() << std::endl;

    ft::vector<int> third(4, 100);
    for (size_t i = 0; i < 4; ++i) {
        std::cout << ' ' << third[i];
    }
    std::cout << '\n';
}

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

void stl_vector_tests2(void) {
  struct units {
    static bool unit1() {
      ft::vector<int> v(2, 100);
      return (v[0] == 100 && v[1] == 100);
    }
    static bool unit2() {
      ft::vector<int> v(100, 100);
      return (v.size() == 100);
    }
    static bool unit3() {
      ft::vector<int> v(1, 1);
      return (*v.begin() == 1);
    }
    static bool unit4() {
      return (0);
    }
  };
  test tests;
  tests.make(4, units::unit1, units::unit2, units::unit3, units::unit4);
  tests.run();
}

int main(void) {
    //stl_vector_tests2();
    //std::vector<int> first;                                // empty vector of ints
    ft::vector<int> second (4,100);                       // four ints with value 100
    //std::vector<int> third (second.begin(),second.end() - 1);  // iterating through second
    //std::vector<int> fourth (third);
    //for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    //    std::cout << ' ' << *it;
    //std::cout << '\n';
    ft::vector<int> third2(second.begin(),second.end());
    return (0);
}
