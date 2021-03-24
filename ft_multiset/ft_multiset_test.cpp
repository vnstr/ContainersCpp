//
// Created by Gueren Drive on 3/23/21.
//

// TODO test for iterators

#include "ft_multiset.hpp"

template <class T>
void print_multiset(ft::Multiset<T> & multiset) {
	typename ft::Multiset<T>::iterator  it;

	std::cout << "multiset:\n";
	for (it = multiset.begin(); it != multiset.end() ; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main () {

	ft::Multiset<int> empty;
	ft::Multiset<int>::iterator iter;

	empty.insert(20);
	empty.insert(19);
	empty.insert(5);
	empty.insert(100);
	empty.insert(6);
	empty.insert(33);
	print_multiset<int>(empty);

	return 0;
}