#include "functions.h"

double Vidurkis(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : pazymiai) suma += pazymys;
    return suma / pazymiai.size();
}

double apskaiciuotiMediana(std::vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0;
    std::sort(pazymiai.begin(), pazymiai.end());
    size_t dydis = pazymiai.size();
    if (dydis % 2 == 0) {
        return (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
    } else {
        return pazymiai[dydis / 2];
    }
}

void Duom(std::vector<Student>& studentai) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);

    std::string kitas_stud = "T";
    while (kitas_stud == "T" || kitas_stud == "t") {
        Student studentas;
        std::cout << "Įveskite studento vardą: ";
        std::cin >> studentas.vardas;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> studentas.pavarde;

        std::cout << "1 - įvesti pažymius rankiniu būdu\n2 - generuoti atsitiktinius pažymius\n";
        int ch;
        std::cin >> ch;

        studentas.namuDarbai.clear();

        if (ch == 1) {
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
        else if (ch == 2) {

            for (int i = 0; i < 5; i++) {
                studentas.namuDarbai.push_back(distr(gen));
            }

            studentas.egz = distr(gen);
            
        }

        studentai.push_back(studentas);

        std::cout << "Ar norite tęsti? (T - taip, N - ne): ";
        std::cin >> kitas_stud;
    }
}

void Rez(const std::vector<Student>& studentai, bool n_vid) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-----------------------------------------------------------\n";
    if (n_vid)
        std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(25) << "Galutinis (vid.)\n";
    else
        std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(25) << "Galutinis (med.)\n";
    std::cout << "-----------------------------------------------------------\n";

    for (const auto& studentas : studentai) {
        double galutinis;
        if (n_vid) {
            galutinis = Vidurkis(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
        } else {
            galutinis = apskaiciuotiMediana(studentas.namuDarbai) * 0.4 + studentas.egz * 0.6;
        }

        std::cout << std::setw(15) << studentas.vardas 
                  << std::setw(15) << studentas.pavarde 
                  << std::setw(15) << galutinis << "\n";
    }
}

int main() {
    std::vector<Student> studentai;
    Duom(studentai);

    std::string vid;
    std::cout << "V - vidurkis, M - mediana: ";
    std::cin >> vid;

    if (vid == "V" || vid == "v") {
        Rez(studentai, true);
    } else {
        Rez(studentai, false);
    }

    return 0;
}
