#include <iostream>
#include <list>

#include "test.hpp" // class Test;

// Constructors ================================================================

void std_default_constructor_test() {
	std::cout << "\nstd_default_constructor\n" << std::endl;
	std::list<Test> useless;

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
	std::cout << "max_size: " << useless.max_size() << std::endl;
}

void std_n_val_constructor_test() {
	std::cout << "\nstd_n_val_constructor\n" << std::endl;
	std::list<Test> useless(10, 8);

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
	std::cout << "max_size: " << useless.max_size() << std::endl;

	std::list<Test>::iterator first = useless.begin();

	for (size_t i = 0; first != useless.end(); ++i, ++first) {
		if (i % 32 == 0 && i != 0)
			std::cout << std::endl;
		std::cout << first->some_ << " ";
	}
	std::cout << std::endl;
}

void std_iter_iter_constructor_test() {
	std::cout << "\nstd_iter_iter_constructor\n" << std::endl;
	std::list<Test>           src(20);
	std::list<Test>::iterator src_iter;
	size_t                    i = 0;

	for (src_iter = src.begin(); src_iter != src.end(); ++src_iter, ++i) {
		src_iter->some_ = i;
	}

	std::list<Test> useless(src.begin(), src.end());
	std::list<Test>::iterator first = useless.begin();

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
	std::cout << "max_size: " << useless.max_size() << std::endl;
	for (i = 0; first != useless.end(); ++i, ++first) {
		if (i % 32 == 0 && i != 0)
			std::cout << std::endl;
		std::cout << first->some_ << " ";
	}
	std::cout << std::endl;
}

void std_copy_constructor_test() {
	std::cout << "\nstd_copy_constructor\n" << std::endl;
	std::list<Test>           src(20);
	std::list<Test>::iterator src_iter;
	size_t                    i = 0;

	for (src_iter = src.begin(); src_iter != src.end(); ++src_iter, ++i) {
		src_iter->some_ = i;
	}

	std::list<Test> useless(src);
	std::list<Test>::iterator first = useless.begin();

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
	std::cout << "max_size: " << useless.max_size() << std::endl;
	for (i = 0; first != useless.end(); ++i, ++first) {
		if (i % 32 == 0 && i != 0)
			std::cout << std::endl;
		std::cout << first->some_ << " ";
	}
	std::cout << std::endl;
}

void std_constructors_capacity_test() {
	std_default_constructor_test();
	std_n_val_constructor_test();
	std_iter_iter_constructor_test();
	std_copy_constructor_test();
}

// =============================================================================

int main() {
	std_constructors_capacity_test();
	return 0;
}
