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
		{
				ft::map<char, int> map;

				map.insert(ft::pair<char, int>('a', 100));
				map.insert(ft::pair<char, int>('b', 100));
				map.insert(ft::pair<char, int>('x', 100));
				map.insert(ft::pair<char, int>('y', 100));
				map.insert(ft::pair<char, int>('z', 100));

				ft::map<char, int>::iterator it = map.begin();

				map.erase(it);
				it = map.begin();
				bool equal = false;
				for (; it != map.end(); it++) {
						equal = true;
				}
				unit.assertTrue(equal);
		}
		delete[] arr;
}

void map_iterators(UnitTest& unit) {
		unit.runTest(testIterators, "testIterators");
}
