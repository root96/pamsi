//
// Created by kamil on 12.03.18.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H
#include <vector>

// IMPLEMENTATION USING ARRAY FROM ANSI C

template <typename T>
void merge(T array[], int first, int last) {
    int mid = (first+last)/2;
    int i1 = 0, i2 = first, i3 = mid+1;

    T temp[last-first];
    while (i2 <= mid && i3 <= last) { // dopóki prawa i lewa podtablica zawieraja elementy
        if (array[i2] < array[i3]) {
            temp[i1++] = array[i2++];
        } else {
            temp[i1++] = array[i3++];
        }
    }

    while (i2 <= mid) {
        temp[i1++] = array[i2++];
    }

    while (i3 <= last) {
        temp[i1++] = array[i3++];
    }

    for (i1 = 0, i2 = first; i2 <= last; array[i2++] = temp[i1++]);
}

template <typename T>
void mergesort(T data[], int first, int last) {
    if (first < last) {
        int mid = (first+last)/2;
        mergesort(data, first, mid);
        mergesort(data, mid+1, last);
        merge(data, first, last);
    }
}

// IMPLEMENTATION USING VECTOR FROM STL

template <typename T>
void merge(std::vector<T>& array, std::vector<T>& array1, std::vector<T>& array2) {
    array.clear();
    int i,j;

    for (i = j = 0; i < array1.size() && j < array2.size(); ) {
        if (array1.at(i) < array2.at(j)) {
            array.push_back(array1.at(i));
            i++;
        } else {
            array.push_back(array2.at(j));
            j++;
        }
    }

    while (i < array1.size()) {
        array.push_back(array1.at(i));
        i++;
    }

    while (j < array2.size()) {
        array.push_back(array2.at(j));
        j++;
    }
}

template <typename T>
void mergesort(std::vector<T>& array) {
    if (1 < array.size()) {
        std::vector<T> array1(array.begin(), array.begin() + array.size() / 2); // left-hand vector
        mergesort(array1);
        std::vector<T> array2(array.begin() + array.size() / 2, array.end()); // right-head vector
        mergesort(array2);
        merge(array, array1, array2);
    }
}

#endif //ALGORITHMS_MERGESORT_H
