#include "tests.hpp"
#include <algorithm>

static void testDefaultConstructor(UnitTest& unit) {
		ft::vector<string> vec;

		unit.assertTrue(vec.empty(), "empty() == true");
		unit.assertTrue(vec.capacity() == 0, "size == 0");
}

static void testFillConstructor(UnitTest& unit) {
		string *names = arraySet();
		{
				ft::vector<string> vec(3, names[1]);
				bool equal = true;
				for (size_t i = 0; i < vec.size(); i++){
						if(vec[i] != "Caio") {
								equal = false;
						}
				}
				unit.assertTrue(equal, "vec[i] == Caio");
				unit.assertTrue(vec.size() == 3, "size == 3");
				unit.assertTrue(vec.capacity() == 3, "capacity == 3");
		}
		delete[] names;
}

static void testRangeConstructor(UnitTest& unit) {
		string *names = arraySet();
		{
				ft::vector<string> vec(names + 2, names + 4);
				unit.assertTrue(ft::equal(vec.begin(), vec.end(), names + 2), "ft::equal(vec.begin(), vec.end(), names + 2)");
				unit.assertTrue(vec.size() == 2, "size == 2");
				unit.assertTrue(vec.capacity() == 2, "capacity == 2");
		}

		delete[] names;
}

static void testCopyConstructor(UnitTest& unit) {
		string *names = arraySet();
		{
				ft::vector<string> vec(names + 1, names + 5);
				ft::vector<string> vec2(vec);
				bool equal = true;
				for (size_t i = 0; i < vec.size(); i++) {if(vec[i] != vec2[i]) { equal = false;}}
				unit.assertTrue(ft::equal(vec.begin(), vec.end(), vec2.begin()), "*vec++ == *vec2++");
				unit.assertTrue(vec.size() == 4, "size == 4");
				unit.assertTrue(vec.capacity() == 4, "capacity == 4");
		}
		{
				ft::vector<string> vec(names + 1, names + 5);
				ft::vector<string> vec2 = vec;
				bool equal = true;
				for (size_t i = 0; i < vec.size(); i++) {if(vec[i] != vec2[i]) { equal = false;}}
				unit.assertTrue(ft::equal(vec.begin(), vec.end(), vec2.begin()), "*vec++ == *vec2++");
				unit.assertTrue(vec.size() == 4, "size == 4");
				unit.assertTrue(vec.capacity() == 4, "capacity == 4");
		}
		delete[] names;
}

void vector_constructors(UnitTest& unit) {
		unit.runTest(testDefaultConstructor, "testDefaultConstrutor");
		unit.runTest(testFillConstructor, "testFillConstrutor");
		unit.runTest(testRangeConstructor, "testRangeConstrutor");
		unit.runTest(testCopyConstructor, "testCopyConstrutor");
}
