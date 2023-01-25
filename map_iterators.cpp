#include "tests.hpp"

void testIterators(UnitTest& unit) {
	std::pair<string, int> *arr = getCars();
	{
		std::map<string, int> cars(arr, arr + 3);
		bool equal = false;
		for (map_iterator it = cars.begin(); it != cars.end(); it++) {
			equal = true;
		}
		unit.assertTrue(equal, "begin()~end()");
	}
	{
		std::map<string, int> cars(arr, arr + 3);
		bool equal = false;
		for (std::map<string,int>::reverse_iterator rit=cars.rbegin(); rit != cars.rend(); rit++) {
			equal = true;
		}
		unit.assertTrue(equal, "rbegin()~rend()");
	}
}

void map_iterators(UnitTest& unit) {
	unit.runTest(testIterators, "testIterators");
}
