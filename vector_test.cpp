#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <chrono>

class Student {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egz;
public:
    Student() : vardas(""), pavarde(""), egz(0) {}
    Student(const std::string& v, const std::string& p, const std::vector<int>& nd, int e) 
        : vardas(v), pavarde(p), namuDarbai(nd), egz(e) {}

    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void setNamuDarbai(const std::vector<int>& nd) { namuDarbai = nd; }
    void setEgz(int e) { egz = e; }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::vector<int> getNamuDarbai() const { return namuDarbai; }
    int getEgz() const { return egz; }
    double getGalutinisVid() const { return skaiciuotiGalutiniVidurki(); }
    double getGalutinisMed() const { return skaiciuotiGalutiniMediana(); }

    static double Vidurkis(const std::vector<int>& pazymiai) {
        if (pazymiai.empty()) return 0.0;
        double suma = 0.0;
        for (int pazymys : pazymiai) suma += pazymys;
        return suma / pazymiai.size();
    }

    double skaiciuotiVidurki() const {
        if (namuDarbai.empty()) return 0.0;
        double suma = 0.0;
        for (int pazymys : namuDarbai) {
            suma += pazymys;
        }
        return suma / namuDarbai.size();
    }

    double skaiciuotiMediana() const {
        if (namuDarbai.empty()) return 0.0;
        std::vector<int> temp = namuDarbai;
        std::sort(temp.begin(), temp.end());
        size_t dydis = temp.size();
        if (dydis % 2 == 0) {
            return (temp[dydis / 2 - 1] + temp[dydis / 2]) / 2.0;
        } else {
            return temp[dydis / 2];
        }
    }
    double skaiciuotiGalutiniVidurki() const {
        return skaiciuotiVidurki() * 0.4 + egz * 0.6;
    }

    double skaiciuotiGalutiniMediana() const {
        return skaiciuotiMediana() * 0.4 + egz * 0.6;
    }
};



void failo_nuskaitymas(const std::string& pav, std::vector<Student>& studentai)
{
    std::ifstream rf(pav);
    if (!rf) std::cout<<"failas neatsidaro"<<std::endl;
    Student s;
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egz, pazymys;
    
    while (rf >> vardas >> pavarde) {
        namuDarbai.clear();
        for (int i = 0; i < 5; i++) {
            if (!(rf >> pazymys)) 
                throw std::runtime_error("Klaida skaitant pažymius iš failo.");
            namuDarbai.push_back(pazymys);
        }
        if (!(rf >> egz))
            throw std::runtime_error("Klaida skaitant egzamino pažymį iš failo.");
        
        s.setVardas(vardas);
        s.setPavarde(pavarde);
        s.setNamuDarbai(namuDarbai);
        s.setEgz(egz);
        studentai.push_back(s);
    }
}
void padalinti1(const std::vector<Student>& studentai, std::vector<Student>& kietekai, std::vector<Student>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    
    for (const auto& studentas : studentai)
    {
        
        if (studentas.getGalutinisVid() < 5.0)
        {
            vargsiukai.push_back(studentas);
        }
        else kietekai.push_back(studentas);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentų padalijimas (1) užtruko: " << diff.count() << " s" << std::endl;
}
void padalinti2(std::vector<Student>& studentai, std::vector<Student>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    auto it = studentai.begin();
    while(it != studentai.end()) {
        if (it->getGalutinisVid() < 5.0) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            it++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentų padalijimas (2) užtruko: " << diff.count() << " s" << std::endl;
}
void padalinti3(std::vector<Student>& studentai, std::vector<Student>& vargsiukai)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::remove_if(studentai.begin(), studentai.end(), [&](const Student& s) {
        
        if (s.getGalutinisVid() < 5.0) {
            vargsiukai.push_back(s);
            return true;
        } else {
            return false;
        }
    });

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentų padalijimas (3) užtruko: " << diff.count() << " s" << std::endl;
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
        out << std::setw(15) << studentas.getVardas()
            << std::setw(15) << studentas.getPavarde()
            << std::setw(15) << studentas.getGalutinisVid() << "\n";
    }

    out.close();
}

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<Student> studentai, kietekai, vargsiukai;
    failo_nuskaitymas("studentai_10000.txt", studentai);
    padalinti1(studentai, kietekai, vargsiukai);
    issaugoti_studentus(studentai, "studentai_issaugoti_vector.txt");
    //padalinti2(studentai, vargsiukai);
    //padalinti3(studentai, vargsiukai);
    issaugoti_studentus(studentai, "kietekai1.txt");
    issaugoti_studentus(vargsiukai, "vargsiukai1.txt");
    auto finish_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = finish_time - start_time;
    std::cout << "Failo studentai10000.txt nuskaitymas ir issaugojimas uztruko: " << diff.count() << " s" << std::endl;

return 0;
}