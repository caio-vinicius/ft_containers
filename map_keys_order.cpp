#include "tests.hpp"

static void check_default_order(UnitTest& unit) {
		ft::pair<string, int> *arr = getCars();

		ft::map<string, int> cars(arr, arr + 6);
		ft::map<string, int>::iterator it = cars.begin();
		ft::map<string, int>::iterator last = it++;

		bool inoder = true;
		bool wrong = false;

		std::less<string> less = cars.key_comp();
		std::greater<string> greater;
		for(; it != cars.end(); it++) {
				if (!less(last->first, it->first)) {
						inoder = false;
				}
				if (greater(last->first, it->first)) {
						wrong = true;
				}
				last = it;
		}
		unit.assertTrue(inoder, "checking default order in three with std::less");
		unit.assertFalse(wrong, "expecting false using std::greater?");
		delete[] arr;
}

static void check_greater_order(UnitTest& unit) {
		ft::pair<string, int> *arr = getCars();

		std::less<string> less;
		std::greater<string> greater;

		ft::map<string, int, std::greater<string> > cars(arr, arr + 6);
		ft::map<string, int>::iterator it = cars.begin();
		ft::map<string, int>::iterator last = it++;

		bool inoder = true;
		bool wrong = false;

		for(; it != cars.end(); it++) {
				if (!greater(last->first, it->first)) {
						inoder = false;
				}
				if (less(last->first, it->first)) {
						wrong = true;
				}
				last = it;
		}
		unit.assertTrue(inoder, "checking default order in three with std::greater");
		unit.assertFalse(wrong, "expecting false using std::less?");
		delete[] arr;
}

void map_keys_order(UnitTest& unit) {
		unit.runTest(check_default_order, "check_default_order");
		unit.runTest(check_greater_order, "check_greater_order");
}
