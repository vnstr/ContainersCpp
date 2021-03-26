//
// Created by Gueren Drive on 3/25/21.
//

#include <iostream>
#include <vector>
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
	lib::con<int, Test> def;

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

void brackets() {
	std::cout << "brackets" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test> def(src.begin(), src.end());

	for (size_t i = 0; i < def.size(); ++i) {
		std::cout << def[i].some_ << " ";
	}
	std::cout << std::endl;

}

void at() {
	std::cout << "at" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test> def(src.begin(), src.end());
	for (size_t i = 0; i < def.size(); ++i) {
		std::cout << def.at(i).some_ << " ";
	}
	std::cout << std::endl;

	try {
		def.at(1000);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void insert_val() {
	std::cout << "insert_val" << std::endl;
	lib::con<int, Test>           def;
	lib::con<int, Test>::iterator it;

	for (int i = 0; i < 20; ++i) {
		if (i != 0 && i % 8 == 0) {
			std::cout << std::endl;
		}
		it = def.insert(std::pair<int, Test>(i, i)).first;
		std::cout
		<< "key: "  <<  (*it).first
		<< " val: " << (*it).second.some_ << " | ";
		def.insert(std::pair<int, Test>(i, i));
	}
	std::cout << std::endl;

	print_map<int, Test>(def);
}

void insert_position_val() {
	std::cout << "insert_position_val" << std::endl;
	lib::con<int, Test>           def;
	lib::con<int, Test>::iterator it;

	for (int i = 0; i < 20; ++i) {
		if (i != 0 && i % 8 == 0) {
			std::cout << std::endl;
		}
		it = def.insert(def.begin(), std::pair<int, Test>(i, i));
		it = def.insert(def.begin(), std::pair<int, Test>(i, i));
		std::cout
				<< "key: "  <<  (*it).first
				<< " val: " << (*it).second.some_ << " | ";
		def.insert(std::pair<int, Test>(i, i));
	}
	std::cout << std::endl;

	print_map<int, Test>(def);

}

void insert_first_last() {
	std::cout << "insert_first_last" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test> def;

	def.insert(src.begin(), src.end());
	print_map<int, Test>(def);

}

int main() {
	// Constructors
	default_constructor();
	constructor_first_last();
	copy_constructor();
	// ------------

	// Element access
	brackets();
	at();
	// ------------

	//Modifiers
	insert_val();
	insert_position_val();
	insert_first_last();
	// ------------
	return 0;
}
