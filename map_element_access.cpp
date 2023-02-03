#include "tests.hpp"

static void testOffSetOperator(UnitTest& unit) {
		ft::map<string, string> map;

		map["Luigi"] = "Ferrari";
		unit.assertTrue(map["Luigi"] == "Ferrari", "Luigi == Ferrari");
		map["Caio"] = "Souza";
		unit.assertTrue(map["Caio"] == "Souza", "Caio == Souza");

		map["Gariadno"];
		unit.assertTrue(map.size() == 3, "size == 3, The size always increases by 1 if does not found a key");
		map["Gariadno"] = "Gustas";
		unit.assertTrue(map["Gariadno"] == "Gustas", "Gariadno == Gustas");
		unit.assertTrue(map.size() == 3, "size == 3, The old value is replaced when found the key, and the size will be the same");
}

void map_element_access(UnitTest& unit) {
		unit.runTest(testOffSetOperator, "testOffSetOperator");
}
