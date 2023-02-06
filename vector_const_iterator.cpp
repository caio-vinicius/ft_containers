#include "tests.hpp"

static void testCompareOperators(UnitTest& unit) {

		int *p = new int[5];

		for (int i = 0; i < 5; i++) { p[i] = i<<1; }
		const ft::vector<int>::iterator it(p);
		ft::vector<int>::iterator it2(p);

		{
				unit.assertTrue(it == it, "Expected: True, it == it");
				unit.assertFalse(it + 1 == it, "Expected: False, it + 1 == it");
				unit.assertTrue(it + 1 != it, "Expected: True, it + 1 != it");

				unit.assertFalse(it > it, "Expected: False, it > it");
				unit.assertTrue(it + 1 > it, "Expected: True, it + 1 > it");

				unit.assertFalse(it < it, "Expected: False, it < it");
				unit.assertTrue(it < it + 1, "Expected: True, it < it + 1");

				unit.assertTrue(it >= it, "Expected: True, it >= it");
				unit.assertTrue(it + 1 >= it, "Expected: True, it + 1 >= it");
				unit.assertFalse(it >= it + 1, "Expected: False, it >= it + 1");

				unit.assertTrue(it <= it, "Expected: True, it <= it ");
				unit.assertTrue(it <= it + 1, "Expected: True, it <= it + 1 ");
				unit.assertFalse(it + 1 <= it, "Expected: False, it + 1 <= it");
		}
		{
				unit.assertTrue(it == it2, "Expected: True, it == it2");
				unit.assertFalse(it + 1 == it2, "Expected: False, it + 1 == it2");
				unit.assertTrue(it + 1 != it2, "Expected: True, it + 1 != it2");

				unit.assertFalse(it > it, "Expected: False, it > it");
				unit.assertTrue(it + 1 > it, "Expected: True, it + 1 > it");

				unit.assertFalse(it < it, "Expected: False, it < it");
				unit.assertTrue(it < it + 1, "Expected: True, it < it + 1");

				unit.assertTrue(it >= it2, "Expected: True, it >= it2");
				unit.assertTrue(it + 1 >= it2, "Expected: True, it + 1 >= it2");
				unit.assertFalse(it >= it2 + 1, "Expected: False, it >= it2 + 1");

				unit.assertTrue(it <= it2, "Expected: True, it <= it2 ");
				unit.assertTrue(it <= it2 + 1, "Expected: True, it <= it2 + 1 ");
				unit.assertFalse(it + 1 <= it2, "Expected: False, it + 1 <= it2");
		}
		delete[] p;
}

void vector_const_iterator(UnitTest& unit) {
		unit.runTest(testCompareOperators, "testCompareOperators");
}
