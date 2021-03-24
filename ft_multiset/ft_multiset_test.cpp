//
// Created by Gueren Drive on 3/23/21.
//

// TODO test for iterators

#include "ft_multiset.hpp"

template <class T>
void print_multiset(ft::Multiset<T> & multiset) {
	typename ft::Multiset<T>::iterator  it;

	std::cout << "multiset:\n";
	size_t i = 0;
	for (it = multiset.begin(); it != multiset.end() ; ++it) {
		if (i != 0 && i % 32 == 0) {
			std::cout << "\n";
		}
		std::cout << *it << " ";
		++i;
	}
	std::cout << std::endl;
}

int main () {

	ft::Multiset<int> empty;
	ft::Multiset<int>::iterator iter;

	for (int i = 1000; i > 0; --i) {
		empty.insert(i);
	}
	print_multiset<int>(empty);

	return 0;
}