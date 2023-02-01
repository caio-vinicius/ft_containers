#include "tests.hpp"

static void testOffSetOperator(UnitTest& unit) {
	ft::map<string, string> map;

	map["Luigi"] = "Rabudo";
	unit.assertTrue(map["Luigi"] == "Rabudo", "Luigi == Rabudo");
	map["Caio"] = "Chad";
	unit.assertTrue(map["Caio"] == "Chad", "Caio == Cahd");

	map["Gariadno"];
	unit.assertTrue(map.size() == 3, "size == 3, The size always increases by 1 if does not found a key");
	map["Gariadno"] = "Short Hair Hunter";
	unit.assertTrue(map["Gariadno"] == "Short Hair Hunter", "Gariadno == Short Hair Hunter");
	unit.assertTrue(map.size() == 3, "size == 3, The old value is replaced when found the key, and the size will be the same");
}

void map_element_access(UnitTest& unit) {
	unit.runTest(testOffSetOperator, "testOffSetOperator");
}
