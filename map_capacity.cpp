#include "tests.hpp"
#include <algorithm>
#include <utility>


static void testEmpty(UnitTest& unit) {
	std::map<string, int> map;

	unit.assertTrue(map.empty(), "empty()");
	unit.assertTrue(map.size() == 0, "size()");
	map["pera"] = 4;
	map["banana"] = 2;
	map["cacau"] = 3;
	unit.assertFalse(map.empty(), "!empty()");
	unit.assertTrue(map.size() == 3, "!empty()");

	std::allocator<std::pair<string, int> > alloc;

	unit.assertTrue(map.max_size() == alloc.max_size(), "max_size()");
}

void map_capacity(UnitTest& unit) {
	unit.runTest(testEmpty, "testEmpty");
}
