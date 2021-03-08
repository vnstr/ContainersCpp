#include <iostream>
#include <iomanip> // std::setw();
#include <vector>

#include "ft_vector.hpp"

struct ab {
	char a;
	char b;
};

void	constructors_operators() {

	std::cout << "\n# Start Vector Test #\n" << std::endl;


	std::cout << "\n---- Constructor test\n" << std::endl;

	std::cout << "Default:" << std::endl;
	ft::Vector<int> iarr1;
	std::cout<< "size() = " << iarr1.size() << " OK: 0" << std::endl;
	// std::cout << "iarr1.capacity() = " << iarr1.capacity() << " OK: 0" << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "Default(32):" << std::endl;
	ft::Vector<int> iarr2(32);
	std::cout<< "size() = " << iarr2.size() << " OK: 32" << std::endl;
	// std::cout << "iarr2.capacity() = " << iarr2.capacity() << " OK: 32" << std::endl;

	std::cout << "arr: ";
	for (size_t i = 0; i < iarr2.size(); ++i) {
		std::cout << iarr2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "Default(32, 7):" << std::endl;
	ft::Vector<int> iarr3(32, 7);
	std::cout<< "size() = " << iarr3.size() << " OK: 32" << std::endl;
	// std::cout << "iarr3.capacity() = " << iarr3.capacity() << " OK: 32" << std::endl;

	std::cout << "arr: ";
	for (size_t i = 0; i < iarr3.size(); ++i) {
		std::cout << iarr3[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n---------------------\n" << std::endl;


	std::cout << "Copy(Default(32, 7)):" << std::endl;
	ft::Vector<int> iarr4(ft::Vector<int> (32, 7));
	std::cout<< "size() = " << iarr4.size() << " OK: 32" << std::endl;
	// std::cout << "iarr4.capacity() = " << capacity() << " OK: 32" << std::endl;

	std::cout << "arr: ";
	for (size_t i = 0; i < iarr4.size(); ++i) {
		std::cout << iarr4[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "Default(Default 32, 7).begin()/end()):" << std::endl;
	ft::Vector<int> iarr5(iarr4.begin(), iarr4.end());
	std::cout<< "size() = " << iarr5.size() << " OK: 32" << std::endl;
	// std::cout << "iarr5.capacity() = " << capacity() << " OK: 32" << std::endl;

	std::cout << "arr: ";
	for (size_t i = 0; i < iarr5.size(); ++i) {
		std::cout << iarr5[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "operator = Default(32, 7):" << std::endl;
	ft::Vector<int> iarr6(ft::Vector<int> (32, 7));
	std::cout<< "size() = " << iarr6.size() << " OK: 32" << std::endl;
	// std::cout << "iarr6.capacity() = " << capacity() << " OK: 32" << std::endl;

	std::cout << "arr: ";
	for (size_t i = 0; i < iarr6.size(); ++i) {
		std::cout << iarr6[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "\n#  End Vector Test  #\n" << std::endl;

	std::cout << "\n#  Iterator Test    #\n" << std::endl;

	ab ab_s;
	ab_s.a = 'a';
	ab_s.b = 'b';
	ft::Vector<ab> ab_arr(1, ab_s);
	std::cout << "\narr[0].a: " << ab_arr[0].a << ", arr[0].b: " << ab_arr[0].b << std::endl;
	std::cout << "begin()->a        : " << ab_arr.begin()->a << "   OK: a" << std::endl;
	std::cout << "begin()->b        : " << ab_arr.begin()->b << "   OK: b" << std::endl;


	ft::Vector<int> iarr_0_128(129);
	for (size_t i = 0; i < iarr_0_128.size(); ++i) {
		iarr_0_128[i] = i;
	}
	std::cout << "\narr: ";
	for (size_t i = 0; i < iarr_0_128.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << iarr_0_128[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;

	ft::Vector<int>::iterator  iter1 = iarr_0_128.begin();
	ft::Vector<int>::iterator iter2 = iarr_0_128.end();
	std::cout << "*iter = begin()   : " << *iter1 << "   OK: 0" << std::endl;
	std::cout << "*iter_end = end() : " << *(--iter2)<< " OK: 128" << std::endl;
	std::cout << "begin() < end()   : " << (iarr_0_128.begin() < iarr_0_128.end()) << "   OK: 1" << std::endl;
	std::cout << "begin() > end()   : " << (iarr_0_128.begin() > iarr_0_128.end()) << "   OK: 0" << std::endl;
	std::cout << "end() <= end()    : " << (iarr_0_128.end() <= iarr_0_128.end()) << "   OK: 1" << std::endl;
	std::cout << "begin() > begin() : " << (iarr_0_128.begin() >= iarr_0_128.begin()) << "   OK: 1" << std::endl;
	iter1++;
	std::cout << "iter++; *iter     : " << *iter1 << "   OK: 1" << std::endl;
	iter1--;
	std::cout << "iter--; *iter     : " << *iter1 << "   OK: 0" << std::endl;
	std::cout << "*(iter + 5)       : " << *(iter1 + 5) << "   OK: 5" << std::endl;
	std::cout << "*(5 + iter)       : " << *(5 + iter1) << "   OK: 5" << std::endl;
	std::cout << "*(iter_end - 5)   : " << *(iter2 - 5) << " OK: 123" << std::endl;
	std::cout << "*(iter_end - iter): " << (iter2 - iter1) << " OK: 128" << std::endl;
	std::cout << "*(iter+=5)        : " << *(iter1+=5) << "   OK: 5" << std::endl;
	std::cout << "*(iter-=3)        : " << *(iter1-=3) << "   OK: 2" << std::endl;
	iter1 -= 2;
	std::cout << "iter[10]          : " << iter1[10] << " OK: 10" << std::endl;
	std::cout << "\n#  Iteratior End    #\n" << std::endl;



}

int     main(void)
{
	// constructors_operators();
    return (0);
}
