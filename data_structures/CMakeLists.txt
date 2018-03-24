cmake_minimum_required(VERSION 3.9)
project(data_structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_structures main.cpp Queue.h Node.h IContainer.h Stack.h List.h DoublyLinkedList.h)