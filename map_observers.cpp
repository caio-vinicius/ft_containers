#include "tests.hpp"

static void testKeyComp(UnitTest& unit) {
		std::map<string, int> map;
		std::map<string, int>::key_compare mycomp = map.key_comp();

		map["a"] = 100;
		map["b"] = 200;
		map["c"] = 300;

		unit.assertFalse(mycomp(map.find("b")->first, "a"), "b < a");
		unit.assertTrue(mycomp(map.find("a")->first, "b"), "a < b");
		unit.assertFalse(mycomp(map.find("b")->first, "b"), "b < b");
}

static void testValueComp(UnitTest& unit) {
		std::map<string, int> map;
		std::map<string, int>::value_compare mycomp = map.value_comp();

		map["a"] = 100;
		map["b"] = 200;
		map["c"] = 300;

		unit.assertTrue(mycomp(*map.find("a"), *map.find("b")), "a < b");
		map["a"] = 200;
		unit.assertTrue(mycomp(*map.find("a"), *map.find("b")), "a < b");
}

void map_observers(UnitTest& unit) {
		unit.runTest(testKeyComp, "testKeyComp");
		unit.runTest(testValueComp, "testValueComp");
}
