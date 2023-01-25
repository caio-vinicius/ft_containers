#ifndef TESTS_HPP
# define TESTS_HPP

#include "UnitTest.hpp"

#ifndef STD
    #define STD 0
    #include "stl_vector.hpp"
    #include "stl_iterator.hpp"
    #include "stl_map.hpp"
    #include "stl_utility.hpp"
#else
    namespace ft = std;
#endif

#include <iostream>
#include <vector>
#include <map>

typedef std::string string;
typedef std::map<string, int>::iterator map_iterator;

typedef std::string string;
std::string *arraySet( void );
std::string *test( void );

bool compareMapAndPair(std::map<string, int> map, std::pair<string, int> *arr, size_t n);
string *setCars( void );
void print_values( std::map<std::string, int> mymap );
std::pair<string, int> *getCars( void );

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

void map_constructors(UnitTest& unit);
void map_iterators(UnitTest& unit);
void map_capacity(UnitTest& unit);
void map_element_access(UnitTest& unit);
void map_modifiers(UnitTest& unit);

#endif
