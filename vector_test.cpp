#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <chrono>

struct Student {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egz;
};

double GalutinisVidurkis(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : pazymiai) suma += pazymys;
    return suma / pazymiai.size();
}

void failo_nuskaitymas(const std::string& pav, std::vector<Student>& studentai)
{
    std::ifstream rf(pav);
    if (!rf) std::cout<<"failas neatsidaro"<<std::endl;
    Student studentas;
    
    while (rf >> studentas.vardas >> studentas.pavarde) {
        studentas.namuDarbai.clear();
        int pazymys;
        for (int i = 0; i < 5; i++) {
            if (!(rf >> pazymys)) 
                throw std::runtime_error("Klaida skaitant pažymius iš failo.");
            studentas.namuDarbai.push_back(pazymys);
        }
        if (!(rf >> studentas.egz))
            throw std::runtime_error("Klaida skaitant egzamino pažymį iš failo.");
        studentai.push_back(studentas);
    }
}
void issaugoti_studentus(const std::vector<Student>& studentai, const std::string& failo_pav) {
    std::ofstream out(failo_pav);
    if (!out) {
        std::cerr << "Klaida atidarant failą: " << failo_pav << std::endl;
        return;
    }

    out << std::fixed << std::setprecision(2);
    out << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (vid.)\n";
    out << "-----------------------------------------------------------\n";

    for (const auto& studentas : studentai) {
        double galutinis_v = GalutinisVidurkis(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
        out << std::setw(15) << studentas.vardas
            << std::setw(15) << studentas.pavarde
            << std::setw(15) << galutinis_v << "\n";
    }

    out.close();
}

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<Student> studentai;
    failo_nuskaitymas("studentai_10000.txt", studentai);
    issaugoti_studentus(studentai, "studentai_issaugoti.txt");
    auto finish_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = finish_time - start_time;
    std::cout << "Failo studentai10000.txt nuskaitymas ir issaugojimas uztruko: " << diff.count() << " s" << std::endl;

return 0;
}