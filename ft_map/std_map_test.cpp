//
// Created by Gueren Drive on 3/25/21.
//

#include <iostream>
#include <map>

#include "test.hpp"

#define lib std
#define con map

template <class KEY, class VAL>
void print_map(lib::con<int, Test> & map) {
	typename lib::con<int, Test>::iterator it(map.begin());

	std::cout
	<< "empty: " << map.empty()
	<< "size: "  << map.size()
	<< "map:\n";
	size_t i = 0;
	while (it != map.end()) {
		if (i != 0 && i % 32 == 0) {
			std::cout << "\n";
		}
		std::cout << "key: "  << (*it).first
		          << " val: " << (*it).second.some_ << " | ";
		++i;
	}
}

void default_constructor() {
	std::cout << "default_constructor" << std::endl;
	std::map<int, Test> def;
}

int main() {
	default_constructor();
	return 0;
}