cmake_minimum_required(VERSION 3.24)
project(List)

set(CMAKE_CXX_STANDARD 17)

add_executable(List src/main.cpp src/Collections/Array/Array.cpp src/Collections/Array/Array.h src/Collections/BinaryHeap/BinaryHeap.cpp src/Collections/BinaryHeap/BinaryHeap.h src/Collections/DoubleList/DoubleList.cpp src/Collections/DoubleList/DoubleList.h src/Collections/AbstractCollection.h src/Collections/RedBlackTree/Node.h src/Collections/RedBlackTree/Color.h src/Collections/DoubleList/Node/DoubleListNode.cpp src/Collections/DoubleList/Node/DoubleListNode.h src/TimeTester/TimeTesterppp.h src/FileReader/FileReader.h src/TimeTester/TimeTester.h src/TimeTester/RandomGenerator.h src/TimeTester/Timer.h src/FileWriter/FileWriter.h src/TimeTester/TimeTester.cpp)
