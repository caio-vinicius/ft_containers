#include "tests.hpp"

void testIterators(UnitTest& unit) {
		ft::pair<string, int> *arr = getCars();
		{
				ft::map<string, int> cars(arr, arr + 3);
				bool equal = false;
				for (map_iterator it = cars.begin(); it != cars.end(); it++) {
						equal = true;
				}
				unit.assertTrue(equal, "begin()~end()");
		}
		{
				ft::map<string, int> cars(arr, arr + 3);
				bool equal = false;
				for (ft::map<string,int>::reverse_iterator rit=cars.rbegin(); rit != cars.rend(); rit++) {
						equal = true;
				}
				unit.assertTrue(equal, "rbegin()~rend()");
		}
		delete[] arr;
}

void marce_error(UnitTest& unit) {
		ft::map<char, int> map;

		map['a'] = 10;
		map['b'] = 30;
		map['c'] = 50;
		map['d'] = 70;
		map['e'] = 90;
		map['f'] = 110;
		map['g'] = 130;
		map['h'] = 150;

		ft::map<char, int>::iterator it = map.begin();

		map.erase(it);
		it++;
		for (; it != map.end(); it++) {
				std::cout << it->first << std::endl;
		}
		unit.assertTrue(true);
}

void map_iterators(UnitTest& unit) {
		unit.runTest(testIterators, "testIterators");
		unit.runTest(marce_error, "marce_error");
}
