#include "func_masyvas.h"
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

double Vidurkis(const Student& studentas) {
    double suma = 0.0;
    for (int i = 0; i < studentas.nd_kiek; i++) {
        suma += studentas.namuDarbai[i];
    }
    return suma / studentas.nd_kiek;
}

double apskaiciuotiMediana(const Student& studentas) {
    if (studentas.nd_kiek == 0) return 0;
    
    std::vector<int> pazymiai(studentas.namuDarbai, studentas.namuDarbai + studentas.nd_kiek);
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
    while (kitas_stud == "T" || kitas_stud == "t") {
        std::cout << "Įveskite studento vardą: ";
        std::cin >> studentas.vardas;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> studentas.pavarde;

        std::cout << "Įveskite namų darbų pažymius (įveskite -1, kad baigtumėte): ";
        int pazymys;
        std::vector<int> laikinas_masyvas;
        while (true) {
            std::cin >> pazymys;
            if (pazymys == -1) break;
            laikinas_masyvas.push_back(pazymys);
        }

        studentas.nd_kiek = laikinas_masyvas.size();
        studentas.namuDarbai = new int[studentas.nd_kiek];

        for (int i = 0; i < studentas.nd_kiek; i++) {
            studentas.namuDarbai[i] = laikinas_masyvas[i];
        }

        std::cout << "Įveskite egzamino rezultatą: ";
        std::cin >> studentas.egz;

        studentai.push_back(studentas);

        std::cout << "Ar norite tęsti? (T - taip, N - ne): ";
        std::cin >> kitas_stud;
    }
}

void Rez(const Student& studentas, bool n_vid) {
    std::cout << std::fixed << std::setprecision(2);
    double Galutinis;

    if (n_vid) {
        Galutinis = Vidurkis(studentas) * 0.4 + studentas.egz * 0.6;
    } else {
        Galutinis = apskaiciuotiMediana(studentas) * 0.4 + studentas.egz * 0.6;
    }

    std::cout << "Studentas: " << studentas.vardas << " " 
              << studentas.pavarde << " Galutinis: " << Galutinis << std::endl;
}

int main() {
    std::vector<Student> studentai;
    Student studentas;

    Duom(studentas, studentai);

    std::string vid;
    std::cout << "V - vidurkis, M - mediana: ";
    std::cin >> vid;

    for (const auto& stud : studentai) {
        if (vid == "V" || vid == "v") {
            Rez(stud, true);
        } else {
            Rez(stud, false);
        }
    }

    return 0;
}