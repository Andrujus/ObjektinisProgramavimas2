#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <algorithm>

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



    ~Student() = default;

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
#endif 