#include "tests.hpp"

static void testConstructor(UnitTest& unit) {
		ft::pair<string, int> *arr = getCars();
		{
				ft::map<string, int> cars;
				unit.assertTrue(cars.size() == 0, "size 0");
		}
		{
				ft::map<string, int> cars(arr, arr + 6);
				unit.assertTrue(compareMapAndPair(cars, arr, 6), "equal");
				unit.assertTrue(cars.size() == 6, "size 6");

				ft::map<string, int> cars2(cars);
				unit.assertTrue(compareMapAndPair(cars2, arr, 6), "equal");
				unit.assertTrue(cars2.size() == 6, "size 6");
		}
		delete[] arr;
}

void testAssignOperator(UnitTest& unit) {
		ft::pair<string, int> *arr = getCars();
		ft::map<string, int> cars(arr, arr + 4);
		ft::map<string, int> cars2;
		cars2 = cars;

		unit.assertTrue(compareMapAndPair(cars2, arr, 4), "equal");
		unit.assertTrue(cars2.size() == 4, "size 4");
		delete[] arr;
}

void map_constructors(UnitTest& unit) {
		unit.runTest(testConstructor, "testConstructor");
		unit.runTest(testAssignOperator, "testAssignOperator");
}
