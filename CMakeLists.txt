cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_CXX_FLAGS "-fexceptions -Wall -Wextra -Wno-long-long -Wno-variadic-macros -std=c++14")
set(name whats_wrong_with_this_code)
set(cmake_export_compile_commands 1)
add_executable(whats_wrong_with_this_code
               whats_wrong_with_this_code.cpp
               example1.cpp
               example2.cpp
               example3.cpp
               example4.cpp
               example5.cpp
               example6.cpp
               example7.cpp)
