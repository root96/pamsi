//
// Created by kamil on 21.03.18.
//

#ifndef HYBRIDSORT_HYBRIDSORT_H
#define HYBRIDSORT_HYBRIDSORT_H

#include "IRunnable.h"
#include "IPreparable.h"
#include "IStrategy.h"
#include "ISortable.h"
#include "Quicksort.h"
#include "Mergesort.h"
#include "Heapsort.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>


template <class T>
class Hybridsort : public IRunnable, public IStrategy, public IPreparable {
public:
    explicit Hybridsort();
    ~Hybridsort();

    // virtual methods
    void run();
    void clear() {}
    void strategy();
    void prepare(int data_size);
    void prepare(int data[], int data_size) {}

    // methods
    std::list<ISortable*>& getSortableList() { return list_sortable; }
    std::list<IPreparable*>& getPreparableList() { return list_preparable; }
    void print() const;

private:
    std::list<ISortable*> list_sortable;
    std::list<IPreparable*> list_preparable;
    Quicksort<T> *q;
    Mergesort<T> *m;
    Heapsort<T>  *h;

    T data_size;
    T *tab;

    T test_data_size;
    T *test_tab;

    std::vector<double> vec_time;
    std::vector<std::string> vec_string;
    std::string the_fastest;
};

template <class T>
Hybridsort<T>::Hybridsort() {
    q = new Quicksort<T>();
    m = new Mergesort<T>();
    h = new Heapsort<T>();

    list_sortable.push_back(q);
    list_sortable.push_back(m);
    list_sortable.push_back(h);

    list_preparable.push_back(q);
    list_preparable.push_back(m);
    list_preparable.push_back(h);

    vec_time.reserve(list_sortable.size());
    vec_string.reserve(list_sortable.size());
}

template <class T>
Hybridsort<T>::~Hybridsort() {
    delete q,m,h;
    list_sortable.clear();
    list_preparable.clear();
}

template <class T>
inline void Hybridsort<T>::prepare(int value) {
    // initializacja pol wewnatrz klasy
    this->data_size = value;
    tab = new T[data_size];

    // przypadek wybrany
    for (auto i=0; i<data_size; i++) {
        tab[i] = rand() %  2147483647;
    }

    // dane przeslane do testu
    int divide = 100;
    T tmp = data_size;
    this->test_data_size = tmp / divide;
    test_tab = new T[test_data_size];

    for (int i=0; i<test_data_size; i++) {
        test_tab[i] = tab[i];
    }

    for (auto& ref : list_preparable) {
        ref->prepare(test_tab, test_data_size);
    }
}

template <class T>
inline void Hybridsort<T>::strategy() {
    clock_t start, stop;
    double counted_time;

    for (auto& ref : list_sortable) {
        start = clock();
        ref->sort();
        stop = clock();

        counted_time = (stop-start)/static_cast<double>(CLOCKS_PER_SEC);
        vec_time.push_back(counted_time);
        vec_string.push_back(ref->name());

        std::cout << ref->name() << " : " << counted_time << std::endl;
    }

    double min = vec_time[0];
    the_fastest = vec_string[0];
    for (int i=1, n=vec_time.size(); i<n; i++) {
        if (min > vec_time[i]) {
            min = vec_time[i];
            the_fastest = vec_string[i];
        }
    }
}

template <class T>
inline void Hybridsort<T>::run() {
    if (the_fastest == "quicksort") {
        clock_t start, stop;
        q->clear();
        q->prepare(tab, data_size);
        start = clock();
        q->sort();
        stop = clock();
        std::cout << q->name() << " : " << (stop-start)/static_cast<double>(CLOCKS_PER_SEC);
        return;
    } else if (the_fastest == "heapsort") {
        clock_t start, stop;
        h->clear();
        h->prepare(tab, data_size);
        start = clock();
        h->sort();
        stop = clock();
        std::cout << h->name() << " : " << (stop - start) / static_cast<double>(CLOCKS_PER_SEC);
        return;
    } else if (the_fastest == "mergesort") {
        clock_t start, stop;
        m->clear();
        m->prepare(tab, data_size);
        start = clock();
        m->sort();
        stop = clock();
        std::cout << m->name() << " : " << (stop - start) / static_cast<double>(CLOCKS_PER_SEC);
        return;
    } else {
        std::cerr << "error";
        return;
    }
}

template <class T>
inline void Hybridsort<T>::print() const {
    if (tab == nullptr) return;

    for (auto i=0; i<data_size; i++) {
        std::cout << tab[i] << " ";
    }
}

#endif //HYBRIDSORT_HYBRIDSORT_H
