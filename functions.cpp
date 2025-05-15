#include "functions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono>

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

void gen_name(std::string& vardas, std::string& pavarde) {
    std::vector<std::string> vardai = {"Pijus", "Justas", "Kostas", "Petras"};
    std::vector<std::string> pavardes = {"Savanevicius", "Andru", "Baranauskas", "Dovydaitis"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, vardai.size() - 1);
    vardas = vardai[distr(gen)];
    pavarde = pavardes[distr(gen)];
}
void gen_file(const std::string& pav, int kiek)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream gf(pav);
    if (!gf) std::cout<<"failas nebuvo sukurtas"<<std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, 10);
    for (int i=0; i<kiek; i++)
    {
        gf<<"VardasNR"<<i<<" "<<"PavardeNR"<<i;
        for (int j=0; j<5; j++)
        {
            gf<<" "<<distr(gen);
        }
        gf<<" ";
        gf<<distr(gen)<<std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo " << pav << " generavimas užtruko: " << diff.count() << " s" << std::endl;
    gf.close();
}
void failo_nuskaitymas(const std::string& pav, int kiek, std::vector<Student>& studentai)
{
    std::ifstream rf(pav);
    if (!rf) std::cout<<"failas neatsidaro"<<std::endl;
    std::string vardas, pavarde;
    while (rf >> vardas >> pavarde) {
        std::vector<int> namuDarbai;
        for (int i = 0; i < 5; i++) {
            int pazymys;
            rf >> pazymys;
            namuDarbai.push_back(pazymys);
        }
        int egz;
        rf >> egz;
        Student s;
        s.setVardas(vardas);
        s.setPavarde(pavarde);
        s.setNamuDarbai(namuDarbai);
        s.setEgz(egz);
        studentai.push_back(s);  
    }
}
void padalinti_studentus (std::vector<Student>& studentai, std::vector<Student>& vargsiukai, std::vector<Student>& kietekai)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& s : studentai)
    {
        if (s.getGalutinisVid() < 5.0)
        {
            vargsiukai.push_back(s);
        }
        else kietekai.push_back(s);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentų padalijimas užtruko: " << diff.count() << " s" << std::endl;
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

    for (const auto& s : studentai) {
        out << std::setw(15) << s.getVardas()
            << std::setw(15) << s.getPavarde()
            << std::setw(15) << s.getGalutinisVid() << "\n";
    }

    out.close();
}

void Duom(std::vector<Student>& studentai, int& ch1) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);

    std::string kitas_stud = "T";
    while (kitas_stud == "T" || kitas_stud == "t") {
        Student studentas;
        std::cout << "1 - įvesti pažymius rankiniu būdu\n2 - generuoti atsitiktinius pažymius\n3 - generuoti vardus, pavardes ir pazymius\n4 - nuskaityti is failo\n5 - generuoti failus\n6 - baigti\n";
        std::cin >> ch1;
        if (ch1 == 6) break;
        if (ch1 == 5)
        {
            std::cout<<"Ar nori generuoti failus? (T - taip, N - ne): ";
            std::string ats;
            std::cin >> ats;
            if (ats == "T" || ats == "t")
            {
            std::vector<Student> vargsiukai;
            std::vector<Student> kietekai;
            std::vector<int> skaicius = {1000, 10000, 100000};
            for (int i=0; i<skaicius.size(); i++)
            {
                std::string pav = "studentai_" + std::to_string(skaicius[i]) + ".txt";
                gen_file(pav, skaicius[i]);
            }
            for (int i=0; i<skaicius.size(); i++)
            {
                std::string pav = "studentai_" + std::to_string(skaicius[i]) + ".txt";
                failo_nuskaitymas(pav, skaicius[i], studentai);
                std::cout<<"Failas studentai_"<<skaicius[i]<<".txt nuskaitytas"<<std::endl;
            }
            for (int i=0; i<skaicius.size(); i++)
            {
                std::string pav = "studentai_" + std::to_string(skaicius[i]) + ".txt";
                padalinti_studentus(studentai, vargsiukai, kietekai);
                
            }
            issaugoti_studentus(vargsiukai, "vargsiukai.txt");
            issaugoti_studentus(kietekai, "kietekai.txt");
            }
            if (ats == "N" || ats == "n")
            {
                std::cout<<"Failai nesugeneruoti, naudojama esancius failus."<<std::endl;
            }
            
        }
        if (ch1 == 4) {
            try {
                std::ifstream rf("studentai10000.txt");
                if (!rf) throw std::runtime_error("Failas nerastas");

                std::string var, pav, nd;
                rf >> var >> pav;
                int kiek = 0;

                while (rf >> nd && nd != "Egz.") {
                    kiek++;
                }

                while (true) {
                    std::string vardas, pavarde;
                    std::vector<int> namuDarbai;
                    int egz;
                    if (!(rf >> vardas >> pavarde)) break;

                    for (int i = 0; i < kiek; i++) {
                        int paz;
                        if (!(rf >> paz)) 
                            throw std::runtime_error("Klaida skaitant pažymius iš failo.");
                        namuDarbai.push_back(paz);
                    }

                    if (!(egz))
                        throw std::runtime_error("Klaida skaitant egzamino pažymį iš failo.");
                    
                    Student s;
                    s.setVardas(vardas);
                    s.setPavarde(pavarde);
                    s.setNamuDarbai(namuDarbai);
                    s.setEgz(egz);

                    studentai.push_back(s);
                }

            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
        if (ch1 == 1) {
            std::string vardas, pavarde;
            std::vector<int> namuDarbai;
            int egz;
            try{
            std::cout << "Įveskite studento vardą: ";
            std::cin >> vardas;
            if (std::isdigit(vardas[0])) throw std::runtime_error("Vardas negali prasidėti skaičiumi");
            std::cout << "Įveskite studento pavardę: ";
            std::cin >> pavarde;
            if (std::isdigit(pavarde[0])) throw std::runtime_error("Pavarde negali prasidėti skaičiumi");
            std::cout << "Įveskite namų darbų pažymius (įveskite -1, kad baigtumėte): ";
            int pazymys;
            namuDarbai.clear();
            while (true) {
                std::cin >> pazymys;
                if (pazymys < -1 || pazymys > 10) throw std::runtime_error("Pažymys turi būti intervale nuo 1 iki 10");
                if (pazymys == -1) break;
                namuDarbai.push_back(pazymys);
            }
            if (std::cin.fail()) throw std::runtime_error("Neteisingas pažymys");
            std::cout << "Įveskite egzamino rezultatą: ";
            std::cin >> egz;

            Student s;
            s.setVardas(vardas);
            s.setPavarde(pavarde);
            s.setNamuDarbai(namuDarbai);
            s.setEgz(egz);

            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            
        }
        if (ch1 == 2) {
            std::string vardas, pavarde;
            std::vector<int> namuDarbai;
            int egz;
            try{
            std::cout << "Įveskite studento vardą: ";
            std::cin >> vardas;
            if (std::isdigit(vardas[0])) throw std::runtime_error("Vardas negali prasidėti skaičiumi");
            std::cout << "Įveskite studento pavardę: ";
            std::cin >> pavarde;
            if (std::isdigit(pavarde[0])) throw std::runtime_error("Pavarde negali prasidėti skaičiumi");
            namuDarbai.clear();
            for (int i = 0; i < 5; i++) {
                namuDarbai.push_back(distr(gen));
            }
            egz = distr(gen);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            Student s;
            s.setVardas(vardas);
            s.setPavarde(pavarde);
            s.setNamuDarbai(namuDarbai);
            s.setEgz(egz);
            
        }
        if (ch1 == 3) {
            std::string vardas, pavarde;
            std::vector<int> namuDarbai;
            int egz;

            gen_name(vardas, pavarde);
            namuDarbai.clear();
            for (int i = 0; i < 5; i++) {
                namuDarbai.push_back(distr(gen));
            }
            egz = distr(gen);
        
            Student s;
        s.setVardas(vardas);
        s.setPavarde(pavarde);
        s.setNamuDarbai(namuDarbai);
        s.setEgz(egz);
        }
        
        
        std::cout << "Ar norite tęsti? (T - taip, N - ne): ";
        std::cin >> kitas_stud;
    }
}

void Rez(std::vector<Student>& studentai, int& ch1) {
    while (ch1 != 5) {
        std::cout << "Pasirinkite rikiavimo būdą:\n1 - pagal vardą\n2 - pagal pavardę\n3 - pagal vidurkį\n4 - pagal medianą\n";
    int ch;
    std::cin >> ch;
    switch (ch) {
        case 1:
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.getVardas() < b.getVardas();
            });
            break;
        case 2:
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.getPavarde() < b.getPavarde();
            });
            break;
        case 3:
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.getGalutinisVid() < b.getGalutinisVid();
            });
            break;
        case 4:
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.getGalutinisMed() < b.getGalutinisMed();
            });
            break;
        default:
            std::cout << "Neteisingas pasirinkimas\n";
            return;
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-----------------------------------------------------------\n";
    std::cout << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(25) << "Galutinis (vid.)  Galutinis (med.)\n";
    std::cout << "-----------------------------------------------------------\n";

    for (const auto& s : studentai) {
        std::cout << std::setw(15) << s.getVardas()
                  << std::setw(15) << s.getPavarde() 
                  << std::setw(15) << s.getGalutinisVid()
                  << std::setw(15) << s.getGalutinisMed() << "\n";
    }
    std::cout << "Ar norite išsaugoti į failą? (T - taip, N - ne): ";
    std::string ats;
    std::cin >> ats;
    if (ats == "T" || ats == "t") {
        std::ofstream rf("rezultatai.txt");
        
        rf << std::fixed << std::setprecision(2);
        rf << "-----------------------------------------------------------\n";
        rf << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(25) << "Galutinis (vid.)  Galutinis (med.)\n";
        rf << "-----------------------------------------------------------\n";
        for (const auto& s : studentai) {

            rf << std::setw(15) << s.getVardas()
               << std::setw(15) << s.getPavarde()
               << std::setw(15) << s.getGalutinisVid()
               << std::setw(15) << s.getGalutinisMed() << "\n";
        }
    }
    }
    
}