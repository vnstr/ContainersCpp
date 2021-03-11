#include <iostream>
#include <iomanip> // std::setw();
#include <vector>

#include <unistd.h>

#include "ft_vector.hpp"

struct ab {
	char a;
	char b;
};

void    constructors_iterator() {

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
	std::cout << (iter2 - iter1) << " OK: 129" << std::endl;
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
	std::cout << "iter[10]          : " << iter1[10] << "  OK: 10" << std::endl;
	std::cout << "\n#  Iteratior End    #\n" << std::endl;
}

void    const_iterator_test(void)
{
	std::cout << "\n# Start Vector Test #\n" << std::endl;


	ft::Vector<int> iarr1;
	ft::Vector<int> iarr2(32);

	ft::Vector<int> iarr3(32, 7);
	ft::Vector<int> iarr4(ft::Vector<int> (32, 7));
	ft::Vector<int> iarr5(iarr4.begin(), iarr4.end());
	ft::Vector<int> iarr6(ft::Vector<int> (32, 7));

	std::cout << "\n# ConstIterator Test#\n" << std::endl;

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

	ft::Vector<int>::const_iterator  iter1 = iarr_0_128.begin();
	ft::Vector<int>::const_iterator  iter2 = iarr_0_128.end();
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
	std::cout << "iter[10]          : " << iter1[10] << "  OK: 10" << std::endl;
	std::cout << "\n# ConstIterator End #\n" << std::endl;

}
class   Test {
public:
	Test() : some(0), str(0) {std::cout << "Test created" << std::endl;}

	Test(int s) : some(s), str(0) {std::cout << "Test " << this->some << " created" << std::endl;}

	Test(Test const & s) : some(s.some), str(0) {
		std::cout << "Copy Test " << this->some << " created" << std::endl;
	}

	~Test() {
		if (this->str != 0)
			free(this->str);
		std::cout << "Test deleted" << std::endl;
	}

	Test &operator=(Test const & x) {
		this->str = (char*)malloc(10);
		this->some = x.some;
		return (*this);
	}

	void alloc() {
		this->str = (char*)malloc(10);
	}
	int some;
	char* str;

};

void    capacity_test() {


	std::cout << "\n# Capasity Test     #\n" << std::endl;

	std::cout << "\n---- resize()        \n" << std::endl;

	// Less
	std::vector<Test> arr(10, 7);
	std::cout << arr[9].some << std::endl;
	for (int i = 0; i < 10; ++i) {
		arr[i].alloc();
	}

	std::cout << arr.size() << ", " << arr.capacity() << std::endl;
	arr.resize(5);
	std::cout << "after resize(5) "<< std::endl;
	std::cout << arr.size() << ", " << arr.capacity() << std::endl;
	arr.resize(0);
	std::cout << "after resize(0) "<< std::endl;

	// More
	std::vector<Test> arr2(10, 7);
	for (int i = 0; i < 10; ++i) {
		arr2[i].alloc();
	}

	arr2.resize(20, 19);
	std::cout << "after resize(20) "<< std::endl;
	std::cout << arr2.size() << ", " << arr2.capacity() << std::endl;


	std::cout << "\n---------------------\n" << std::endl;


	std::cout << "\n---- empty()         \n" << std::endl;

	ft::Vector<int> arr3;

	std::cout << arr3.empty() << " OK: 1" << std::endl;
	arr3.resize(3);
	std::cout << arr3.empty() << " OK: 0" << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "\n---- reserve()       \n" << std::endl;

	std::vector<Test> arr4(5, 7);

	std::cout << arr4.size() << ", " << arr4.capacity() << std::endl;

	arr4.reserve(10);
	std::cout << "after reserve(10) "<< std::endl;
	std::cout << arr4.size() << ", " << arr4.capacity() << std::endl;


	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "\n# Capasity Test End #\n" << std::endl;
}

void    element_access_test() {

	std::cout << "\n# ElementAccess     #\n" << std::endl;

	// std::cout << "\n---- operator[]      \n" << std::endl;

	ft::Vector<Test> arr(10, 7);
	for (int i = 0; i < 10; ++i) {
		arr[i].alloc();
	}
	std::cout << arr[0].some << " OK: 7" << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "\n---- at()            \n" << std::endl;

	std::cout << arr.at(0).some <<  " OK: 7" << std::endl;

	try {
		arr.at(1000);
	}
	catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "\n---- front()         \n" << std::endl;

	std::cout << arr.front().some << " OK: 7" << std::endl;

	std::cout << "\n---------------------\n" << std::endl;


	std::cout << "\n---- front()         \n" << std::endl;

	std::cout << arr.back().some << " OK: 7";

	std::cout << "\n---------------------\n" << std::endl;

	std::cout << "\n# ElementAccess End #\n" << std::endl;
}

void    modifier_test() {

	std::cout << "\n# Modifiers Test    #\n" << std::endl;

	// assign(iter, iter);
	// ARR ---------------------------------------------------------------------

	std::cout << "ARR_ITER_TEST:" << std::endl;

	ft::Vector<int> iarr_0_128_iter(129);
	for (size_t i = 0; i < iarr_0_128_iter.size(); ++i) {
		iarr_0_128_iter[i] = i;
	}
	std::cout << "\narr: ";
	for (size_t i = 0; i < iarr_0_128_iter.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << iarr_0_128_iter[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
	std::cout << "size: " << iarr_0_128_iter.size() << ", capacity: " << iarr_0_128_iter.capacity() << std::endl;

	std::vector<int> std_i_arr_0_256(256);
	for (size_t i = 0; i < std_i_arr_0_256.size(); ++i) {
		std_i_arr_0_256[i] = i;
	}



	std::cout << "\n---- assign()        \n" << std::endl;

	// ft::Vector<int>::iterator iter1 = iarr_0_128_iter.begin() + 5;
	// ft::Vector<int>::iterator iter2 = iarr_0_128_iter.end() - 5;

	try {
		iarr_0_128_iter.assign(3, 2);
	}
	catch(std::exception & e) {
		std::cout << "Exceptions: |" << e.what() << "|" << std::endl;
	}

	std::cout << "\narr: ";
	for (size_t i = 0; i < iarr_0_128_iter.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << iarr_0_128_iter[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
	std::cout << "size: " << iarr_0_128_iter.size() << ", capacity: " << iarr_0_128_iter.capacity() << std::endl;


	std::cout << "\n---------------------\n" << std::endl;

	// STD_ARR -----------------------------------------------------------------

	std::cout << "STD_ARR_ITER_TEST:" << std::endl;

	std::vector<int> std_iarr_0_128_iter(129);
	for (size_t i = 0; i < std_iarr_0_128_iter.size(); ++i) {
		std_iarr_0_128_iter[i] = i;
	}
	std::cout << "\nstd_arr: ";
	for (size_t i = 0; i < std_iarr_0_128_iter.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << std_iarr_0_128_iter[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
	std::cout << "size: " << std_iarr_0_128_iter.size() << ", capacity: " << std_iarr_0_128_iter.capacity() << std::endl;

	std::cout << "\n---- assign()        \n" << std::endl;


	// std::vector<int>::iterator std_iter1 = std_iarr_0_128_iter.begin() + 5;
	// std::vector<int>::iterator std_iter2 = std_iarr_0_128_iter.end() - 5;

	try {
		std_iarr_0_128_iter.assign(3, 2);
	}
	catch(std::exception & e) {
		std::cout << "Exceptions: |" << e.what() << "|" << std::endl;
	}

	std::cout << "\nstd_arr: ";
	for (size_t i = 0; i < std_iarr_0_128_iter.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << std_iarr_0_128_iter[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
	std::cout << "size: " << std_iarr_0_128_iter.size() << ", capacity: " << std_iarr_0_128_iter.capacity() << std::endl;

	std::cout << "\n---------------------\n" << std::endl;

	// ARR ---------------------------------------------------------------------
	// assign(n, val);

	std::cout << "ARR:" << std::endl;


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
	std::cout << "size: " << iarr_0_128.size() << ", capacity: " << iarr_0_128.capacity() << std::endl;



	std::cout << "\n---- assign()        \n" << std::endl;


	try {
		iarr_0_128.assign(0, 8);
	}
	catch(std::exception & e) {
		std::cout << "Exceptions: |" << e.what() << "|" << std::endl;
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
	std::cout << "size: " << iarr_0_128.size() << ", capacity: " << iarr_0_128.capacity() << std::endl;


	// std::cout << "\n---------------------\n" << std::endl;

	// STD_ARR -----------------------------------------------------------------

	std::cout << "STD_ARR:" << std::endl;

	std::vector<int> std_iarr_0_128(129);
	for (size_t i = 0; i < std_iarr_0_128.size(); ++i) {
		std_iarr_0_128[i] = i;
	}
	std::cout << "\nstd_arr: ";
	for (size_t i = 0; i < std_iarr_0_128.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << std_iarr_0_128[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
	std::cout << "size: " << std_iarr_0_128.size() << ", capacity: " << std_iarr_0_128.capacity() << std::endl;

	std::cout << "\n---- assign()        \n" << std::endl;


	try {
		std_iarr_0_128.assign(0, 8);
	}
	catch(std::exception & e) {
		std::cout << "Exceptions: |" << e.what() << "|" << std::endl;
	}

	std::cout << "\nstd_arr: ";
	for (size_t i = 0; i < std_iarr_0_128.size(); ++i) {
		if (i == 32 || i == 64 || i == 96)
			std::cout << "     ";
		std::setw(3);
		std::cout << std_iarr_0_128[i] << " ";
		if (i == 31 || i == 63 || i == 95)
			std::cout << std::endl;
	}
	std::cout << "\n" << std::endl;
	std::cout << "size: " << std_iarr_0_128.size() << ", capacity: " << std_iarr_0_128.capacity() << std::endl;

	std::cout << "\n# Modifiers Test End#\n" << std::endl;
}

void push_back_test()
{
	std::vector<int> arr1(10);
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	arr1.push_back(4);
	arr1.push_back(5);


	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::cout << std::endl;

	ft::Vector<int> ft_arr1(10);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft_arr1.push_back(4);
	ft_arr1.push_back(5);


	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;
}

void insert_pos_val_test() {

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	arr1.insert(arr1.begin() + 5, 998);
	arr1.insert(arr1.begin(), 997);
	std::vector<int>::iterator res = arr1.insert(arr1.end(), 996);

	// for (size_t i = 0; i < arr1.size(); ++i) {
	//     std::cout << arr1[i] << " ";
	// }
	// std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::cout << "*(res = arr1.insert(arr1.end(), 996)) =  " << *res << std::endl;

	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft_arr1.insert(ft_arr1.begin() + 5, 998);
	ft_arr1.insert(ft_arr1.begin(), 997);
	ft::Vector<int>::iterator ft_res = ft_arr1.insert(ft_arr1.end(), 996);


	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	std::cout << "*(ft_res = ft_arr1.insert(ft_arr1.end(), 996)) =  " << *ft_res << std::endl;

	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void insert_pos_n_val_test() {

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	arr1.insert(arr1.begin() + 5, 5, 998);
	arr1.insert(arr1.begin(), 3, 997);
	arr1.insert(arr1.end(), 3, 996);

	// for (size_t i = 0; i < arr1.size(); ++i) {
	//     std::cout << arr1[i] << " ";
	// }
	// std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;


	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft_arr1.insert(ft_arr1.begin() + 5, 5, 998);
	ft_arr1.insert(ft_arr1.begin(), 3, 997);
	ft_arr1.insert(ft_arr1.end(), 3, 996);


	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;


	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void    insert_pos_iter_iter() {

	std::vector<int> src(30);
	for (size_t i = 0; i < src.size(); ++i) {
		src[i] = i + 990;
	}

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	arr1.insert(arr1.begin(), src.begin(), src.end());

	// for (size_t i = 0; i < arr1.size(); ++i) {
	//     std::cout << arr1[i] << " ";
	// }
	// std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;


	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft_arr1.insert(ft_arr1.begin(), src.begin(), src.end());


	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;


	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void    erase_iter_test() {

	std::vector<int> src(30);
	for (size_t i = 0; i < src.size(); ++i) {
		src[i] = i + 990;
	}

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::vector<int>::iterator res = arr1.erase(arr1.end() - 3);

	// for (size_t i = 0; i < arr1.size(); ++i) {
	//     std::cout << arr1[i] << " ";
	// }
	// std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::cout << "*(res = arr1.insert(arr1.end(), 996)) =  " << *res << std::endl;

	(void)(res);
	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft::Vector<int>::iterator ft_res = ft_arr1.erase(ft_arr1.end() - 3);

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	std::cout << "*(ft_res = ft_arr1.insert(ft_arr1.end(), 996)) =  " << *ft_res << std::endl;

	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void    erase_iter_iter_test() {

	std::vector<int> src(30);
	for (size_t i = 0; i < src.size(); ++i) {
		src[i] = i + 990;
	}

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::vector<int>::iterator res = arr1.erase(arr1.begin(), arr1.end() - 3);

	// for (size_t i = 0; i < arr1.size(); ++i) {
	//     std::cout << arr1[i] << " ";
	// }
	// std::cout << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::cout << "*(res = arr1.insert(arr1.end(), 996)) =  " << *res << std::endl;

	(void)(res);
	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft::Vector<int>::iterator ft_res = ft_arr1.erase(ft_arr1.begin(), ft_arr1.end() - 3);

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	std::cout << "*(ft_res = ft_arr1.insert(ft_arr1.end(), 996)) =  " << *ft_res << std::endl;

	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void    swap_test() {

	std::vector<int> src(30);
	for (size_t i = 0; i < src.size(); ++i) {
		src[i] = i + 990;
	}

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	arr1.swap(src);

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_src(30);
	for (size_t i = 0; i < ft_src.size(); ++i) {
		ft_src[i] = i + 990;
	}
	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i + 10;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	ft_arr1.swap(ft_src);

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	std::cout << "arr1.size() = " << ft_arr1.size()
		<< ", arr1.capacity() = " << ft_arr1.capacity() << std::endl;


	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void    clear_test() {

	std::cout << "\n STD_ARR\n" << std::endl;
	std::vector<int> arr1(10, 3);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;


	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;

	arr1.clear();
	arr1.push_back(1);

	std::cout << "arr1.size() = " << arr1.size()
		<< ", arr1.capacity() = " << arr1.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "\n FT_ARR\n" << std::endl;

	ft::Vector<int> ft_arr1(10, 3);
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		ft_arr1[i] = i;
	}
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "ft_arr1.size() = " << ft_arr1.size()
		<< ", ft_arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	ft_arr1.clear();
	ft_arr1.push_back(1);
	std::cout << "ft_arr1.size() = " << ft_arr1.size()
		<< ", ft_arr1.capacity() = " << ft_arr1.capacity() << std::endl;

	std::cout << "arr   : ";
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ft_arr: ";
	for (size_t i = 0; i < ft_arr1.size(); ++i) {
		std::cout << ft_arr1[i] << " ";
	}
	std::cout << std::endl;
}

void relational_operators_test() {

	ft::Vector<int> arr1(20, 3);
	ft::Vector<int> arr2(20, 3);
	ft::Vector<int> arr3(20, 1);

	std::cout << (arr1 == arr2) << " OK: 1" << std::endl;
	std::cout << (arr1 == arr3) << " OK: 0" << std::endl;
	std::cout << (arr1 != arr2) << " OK: 0" << std::endl;
	std::cout << (arr1 != arr3) << " OK: 1" << std::endl;

	std::cout << (arr3 < arr1)  << " OK: 1" << std::endl;

	std::cout << (arr1 < arr2)  << " OK: 0" << std::endl;
	std::cout << (arr1 <= arr2) << " OK: 1" << std::endl;

	std::cout << (arr3 > arr1)  << " OK: 0" << std::endl;
	std::cout << (arr1 > arr3)  << " OK: 1" << std::endl;

	std::cout << (arr1 >= arr2) << " OK: 1" << std::endl;
	std::cout << (arr1 >= arr3) << " OK: 1" << std::endl;
	std::cout << (arr3 >= arr1)  << " OK: 0" << std::endl;
}

void reverse_iterator_test() {

	ft::Vector<int> arr1(20);
	ft::Vector<int> arr2(1, 2);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i;
	}
	ft::Vector<int>::reverse_iterator       riter;
	ft::Vector<int>::const_reverse_iterator criter;

	for (riter = arr1.rbegin(); riter != arr1.rend(); ++riter) {
		std::cout << *riter << " ";
	}
	std::cout << std::endl;

	for (criter = arr1.rbegin(); criter != arr1.rend(); ++criter) {
		std::cout << *criter << " ";
	}
	std::cout << std::endl;

	for (riter = arr1.rend() - 1; riter != arr1.rbegin() - 1; --riter) {
		std::cout << *riter << " ";
	}
	std::cout << std::endl;


	std::cout << (arr1.rbegin() == arr1.rbegin()) << " OK: 1" << std::endl;
	std::cout << (arr1.rbegin() != arr1.rbegin()) << " OK: 0" << std::endl;
	std::cout << *(arr1.rbegin() + 5) << " OK: 14" << std::endl;
	*(arr1.rbegin() + 5) += 100;
	std::cout << *(arr1.rbegin() + 5) << " OK: 114" << std::endl;

	ft::Vector<ab> ab(2);

	ab[1].a = 'a';
	ab[1].b = 'b';

	std::cout << (ab.rbegin())->a << " OK: a" << std::endl;

	*(arr1.rbegin() + 5) -= 100;
	std::cout << *(arr1.rbegin() + 5) << " OK: 14" << std::endl;

	std::cout << (arr1.begin() > arr1.end()) << " OK: 0" << std::endl;
	std::cout << (arr1.begin() >= arr1.end()) << " OK: 0" << std::endl;
	std::cout << (arr1.begin() >= arr1.begin()) << " OK: 1" << std::endl;
	std::cout << (arr1.begin() < arr1.end()) << " OK: 1" << std::endl;
	std::cout << (arr1.begin() <= arr1.begin()) << " OK: 1" << std::endl;
	std::cout << (arr1.end() <= arr1.begin()) << " OK: 0" << std::endl;
	std::cout << (arr1.end() <= arr1.end()) << " OK: 1" << std::endl;

	std::cout << (arr1.rbegin()[5]) << " OK: 14" << std::endl;

	std::cout << *(5 + arr1.rbegin()) << " OK: 14" << std::endl;

	std::cout << (arr1.rend() - arr1.rbegin()) << " OK: 20" << std::endl;

}

int     main(void)
{
	constructors_iterator();
	const_iterator_test();
	capacity_test();
	element_access_test();
	modifier_test();
	push_back_test();
	insert_pos_val_test();
	insert_pos_iter_iter();
	erase_iter_test();
	erase_iter_iter_test();
	swap_test();
	clear_test();
	relational_operators_test();
	reverse_iterator_test();


    return (0);
}
