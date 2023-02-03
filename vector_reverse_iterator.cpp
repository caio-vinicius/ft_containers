#include "tests.hpp"
#include <map>
static void testBaseFunction(UnitTest& unit) {
		int *p = new int[5];
		for (int i = 0; i < 5; i++) { p[i] = i<<1; }
		ft::vector<int>::iterator it(p);

		ft::vector<int>::reverse_iterator rit(it + 5);

		unit.assertTrue(*(it + 4) == *(rit.base() - 1), "Expect: True; *(it + 4) == *(rit.base() - 1)");

		delete[] p;
}

static void testOffSetDereferenceOperator(UnitTest& unit) {
		int *p = new int[5];
		bool equal = true;

		ft::vector<int>::iterator it(p);

		ft::vector<int>::reverse_iterator rit(it + 5);
		for (int i = 0; i < 5; i++) {
				p[i] = i<<1;
				if (rit[4 - i] != p[i]) {
						equal = false;
				}
		}
		unit.assertTrue(equal, "Expect: True; it[i] == p[i]");
		delete[] p;
}

static void testIteratorIncrementedDecremented(UnitTest& unit) {
		int *p = new int[5];
		int *tmp = p;
		bool equal = true;
		for (int i = 0; i < 5; i++) {
				p[i] = i<<1;
		}
		typedef ft::vector<int>::iterator iter_type;
		ft::vector<int> src(p, p + 5);
		iter_type it = src.begin();

		ft::vector<int>::reverse_iterator rit(it + 5);
		it += 4;
		for (int i = 0; i < 5; i++, rit++, it--) {
				if (*rit != *it) {
						equal = false;
				}
		}
		unit.assertTrue(equal, "Expect: True; rit(it + 5), it+=4, *rit++ == *it--)");

		for (int i = 0; i < 5; i++, rit--, it++) {
				if (*(rit - 1) != *(it + 1)) {
						equal = false;
				}
		}
		unit.assertTrue(equal, "Expect: True; *rit-- == *it++)");

		for (int i = 0; i < 5; i++) {
				if (*it != *rit) {
						equal = false;
				}
				++rit;
				--it;
		}
		unit.assertTrue(equal, "Expect: True; *++it == *rit");
		for (int i = 0; i < 5; i++) {
				if (*(it + 1) != *(rit - 1)) {
						equal = false;
				}
				--rit;
				++it;
		}
		unit.assertTrue(equal, "Expect: True; *--it == *--rit");
		delete[] tmp;
}

static void testCompoundAssignmentOperations(UnitTest& unit) {
		string *names = arraySet();
		ft::vector<string>src(names, names + 5);
		ft::vector<string>::reverse_iterator it(src.end());
		it += 3;
		unit.assertTrue(!(*it).compare("Caio"), "Expected: True; it += 3, *it == Caio");
		unit.assertFalse(!(*it).compare("Rafa"), "Expected: Fase; it += 3, *it == Rafa");

		it -= 2;
		unit.assertTrue(!(*it).compare("Adrian"), "Expected: True; it -= 2, *it == Adrian");
		unit.assertFalse(!(*it).compare("Gustavo"), "Expected: False; it -= 2, *it == Gustavo");
		delete[] names;
}

void vector_reverse_iterator(UnitTest& unit) {
		unit.runTest(testCompoundAssignmentOperations, "testCompoundAssignmentOperations");
		unit.runTest(testIteratorIncrementedDecremented, "testIteratorIncrementedDecremented");
		unit.runTest(testOffSetDereferenceOperator, "testOffSetDereferenceOperator");
		unit.runTest(testBaseFunction, "testBaseFunction");
}
