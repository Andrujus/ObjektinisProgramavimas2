#ifndef FUNC_MASYVAS_H
#define FUNC_MASYVAS_H

#include <random>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string vardas;
    std::string pavarde;
    int* namuDarbai;
    int nd_kiek;
    int egz;
};

double Vidurkis(int* pazymiai);
double apskaiciuotiMediana(int* pazymiai);
void Duom(Student& studentas);
void Rez(const Student& studentas);

#endif