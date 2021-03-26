//
// Created by Gueren Drive on 3/25/21.
//

#include <iostream>
#include <map>

#include "ft_map.hpp"
#include "test.hpp"

#define lib ft
#define con Map

template <class KEY, class VAL>
void print_map(lib::con<int, Test> & map) {
	typename lib::con<int, Test>::iterator it(map.begin());

	std::cout
			<< "empty: " << map.empty()
			<< " size: "  << map.size() << "\n"
			<< "map:\n";
	size_t i = 0;
	while (it != map.end()) {
		if (i != 0 && i % 32 == 0) {
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
	std::cout << "std_default_constructor" << std::endl;
	lib::con<int, Test> def;

	def.insert(std::pair<int, Test>(1, Test(1)));
	print_map<int, Test>(def);
}

int main() {
	// Constructors
	default_constructor();
	// ------------
	return 0;
}
