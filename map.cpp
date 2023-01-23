#include "tests.hpp"

void test(UnitTest& unit) {
    std::map<std::string, int> m;

    (void)unit;
    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;
    std::cout << m["a"] << std::endl;
}

void map(UnitTest& unit) {
    unit.runTest(test, "General Map");
}
