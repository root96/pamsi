//
// Created by pati on 13.03.18.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H
template<class T>
inline void swap(T& v1, T& v2)
{
    T tmp = v2;
    v2 = v1;
    v1 = tmp;
}

template<class T>
void quicksort(T data[], int first, int last){
    int left = first+1, right = last;
    swap(data[first],data[(first+last)/2]);
    T pivot = data[first];                     // el srodkowy

    while(left <= right){

        while(data[left] < pivot)               // przesuwa indeks-left na pozycje, ktorej wart. el > pivot
            left++;
        while(pivot < data[right])              // przesuwa indeks-right na pozycje, ktorej wart. el < pivot
            right--;
        if(left < right)
            swap(data[left++],data[right--]);   // zamiana znalezionych wyzej elementow, inkrementacja left i dekrementacja right
        else left++;
    }

    swap(data[right],data[first]);              // zamiana pivotu z najmniejszym el w tablicy

    if(first < right-1)                         // podzial na 2 podtablice, wartosci mniejsze od pivotu i wieksze od pivotu
        quicksort(data,first,right-1);          // sortowanie lewej podtablicy gdy jest wiecej niz 1 el

    if(right+1 < last)
        quicksort(data,right+1,last);           // sortowanie prawej podtablicy,gdy jest wiecej niz 1 el
}


template<class T>
void quicksort(T data[], int size){
    int i,max;
    if(size<2)
        return;
    for(i=1, max = 0; i < size; i++){
        if(data[max] < data[i])
            max = i;
    }
    swap(data[size-1],data[max]);               // znajdujemy max i zamieniamy miejscem z ostatni element tablicy
    quicksort(data,0,size-2);                   // el ostatni nie bierze dalej udziału w sortowaniu
}
#endif //ALGORITHMS_QUICKSORT_H
