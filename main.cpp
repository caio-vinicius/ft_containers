/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include "tests.hpp"
#include <time.h>

int main( void ) {
    clock_t start = clock();
    UnitTest unit;

    unit.setMode(false);
    //unit.addSuit(vector_non_member_functions, "NON MEMBER FUNCTIONS");
    //unit.addSuit(vector_iterator, "ITERATOR");
    //unit.addSuit(vector_reverse_iterator, "REVERSE ITERATOR");
    //unit.addSuit(vector_constructors, "CONSTRUCTORS");
    //unit.addSuit(vector_modifiers, "MODIFIERS");
    //unit.addSuit(vector_capacity, "CAPACITY");
    //unit.addSuit(vector_elements_access, "ELEMENT ACCESS");
    unit.addSuit(map_constructors, "MAP - CONSTRUCTOR");
    //unit.addSuit(map_iterators, "MAP - ITERATORS");
    //unit.addSuit(map_capacity, "MAP - CAPACITY");
    //unit.addSuit(map_element_access, "MAP - ELEMENT ACCESS");
    //unit.addSuit(map_modifiers, "MAP - MODIFIERS");
    //unit.addSuit(map_observers, "MAP - OBSERVERS");
    //unit.addSuit(map_operations, "MAP - OBSERVERS");
    //unit.addSuit(map_pair, "MAP - PAIR");
    unit.run();
    unit.status();
    unit.clear();
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << elapsed_time * 1000 << " ms." << std::endl;
    return (unit.exitStatus());
}
