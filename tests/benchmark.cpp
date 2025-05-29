#include "../include/vector.hpp"
#include <vector>
#include <iostream>
#include <chrono>

int main() {
    std::size_t sz = 10000000;

    auto start1 = std::chrono::high_resolution_clock::now();

    std::vector<int> v1;
    for (int i = 1; i <= static_cast<int>(sz); ++i) {
        v1.push_back(i);
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

    std::cout << "std::vector užpildyta per: " << duration1 << " ms\n";

    auto start2 = std::chrono::high_resolution_clock::now();

    Vector<int> v2;
    for (int i = 1; i <= static_cast<int>(sz); ++i) {
        v2.push_back(i);
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

    std::cout << "mano Vector užpildyta per: " << duration2 << " ms\n";

    return 0;
}
