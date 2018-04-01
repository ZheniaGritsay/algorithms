cmake_minimum_required(VERSION 3.9)
project(c__)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(c__ main.cpp binary-tree/traversal/tree_traversal.cpp binary-tree/construct/tree_construct.cpp
        binary-tree/recursion/tree_recursion.cpp binary-tree/other/other.cpp)