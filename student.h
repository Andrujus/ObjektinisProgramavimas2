#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

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
};
#endif