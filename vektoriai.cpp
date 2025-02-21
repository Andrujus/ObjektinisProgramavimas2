#include "functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>



double Vidurkis(const std::vector<int>& pazymiai) {
    double suma = 0.0;
    for (int pazymys : pazymiai) suma += pazymys;
    return suma / pazymiai.size();
}

double apskaiciuotiMediana(std::vector<int> pazymiai) {
    std::sort(pazymiai.begin(), pazymiai.end());
    size_t dydis = pazymiai.size();
    if (dydis % 2 == 0) {
        return (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
    } else {
        return pazymiai[dydis / 2];
    }
}


void Duom(Student& studentas, std::vector<Student>& studentai) {
    std::string kitas_stud = "T";
    while(kitas_stud == "T" || kitas_stud == "t")
    {
    std::cout << "Įveskite studento vardą: ";
    std::cin >> studentas.vardas;
    std::cout << "Įveskite studento pavardę: ";
    std::cin >> studentas.pavarde;

    std::cout << "Įveskite namų darbų pažymius (įveskite -1, kad baigtumėte): ";
    
    studentas.namuDarbai.clear();

    int pazymys;

    while (true) {
        std::cin >> pazymys;
        if (pazymys == -1) break;
        studentas.namuDarbai.push_back(pazymys);
    }

    std::cout << "Įveskite egzamino rezultatą: ";
    std::cin >> studentas.egz;
    studentai.push_back(studentas);
    std::string kitas;
    std::cout<<"Ar norite testi? (T - taip, N - ne): ";
    std::cin>>kitas;
    if(kitas == "T" || kitas == "t")
        kitas_stud = "T";
    else{
        kitas_stud = "N";
    }
    }
}

void Rez(const std::vector<Student>& studentai, bool n_vid) {
    std::cout << std::fixed << std::setprecision(2);
    if(n_vid)
    {
        std::cout << "-----------------------------------------------------------"<<std::endl;
        std::cout << "Vardas     Pavarde       Galutunis (vid.)"<<std::endl;
        std::cout << "-----------------------------------------------------------"<<std::endl;
    }
    else
    {
        std::cout << "-----------------------------------------------------------"<<std::endl;
        std::cout << "Vardas    Pavarde      Galutunis (med.)"<<std::endl;
        std::cout << "-----------------------------------------------------------"<<std::endl;
    
    }
    for (const auto& studentas : studentai) {
        double galutinis;
        if (n_vid) {
            
            galutinis = Vidurkis(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
        } else {
            
            double mediana = apskaiciuotiMediana(studentas.namuDarbai);
        }
        
        std::cout << studentas.vardas << "     " << studentas.pavarde << "       " << galutinis << std::endl;
    }
}

int main() {
    Student studentas;
    std::vector<Student> studentai;
    Duom(studentas, studentai);
    std::string vid;
    std::cout<<"V - vidurkis, M - mediana"<<std::endl;
    std::cin>>vid;
    if (vid == "V" || vid == "v") {
        Rez(studentai, true);
    } else {
        Rez(studentai, false);
    }
    return 0;
}