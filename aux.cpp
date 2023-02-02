#include "tests.hpp"

string *arraySet( void ) {
	string *names = new string[5];
	names[0] = "Luigi";
	names[1] = "Caio";
	names[2] = "Rafa";
	names[3] = "Adrian";
	names[4] = "Gustavo";
	return (names);
}


bool compareMapAndPair(ft::map<string, int> map, ft::pair<string, int> *arr, size_t n) {
	for (size_t i = 0; i < n; i++) {
		if (!map.count(arr[i].first)) {
			std::cout << !map.count(arr[i].first) << "==" << std::endl;
			return (false);
		}
		if (map[arr[i].first] != arr[i].second) {
			std::cout << map[arr[i].first] << "   " << arr[i].second << std::endl;
			return (false);
		}
	}
	return (true);
}

ft::pair<string, int> *getCars( void ) {
    ft::pair<string, int> *arr = new ft::pair<string, int>[6];

    arr[0] = ft::make_pair("Mitsubishi Lancer", 5);
    arr[1] = ft::make_pair("Peugeot 207", 3);
    arr[2] = ft::make_pair("Ferrari 458", 7);
    arr[3] = ft::make_pair("Kawasaki ZZR 250", 4);
    arr[4] = ft::make_pair("Porsche 911", 8);
    arr[5] = ft::make_pair("Subaru WRX", 6);
    return (arr);
}
