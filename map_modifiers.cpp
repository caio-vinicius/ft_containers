#include "tests.hpp"

static void testInsertSingleElement(UnitTest& unit) {
    ft::map<char, int> map;
    ft::pair<ft::map<char, int>::iterator, bool> ret;

    map.insert(ft::pair<char, int>('a', 100));

    ret = map.insert(ft::pair<char, int>('z', 200));
    unit.assertTrue(ret.second, "insert() returned true");
    unit.assertTrue(ret.first->first == 'z', "ret.first->first == 'z'");
    unit.assertTrue(ret.first->second == 200, "ret.first->second == 200");
    unit.assertTrue(map.size() == 2, "map.size() == 2");
    unit.assertTrue(map['a'] == 100, "map['a'] == 100");
    unit.assertTrue(map['z'] == 200, "map['z'] == 200");

    ret = map.insert(ft::pair<char, int>('z', 300));
    unit.assertTrue(ret.second == false, "insert() returned false");
    unit.assertTrue(ret.first->first == 'z', "ret.first->first == 'z'");
    unit.assertTrue(ret.first->second == 200, "ret.first->second == 200");
    unit.assertTrue(map.size() == 2, "map.size() == 2");
    unit.assertTrue(map['z'] == 200, "map['z'] == 200");
}

static void testInsertWithHint(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 2);
    ft::map<string, int>::iterator it = map.begin();

    it = map.insert(it, p[5]);
    unit.assertTrue(map.size() == 3, "map.size() == 3");
    unit.assertTrue(it->first == "Subaru WRX", "it->first == 'Subaru WRX'");
    unit.assertTrue(it->second == 6, "it->second == 6");

    it = map.end();
    it = map.insert(it, p[3]);
    unit.assertTrue(it->first == "Kawasaki ZZR 250", "it->first == 'Kawasaki ZZR 250'");
    unit.assertTrue(it->second == 4, "it->second == 4");
    delete[] p;
}

static void testInsertRange(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 2);

    map.insert(p + 4, p + 6);
    unit.assertTrue(map.count("Subaru WRX") == 1, "map.count('Subaru WRX') == 1");
    unit.assertTrue(map.count("Porsche 911") == 1, "map.count('Porsche 911') == 1");
    delete[] p;
}

static void testEraseIterator(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 3);
    map_iterator it;

    it = map.find(p[0].first);
    map.erase(it);
    unit.assertTrue(map.count(p[0].first) == 0, "map.count(p[0].first) == 0");
    unit.assertTrue(map.count(p[1].first) == 1, "map.count(p[1].first) == 1");
    unit.assertTrue(map.count(p[2].first) == 1, "map.count(p[2].first) == 1");
    unit.assertTrue(map.size() == 2, "map.size() == 2");
    delete[] p;
}

static void testEraseKey(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 3);
    map_iterator it;

    map.erase(p[1].first);
    unit.assertTrue(map.count(p[1].first) == 0, "map.count(p[1].first) == 0");
    unit.assertTrue(map.count(p[0].first) == 1, "map.count(p[0].first) == 1");
    unit.assertTrue(map.count(p[2].first) == 1, "map.count(p[2].first) == 1");
    unit.assertTrue(map.size() == 2, "map.size() == 2");
    delete[] p;
}

static void testEraseRange(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 3);

	map.erase(map.begin(), map.end());

    unit.assertTrue(map.size() == 0, "map.size() == 0");
    unit.assertTrue(map.count(p[0].first) == 0, "map.count(p[0].first) == 0");
    delete[] p;
}

static void testSwap(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 3);
    ft::map<string, int> map2;

    map.swap(map2);
    unit.assertTrue(map.size() == 0, "map.size() == 0");
    unit.assertTrue(map2.size() == 3, "map2.size() == 3");
    unit.assertTrue(compareMapAndPair(map2, p, 3) == true, "compareMapAndPair(map2, p, 3) == true");

    map[p[4].first] = p[4].second;
    map[p[5].first] = p[5].second;
    map2.swap(map);
    unit.assertTrue(map.size() == 3, "map.size() == 3");
    unit.assertTrue(map2.size() == 2, "map2.size() == 2");
    unit.assertTrue(compareMapAndPair(map2, p + 4, 2) == true, "compareMapAndPair(map, p + 4, 2) == true");
    delete[] p;
}

static void testClear(UnitTest& unit) {
    ft::pair<string, int> *p = getCars();
    ft::map<string, int> map(p, p + 6);

    map.clear();
    unit.assertTrue(map.size() == 0, "map.size() == 0");
    unit.assertTrue(map.count(p[0].first) == 0, "map.count(p[0].first) == 0");
    delete[] p;
}

void map_modifiers(UnitTest& unit) {
	unit.runTest(testInsertSingleElement, "testInsertSingleElement");
    unit.runTest(testInsertWithHint, "testInsertWithHint");
    unit.runTest(testInsertRange, "testInsertRange");
    unit.runTest(testEraseIterator, "testEraseIterator");
    unit.runTest(testEraseKey, "testEraseKey");
    unit.runTest(testEraseRange, "testEraseRange");
    unit.runTest(testSwap, "testSwap");
    unit.runTest(testClear, "testClear");
}
