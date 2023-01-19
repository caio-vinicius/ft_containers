#ifndef TESTS_HPP
# define TESTS_HPP

#ifndef STD
    #define STD 0
    #include "stl_vector.hpp"
    #include "stl_iterator.hpp"
#else
    #include <iostream>
    #include <vector>
    namespace ft = std;
#endif

#include "UnitTest.hpp"

void testVectorIterator(UnitTest unit);
void testVectorCapacity(UnitTest unit);

void testVectorModifiers(UnitTest unit);
void testVectorPushBack(UnitTest unit);
void testVectorPopBack(UnitTest unit);
void testVectorInsert(UnitTest unit);

template <typename T>
void pvec(typename ft::vector<T> vec) {
    std::cout << "pvec:";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];
    std::cout << std::endl;
}
#endif
