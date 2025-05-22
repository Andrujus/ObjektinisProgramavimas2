#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;

public:
    Zmogus() = default;
    Zmogus(const std::string& v, const std::string& p) : vardas(v), pavarde(p) {}
    virtual ~Zmogus() = default;

    virtual std::string getVardas() const = 0;
    virtual std::string getPavarde() const = 0;

    virtual void setVardas(const std::string& v) = 0;
    virtual void setPavarde(const std::string& p) = 0;
};

#endif
