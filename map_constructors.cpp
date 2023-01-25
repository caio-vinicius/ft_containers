#include "tests.hpp"

void testConstructor(UnitTest& unit) {
	std::pair<string, int> *arr = getCars();
	{
		std::map<string, int> cars;
		unit.assertTrue(cars.size() == 0, "size 0");
	}
	{
		std::map<string, int> cars(arr, arr + 6);
		unit.assertTrue(compareMapAndPair(cars, arr, 6), "equal");
		unit.assertTrue(cars.size() == 6, "size 6");

		std::map<string, int> cars2(cars);
		unit.assertTrue(compareMapAndPair(cars2, arr, 6), "equal");
		unit.assertTrue(cars2.size() == 6, "size 6");
	}
}

void testAssignOperator(UnitTest& unit) {
	std::pair<string, int> *arr = getCars();
	std::map<string, int> cars(arr, arr + 5);
	std::map<string, int> cars2;
	cars2 = cars;

	unit.assertTrue(compareMapAndPair(cars2, arr, 5), "equal");
	unit.assertTrue(cars2.size() == 5, "size 6");
}

void map_constructors(UnitTest& unit) {
	unit.runTest(testConstructor, "testConstructor");
	unit.runTest(testAssignOperator, "testAssignOperator");
}
