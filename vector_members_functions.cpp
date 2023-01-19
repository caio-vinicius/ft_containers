#include "tests.hpp"

static std::string *arraySet( void ) {
	std::string *names = new std::string[5];
	names[0] = "Luigi";
	names[1] = "Caio";
	names[2] = "Rafa";
	names[3] = "Adrian";
	names[4] = "Gustavo";
	return (names);
}


void testVectorModifiers(UnitTest unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 5) ;
	vec.assign(3, "Victor");
	bool equal = true;
	for (size_t i = 0; i < 3; i++) {
		if(std::string("Victor").compare(vec[i]) != 0) {
			equal = false;
			break ;
		}
	}
	unit.assertTrue(equal, "Expected: True; i < 10 vec[i] == Victor");

	vec.assign(10, "Victor");
	for (size_t i = 0; i < 10; i++) {
		if(std::string("Victor").compare(vec[i]) != 0) {
			equal = false;
			break ;
		}
	}
	unit.assertTrue(equal, "Expected: True; i < 10 vec[i] == Victor");
	unit.assertTrue(vec.size() == 10, "vec.size() == 10");
	unit.assertTrue(vec.capacity() == 10, "vec.size() == 10");
	ft::vector<std::string> vec2(names, names + 5);
	vec.assign(vec2.begin() + 2, vec2.begin() + 4);
	size_t i = 0;
	for (
		ft::vector<std::string>::iterator it = vec.begin(); it < vec.begin() + 2; it++, i++) {
		if((*it).compare(names[i])) {
			equal = false;
			break ;
		}
	}
	delete[] names;
}


void testVectorCapacity(UnitTest unit) {
	ft::vector<std::string> vec;
	std::string *names = arraySet();

	unit.assertTrue(vec.empty(), "Expected: True; vec.empty() == 0");
	unit.assertTrue(vec.size() == 0, "Expected: True; vec.size() == 0");
	unit.assertTrue(vec.capacity() == 0, "Expected: True; vec.capacity() == 0");

	vec.reserve(3);
	unit.assertTrue(vec.size() == 0, "Expected: True, reserve(3); vec.size() == 0");
	unit.assertTrue(vec.capacity() == 3, "Expected: True; vec.capacity() == 3");

	vec.resize(6);
	unit.assertFalse(vec.empty(), "Expected: False; vec.empty() != 0");
	unit.assertTrue(vec.size() == 6, "Expected: True, resize(6); vec.size() == 6");
	unit.assertTrue(vec.capacity() == 6, "Expected: True; vec.capacity() == 6");
	std::vector<std::string> originalvec;
	originalvec.resize(6);
	unit.assertTrue(vec.max_size() == originalvec.max_size());
	std::cout << vec.max_size() << "   " << originalvec.max_size() << std::endl;
	delete[] names;
}

void testVectorIterator(UnitTest unit) {
	std::string *names = arraySet();
	ft::vector<std::string> vec(names, names + 5);
	ft::vector<std::string>::iterator it;

	it = vec.begin();
	unit.assertTrue((*it) == "Luigi", "Expected: Luigi; vec.begin() == Luigi");

	it = vec.end();
	unit.assertTrue((*(it - 1)) == "Gustavo", "Expected: Luigi; vec.end() - 1 == Gustavo");

	ft::vector<std::string>::reverse_iterator rit;

	rit = vec.rbegin();
	unit.assertTrue((*rit) == "Gustavo", "Expected: Luigi; vec.rbegin() == Gustavo");

	rit = vec.rend();
	unit.assertTrue((*(rit - 1)) == "Luigi", "Expected: Luigi; vec.rend() - 1 == Luigi");

	delete[] names;
}
