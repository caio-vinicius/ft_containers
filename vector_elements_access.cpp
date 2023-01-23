#include "tests.hpp"

void testElementsAcess(UnitTest& unit) {
	string *names = arraySet();
	{
		bool equal = true;
		ft::vector<string> vec(names, names + 5);
		for (size_t i = 0; i < vec.size(); i++) {
			if (vec[i] != vec.at(i)) {
				equal = false;
			}
		}
		unit.assertTrue(equal, "vec[i] == vec.at(i)");
		vec.at(3) = "Victor";
		unit.assertTrue(vec[3] == "Victor", "vec.at(i) = Victor; vec[i] == Victor");

	}
	{
		ft::vector<string> const vec(names, names + 5);
		const string& name = vec.at(2);
		unit.assertTrue(name == names[2], "name == names[2]");
	}
	{
		ft::vector<string> vec(names, names + 5);
		string& name = vec.front();
		unit.assertTrue(name == names[0], "name == names[0]");
		name = "Victor";
		unit.assertTrue(vec[0] == "Victor", "vec[0] == Victor");
	}
	{
		ft::vector<string> const vec(names, names + 5);
		const string& name = vec.front();
		unit.assertTrue(name == names[0], "name == names[0]");
	}
	{
		ft::vector<string> vec(names, names + 5);
		string& name = vec.back();
		unit.assertTrue(name == names[4], "name == names[4]");
		name = "Victor";
		unit.assertTrue(vec[4] == "Victor", "vec[4] == Victor");
	}
	{
		ft::vector<string> const vec(names, names + 5);
		const string& name = vec.back();
		unit.assertTrue(name == names[4], "name == names[4]");
	}
	delete[] names;
	
}


void testVectorIterator(UnitTest& unit) {
	string *names = arraySet();
	ft::vector<string> vec(names, names + 5);
	ft::vector<string>::iterator it;

	it = vec.begin();
	unit.assertTrue((*it) == "Luigi", "Expected: Luigi; vec.begin() == Luigi");

	it = vec.end();
	unit.assertTrue((*(it - 1)) == "Gustavo", "Expected: Luigi; vec.end() - 1 == Gustavo");

	ft::vector<string>::reverse_iterator rit;

	rit = vec.rbegin();
	unit.assertTrue((*rit) == "Gustavo", "Expected: Luigi; vec.rbegin() == Gustavo");

	rit = vec.rend();
	unit.assertTrue((*(rit - 1)) == "Luigi", "Expected: Luigi; vec.rend() - 1 == Luigi");

	delete[] names;
}

void vector_elements_access(UnitTest& unit) {
	unit.runTest(testElementsAcess, "testElementsAcess");
	unit.runTest(testVectorIterator, "testVectorIterator");
}
