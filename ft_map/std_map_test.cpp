//
// Created by Gueren Drive on 3/25/21.
//

#include <iostream>
#include <vector>
#include <map>

#include "test.hpp"

#define lib std
#define con map

template <class KEY, class VAL>
void print_map(lib::con<int, Test> & map) {
	typename lib::con<int, Test>::iterator it(map.begin());

	std::cout
	<< "empty: " << map.empty()
	<< " size: "  << map.size() << "\n"
	<< "map:\n";
	size_t i = 0;
	while (it != map.end()) {
		if (i != 0 && i % 8 == 0) {
			std::cout << "\n";
		}
		std::cout << "key: "  << (*it).first
		          << " val: " << (*it).second.some_ << " | ";
		++i;
		++it;
	}
	std::cout << std::endl;
}

void default_constructor() {
	std::cout << "default_constructor" << std::endl;
	std::map<int, Test> def;

	print_map<int, Test>(def);
}

void constructor_first_last() {
	std::cout << "constructor_first_last" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test> def(src.begin(), src.end());

	print_map<int, Test>(def);

}

void copy_constructor() {
	std::cout << "copy_constructor" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test> def(src.begin(), src.end());
	lib::con<int, Test> copy_def(def);

	print_map<int, Test>(copy_def);
}

int main() {
	// Constructors
	default_constructor();
	constructor_first_last();
	copy_constructor();
	// ------------
	return 0;
}