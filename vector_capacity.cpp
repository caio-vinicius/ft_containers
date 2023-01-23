#include "tests.hpp"

void testReserve(UnitTest &unit) {
	string *names = arraySet();
	{
		std::vector<string> vec;
		vec.reserve(1);
		unit.assertTrue(vec.size() == 0, "Reserve; size = 0");
		unit.assertTrue(vec.capacity() == 1, "Reserve; capacity = 1");
	}
	{
		std::vector<string> vec;
		vec.reserve(5);
		unit.assertTrue(vec.size() == 0, "Reserve; size = 0");
		unit.assertTrue(vec.capacity() == 5, "Reserve; capacity = 5");
	}
	{
		std::vector<string> vec(names, names + 5);
		vec.reserve(6);
		unit.assertTrue(vec.size() == 5, "Reserve; size = 5");
		unit.assertTrue(vec.capacity() == 6, "Reserve; capacity = 6");
	}
	{
		std::vector<string> vec(names, names + 5);
		vec.reserve(3);
		unit.assertTrue(vec.size() == 5, "Reserve; size = 5");
		unit.assertTrue(vec.capacity() == 5, "Reserve; capacity = 5");
	}
	delete[] names;
}

static void testResize(UnitTest &unit) {
	string *names = arraySet();
	{
		std::vector<string> vec;
		vec.resize(0);
		unit.assertTrue(vec.size() == 0, "Resize; size = 0");
		unit.assertTrue(vec.capacity() == 0, "Resize; capacity = 0");
	}
	{
		std::vector<string> vec;
		vec.resize(1);
		unit.assertTrue(vec.size() == 1, "Resize; size = 1");
		unit.assertTrue(vec.capacity() == 1, "Resize; capacity = 1");
	}
	{
		std::vector<string> vec;
		vec.resize(2);
		unit.assertTrue(vec.size() == 2, "Resize; size = 2");
		unit.assertTrue(vec.capacity() == 2, "Resize; capacity = 2");
	}
	{
		std::vector<string> vec(names, names + 5);
		vec.resize(2);
		unit.assertTrue(vec.size() == 2, "Resize; size = 2");
		unit.assertTrue(vec.capacity() == 5, "Resize; capacity = 3");
	}
	delete[] names;
}

void vector_capacity(UnitTest &unit) {
	unit.runTest(testResize, "testResize");
	unit.runTest(testReserve, "testReserve");
}
