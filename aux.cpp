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

string *setCars( void ) {
	string *names = new string[5];
	names[0] = "Mitsubishi";
	names[1] = "Peugeot";
	names[2] = "Ferrari";
	names[3] = "Kawasaki";
	names[4] = "Porsche";
	return (names);
}

bool compareMapAndPair(std::map<string, int> map, std::pair<string, int> *arr, size_t n) {
	for (size_t i = 0; i < n; i++) {
		if (!map.count(arr[i].first)) {
			return (false);
		}
		if (map[arr[i].first] != arr[i].second) {
			return (false);
		}
	}
	return (true);
}

std::pair<string, int> *getCars( void ) {
	static std::pair<string, int> *arr = new std::pair<string, int>[6];

	arr[0] = std::make_pair("Mitsubishi Lancer", 5);
	arr[1] = std::make_pair("Peugeot 207", 3);
	arr[2] = std::make_pair("Ferrari 458", 7);
	arr[3] = std::make_pair("Kawasaki ZZR 250", 4);
	arr[4] = std::make_pair("Porsche 911", 8);
	arr[5] = std::make_pair("Subaru WRX", 6);
	return (arr);
}

void print_values( std::map<std::string, int> mymap ) {
	for (std::map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		std::cout << it->first    // string (key)
				<< ':'
				<< it->second   // string's value 
				<< std::endl;
	}
}
