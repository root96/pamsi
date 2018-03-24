//
// Created by kamil on 21.03.18.
//

#ifndef STOP_WATCH_HYBRIDSORT_H
#define STOP_WATCH_HYBRIDSORT_H

#include "IRunnable.h"
#include "IPreparable.h"
#include "IStrategy.h"
#include "importedClasses/MergeSort.h"
#include "importedClasses/QuickSort.h"
#include "importedClasses/HeapSort.h"
#include <cstdlib>
#include <ctime>

template <class T>
class HybridSort : public IRunnable<T>, public IPreparable<T>, public IStrategy<T> {
public:
    HybridSort() { merge = quick = heap = nullptr; TAB_SIZE = 100;}
    ~HybridSort() { delete[] tab; delete merge, quick, heap;}

    void run();
    void prepare(const T&);
    void choose_strategy(IRunnable*);

private:
    T data_size;
    T *tab;

    int TAB_SIZE;
    T tab_quick[];
    T tab_merge[];
    T tab_heap[];

    MergeSort<T> *merge;
    QuickSort<T> *quick;
    HeapSort<T>  *heap;
};

template <class T>
inline void HybridSort<T>::choose_strategy(IRunnable<T> *prog) {
    
}

template <class T>
inline void HybridSort<T>::prepare(const T& value) {
    this->data_size = value;
    tab = new T[data_size];

    for(auto i=0; i<data_size; i++) {
        tab[i] = rand() * data_size;
    }

    merge = new MergeSort<T>();
    quick = new QuickSort<T>();
    heap = new HeapSort<T>();

    for (auto i=0; i<TAB_SIZE; i++) {
        tab_quick[i] = tab[i];
        tab_merge[i] = tab[i];
        tab_heap[i] = tab[i];
    }
}

#endif //STOP_WATCH_HYBRIDSORT_H
