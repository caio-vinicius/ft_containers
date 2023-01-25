#include "tests.hpp"

void	testClear(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vec(names, names + 5);
	vec.clear();
	unit.assertTrue(vec.size() == 0, "vec.size() == 0");
	unit.assertTrue(vec.capacity() == 5, "vec.capacity() == 4");
}

void	testEraseRange(UnitTest& unit) {
	string *names = arraySet();

	{
		ft::vector<string> vec(names, names + 4);
		vec.erase(vec.begin(), vec.begin() + 3);
		unit.assertTrue(vec.size() == 1, "vec.size() == 1");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
	}
	{
		ft::vector<string> vec(names, names + 4);
		vec.erase(vec.begin() + 2, vec.begin() + 3);
		unit.assertTrue(vec.size() == 3, "vec.size() == 1");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
	}
	{
		ft::vector<string> vec;
		vec.erase(vec.end(), vec.end());
		unit.assertTrue(vec.size() == 0, "vec.size() == 0");
		unit.assertTrue(vec.capacity() == 0, "vec.capacity() == 0");
	}
	delete[] names;
}

static void	testErase(UnitTest& unit) {
	string *names = arraySet();

	{
		ft::vector<string> vec(names, names + 4);
		vec.erase(vec.begin());
		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
		unit.assertTrue(ft::equal(names + 1, names + 4, vec.begin()), "vec[i] == names[i + 1]");
	}
	{
		ft::vector<string> vec(names, names + 4);
		vec.erase(vec.end());
		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names), "vec[i] == names[i]");
	}
	delete[] names;
}

void	testInsertSingleElement(UnitTest& unit) 	{
	string *names = arraySet();
	ft::vector<string> vec(names, names + 5);
	vec.insert(vec.begin() + 2, names[0]);

	unit.assertTrue(vec[2] == "Luigi", "vec[2] == Luigi");
	unit.assertTrue(vec.capacity() == 10, "vec.capacity() == 10");

	ft::vector<string> vec2;

	vec2.insert(vec2.begin(), names[0]);

	unit.assertTrue(vec2[0] == "Luigi", "vec2[0] == Luigi");
	unit.assertTrue(vec2.size() == 1, "vec2.size() == 1");
	unit.assertTrue(vec2.capacity() == 1, "vec2.capacity() == 1");

	vec2.insert(vec2.end(), names[2]);

	unit.assertTrue(vec2[1] == "Rafa", "vec2[1] == Rafa");
	unit.assertTrue(vec2.size() == 2, "vec2.size() == 2");
	unit.assertTrue(vec2.capacity() == 2, "vec2.capacity() == 2");
	delete[] names;
}

void	testInsertFillElements(UnitTest &unit) {
	string *names = arraySet();
	{
		ft::vector<string> vec;
		vec.insert(vec.begin(), 1, names[2]);
		unit.assertTrue(vec[0] == names[2], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 1, "size == 1");
		unit.assertTrue(vec.capacity() == 1, "capacity == 1");
	}
	{
		ft::vector<string> vec;
		vec.insert(vec.begin(), 3, names[3]);
		unit.assertTrue(vec[0] == names[3] && vec[1] == names[3] && vec[2] == names[3], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 3, "size == 3");
		unit.assertTrue(vec.capacity() == 3, "capacity == 3");
	}
	{
		ft::vector<string> vec(names, names + 5);
		vec.insert(vec.begin() + 2, 2, names[4]);
		unit.assertTrue(vec[2] == names[4] && vec[3] == names[4], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 7, "size == 7");
		unit.assertTrue(vec.capacity() == 10, "capacity == 10");
	}
	{
		ft::vector<string> vec(names, names + 4);
		vec.insert(vec.end(), 2, names[1]);
		unit.assertTrue(*(vec.end() - 1) == names[1] && *(vec.end() - 2) == names[1], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 6, "size == 6");
		unit.assertTrue(vec.capacity() == 8, "capacity == 8");
	}
	delete[] names;
}

void	testInsertRange(UnitTest& unit) {
	string *names = arraySet();
	{
		ft::vector<string> vec;

		vec.insert(vec.begin(),vec.begin(), vec.begin());
		unit.assertTrue(vec.empty(), "vec.empty()");
		unit.assertTrue(vec.capacity() == 0, "vec.capacity() == 0");
	}
	{
		ft::vector<string> vec;
		ft::vector<string> vec2(names, names + 3);
		vec.insert(vec.end(), vec2.begin(), vec2.end());

		unit.assertTrue(vec[0] == names[0] && vec[1] == names[1] && vec[2] == names[2], "~vec[x] == name[x]");
		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 3, "vec.capacity()== 3");
	}
	{
		ft::vector<string> vec(names, names + 3);
		ft::vector<string> vec2(names + 3, names + 5);

		vec.insert(vec.begin() + 2, vec2.begin(), vec2.end());

		unit.assertTrue(vec[2] == vec2[0] && vec[3] == vec2[1], "vec[x] == name[x]");
		unit.assertTrue(vec.size() == 5, "vec.size() == 5");
		unit.assertTrue(vec.capacity() == 6, "vec.capacity()== 6");
	}
	delete[] names;
}

void	testPopBack(UnitTest& unit) {
	string *names = arraySet();
	{
		ft::vector<string> vec(names, names + 1);
		vec.pop_back();
		unit.assertTrue(vec.size() == 0, "size == 0");
		unit.assertTrue(vec.capacity() == 1, "capacity == 1");
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names), "vec[i] == vec2[i]");
	}
	{
		ft::vector<string> vec(names, names + 5);
		vec.pop_back();
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names), "vec[i] == vec[i]");
		unit.assertTrue(vec.size() == 4, "size == 4");
		unit.assertTrue(vec.size() == 4, "vec[i] == names[i]");
	}
	delete[] names;
}

void	testPushBack(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vec;

	for (size_t i = 0; i < 3; i++) {
		vec.push_back(names[i]);
		unit.assertTrue(vec.size() == i + 1, "Expeted: Equal; size() = i");
		unit.assertTrue(vec.capacity() == 1 << i, "Expeted: Equal; capacity() = 1 << i");
		unit.assertTrue(vec[i].compare(names[i]) == 0, "Expeted: Equal; vec[i] = names[i]");
	}
	vec.push_back(names[3]);
	vec.push_back(names[4]);

	unit.assertTrue(vec.size() == 5, "Expeted: Equal; size() = 5");
	unit.assertTrue(vec.capacity() == 8, "Expeted: Equal; capacity() = 8");
	unit.assertTrue(vec[3].compare(names[3]) == 0, "Expeted: Equal; vec[3] = names[3]");

	delete[] names;
}

void	testAssignRange(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vect(names, names + 5);
	{
		ft::vector<string> vec;
		vec.assign(vect.begin(), vect.begin());

		unit.assertTrue(vec.size() == 0, "vec.size() == 0");
		unit.assertTrue(vec.capacity() == 0, "vec.capacity() == 0");
	}
	{
		ft::vector<string> vec;
		vec.assign(vect.begin(), vect.end());

		unit.assertTrue(vec.size() == 5, "vec.size() == 5");
		unit.assertTrue(vec.capacity() == 5, "vec.capacity() == 5");
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names), "ft::equal(vec.begin(), vec.end(), names)");
	}
	{
		ft::vector<string> vec(names, names + 5);
		vec.assign(vect.begin(), vect.begin() + 3);

		unit.assertTrue(vec.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec.capacity() == 5, "vec.capacity() == 5");
		unit.assertTrue(ft::equal(vec.begin(), vec.end(), names), "ft::equal(vec.begin(), vec.end(), names)");
	}
	{
		ft::vector<string> vec(names, names + 5);
		vec.assign(vec.begin() + 2, vec.begin() + 4);

		unit.assertTrue(vec.size() == 2, "vec.size() == 2");
		unit.assertTrue(vec.capacity() == 5, "vec.capacity() == 5");
		unit.assertTrue(ft::equal(vec.begin() + 2 , vec.begin() + 4, names + 2), "ft::equal(vec.begin() + 2 , vec.begin() + 4, names + 2)");
	}
	delete[] names;
}

void testAssignFill(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vect(names, names + 5);
	{
		ft::vector<string> vec;
		vec.assign(3, "Banana");

		unit.assertTrue(vec.size() == 3, "vec.size() == 2");
		unit.assertTrue(vec.capacity() == 3, "vec.capacity() == 5");
	}
	{
		ft::vector<string> vec(4, "Peras");
		vec.assign(2, "Abacaxis");

		unit.assertTrue(vec.size() == 2, "vec.size() == 2");
		unit.assertTrue(vec.capacity() == 4, "vec.capacity() == 4");
	}
	{
		ft::vector<string> vec(4, "Pamanhas");
		vec.assign(6, "Chocolates");

		unit.assertTrue(vec.size() == 6, "vec.size() == 6");
		unit.assertTrue(vec.capacity() == 6, "vec.capacity() == 6");
	}
	delete[] names;
}

void testSwap(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vec(names, names + 5);
	ft::vector<string> vec2;
	{
		ft::vector<string> vec3;
		vec3.swap(vec2);
		unit.assertTrue(vec3.size() == 0, "vec3.size() == 0");
		unit.assertTrue(vec3.capacity() == 0, "vec3.capacity() == 0");
	}
	{
		vec2.swap(vec);
		unit.assertTrue(vec.size() == 0, "vec.size() == 0");
		unit.assertTrue(vec.capacity() == 0, "vec.capacity() == 0");
		unit.assertTrue(vec2.size() == 5, "vec.size() == 5");
		unit.assertTrue(vec2.capacity() == 5, "vec.capacity() == 5");
		unit.assertTrue(ft::equal(names, names + 5, vec2.begin()), "ft::equal(names, names + 5, vec2.begin()");
	}
	{
		vec.assign(names, names + 3);
		vec.swap(vec2);
		unit.assertTrue(vec.size() == 5, "vec.size() == 5");
		unit.assertTrue(vec.capacity() == 5, "vec.capacity() == 5");
		unit.assertTrue(vec2.size() == 3, "vec.size() == 3");
		unit.assertTrue(vec2.capacity() == 3, "vec.capacity() == 3");
		unit.assertTrue(ft::equal(names, names + 3, vec.begin()), "ft::equal(names, names + 3, vec.begin()");
	}
	delete[] names;
}

void vector_modifiers(UnitTest& unit) {
	unit.runTest(testPushBack, "testPushBack");
	unit.runTest(testPopBack, "testPopBack");
	unit.runTest(testInsertSingleElement, "testInsertSingleElement");
	unit.runTest(testInsertRange, "testInsertRange");
	unit.runTest(testInsertFillElements, "testInsertFillElements");
	unit.runTest(testErase, "testErase");
	unit.runTest(testEraseRange, "testEraseRange");
	unit.runTest(testAssignRange, "testAssignRange");
	unit.runTest(testAssignFill, "testAssignFill");
	unit.runTest(testSwap, "testSwap");
}
