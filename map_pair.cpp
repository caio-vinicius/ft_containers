#include "tests.hpp"
void testPair(UnitTest& unit) {
	{
		ft::map<int, int>::value_type data(3, 4);
		unit.assertTrue(data.first == 3, "data.first == 3");
		unit.assertTrue(data.second == 4, "data.second == 4");
	}
	{
		ft::map<string, char>::value_type data("Pera", 'P');
		unit.assertTrue(data.first == "Pera", "data.first == Pera");
		unit.assertTrue(data.second == 'P', "data.second == 'P");
	}
}
void testMakePair(UnitTest& unit) {
	{
		ft::map<float, ft::vector<int> >::value_type data = ft::make_pair(3.4, ft::vector<int>());

		unit.assertTrue(data.first == 3.4f, "data.first == 3.4f");
		data.second.insert(data.second.begin(), 5);
		unit.assertTrue(data.second.size() == 1, "data.second.size() == 1");
		unit.assertTrue(data.second[0] == 5, "data.second[0] == 1");
	}
}
void map_pair(UnitTest& unit) {
	unit.runTest(testPair, "testPair");
	unit.runTest(testMakePair, "testMakePair");
}
