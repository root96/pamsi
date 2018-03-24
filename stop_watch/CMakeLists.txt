cmake_minimum_required(VERSION 3.9)
project(stop_watch)

set(CMAKE_CXX_STANDARD 17)

add_executable(stop_watch main.cpp IPreparable.h IRunnable.h Stub.h importedClasses/HeapSort.h HybridSort.h IStrategy.h)