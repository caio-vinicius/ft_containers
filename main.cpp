/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#ifndef STD
    #define STD 0
    #include "stl_vector.hpp"
    #include "stl_iterator.hpp"
#else
    #include <iostream>
    #include <vector>
    namespace ft = std;
#endif

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
            ft::vector<int> first(4,100);
            ft::vector<int> second(first.begin(), first.end() - 1);
            return (second.size() == 3);
        }
        static bool unit5() {
            return (0);
        }
    };
    test tests;
    tests.make(4, units::unit1, units::unit2, units::unit3, units::unit4);
    tests.run();
}

int main(void) {
        if (STD)
                std::cout << "== STD";
        else
                std::cout << "== FT";
        std::cout << std::endl;
        ft::vector<int> myvector (3,100);
        std::cout << " capacity: " << myvector.capacity() << " size: " << myvector.size() << std::endl;
        //it = myvector.insert(myvector.begin() + 2, 200);
        ft::vector<int>::iterator it = myvector.begin();
        ft::vector<int>::iterator it2 = myvector.end();
        myvector.insert(it, it, it2);
        //myvector.insert(myvector.begin() + 1, 2, 200);
        std::cout << " capacity: " << myvector.capacity() << " size: " << myvector.size() << std::endl;
        //myvector.insert(myvector.begin(), 200);
        //myvector.insert (it,2,300);
        for (it = myvector.begin(); it < myvector.end(); it++)
            std::cout << ' ' << *it;
        return (0);
}
