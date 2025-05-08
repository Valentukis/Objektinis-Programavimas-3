#include "class/studentas.h"
#include <cassert>
#include <iostream>
#include <sstream>

void test_rule_of_five() {
    std::cout << "Testing Rule of Five...\n";

    Studentas a;
    a.ivedimas_generuojant_viska();
    std::cout << "Original studentas (a):\n" << a << "\n";
    std:: cout << string(80, '-') << endl;

    Studentas b = a;  // Copy constructor
    std::cout << "Copy constr. (b = a). Naujas studentas(b): \n" << b << "\n";
    std::cout << "Senas studentas (a): \n" << a << endl;
    std:: cout << string(80, '-') << endl;

    Studentas c(std::move(a));  // Move constructor
    std::cout << "Move constructor (c = std::move(a)). Naujas studentas (c): \n" << c << "\n";
    std::cout << "Senas studentas (a): \n" << a << endl;
    std:: cout << string(80, '-') << endl;

    Studentas d;
    d = b;  // Copy assignment
    std::cout << "Copy assignment (d = b). Naujas studentas (d): \n" << d << "\n";
    std::cout << "Senas studentas (b): \n" << b << endl;
    std:: cout << string(80, '-') << endl;

    Studentas e;
    e = std::move(b);  // Move assignment
    std::cout << "Move assignment (e = std::move(b)). Naujas studentas (e): \n" << e << "\n";
    std::cout << "Senas studentas (b): \n" << b << endl;
    std:: cout << string(80, '-') << endl;
}

void test_io() {
    std::cout << "\nTesting input operator...\n";

    Studentas s;
    std::stringstream ss("Vardenis Pavardenis 10 9 8 7 6 8");
    ss >> s;
    std::cout << s.vardas() << " " << s.pavarde() << " " << s.egzaminas() << endl;
    std:: cout << string(80, '-') << endl;
    
    std::cout << "Tesing output operator..." << endl;
    std::stringstream out;
    
    Studentas a;
    a.ivedimas_generuojant_viska();
    out << a;
    assert(!out.str().empty()); 
    std::cout << "I/O stream test passed. Output:\n" << out.str() << "\n";
}

int main() {
    //Zmogus zm;
    test_rule_of_five();
    test_io();
}
