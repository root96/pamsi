#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <memory>
#include "importedClasses/MergeSort.h"
#include "importedClasses/QuickSort.h"
#include "importedClasses/HeapSort.h"

using namespace std;


using dtype = long long int;
const int index = 7;
double time_from_measure[index];
int counter;


int measureTime(IRunnable<dtype> *prog)
{
    clock_t start_s, stop_s;
    double average_time, sum = 0, time[5];

    for (int i=0; i<5; i++) {
        start_s = clock();
        prog->run();
        stop_s = clock();

        time[i] =  (stop_s - start_s) / static_cast<double>(CLOCKS_PER_SEC);
        sum += time[i];
        average_time = sum/5;
    }

    cout << "averange time: "<< average_time << endl;
    time_from_measure[counter] = average_time;
    counter++;
}


int main() {

    auto program = make_unique<HeapSort<dtype>>();
    dtype sizes[] = {pow(10,1), pow(10,2), pow(10,3), pow(10,4), pow(10,5),
                             pow(10,6), pow(10,7), pow(10,8)};


    counter = 0;


    for (int i = 0; i<index; i++) {
        cout << "Size = " << sizes[i] << endl;
        program->prepare(sizes[i]);
        program->normal_case();
        //program->print();
        measureTime(program.get());
        //program->print();
        cout << endl;
    }


    ofstream myFile;
    myFile.open("data_from_" + program->getName() + "_worst.csv");
    for (int i=0; i<index; i++) {
        myFile << sizes[i] << "," << time_from_measure[i] << "\n";
    }
    myFile.close();

    return 0;
}