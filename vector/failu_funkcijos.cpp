#include "failu_funkcijos.h"

int rasti_nd_skaiciu_faile(ifstream& fd) {
    string line, word;
    int nd_sk = 0;
    getline(fd, line);
    istringstream pirma_eilute(line);

    while (pirma_eilute >> word) nd_sk++;
    nd_sk -= 3; //atimti varda, pavarde, egz
    return nd_sk;
}

void buferio_apdorojimas(vector <Studentas> &grupe, size_t buffer_size, vector <char> &buffer, ifstream &fd, int nd_sk) {
    string line, leftover = "", chunk;
    
    while(fd.read(buffer.data(), buffer_size) || fd.gcount() ) {
        chunk = leftover + string(buffer.data(), fd.gcount());
        size_t last_new_line = chunk.rfind('\n');

        if (last_new_line != string::npos) {
            leftover = chunk.substr(last_new_line + 1);
            chunk = chunk.substr(0, last_new_line);
        }

        else leftover = "";
            
        istringstream stream(chunk);

        while (std::getline(stream, line)) {
            istringstream duom(line);
            Studentas laik(duom, nd_sk);
            grupe.emplace_back(std::move(laik)); 
        }
        
    }

    if (!leftover.empty()) {
        istringstream duom(leftover);
        Studentas laik(duom, nd_sk);
        grupe.emplace_back(std::move(laik)); 
    }
    fd.close();
}

void failo_generavimas(ifstream &fd){

    int Studentasent_sk, nd_sk;
        
        cout << "Įveskite, kiek Studentasentų sugeneruoti: " << endl;
        while(true) {
            cin >> Studentasent_sk;
            if (cin.fail() || Studentasent_sk <= 0) {
                cin.clear(); // Clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cout << "Klaida! Įveskite teigiamą sveiką skaičių Studentasentams: ";
            } else break;
        }

        cout << "Įveskite, kiek buvo namų darbų atsiskaitymų: " << endl;
        while(true) {
            cin >> nd_sk;
            if (cin.fail() || nd_sk <= 0) {
                cin.clear(); // Clear error state
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                cout << "Klaida! Įveskite teigiamą sveiką skaičių Studentasentams: ";
            } else break;
        }

        auto start = std::chrono::high_resolution_clock::now(); 

        string failo_pav = "Studentasentai" + std::to_string(Studentasent_sk) + ".txt";
        ofstream fr;
        fr.open(failo_pav);
        
        fr << std::left << setw(20) << "Vardas" << setw(20) << std::right << "Pavarde" << setw(15);
        for (int i = 0; i < nd_sk; i++) fr << "ND" + std::to_string(i+1) << setw(15); 
        fr << "Egzaminas" << endl;

        for (int i = 0; i < Studentasent_sk; i++) {
            fr << std::left << setw(20) << "Vardas" + std::to_string(i+1) << std::right << setw(20) << "Pavarde" + std::to_string(i+1) << setw(15);
            for (int j = 0; j < nd_sk; j++) fr << std::right << rand() % 10 + 1 << setw(15);
            fr << rand() % 10 + 1 << endl;
        }
        fr.close();
        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = end - start;
        cout << "Failas sugeneruotas per " << std::fixed << std::setprecision(1) << elapsed.count() << " sekundžių!" << endl;
        fd.open(failo_pav);
    }

void failo_pav_gavimas(ifstream &fd) {
    string file_name;
    
    while (true) {
        cout << "Įveskite failo pavadinimą, esantį darbo aplanke, kurį norite naudoti [pavadinimas.txt]: " << endl;
        cin >> file_name;
        fd.open(file_name);
        if (!fd || fd.peek() == ifstream::traits_type::eof()){
             std::cerr << ("Klaida atidarant failą. Patikrinkite, ar failas direktyvoje ir bandykite įvesti vėl.\n");
             cin.clear();
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             cout << string(80, '-') << endl;
    }
    else break;
    
        }
}

void ivedimas_failu(vector <Studentas> &grupe) {

    const size_t buffer_size = 8192;
    vector <char> buffer(buffer_size);
    int spausdinimas;
    ifstream fd;
    bool generuoti;

    cout << string(80, '-') << endl;
    cout << "Norite naudoti ęsamą failą ar sugeneruoti naują? (0 - Naudoti esamą, 1 - Generuoti naują): " << endl;
    while(true) {
    cin >> generuoti;
    if (cin.fail() || (generuoti != 0 && generuoti != 1)) {
        cin.clear(); // Clear error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "Klaida! Prašome įvesti 0 arba 1: ";
    }
    else break;
    }

    if(generuoti) failo_generavimas(fd);
    else failo_pav_gavimas(fd);
    
    cout << "Nuskaitomi duomenys iš failo..." << endl;
    int nd_sk = rasti_nd_skaiciu_faile(fd);
    auto start = std::chrono::high_resolution_clock::now(); 
    buferio_apdorojimas(grupe, buffer_size, buffer, fd, nd_sk);
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsed = end - start;
    cout << "Baigta! Duomenų nuskaitymas užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << " s" << endl;
    cout << string(80, '-') << endl;
    
    cout << "Pagal ką norėsite rūšiuoti duomenis? (1 - vardas, 2 - pavardė, 3 - galutinis balas pagal vidurkį, 4 - galutinis balas pagal medianą): " << endl;
    pasirink_rusiavimas(grupe);

    cout << string(80, '-') << endl;
    while(true) {
    cout << "Duomenis išvesti ekrane ar į tekstinį failą? (0 - ekrane, 1 - faile): " << endl;
    cin >> spausdinimas;
    if (cin.fail() || spausdinimas < 0 || spausdinimas > 1) {
        std::cerr << "Bloga įvestis. Bandykite vėl." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else break;
    }
    spausdinimas_kartu(grupe, spausdinimas);
    cout << string(80, '-') << endl;
    cout << "Rūšiuojama į kietuolius ir varšelius..." << endl;
    ofstream varg("vargseliai"+std::to_string(grupe.size()) + ".txt");
    ofstream kiet("kietuoliai"+std::to_string(grupe.size()) + ".txt");
    vector<Studentas> kietuoliai, vargseliai;
    rusiuoti_grupemis(grupe, vargseliai);

    cout << "Išvedama į failą..." << endl;
    start = std::chrono::high_resolution_clock::now();
    for (auto n: grupe) kiet << std::left << setw(15) << n.vardas() << setw(15) << n.pavarde() << setw(15) << std::fixed << std::setprecision(2) << n.galutinis_vidurkis() << endl;
    for (auto n: vargseliai) varg << std::left << setw(15) << n.vardas() << setw(15) << n.pavarde() << setw(15) << std::fixed << std::setprecision(2) << n.galutinis_vidurkis()  << endl;

    end = std::chrono::high_resolution_clock::now(); 
    elapsed = end - start;
    cout << "Sūrušiuotų studentų išvedimas į failą užtruko: " << std::fixed << std::setprecision(1) << elapsed.count() << "s" << endl;
    cout << string(80, '-') << endl;

}