#include "functions.h"
#include "student.h"
#include <chrono>
#include <iostream>
#include "include/vector.hpp"

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> diff;
    int ch1;
    Vector<Student> studentai;
    Vector<int> skaicius = {1000, 10000, 100000};

    start = std::chrono::system_clock::now();
    Duom(studentai, ch1);
    Rez(studentai, ch1);
    end = std::chrono::system_clock::now();  
    
    diff = end - start;
    std::cout << "Programos veikimo laikas: " << diff.count() << " s\n";
    return 0;
}
