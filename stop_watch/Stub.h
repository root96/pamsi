#ifndef STOP_WATCH_STUB_H
#define STOP_WATCH_STUB_H

//#include "IRunnable.h"
//#include "IPreparable.h"
//#include <iostream>
//#include <unistd.h>
//#include "importedClasses/MergeSort.h"
//#include "importedClasses/QuickSort.h"
//#include "importedClasses/HeapSort.h"
//#include <memory>
//
///*
// * na przyszle zajecia konczymy algorytmy sortowania
// * nasze zadanie : poczytanie o grafach, co to jest, jak to sie je
// *
// */
//
//template <typename T>
//class Stub : public IRunnable<T>, public IPreparable<T> {
//    T data_size;
//    T *array;
//    T *temp;
////    std::unique_ptr<T[]> array;
////    std::unique_ptr<T[]> temp;
//
//public:
//    Stub() {}
//    ~Stub() { delete[] array; delete[] temp; }
//
//    void run();
//    void prepare(const T&);
//    void print() const;
//};
//
//
//template <typename T>
//void Stub<T>::run() {
// //   quicksort<T>(array, data_size);
////    mergesort<T>(array, temp, 0, data_size);
////    heapsort<T>(array, data_size);
//}
//
//
//template <typename T>
//void Stub<T>::prepare(const T& size) {
//    this->data_size = size;
//    array = new T[data_size];
//    temp = new T[data_size];
//
////    auto array = std::make_unique<T[]>(data_size);
////    auto temp  = std::make_unique<T[]>(data_size);
//
//    // przypadek optymalny
////    for (int i=0; i<data_size; i++) {
////        if (i == 0) {
////            array[i] = rand() % data_size;
////        } else {
////            array[i] = rand() % data_size + array[i-1];
////        }
////    }
//
//    // przypadek sredni
//    for (int i=0; i<data_size; i++) {
//        array[i] = rand() % (data_size*3);
//    }
//
//    // przypadek negatywny
////    for (int i=0; i<data_size; i++) {
////        if (i == 0) {
////            array[i] = rand() % data_size;
////        } else {
////            array[i] = rand() % data_size + array[i-1];
////        }
////    }
////    for (int i=0; i<(data_size/2); i++) {
////        swap(array[i], array[(data_size-1)-i]);
////    }
//}
//
//template <typename T>
//void Stub<T>::print() const {
//    for (int i=0; i<data_size; i++) {
//        std::cout << array[i] << " ";
//    }
//}

#endif //STOP_WATCH_STUB_H
