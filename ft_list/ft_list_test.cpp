#include <iostream>
#include <list>

#include "ft_list.hpp"
#include "test.hpp" // class Test;

// Constructors ================================================================

void ft_default_constructor_test() {
	std::cout << "\nstd_default_constructor\n" << std::endl;
	ft::List<Test> useless;

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
}

void ft_n_val_constructor_test() {
	std::cout << "\nstd_n_val_constructor\n" << std::endl;
	ft::List<Test> useless(10, 8);

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;

	ft::List<Test>::iterator first = useless.begin();

	for (size_t i = 0; first != useless.end(); ++i, ++first) {
		if (i % 32 == 0 && i != 0)
			std::cout << std::endl;
		std::cout << first->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_iter_iter_constructor_test() {
	std::cout << "\nstd_iter_iter_constructor\n" << std::endl;
	ft::List<Test>           src(20);
	ft::List<Test>::iterator src_iter;
	size_t                    i = 0;

	for (src_iter = src.begin(); src_iter != src.end(); ++src_iter, ++i) {
		src_iter->some_ = i;
	}

	ft::List<Test> useless(src.begin(), src.end());
	ft::List<Test>::iterator first = useless.begin();

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
	for (i = 0; first != useless.end(); ++i, ++first) {
		if (i % 32 == 0 && i != 0)
			std::cout << std::endl;
		std::cout << first->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_copy_constructor_test() {
	std::cout << "\nstd_copy_constructor\n" << std::endl;
	ft::List<Test>           src(20);
	ft::List<Test>::iterator src_iter;
	size_t                    i = 0;

	for (src_iter = src.begin(); src_iter != src.end(); ++src_iter, ++i) {
		src_iter->some_ = i;
	}

	ft::List<Test> useless(src);
	ft::List<Test>::iterator first = useless.begin();

	std::cout << "empty() : " << useless.empty()    << std::endl;
	std::cout << "size    : " << useless.size()     << std::endl;
	for (i = 0; first != useless.end(); ++i, ++first) {
		if (i % 32 == 0 && i != 0)
			std::cout << std::endl;
		std::cout << first->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_constructors_capacity_test() {
	ft_default_constructor_test();
	ft_n_val_constructor_test();
	ft_iter_iter_constructor_test();
	ft_copy_constructor_test();
}

// =============================================================================

// Iterator ====================================================================

void ft_iterator_test() {
	std::cout << "\niterator_test()\n" << std::endl;
	ft::List<int>           mouse(10, 5);
	ft::List<int>           fat_mouse(1000, 9);
	ft::List<int>::iterator begin;
	ft::List<int>::iterator fat_end;

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

// template <class T>
// void print_list(const ft::List<T> & lst) {
//     typename ft::List<T>::node_type* node;

//     node = lst.end_node_->next;
//     std::cout << "size =        " << lst.size_            << std::endl;
//     std::cout << "end_node_     " << lst.end_node_        << std::endl;
//     std::cout << "end_node_next " << lst.end_node_->next << std::endl;
//     std::cout << "end_node_prev " << lst.end_node_->prev << std::endl;
//     std::cout << "\nlst----\n" << std::endl;
//     for (size_t i = 0; i < lst.size_; ++i) {
//         std::cout << "el[" << i << "]: " << "data = " << node->data
//                   << ", current = " << node
//                   << ", next = " << node->next << ", prev = "
//                   << node->prev << std::endl;
//         node = node->next;
//     }
//     std::cout << "\n-------\n" << std::endl;

// }



int main() {
	ft_iterator_test();
	ft_constructors_capacity_test();
	return 0;
}
