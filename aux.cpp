#include "tests.hpp"

std::string *arraySet( void ) {
    std::string *names = new std::string[5];
    names[0] = "Luigi";
    names[1] = "Caio";
    names[2] = "Rafa";
    names[3] = "Adrian";
    names[4] = "Gustavo";
    return (names);
}
