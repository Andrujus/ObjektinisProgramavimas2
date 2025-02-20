#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Student {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egz;
};

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


void Duom(Student& studentas) {
    std::cout << "Įveskite studento vardą: ";
    std::cin >> studentas.vardas;
    std::cout << "Įveskite studento pavardę: ";
    std::cin >> studentas.pavarde;

    std::cout << "Įveskite namų darbų pažymius (įveskite -1, kad baigtumėte): ";
    int pazymys;
    while (true) {
        std::cin >> pazymys;
        if (pazymys == -1) break;
        studentas.namuDarbai.push_back(pazymys);
    }

    std::cout << "Įveskite egzamino rezultatą: ";
    std::cin >> studentas.egz;
    
}

void Rez(const Student& studentas) {
    double Galutinis = Vidurkis(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Studentas: " << studentas.vardas << " " << studentas.pavarde << std::endl;
    std::cout << "Galutinis: " << Galutinis << std::endl;
}

int main() {
    Student studentas;
    Duom(studentas);
    std::string vid;
    std::cout<<"V - vidurkis, M - mediana"<<std::endl;
    std::cin>>vid;
    if(vid == "V")
    {
        std::cout << "-----------------------------------------------------------"<<std::endl;
        std::cout << "Vardas     Pavarde       Galutunis (vid.)"<<std::endl;
        std::cout << "-----------------------------------------------------------"<<std::endl;
            double Galutinis = Vidurkis(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
        double Galetunis_med = apskaiciuotiMediana(studentas.namuDarbai);
        std::cout << std::fixed << std::setprecision(2);
    
        std::cout<< studentas.vardas << "        " << studentas.pavarde << "       " << Galutinis;
    }
    else
    {
        std::cout << "-----------------------------------------------------------"<<std::endl;
        std::cout << "Vardas    Pavarde      Galutunis (med.)"<<std::endl;
        std::cout << "-----------------------------------------------------------"<<std::endl;
        double Galutinis = Vidurkis(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
        double mediana = apskaiciuotiMediana(studentas.namuDarbai);
        double Galutinis_med = 0.4*mediana+0.6*studentas.egz;
        std::cout << std::fixed << std::setprecision(2);
    
        std::cout<< studentas.vardas << "        " << studentas.pavarde << "       " << Galutinis_med;
    }
    

    
    return 0;
}
