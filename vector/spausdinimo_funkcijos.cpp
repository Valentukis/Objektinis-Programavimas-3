#include "spausdinimo_funkcijos.h"

void spausdinimas_atskiras(vector <Studentas> &grupe) {
    char pasirinkimas;
    
    while(true) {
        cout << "Norite skaičiuoti galutinį įvertinimą su studentų pažymių vidurkiais ar medianomis? [V/M]" << endl;
        cin >> pasirinkimas;
        pasirinkimas = toupper(pasirinkimas);
        if (pasirinkimas != 'V' && pasirinkimas != 'M') std::cerr << "Bloga pasirinkimo įvestis. Bandykite vėl: " << endl;
        else break;
    }
    
    cout << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << ( (pasirinkimas == 'V') ? " Galutinis (Vid.)" : " Galutinis (Med.)" ) << endl;
    cout << string(56, '-') << endl;
    for (auto n: grupe) {
        cout << std::left << setw(20) << n.vardas() << setw(20) << n.pavarde() << setw(20) << std::fixed << std::setprecision(2) << ((pasirinkimas == 'V') ? (n.galutinis_vidurkis()) : (n.galutinis_mediana())) << endl;
        }
}

void spausdinimas_kartu(vector <Studentas> &grupe, bool spausdinimas) {
    if (spausdinimas) {
        std::ofstream fr("rez.txt");
        cout << "Įrašoma į failą..." << endl;
        fr << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << " Galutinis (Vid.)" << setw(20) << " Galutinis (Med.)" << endl;
        fr << string(76, '-') << endl;
        auto start = std::chrono::high_resolution_clock::now();
        for (auto n: grupe) {
            fr << n << endl;
            }
            auto end = std::chrono::high_resolution_clock::now(); 
            std::chrono::duration<double> elapsed = end - start;
            cout << "Spausdinimas užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
            fr.close();
    }
    
    else {
    std::ostringstream output;
    output << std::left << setw(20) << "Pavardė" << setw(20) << " Vardas" << setw(20) << " Galutinis (Vid.)" << setw(20) << " Galutinis (Med.)" << endl;
    output << string(76, '-') << endl;
    auto start = std::chrono::high_resolution_clock::now(); 
    for (auto n: grupe) {
        output << n << endl;
        }
        cout << output.str();
        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = end - start;
        cout << "Spausdinimas užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
    }
}

int eigos_parinktis() {
    int eiga;
    while(true) {
        cout << "Kaip norėsite įvesti duomenis apie šį studentą? \n(1 - ranka, 2 - generuoti pažymius ir egzamino rezultatą, 3 - generuoti pažymius, egzaminą bei vardą ir pavardę, 4 - nuskaityti duomenis iš failo (visiems studentams), 5 - baigti darbą): \n";
        cin >> eiga;

        if(cin.fail() || eiga < 1 || eiga > 5) {
            std::cerr << "Bloga įvestis! Bandykite dar kartą" << endl;
            cout << string(56, '-') << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        else {
            break;
        }
    }
    return eiga;
}