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

// Element access ==============================================================

void ft_element_access_test() {
	std::cout << "\nelement_access_test()\n" << std::endl;
	ft::List<int>           small_mouse(1);
	ft::List<int>           mouse(10);
	ft::List<int>::iterator iter;

	for (iter = small_mouse.begin(); iter != small_mouse.end(); ++iter) {
		*iter = 123;
	}
	std::cout << small_mouse.front() << std::endl;
	std::cout << small_mouse.back()  << std::endl;

	size_t i = 900;
	for (iter = mouse.begin(); iter != mouse.end(); ++iter) {
		*iter = i++;
	}

	std::cout << mouse.front() << std::endl;
	std::cout << mouse.back()  << std::endl;
}

// =============================================================================

// Modifiers ===================================================================

void ft_push_front_test() {
	std::cout << "\npush_front_test()\n" << std::endl;
	ft::List<int>           empty_mouse;
	ft::List<int>           small_mouse(1);
	ft::List<int>           mouse(10);
	ft::List<int>::iterator iter;
	size_t                  i = 0;

	// empty_mouse
	for (i = 0; i < 19 ; ++i) {
		empty_mouse.push_front(i + 50);
	}
	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	// small_mouse
	for (i = 0; i < 27 ; ++i) {
		small_mouse.push_front(i + 20);
	}
	std::cout << "empty() : " << small_mouse.empty() << std::endl;
	std::cout << "size    : " << small_mouse.size()  << std::endl;
	i = 0;
	for (iter = small_mouse.begin(); iter != small_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	// mouse
	for (i = 0; i < 27 ; ++i) {
		mouse.push_front(i + 900);
	}
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void ft_pop_front_test() {
	std::cout << "\npop_front_test()\n" << std::endl;
	ft::List<Test>           small_mouse(1, 10);
	ft::List<Test>           mouse(18, 8);
	ft::List<Test>::iterator iter;
	size_t                   i;

	small_mouse.pop_front();
	std::cout << "empty() : " << small_mouse.empty() << std::endl;
	std::cout << "size    : " << small_mouse.size()  << std::endl;
	i = 0;
	for (iter = small_mouse.begin(); iter != small_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	i = 10;
	while (i--) {
		mouse.pop_front();
	}
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_erase_position_test() {
	std::cout << "\nerase_position_test()\n" << std::endl;
	ft::List<Test>           small_mouse(1, 10);
	ft::List<Test>           mouse;
	ft::List<Test>::iterator iter;
	size_t                   i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}

	small_mouse.erase(small_mouse.begin());
	std::cout << "empty() : " << small_mouse.empty() << std::endl;
	std::cout << "size    : " << small_mouse.size()  << std::endl;
	i = 0;
	for (iter = small_mouse.begin(); iter != small_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.begin();
	++iter;
	++iter;
	++iter;
	mouse.erase(iter);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.end();
	--iter;
	mouse.erase(iter);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_erase_iter_iter_test() {
	std::cout << "\nerase_iter_iter_test()\n" << std::endl;
	ft::List<Test>           small_mouse(1, 10);
	ft::List<Test>           mouse;
	ft::List<Test>::iterator iter;
	ft::List<Test>::iterator iter2;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}

	small_mouse.erase(small_mouse.begin(), small_mouse.end());
	std::cout << "empty() : " << small_mouse.empty() << std::endl;
	std::cout << "size    : " << small_mouse.size()  << std::endl;
	i = 0;
	for (iter = small_mouse.begin(); iter != small_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter  = mouse.begin();
	iter2 = mouse.begin();
	i = 3;
	while (i--) {
		++iter;
	}
	i = 6;
	while (i--) {
		++iter2;
	}
	mouse.erase(iter, iter2);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	mouse.erase(mouse.begin(), mouse.end());
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_swap_test() {
	std::cout << "\nswap_test()\n" << std::endl;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}
	mouse.swap(fat_mouse);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_resize_test() {
	std::cout << "\nresize_test()\n" << std::endl;
	std::list<Test>           mouse;
	std::list<Test>           fat_mouse;
	std::list<Test>::iterator iter;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	mouse.resize(50, 2);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	fat_mouse.resize(100, 8);
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_clear_test() {
	std::cout << "\nclear_test()\n" << std::endl;
	ft::List<Test>           empty_mouse;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	empty_mouse.clear();
	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	mouse.clear();
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	fat_mouse.clear();
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_insert_iter_val_test() {
	std::cout << "\nstd_insert_iter_val_test()\n" << std::endl;
	ft::List<Test>           empty_mouse;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	std::cout << empty_mouse.insert(empty_mouse.begin(), 7)->some_ << std::endl;

	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.begin();
	i = 5;
	while (i--) {
		++iter;
	}
	std::cout << mouse.insert(iter, 7)->some_ << std::endl;
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = fat_mouse.end();
	std::cout << fat_mouse.insert(iter, 7)->some_ << std::endl;
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_insert_iter_n_val_test() {
	std::cout << "\nstd_insert_iter_val_test()\n" << std::endl;
	ft::List<Test>           empty_mouse;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	empty_mouse.insert(empty_mouse.begin(), 2, 7);

	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.begin();
	i = 5;
	while (i--) {
		++iter;
	}
	mouse.insert(iter, 10, 7);;
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = fat_mouse.end();
	fat_mouse.insert(iter, 7, 7);
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_insert_iter_iter_iter_test() {
	std::cout << "\nstd_insert_iter_iter_iter_test()\n" << std::endl;
	ft::List<Test>           empty_mouse;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	ft::List<Test>::iterator iter2;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	empty_mouse.insert(empty_mouse.begin(), mouse.begin(), mouse.end());

	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.begin();
	i = 5;
	while (i--) {
		++iter;
	}
	iter2 = mouse.end();
	iter2--;
	mouse.insert(iter, iter, iter2);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.begin();
	i = 5;
	while (i--) {
		++iter;
	}
	iter2 = mouse.end();
	iter2--;

	fat_mouse.insert(fat_mouse.end(), iter, iter2);
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_assign_iter_iter_test() {
	std::cout << "\nstd_assign_iter_iter_test()\n" << std::endl;
	ft::List<Test>           empty_mouse;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	ft::List<Test>::iterator iter2;
	size_t                    i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	empty_mouse.assign(mouse.begin(), mouse.end());

	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = fat_mouse.begin();
	i = 5;
	while (i--) {
		++iter;
	}
	iter2 = fat_mouse.end();
	iter2--;
	mouse.assign(iter, iter2);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	iter = mouse.begin();
	i = 5;
	while (i--) {
		++iter;
	}
	iter2 = mouse.end();
	iter2--;

	fat_mouse.assign(mouse.begin(), mouse.end());
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

void ft_assign_n_val_test() {
	std::cout << "\nstd_assign_iter_iter_test()\n" << std::endl;
	ft::List<Test>           empty_mouse;
	ft::List<Test>           mouse;
	ft::List<Test>           fat_mouse;
	ft::List<Test>::iterator iter;
	size_t                   i;

	for (i = 0; i < 10; ++i) {
		mouse.push_back(i + 10);
	}
	i = 0;
	for (i = 0; i < 1000; ++i) {
		fat_mouse.push_back(i + 100);
	}

	empty_mouse.assign(7, 10);

	std::cout << "empty() : " << empty_mouse.empty() << std::endl;
	std::cout << "size    : " << empty_mouse.size()  << std::endl;
	i = 0;
	for (iter = empty_mouse.begin(); iter != empty_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	mouse.assign(3, 99);
	std::cout << "empty() : " << mouse.empty() << std::endl;
	std::cout << "size    : " << mouse.size()  << std::endl;
	i = 0;
	for (iter = mouse.begin(); iter != mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;

	fat_mouse.assign(21, 1);
	std::cout << "empty() : " << fat_mouse.empty() << std::endl;
	std::cout << "size    : " << fat_mouse.size()  << std::endl;
	i = 0;
	for (iter = fat_mouse.begin(); iter != fat_mouse.end() ; ++iter, ++i) {
		if (i != 0 && i % 32 == 0)
			std::cout << std::endl;
		std::cout << iter->some_ << " ";
	}
	std::cout << std::endl;
}

// =============================================================================

int main() {
	ft_iterator_test();
	ft_constructors_capacity_test();
	ft_element_access_test();

	// Modifiers

	ft_push_front_test();
	ft_pop_front_test();
	ft_erase_position_test();
	ft_erase_iter_iter_test();
	ft_swap_test();
	ft_resize_test();
	ft_clear_test();
	ft_insert_iter_val_test();
	ft_insert_iter_n_val_test();
	ft_insert_iter_iter_iter_test();
	ft_assign_iter_iter_test();
	ft_assign_n_val_test();

	// ---------
	return 0;
}
