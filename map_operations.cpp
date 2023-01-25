#include "tests.hpp"

static void testFind(UnitTest& unit) {
    std::pair<string, int> *p = getCars();
    std::map<string, int> map(p, p + 6);
    std::map<string, int>::iterator it;

    it = map.find("Mitsubishi Lancer");
    unit.assertFalse(it == map.end(), "Mitsubishi Lancer not found");
    unit.assertTrue(it->first == "Mitsubishi Lancer", "Mitsubishi Lancer found");
    unit.assertTrue(it->second == 5, "Mitsubishi Lancer has 5 of popularity");

    unit.assertTrue(false, "const find not tested");
}

static void testCount(UnitTest& unit) {
    std::pair<string, int> *p = getCars();
    std::map<string, int> map(p, p + 6);
    std::map<string, int>::iterator it;

    unit.assertTrue(map.count("Mitsubishi Lancer") == 1, "Mitsubishi Lancer found");
    unit.assertTrue(map.count("Mitsubishi Lancer Evolution") == 0, "Mitsubishi Lancer Evolution not found");
}

static void testLowerBound(UnitTest& unit) {
    std::pair<string, int> *p = getCars();
    std::map<string, int> map(p, p + 6);
    std::map<string, int>::iterator it;

    it = map.lower_bound("Mitsubishi Lancer");
    unit.assertTrue(it->first == "Mitsubishi Lancer", "Mitsubishi Lancer found");
    unit.assertTrue(it->second == 5, "Mitsubishi Lancer has 5 of popularity");

    it = map.lower_bound("Subaru Impreza");
    unit.assertTrue(it->first == map.rbegin()->first, "Subaru Impreza not found");

    unit.assertTrue(false, "const lower_bound not tested");
}

static void testUpperBound(UnitTest& unit) {
    std::pair<string, int> *p = getCars();
    std::map<string, int> map(p, p + 6);
    std::map<string, int>::iterator it;

    it = map.upper_bound("Mitsubishi Lancer");
    unit.assertTrue(it->first == "Peugeot 207", "Peugeot 207 found");
    unit.assertTrue(it->second == 3, "Peugeot has 3 of popularity");

    it = map.upper_bound("Subaru Impreza");
    unit.assertTrue(it->first == map.rbegin()->first, "Subaru Impreza not found");

    unit.assertTrue(false, "const upper_bound not tested");
}

static void testEqualRange(UnitTest& unit) {
    std::map<char, int> map;

    map['a'] = 10;
    map['b'] = 20;
    map['c'] = 30;

    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = map.equal_range('b');

    unit.assertTrue(ret.first->first == 'b', "lower bound points to b");
    unit.assertTrue(ret.second->first == 'c', "upper bound points to c");
}

void map_operations(UnitTest& unit) {
    unit.runTest(testFind, "testFind");
    unit.runTest(testCount, "testCount");
    unit.runTest(testLowerBound, "testLowerBound");
    unit.runTest(testUpperBound, "testUpperBound");
    unit.runTest(testEqualRange, "testEqualRange");
}
