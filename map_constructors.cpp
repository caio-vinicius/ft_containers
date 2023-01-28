#include "tests.hpp"


static void test_red_black(UnitTest& unit) {
	ft::map<int, int> one;
	ft::pair<int, int> arr = ft::make_pair(20, 5);
	one.insert(arr);
	ft::pair<int, int> arr2 = ft::make_pair(25, 45);
	one.insert(arr2);
	ft::pair<int, int> arr3 = ft::make_pair(26, 45);
	one.insert(arr3);
	ft::pair<int, int> arr4 = ft::make_pair(30, 45);
	one.insert(arr4);
    one._black.printBT();
	unit.assertTrue(true);
}

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
    unit.runTest(test_red_black, "test_red_black");
}
