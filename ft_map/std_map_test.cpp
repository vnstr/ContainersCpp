//
// Created by Gueren Drive on 3/25/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <exception>

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

void erase_position() {
	std::cout << "erase_position" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test>           def(src.begin(), src.end());

	def.erase(def.begin());

	lib::con<int, Test>::iterator it(def.begin());

	++it; ++it; ++it;
	def.erase(it);
	it = def.end();
	--it;
	def.erase(it);
	print_map<int, Test>(def);
}

void erase_key() {
	std::cout << "erase_key" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test>           def(src.begin(), src.end());

	for (int i = 0; i < 20 ; i += 2) {
		std::cout << def.erase(i) << std::endl;
	}
	std::cout << def.erase(100) << std::endl;
	print_map<int, Test>(def);

}

void erase_firts_last() {
	std::cout << "erase_firts_last" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test>           def(src.begin(), src.end());
	lib::con<int, Test>::iterator first(def.begin());
	lib::con<int, Test>::iterator last(def.end());

	++first; ++first; ++first; ++first;
	--last; --last; --last; --last;

	def.erase(first, last);
	print_map<int, Test>(def);
	def.erase(def.begin(), def.end());
	print_map<int, Test>(def);

}

void swap() {
	std::cout << "swap" << std::endl;
	std::vector<std::pair<int, Test> > src;
	std::vector<std::pair<int, Test> > src2;

	for (int i = 0; i < 20; i += 2) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	for (int i = 1; i < 20; i += 2) {
		src2.push_back(std::pair<int, Test>(i, i));
		src2.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test>           def(src.begin(), src.end());
	lib::con<int, Test>           def2(src2.begin(), src2.end());

	def.swap(def2);
	print_map<int, Test>(def);
	print_map<int, Test>(def2);

}

void clear() {
	std::cout << "clear" << std::endl;
	std::vector<std::pair<int, Test> > src;

	for (int i = 0; i < 20; ++i) {
		src.push_back(std::pair<int, Test>(i, i));
		src.push_back(std::pair<int, Test>(i, i));
	}

	lib::con<int, Test> def(src.begin(), src.end());

	def.clear();
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
	erase_position();
	erase_key();
	erase_firts_last();
	swap();
	clear();
	// ------------
	return 0;
}