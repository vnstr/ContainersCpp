#include <iostream>
#include <list>

#include "test.hpp" // class Test;

// Constructors ================================================================

void std_default_constructor_test() {
	std::cout << "\nstd_default_constructor\n" << std::endl;
	std::list<Test> useless;

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
}

void std_n_val_constructor_test() {
	std::cout << "\nstd_n_val_constructor\n" << std::endl;
	std::list<Test> useless(10, 8);

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;

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

// Iterator ====================================================================

void std_iterator_test() {
	std::cout << "\niterator_test()\n" << std::endl;
	std::list<int>           mouse(10, 5);
	std::list<int>           fat_mouse(1000, 9);
	std::list<int>::iterator begin;
	std::list<int>::iterator fat_end;

	begin    = mouse.begin();
	fat_end  = fat_mouse.end();

	std::cout << (begin++ == begin)     << std::endl;
	std::cout << (begin   == ++begin)   << std::endl;
	std::cout << (begin   == --fat_end) << std::endl;

	std::cout << (begin   != begin)     << std::endl;
	std::cout << (begin   != begin--)   << std::endl;
	std::cout << (--begin != begin)     << std::endl;
	std::cout << (begin   != --fat_end) << std::endl;

	std::cout << *begin << std::endl;
}

// =============================================================================

int main() {
	std_iterator_test();
	std_constructors_capacity_test();
	return 0;
}
