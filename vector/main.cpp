#include "mano_lib.h"
#include "spausdinimo_funkcijos.h"
#include "failu_funkcijos.h"
#include "studentas.h"

int main(){

    auto prog_prad = std::chrono::high_resolution_clock::now(); 
    std::chrono::time_point<std::chrono::high_resolution_clock> prog_pab;
    std::chrono::duration<double> prog_laik;

    srand(time(NULL));
    vector <Studentas> grupe;
    int eiga;
    bool testi = true;
    cout << "Sveiki! Padėsiu jums paskaičiuoti galutinius Jūsų studentų balus!" << endl;

   while(testi) {
        Studentas laik;
        eiga = eigos_parinktis();

        switch(eiga) {
            case 1:
            laik.ivedimas_ranka();
            break;

            case 2:
            laik.ivedimas_pazymiu_generavimu();
            break;

            case 3:
            laik.ivedimas_generuojant_viska();
            break;

            case 4:
            ivedimas_failu(grupe);
            prog_pab = std::chrono::high_resolution_clock::now(); 
            prog_laik = prog_pab - prog_prad;
            cout << "Visa programa veikė: " << std::fixed << std::setprecision(1) << prog_laik.count() << "s" << endl;
            exit(0);
            break;

            case 5:
            testi = false;
            break;
        }
        
        if (eiga != 5) {
        
        grupe.push_back(laik);
        cout << string(56, '-') << endl;
        }
    }

    spausdinimas_atskiras(grupe);
}

