/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include "tests.hpp"
#include <time.h>

int main( void ) {
    clock_t start = clock();
    UnitTest unit;

    unit.setMode(false);
    unit.addSuit(vector_non_member_functions, "NON MEMBER FUNCTIONS");
    unit.addSuit(vector_iterator, "ITERATOR");
    unit.addSuit(vector_reverse_iterator, "REVERSE ITERATOR");
    unit.addSuit(vector_constructors, "CONSTRUCTORS");
    unit.addSuit(vector_modifiers, "MODIFIERS");
    unit.addSuit(vector_capacity, "CAPACITY");
    unit.addSuit(vector_elements_access, "ELEMENT ACCESS");
    unit.run();
    unit.status();
    unit.clear();
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Tempo de execução: " << elapsed_time * 1000 << " ms." << std::endl;
    return (unit.exitStatus());
}
