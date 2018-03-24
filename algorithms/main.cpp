#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;

int main() {

    const long int value = 10;
    int tab[value];

    for (int i=0; i<value; i++) {
        tab[i] = rand() % 100;
        cout << tab[i] << " ";
    }

    mergesort<int>(tab, 0, value-1);
    cout << endl << endl;

    for (int i=0; i<value; i++) {
        cout << tab[i] << " ";
    }

    cout << endl << endl << endl;

    vector<int> vec;

    for (int i=0; i<10; i++) {
        vec.push_back(rand() % 100);
        cout << vec.at(i) << " ";
    }

    mergesort(vec);
    cout << endl << endl;

    for (int i=0; i<10; i++) {
        cout << vec.at(i) << " ";
    }

    cout << endl << endl << "Quicksort" << endl << endl;

    for (int i=0; i<value; i++) {
        tab[i] = rand() % 100;
        cout << tab[i] << " ";
    }

    cout << endl << endl ;
    quicksort<int>(tab,value);
    for (int i=0; i<value; i++) {
        cout << tab[i] << " ";
    }
    cout << endl << endl ;


    return 0;
}