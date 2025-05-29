#include "include/Vector.hpp"
#include <iostream>

int main() {
    Vector<int> v;
    for (int i = 0; i <= 5; ++i) {
        v.push_back(i * 10);
    }
    v.pop_back();
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "Talpa: " << v.capacity() << ", Dydis: " << v.size() << std::endl;
    std::cout << "Pirmas elementas: " << v.front() << std::endl;
    std::cout << "Paskutinis elementas: " << v.back() << std::endl;
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);

    Vector<int> b = a;
    std::cout << a[0] << " " << b[0] << std::endl;
    Vector<int> c;
    c = a;
    Vector<int> d = std::move(a);
    Vector<int> e;
    e = std::move(b);

}