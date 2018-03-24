//
// Created by kamil on 21.03.18.
//

#ifndef HYBRIDSORT_QUICKSORT_H
#define HYBRIDSORT_QUICKSORT_H

#include <iostream>
#include "ISortable.h"
#include "IPreparable.h"

template <class T>
class Quicksort : public ISortable, public IPreparable {
public:
    Quicksort() : tab(nullptr) {}
    ~Quicksort() { delete tab; }

    // virtual methods
    void sort();
    void clear();
    void prepare(int) {}
    void prepare(int data[], int data_size);
    std::string name() { return "quicksort"; }

    // methods
    void quick(T data[], T first, T last);
    void quicksort(T data[], T size);
    void swap(T& v1, T& v2);
    void print() const { for(auto i=0; i<data_size; i++) { std::cout << tab[i] << " "; }}

private:
    T data_size;
    T *tab;
};

template <class T>
inline void Quicksort<T>::sort() {
    quicksort(tab, data_size);
}

template <class T>
inline void Quicksort<T>::clear() {
    delete tab;
    tab = nullptr;
    this->data_size = 0;
}

template <class T>
inline void Quicksort<T>::prepare(int data[], int data_size) {
    if (tab != nullptr) return;

    this->data_size = data_size;
    tab = new int[data_size];

    for (auto i=0; i<data_size; i++) {
        tab[i] = data[i];
    }
}

/*///////////////////////////
// IMPLEMENTACJA ALGORYTMU //
///////////////////////////*/

template<class T>
inline void Quicksort<T>::swap(T& v1, T& v2)
{
    T tmp = v2;
    v2 = v1;
    v1 = tmp;
}

template <class T>
inline void Quicksort<T>::quicksort(T data[], T size) {
    T i,max,min = 0;
    if(size<2)
        return;
    for(i=1, max = 0; i < size; i++){
        if(data[max] < data[i])
            max = i;
    }
    swap(data[size-1], data[max]);               // znajdujemy max i zamieniamy miejscem z ostatni element tablicy
    quick(data, min, size-2);                   // el ostatni nie bierze dalej udziału w sortowaniu
}


template <class T>
inline void Quicksort<T>::quick(T *data, T first, T last) {
    T left = first+1, right = last;
    swap(data[first], data[(first+last)/2]);
    T pivot = data[first];                     // el srodkowy

    while(left <= right){

        while(data[left] < pivot)               // przesuwa indeks-left na pozycje, ktorej wart. el > pivot
            left++;
        while(pivot < data[right])              // przesuwa indeks-right na pozycje, ktorej wart. el < pivot
            right--;
        if(left < right)
            swap(data[left++], data[right--]);   // zamiana znalezionych wyzej elementow, inkrementacja left i dekrementacja right
        else left++;
    }

    swap(data[right], data[first]);              // zamiana pivotu z najmniejszym el w tablicy

    if(first < right-1)                         // podzial na 2 podtablice, wartosci mniejsze od pivotu i wieksze od pivotu
        quick(data, first, right-1);          // sortowanie lewej podtablicy gdy jest wiecej niz 1 el

    if(right+1 < last)
        quick(data, right+1, last);           // sortowanie prawej podtablicy,gdy jest wiecej niz 1 el
}



#endif //HYBRIDSORT_QUICKSORT_H
