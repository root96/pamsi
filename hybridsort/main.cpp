#include <iostream>
#include <memory>
#include <cmath>
#include "Quicksort.h"
#include "Hybridsort.h"
using namespace std;

int main() {

    auto hybrid = make_unique<Hybridsort<int>>();
    hybrid->prepare(pow(10,8));
    hybrid->strategy();
    hybrid->run();

    return 0;
}