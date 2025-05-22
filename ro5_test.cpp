#include "Student.h"
#include <sstream>
#include <iostream>

std::istream& operator>>(std::istream& is, Student& s) {
    std::string vardas, pavarde;
    int egz;
    std::vector<int> namuDarbai;
    std::string eilute;

    is >> vardas >> pavarde;

    std::getline(is, eilute);
    std::istringstream iss(eilute);
    int pazymys;
    
    while (iss >> pazymys) {
        namuDarbai.push_back(pazymys);
    }

    if (!namuDarbai.empty()) {
        egz = namuDarbai.back();
        namuDarbai.pop_back();
    } else {
        egz = 0;
    }

    s.setVardas(vardas);
    s.setPavarde(pavarde);
    s.setNamuDarbai(namuDarbai);
    s.setEgz(egz);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.vardas << " " << s.pavarde << " ND: ";
    for (int nd : s.namuDarbai) {
        os << nd << " ";
    }
    os << "Egz: " << s.egz;
    return os;
}

void ro5_test(){
    Student a("Justas", "An", {8, 9, 10}, 7);
    std::cout << a << std::endl;

    Student b(a);
    std::cout << "Copy: " << b << std::endl;

    Student c(std::move(a));
    std::cout << "Move: " << c << std::endl;
    std::cout << "Is ko move:" << a << std::endl;

    Student c = std::move(a);
    std::cout << "Move assignment: " << c << std::endl;
    std::cout << "Is ko move:" << a << std::endl;

    Student d;
    d = b;
    std::cout << "Copy assignment: " << d << std::endl;
}

int main() {

    /*Student student1("Justas", "An", {8, 9, 10}, 7);
    Student student2("Justin", "Bm", {6, 7, 8}, 9);

    std::cout << student1 << std::endl;
    std::cout << student2 << std::endl;*/
    ro5_test();


return 0;
}