//
// Created by Gueren Drive on 3/23/21.
//

// TODO test for iterators

#include "ft_multiset.hpp"

#include <iostream>
#include <vector>

#define lib ft
#define con Multiset

template <class T>
static void print_multiset(lib::con<T> & multiset) {
	typename lib::con<T>::iterator it(multiset.begin());

	std::cout
			<<  "empty: " << multiset.empty()
			<< " size: "  << multiset.size()
			<< " multiset:\n";
	size_t i = 0;
	while (it != multiset.end()) {
		if (i != 0 && i % 32 == 0) {
			std::cout << "\n";
		}
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

// Constructors ----------------------------------------------------------------

static void default_constructor_test() {
	lib::con<int> def;
	print_multiset<int>(def);

}

static void constructor_first_last_test() {
	std::vector<int> src;
	for (int i = 1000; i > 0; --i) {
		src.push_back(i);
	}
	lib::con<int> def(src.begin(), src.end());
	print_multiset(def);
}

static void copy_constructor() {
	std::vector<int> src;
	for (int i = 1000; i > 0; --i) {
		src.push_back(i);
	}
	lib::con<int> def(src.begin(), src.end());
	lib::con<int> copy_def(def);
	print_multiset(copy_def);
}

// -----------------------------------------------------------------------------

// Modifiers -------------------------------------------------------------------

static void insert_val_test() {
	lib::con<int> def;

	size_t j = 0;
	std::cout << "Inserting: \n";
	for (int i = 999; i >= 0; --i) {
		if (j != 0 && j % 32 == 0) {
			std::cout << "\n";
		}
		std::cout << *(def.insert(i)) << " " ;
		++j;
	}
	std::cout << std::endl;
	print_multiset<int>(def);
}

static void insert_position_val_test() {
	lib::con<int> def;

	size_t j = 0;
	std::cout << "Inserting: \n";
	for (int i = 999; i >= 0; --i) {
		if (j != 0 && j % 32 == 0) {
			std::cout << "\n";
		}
		std::cout << *(def.insert(def.begin(), i)) << " ";
		++j;
	}
	print_multiset<int>(def);
}

static void insert_first_last_test() {
	std::vector<int> src;
	lib::con<int>    def;
	for (int i = 1000; i > 0; --i) {
		src.push_back(i);
	}
	def.insert(src.begin(), src.end());
	def.insert(src.begin(), src.end());
	print_multiset(def);
}

// -----------------------------------------------------------------------------

int main() {
	// Constructors
	default_constructor_test();
	constructor_first_last_test();
	copy_constructor();
	// ------------

	// Modifiers

	insert_val_test();
	insert_position_val_test();
	insert_first_last_test();

	// ------------
	return 0;
}
