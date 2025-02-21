#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string vardas;
    std::string pavarde;
    int* namuDarbai;
    int egz;
};

double Vidurkis(const std::vector<int>& pazymiai);
double apskaiciuotiMediana(std::vector<int> pazymiai);
void Duom(Student& studentas);
void Rez(const Student& studentas);

#endif