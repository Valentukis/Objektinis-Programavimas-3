#include <iostream>
#include <chrono>
#include <vector>
#include "../vector/Vector.hpp"
#include <iomanip>

using namespace std::chrono;
using namespace std;

int main() {
    unsigned int sz = 1000000000;
    size_t reallocs_std = 0;
    size_t reallocs_custom = 0;

    // std::vector timing + reallocation tracking
    auto start = high_resolution_clock::now();
    std::vector<int> v1;
    for (unsigned int i = 0; i < sz; ++i) {
        if (v1.size() == v1.capacity()) ++reallocs_std;
        v1.push_back(i);
    }
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    cout << "std::vector: " << fixed << setprecision(2) << duration.count() << "s\n";
    cout << "std::vector reallocations: " << reallocs_std << "\n\n";

    // Custom Vector timing + reallocation tracking
    start = high_resolution_clock::now();
    Vector<int> v2;
    for (unsigned int i = 0; i < sz; ++i) {
        if (v2.size() == v2.capacity()) ++reallocs_custom;
        v2.push_back(i);
    }
    end = high_resolution_clock::now();
    duration = end - start;
    cout << "Vector:      " << fixed << setprecision(2) << duration.count() << "s\n";
    cout << "Vector reallocations:      " << reallocs_custom << "\n";

    return 0;
}
