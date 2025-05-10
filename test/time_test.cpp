#include <iostream>
#include <chrono>
#include <vector>
#include "../vector/Vector.hpp"
#include <iomanip>

using namespace std::chrono;
using namespace std;

int main() {

    auto start = high_resolution_clock::now();

    unsigned int sz = 10000000;
    std::vector <int> v1;

    for (int i = 0; i < sz; i++) {
        v1.push_back(i);
    }

    auto end = high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(2) << duration.count() << "s" << endl;


    start = high_resolution_clock::now();
    Vector<int> v2;

    for (int i = 0; i < sz; i++) {
        v2.push_back(i);
    }

    end = high_resolution_clock::now();

    duration = end - start;

    cout << fixed << setprecision(2) << duration.count() << "s" << endl;
}