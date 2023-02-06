#ifndef TESTS_HPP
# define TESTS_HPP

#include "UnitTest.hpp"

#ifndef STD
#define STD 0
		#include "stl_vector.hpp"
		#include "stl_map.hpp"
		#include "stl_stack.hpp"
		#include "stl_iterator.hpp"
		#include "stl_utility.hpp"
#else
		namespace ft = std;
#endif

#include <iostream>
#include <vector>
#include <map>
#include <stack>

typedef std::string string;
typedef ft::map<string, int>::iterator map_iterator;

std::string *arraySet( void );
std::string *test( void );

bool compareMapAndPair(ft::map<string, int> map, ft::pair<string, int> *arr, size_t n);
string *setCars( void );
void print_values( std::map<std::string, int> mymap );
ft::pair<string, int> *getCars( void );

void vector_iterator(UnitTest& unit);
void vector_reverse_iterator(UnitTest& unit);
void vector_modifiers(UnitTest& unit);
void vector_elements_access(UnitTest& unit);
void vector_constructors(UnitTest& unit);
void vector_capacity(UnitTest& unit);
void vector_non_member_functions(UnitTest& unit);
void vector_const_iterator(UnitTest& unit);

void map_constructors(UnitTest& unit);
void map_iterators(UnitTest& unit);
void map_keys_order(UnitTest& unit);
void map_capacity(UnitTest& unit);
void map_element_access(UnitTest& unit);
void map_modifiers(UnitTest& unit);
void map_observers(UnitTest& unit);
void map_operations(UnitTest& unit);
void map_pair(UnitTest& unit);

void stack_member_functions(UnitTest& unit);

#endif
