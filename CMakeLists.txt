cmake_minimum_required(VERSION 3.17)
project(containers_cpp)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

include_directories(ft_list)

add_executable(containers_cpp

        # ------------- Stack ------------ #
        ft_stack/ft_stack.hpp
        ft_stack/ft_stack_test.cpp
#        ft_stack/std_stack_test.cpp
        )

        # ------- Vector, Multiset ------- #
#        ft_vector/ft_vector.hpp
#        ft_vector/ft_vector_random_access_iterator.hpp
#        utils.hpp
#        ft_multiset/ft_multiset.hpp
#        ft_multiset/ft_multiset_test.cpp
#        ft_multiset/ft_multiset_bidir_iterator.hpp)

        # ------- Vector, Multiset, Map -- #
#        utils.hpp
#        ft_vector/ft_vector.hpp
#        ft_vector/ft_vector_random_access_iterator.hpp
#        ft_multiset/ft_multiset.hpp
#        ft_multiset/ft_multiset_bidir_iterator.hpp
#        ft_map/ft_map.hpp
#        ft_map/ft_map_test.cpp
#        ft_map/std_map_test.cpp
#        ft_map/ft_map_bidir_iterator.hpp)

        # ------------ List -------------- #
#        ft_list/std_list_test.cpp
#        ft_list/ft_list_bidirectional_iterator.hpp
#        ft_list/ft_list.hpp
#        ft_list/ft_list_test.cpp
#        ft_list/test.hpp)

        # ----------- Vector ------------- #
#        ft_vector/ft_vector.hpp
#        ft_vector/ft_random_access_iterator.hpp
#        ft_vector/ft_reverse_iterator.hpp
#        ft_vector/ft_vector_test.cpp)
