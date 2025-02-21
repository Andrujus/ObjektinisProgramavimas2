#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <random>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egz;
};

double Vidurkis(const std::vector<int>& pazymiai);
double apskaiciuotiMediana(std::vector<int> pazymiai);
void Duom(Student& studentas);
void Rez(const Student& studentas);
void gen_name(std::string& vardas, std::string& pavarde);

#endif