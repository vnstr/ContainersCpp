cmake_minimum_required(VERSION 3.17)
project(containers_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(ft_list)

add_executable(containers_cpp
        ft_list/ft_bidirectional_iterator.hpp
        ft_list/ft_list.hpp
        ft_list/ft_list_test.cpp
        ft_list/std_list_test.cpp
        ft_list/test.hpp)
