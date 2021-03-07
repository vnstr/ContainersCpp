#include <iostream>

#include "ft_vector.hpp"

int     main(void)
{
	ft::Vector<int>  int_arr(10);

	std::cout << "Test copy-constructor: " << std::endl;
	ft::Vector<int>  int_arr2(int_arr);
	std::cout << "DONE" << std::endl;

	// for (int i = 0; i < int_arr.size_; ++i) {
	//     std::cout << int_arr.arr_[i] << " ";
	// }
	// std::cout << std::endl;

	ft::Vector<int>  int_arr3(30);

	std::cout << "Test operator =: " << std::endl;
	int_arr = int_arr3;
	std::cout << "DONE" << std::endl;

	ft::Vector<int>::iterator iter;
	(void)(iter);

    return (0);
}
