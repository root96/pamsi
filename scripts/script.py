#!/bin/usr/env python
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import os
from pathlib import Path

def read_data_from_csv(name):
    ''' funckja ta otwiera plik csv i wpisuje do tablic odpowiednie wartosc '''
    data = np.genfromtxt(name + '.csv', delimiter=",")
    array1 = np.array(data[:,0])
    array2 = np.array(data[:,1])
    return array1, array2

def plotting_data_from_two_vectors(time, value, name):
    ''' funkcja ta tworzy wykres na podstawie dwoch tablic
    i przypisuje mu odpowiednio nazwe '''
    plt.figure(1)
    plt.title(name + ' (log x/y scale)')
    plt.ylabel('time of sorting')
    plt.xlabel('sorted elements')
    plt.xscale('log')
    plt.yscale('log')
    plt.plot(time, value, color="purple", lw=1, ls='-',
             marker='s' ,markersize=8, markerfacecolor='yellow',
             markeredgewidth=2, markeredgecolor='blue')
    plt.savefig(name + '.png')
    plt.show()

def plotting_data_from_six_vectors(x1, y1, x2, y2, x3, y3, name):
    ''' funkcja ta tworzy wykres na podstawie 6 tablic i nazwy '''
    fig, ax = plt.subplots()
    ax.plot(x1, y1, color="blue", lw=1, ls='-', marker='s', markersize=8,
            markerfacecolor='blue', markeredgewidth=2, markeredgecolor='blue')
    ax.plot(x2, y2, color="red", lw=1, ls='-', marker='s', markersize=8,
            markerfacecolor='red', markeredgewidth=2, markeredgecolor='red',)
    ax.plot(x3, y3, color="green", lw=1, ls='-', marker='s', markersize=8,
            markerfacecolor='green', markeredgewidth=2, markeredgecolor='green')
    ax.set_title('algorithms of ' + name + ' case')
    ax.set_title(name)
    ax.set_ylabel('time of sorting')
    ax.set_xlabel('sorted elements')
    ax.set_xscale('log')
    ax.set_yscale('log')
    # ax.legend(['quicksort', 'heapsort', 'mergesort'], loc=2)
    ax.legend(['worst', 'middle', 'better'], loc=2)
    # plt.savefig('plot_' + name + '.png')
    plt.savefig(name + '_every_case.png')
    plt.show()

def function_for_one_case(type_of_case):
    quicksort_file = 'data_from_quicksort_' + type_of_case
    heapsort_file = 'data_from_heapsort_' + type_of_case
    mergesort_file = 'data_from_mergesort_' + type_of_case
    x1, y1 = read_data_from_csv(quicksort_file)
    x2, y2 = read_data_from_csv(heapsort_file)
    x3, y3 = read_data_from_csv(mergesort_file)
    plotting_data_from_six_vectors(x1, y1, x2, y2, x3, y3, type_of_case)

def function_for_one_algorithm(type_of_algorithm):
    algorithm_worst = 'data_from_' + type_of_algorithm + '_worst'
    algorithm_middle = 'data_from_' + type_of_algorithm + '_middle'
    algorithm_better = 'data_from_' + type_of_algorithm + '_better'
    x1, y1 = read_data_from_csv(algorithm_worst)
    x2, y2 = read_data_from_csv(algorithm_middle)
    x3, y3 = read_data_from_csv(algorithm_better)
    plotting_data_from_six_vectors(x1, y1, x2, y2, x3, y3, type_of_algorithm)

if __name__ == '__main__':
    function_for_one_algorithm('heapsort')
