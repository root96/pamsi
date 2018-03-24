cmake_minimum_required(VERSION 3.9)
project(HybridSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(HybridSort main.cpp ISortable.h Quicksort.h Mergesort.h Heapsort.h IPreparable.h IRunnable.h Hybridsort.h IStrategy.h)