/* Copyright (c) 2023 Caio Souza. All rights reserved. */
/* 42 */

#include "tests.hpp"

int main( void ) {
    testlist test1 = {
        testVectorIterator,
        testVectorCapacity
    };
    testSuite("Capacity", test1);
    testlist test2 = {
        testVectorModifiers,
        testVectorPushBack,
        testVectorPopBack,
        testVectorInsert
    };
    testSuite("Modifers", test2);
    return (0);
}
