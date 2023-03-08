cmake_minimum_required(VERSION 3.24)
project(List)

set(CMAKE_CXX_STANDARD 17)

add_executable(List main.cpp LinkedList/Node/Node.cpp LinkedList/Node/Node.h LinkedList/LinkedList.cpp LinkedList/LinkedList.h Array/Array.cpp Array/Array.h BinaryHeap/BinaryHeap.cpp BinaryHeap/BinaryHeap.h)
