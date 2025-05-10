#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
using std::string;

class Zmogus {
protected:
    string var_, pav_;

public:
    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde) : var_(vardas), pav_(pavarde) {}

    virtual string vardas() const = 0;
    virtual string pavarde() const = 0;

    virtual void spausdinti(std::ostream& os) const = 0;
    virtual ~Zmogus() {}
};

#endif
