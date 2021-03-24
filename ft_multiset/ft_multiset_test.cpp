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
	std::cout << "default_constructor_test" << std::endl;
	lib::con<int> def;
	print_multiset<int>(def);

}

static void constructor_first_last_test() {
	std::cout << "constructor_first_last_test" << std::endl;
	std::vector<int> src;
	for (int i = 1000; i > 0; --i) {
		src.push_back(i);
	}
	lib::con<int> def(src.begin(), src.end());
	print_multiset(def);
}

static void copy_constructor() {
	std::cout << "copy_constructor" << std::endl;
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
	std::cout << "insert_val_test" << std::endl;
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
	std::cout << "insert_position_val_test" << std::endl;
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
	std::cout << "insert_first_last_test" << std::endl;
	std::vector<int> src;
	lib::con<int>    def;
	for (int i = 1000; i > 0; --i) {
		src.push_back(i);
	}
	def.insert(src.begin(), src.end());
	def.insert(src.begin(), src.end());
	print_multiset(def);
}

static void erase_position_test() {
	std::cout << "erase_position_test" << std::endl;
	std::vector<int> src;
	for (int i = 1000; i > 0; --i) {
		src.push_back(i);
	}
	lib::con<int>           def(src.begin(), src.end());
	lib::con<int>::iterator it;

	def.erase(def.begin());

	it = def.begin();
	for (int i = 0; i < 10; ++i) {
		++it;
	}
	def.erase(it);

	it = def.end();
	for (int i = 0; i < 10; ++i) {
		--it;
	}
	def.erase(it);

	print_multiset(def);
}

static void erase_val() {
	std::cout << "erase_val" << std::endl;
	lib::con<int>           def;
	lib::con<int>::iterator it;
	for (int i = 0; i < 10 ; ++i) {
		def.insert(def.end(), i);
		def.insert(def.end(), i);
	}

	def.erase(5);
	print_multiset(def);

	it = def.begin();
	for (int i = 0; i < 10; ++i) {
		def.insert(it, 6);
		it = def.begin();
	}
	def.erase(6);
	print_multiset(def);

	for (int i = 0; i < 10; ++i) {
		def.insert(99);
	}
	def.erase(99);
	print_multiset(def);
}

static void erase_first_last() {
	std::cout << "erase_val" << std::endl;
	lib::con<int>           def;
	lib::con<int>::iterator it;
	lib::con<int>::iterator it2;
	for (int i = 0; i < 10 ; ++i) {
		def.insert(def.end(), i);
		def.insert(def.end(), i);
	}

	def.erase(def.begin(), def.end());
	print_multiset(def);

	for (int i = 0; i < 30; ++i) {
		def.insert(i);
	}
	it = def.begin();
	for (int i = 0; i < 5; ++i) {
		++it;
	}
	it2 = def.end();
	for (int i = 0; i < 5; ++i) {
		--it2;
	}
	def.erase(it, it2);
	print_multiset(def);
}

static void swap_test() {
	std::cout << "swap_test" << std::endl;
	lib::con<int>           def;
	for (int i = 0; i < 10 ; ++i) {
		def.insert(def.end(), i);
		def.insert(def.end(), i);
	}
	lib::con<int>           def2;
	for (int i = 0; i < 10 ; ++i) {
		def.insert(def.end(), i + 100);
		def.insert(def.end(), i + 100);
	}

	def.swap(def2);
	print_multiset(def);
	print_multiset(def2);
}

static void clear_test() {
	std::cout << "clear" << std::endl;
	lib::con<int>           def;
	for (int i = 0; i < 10 ; ++i) {
		def.insert(def.end(), i);
		def.insert(def.end(), i);
	}

	def.clear();
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

	erase_position_test();
	erase_val();
	erase_first_last();
	swap_test();
	clear_test();

	// ------------
	return 0;
}

