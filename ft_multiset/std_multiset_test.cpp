//
// Created by Gueren Drive on 3/24/21.
//

#include <iostream>
#include <vector>
#include <set>

#define lib std
#define con multiset

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

int main() {
	// Constructors
	default_constructor_test();
	constructor_first_last_test();
	copy_constructor();
	// ------------
	return 0;
}

