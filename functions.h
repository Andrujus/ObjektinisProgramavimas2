#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "student.h"
#include "include/vector.hpp"
#include <string>

double Vidurkis(const Vector<int>& pazymiai);
double apskaiciuotiMediana(Vector<int> pazymiai);
void gen_name(std::string& vardas, std::string& pavarde);
void Duom(Vector<Student>& studentai, int& ch1);
void Rez(Vector<Student>& studentai, int& ch1);

#endif