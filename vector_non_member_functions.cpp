#include "tests.hpp"
void testEqual(UnitTest& unit) {
	string *names = arraySet();
	{
		ft::vector<string> vec(names, names + 5);
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names), "ft::equal(vec.begin(), vec.end(), names)");
	}
	{
		ft::vector<string> vec(names, names + 3);
		unit.assertTrue(!ft::equal(names, names + 4, vec.begin()), "!ft::equal(names, names + 4, vec.begin())");
	}
	delete[] names;
}

void testRelationalOperators(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vec(names, names + 5);
	{
		ft::vector<string> vec2(names, names + 5);
		unit.assertTrue(vec == vec2, "vec == vec2");
		unit.assertTrue(vec <= vec2, "vec <= vec2");
		unit.assertTrue(vec >= vec2, "vec >= vec2");
	}
	{
		ft::vector<string> vec2(names, names + 4);
		unit.assertTrue(vec != vec2, "vec != vec2");
		unit.assertTrue(vec > vec2, "vec > vec2");
		unit.assertTrue(vec2 < vec, "vec2 < vec");
		unit.assertFalse(vec2 > vec, "!vec2 > vec");
		unit.assertFalse(vec < vec2, "!vec < vec2");
	}
	delete[] names;
}

void vector_non_member_functions(UnitTest& unit) {
	unit.runTest(testEqual, "testEqual");
	unit.runTest(testRelationalOperators, "testRelationalOperators");
}
