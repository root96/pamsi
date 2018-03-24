//
// Created by pati on 13.03.18.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include "../IPreparable.h"
#include "../IRunnable.h"

template <class T>
class QuickSort : public IPreparable<T>, public IRunnable<T> {
public:
    QuickSort() {}
    ~QuickSort() { delete[] tab; std::cout << "destructor called"; }

    void prepare(const T&);
    void run();
    void quick(T[], T, T);
    void quicksort(T[], T);
    void swap(T&, T&);
    void optimal_case();
    void normal_case();
    void pesimist_case();
    void print() const;
    const std::string getName() const { return "quicksort"; }

private:
    T data_size;
    T* tab;
};

template <class T>
inline void QuickSort<T>::pesimist_case() {
    for (auto i = 0; i<data_size; i++) {
        tab[i] = data_size - i ;
    }
}

template <class T>
inline void QuickSort<T>::normal_case() {
    for (auto i = 0; i<data_size; i++) {
        tab[i] = rand() % data_size*25;
    }
}

template <class T>
inline void QuickSort<T>::optimal_case() {
    for (auto i = 0; i<data_size; i++) {
        tab[i] = i ;
    }
}

template <class T>
inline void QuickSort<T>::prepare(const T& value) {
    this->data_size = value;
    tab = new T[data_size];
}

template <class T>
inline void QuickSort<T>::run() {
    quicksort(tab, data_size);
}

template<typename T>
inline void QuickSort<T>::swap(T& v1, T& v2)
{
    T tmp = v2;
    v2 = v1;
    v1 = tmp;
}

template<typename T>
inline void QuickSort<T>::quick(T data[], T first, T last) {
    T left = first+1, right = last;
    //swap(data[first], data[(first+last)/2]);
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


template<class T>
inline void QuickSort<T>::quicksort(T data[], T size){
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
void QuickSort<T>::print() const {
    for (auto iter = 0; iter<data_size; iter++) {
        std::cout << tab[iter] << " ";
    }
}
#endif //ALGORITHMS_QUICKSORT_H
