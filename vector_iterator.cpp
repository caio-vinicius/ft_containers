#include "tests.hpp"

static void testConstructors(UnitTest& unit) {
		ft::vector<int>::iterator it;
		ft::vector<int>::iterator it2(it);

		unit.assertTrue(it == it2, "Expected: True; it2(it), it == it2");
		int *p = new int[5];
		for (int i = 0; i < 5; i++) { p[i] = i<<1; }

		ft::vector<int>::iterator it3(p);
		ft::vector<int>::iterator it4(it3);
		unit.assertEqual(it3, it4, "Expected: True; it3(p), it4(it3), it3 == it4");
		unit.assertEqual(it3[3], it4[3], "Expected: True; it3[3] == it4[3]");
		unit.assertTrue((it3 + 3) == (it4 + 3), "Expected: True; it3 + 3 == it4 + 3");

		it = it3;
		unit.assertEqual(it, it3, "Expected: True; it = it3, it == it3");
		unit.assertEqual(it[3], it3[3], "Expected: True; it3[3] == it[3]");
		unit.assertTrue((it + 3) == (it3 + 3), "Expected: True; it + 3 == it3 + 3");

		delete[] p;
}

static void testIncrementedDecremented(UnitTest& unit) {
		int *p = new int[5];
		bool equal = true;

		ft::vector<int>::iterator it(p);
		for (int i = 0; i < 5; i++, p++, it++) {
				*p = i<<1;
				if (*it != *p) {
						equal = false;
				}
		}

		unit.assertTrue(equal, "Expect: True; *it++ == *p++");
		for (int i = 0; i < 5; i++, p--, it--) {
				if (*(it - 1) != *(p - 1)) {
						equal = false;
				}
		}

		unit.assertTrue(equal, "Expect: True; *it-- == *p--");

		for (int i = 0; i < 5; i++) {
				if (*it != *p) {
						equal = false;
				}
				++p;
				++it;
		}
		unit.assertTrue(equal, "Expect: True; *++it == *++p");
		for (int i = 0; i < 5; i++) {
				if (*(it - 1) != *(p - 1)) {
						equal = false;
				}
				--p;
				--it;
		}
		unit.assertTrue(equal, "Expect: True; *--it == *--p");
		delete[] p;
}

static void testOffSetDereferenceOperator(UnitTest& unit) {
		int *p = new int[5];
		bool equal = true;

		ft::vector<int>::iterator it(p);
		for (int i = 0; i < 5; i++) {
				p[i] = i<<1;
				if (it[i] != p[i]) {
						equal = false;
				}
		}
		unit.assertTrue(equal, "Expect: True; it[i] == p[i]");
		delete[] p;
}

static void testCompoundAssignmentOperations(UnitTest& unit) {
		string *names = arraySet();
		ft::vector<string>::iterator it(names);
		it += 3;
		unit.assertTrue(!(*it).compare("Adrian"), "Expected: True; it += 3, *it == Adrian");
		unit.assertFalse(!(*it).compare("Rafa"), "Expected: Fase; it += 3, *it == Rafa");

		it -= 2;
		unit.assertFalse(!(*it).compare("Adrian"), "Expected: Fase; it -= 2, *it == Adrian");
		unit.assertTrue(!(*it).compare("Caio"), "Expected: True; it -= 2, *it == Caio");
		delete[] names;
}

static void testCompareOperators(UnitTest& unit) {

		int *p = new int[5];

		for (int i = 0; i < 5; i++) { p[i] = i<<1; }
		ft::vector<int>::iterator it(p);
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
		delete[] p;
}

void vector_iterator(UnitTest& unit) {
		unit.runTest(testCompareOperators, "testCompareOperators");
		unit.runTest(testCompoundAssignmentOperations, "testCompoundAssignmentOperations");
		unit.runTest(testIncrementedDecremented, "testIncrementedDecremented");
		unit.runTest(testOffSetDereferenceOperator, "testOffSetDereferenceOperator");
		unit.runTest(testConstructors, "testConstructors");
}
