#ifndef TESTS_HPP
# define TESTS_HPP

#include "UnitTest.hpp"

#ifndef STD
    #define STD 0
    #include "stl_vector.hpp"
    #include "stl_iterator.hpp"
#else
    #include <iostream>
    #include <vector>
    namespace ft = std;
#endif

typedef std::string string;
std::string *arraySet( void );
std::string *test( void );
class Sets {
    std::string *names;

    Sets( void ) {
        names = arraySet();
    };
    ~Sets( void ) {
        delete[] names;
    }
};

void vector_iterator(UnitTest& unit);
void vector_reverse_iterator(UnitTest& unit);
void vector_modifiers(UnitTest& unit);
void vector_elements_access(UnitTest& unit);
void vector_constructors(UnitTest& unit);
void vector_capacity(UnitTest& unit);
void vector_non_member_functions(UnitTest& unit);

#endif
