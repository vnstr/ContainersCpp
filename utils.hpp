#ifndef CONTAINERS_CPP_UTILS_HPP
#define CONTAINERS_CPP_UTILS_HPP

# include <type_traits>

namespace ft {
	template<class T>
	void swap(T &a, T &b) {
		T tmp(a);

		a = b;
		b = tmp;
	}
}

#endif //CONTAINERS_CPP_UTILS_HPP
