Objektinio programavimo praktikos projektinis darbas, skirtas kaip pagalbinė priemonė destytojams vertinant studentus. Realizuota galimybė įvesti duomenis ranka, juos generuoti atsitktinai arba nuskaityti iš duomenų failo. Programa buvo kuriama per kelias versijas, palaipsniui papildant funkcionalumą ir optimizuojant veikimą.

Programos pasikeitimai tarp versijų:  
-v0.1: Pradinė programos versija, leidžianti ranka įvesti duomenis ir juos sūrušiuoti bei išvesti ekrane.  
-v0.2: Pridėta galimybė nuskaityti duomenis iš tekstinio failo.  
-v0.3: Pilnas refactoringas, pritaikomas geros programavimo praktikos.  
-v0.4: Įgyvendinta failo generavimo bei studentų skirstymo į grupes pagal pažymius funkcijos.  
-v1.0: Pilna programos versija, sutvarkytos direktyvos, patobulinta išvestis, sukurtas Makefile, realizuotos kelios versijos naudojant skirtingus konteinerius, optimizuotos senos funkcijos.  
-v1.1: Perdaryta programa naudojant klases, taip užtikrinant patogų programos naudojimą, duomenų saugumą, patikimumą. Sutvarkyta programos strukūra, paliekant tik efektyviausius metodus
-v1.2 Pritaikytas "Rule of five" studentų klasei, taip pat perdengti įvesties/išvesties operatoriui darbui su klase patogumui. Parašytas testas testuoti šią naują versiją.

**Įdiegimo instrukcija**

Jūsų patogumui, buvo sukurtas Makefile. Atsidarę mėgstamiausią terminalą, galite naudoti šias komandas:
1. Paleidžiamojo failo kūrimas   
  1.1 Vector realziacija - "make vector" 
  1.2 List realizacija - "make list"   
  1.3 Deque realizacija - "make deque"
  1.4 Class+Vector realizacija - "make main" (arba "make")
3. Paleidimas  
  2.1 Vector realziacija - "./vector_program"   
  2.2 List realizacija - "./list_program"   
  2.3 Deque realizacija - "./deque_program"   
  2.4 Class realizacija - "./main"
5. Programos valymas (ištrina sugeneruotus vykdomuosius failus) - "make clean"

![image](https://github.com/user-attachments/assets/cb8a2436-d262-4c9d-bc6d-33f241aac815)


**Naudojimosi instrukcija**
Programa sukurta intuityviai ir aiškiai. Atsidarius programą, Jūsų bus paprašoma pasirinkti norimą įvedimo būdą. Atitinkamai po to būsite prašomi įvesti studentų informaciją arba failo, laikančius šiuos duomenis, pavadinimą. Jūsų patogumui, bus galima pasirinkti rūšiavimo ir spausdinimo būdus. Pasirinkus įvedimą failu, studentai bus skirstomi į papildomus 2 failus pagal jų vidurkį, rezultatus rasite projekto direktyvoje

**Programos veikimo pavyzdžiai**

Programos eiga:
![image](https://github.com/user-attachments/assets/ab721bc3-24ff-43f4-8ec0-7079ff88bb1f)
Sugeneruotas studentų failas:
![image](https://github.com/user-attachments/assets/4dcdb3a0-c2ba-4f71-b03c-d8c6e0d37e56)
Surūšiuotų studentų failas:
![image](https://github.com/user-attachments/assets/39f13c60-4014-4706-8914-c793d66fbf98)


**Spartos analizė**

Programos efektyvumui nustatyti buvo atlikta spartos analizė. Nuo v1.0 taip pat atlikta list ir deque analizė, palyginimui matuojamas duomenų nuskaitymo, rūšiavimo mažėjimo tvarka beiskirstymo į kategorijas laikai. Kiekvieną įrašą sudaro 5 bandymų vidurkis naudojant tuos pačius failus. Optimizavimui naudojamas 'O3' flag'as. Naudojamo kompiuterio specifikacijos:

CPU: AMD Ryzen 7840hs

Memory: 16GB LPDDR5 6400Mhz RAM

Storage: PCIe 4.0 NVMe M.2 1TB SSD

**Analizės rezultatai**
</br> 

"Vector" realizacija
| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Failo generavimas | < 0.1s | < 0.1s | 0.4s | 3.7s | 27.0s |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.3s | 16.7s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.3s | 3.9s |
| Rezultatų spausdinimas | < 0.1s | < 0.1s | 0.3s | 3.4s | 37.0s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.1s | 1.1s |
| Surūšiuotų studentų išvedimas į failą | < 0.1s | < 0.1s | 0.3s | 2.8s | 31.3s |
| Bendras vidutinis programos veikimo laikas | < 0.1s | 0.1s | 0.8s | 8.1s | 92.2s |

"List" realizacija
| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.4s | 16.6s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.6s | 14.2s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.2s | 2.8s |

"Deque" realizacija
| Testas | 1000 įrašų | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ---------- | ----------- | ------------ | ------------- | -------------- |
| Duomenų nuskaitymas | < 0.1s | < 0.1s | 0.2s | 1.4s | 17.2s |
| Rūšiavimas pagal parinktį | < 0.1s | < 0.1s | < 0.1s | 0.7s | 7.8s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | < 0.1s | < 0.1s | 0.1s | 1.4s |

Atlikus analizę galima teigti, kad sparčiausiai programa veikia, naudojant vektoriaus tipo konteinerius duomenims laikyti. Su mažesniais failais skirtumas minimalus, tačiau su dideliais failais (>10000000 įrašų) vektoriai veikia greičiau už kitus, o deque yra šiek tiek greitiesnis už list'ą. 

Sekančiai daliai, bus išbandomos įvairios strategijos rūšiavimui į 2 grupes ir randamas optimaliausias variantas.  Bus matuojamas ir palyginiamas rūšiavimo laikas tarp implementacijų (nuo 100000 įrašų).

**1 Strategija**
Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius. Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų. 

"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.3s | 3.4s |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.4s | 5.1s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.3s | 4.1s |

Pastebama, kad ši strategija neoptimali, atsižvelgiant į naudojamos atminties dydį
![image](https://github.com/user-attachments/assets/56c74d1f-2a2e-41e3-8ed7-c3b029b0ee8d)

**2 Strategija**
"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | 4.2s | > 5min | > 5min |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | 0.3s| 0.2s | 2.8s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | 8.1s | > 5min | > 5min |

Pastebime, kad dabartinė strategijos implementacija labai lėta, nes naudojami metodai yra neefektyvus naudojant deque ir vector, palyginus su list. 

**3 Strategija (realizacija iki v1.0)**
Šioje strategijoje mes einame pro esamą konteinerį, ir iš jo keliame į naujus naudodami std::move. Taip yra sutaupoma atmintis ir move yra "pigesnė" operacija už kopijavimą.

"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 1.1s |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.2s | 2.8s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 1.4s |

Taigi, iš pateiktų strategijų, 3 buvo geriausia dėl žymiai efektyvesnio rušiavimo vector ir deque konteineriuose. 

**4 Strategija (realizacija iki v1.0)**
Įdėja yra sujungti originalų sprendimą su std::move ir 2 strategiją su tik vienu nauju konteineriu, pridedant efektyvius algoritmus kaip std::partition

"Vector" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 0.3s |

"List" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.4s | 3.5s |

"Deque" realizacija
| Testas | 100000 įrašų | 1000000 įrašų | 10000000 įrašų | 
| ------ | ------------ | ------------- | -------------- |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s | 1.1s |

Ši optimizacija geriausiai veikia su vector konteineriais dėl jo savybių, tačiau šiek tiek praverčia ir deque. Pažymėtina, kad list geriau veikia su 3 strategija, nes std::partition nėra efektyvus be random access galimybių.

*v1.1*

Nuo šios versijos buvo paliktos tik efektyviausios strategijos, remiantis viršuje nurodyta analize. Nuo šios versijos buvo atlikta realizacija su klasėmis, apačioje bus aprašta analizė, lyginanti struktūros ir klasės veikimo laiku skirtumus, taikant "vector" konteinerį. Taip pat bus atliekamas flag'ų optimizacijos tyrimas.

"Struct" realizacija
| Testas | 100000 įrašų | 1000000 įrašų |
| ------ | ------------ | ------------- |
| Duomenų nuskaitymas | 0.2s | 1.3s |
| Rūšiavimas pagal parinktį | < 0.1s | 0.3s |
| Rezultatų spausdinimas | 0.5s | 5.1s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s |
| Surūšiuotų studentų išvedimas į failą | 0.4s | 3.9s |
| Bendras vidutinis programos veikimo laikas | 1.1s | 10.8s |


"Class" realizacija
| Testas | 100000 įrašų | 1000000 įrašų |
| ------ | ------------ | ------------- |
| Duomenų nuskaitymas | 0.2s | 1.3s |
| Rūšiavimas pagal parinktį | < 0.1s | 0.3s |
| Rezultatų spausdinimas | 0.5s | 5.0s |
| Studentų rūšiavimas į 2 grupes | < 0.1s | 0.1s |
| Surūšiuotų studentų išvedimas į failą | 0.4s | 3.9s |
| Bendras vidutinis programos veikimo laikas | 1.1s | 10.7s |

Taigi, spartos skirtumo tarp strukūros ir klasių implementacijų nėra.

*Flag'ų testavimas*   
Testavimui bus naudojamas 1000000 įrašų failas, balansuojant didelę duomenų apimtį ir rezultatų patikimumą.


| Testas | O1 | O2 | O3 | Be "flag" |
| ------ | ------------ | ------------- | -------------- | ---------|
| Bendras vidutinis programos veikimo laikas | 11.5s | 11.8s | 11.2s| 16.0s |
| .exe failo dydis | 249KB | 249KB | 288KB| 401KB |   

Taigi, matoma, kad optimizavimo flag'ai yra efektyvus būdas pagerinti programos spartą ir dydį.     

Programos dokumentacija programuotojams (nuo v1.2): 
---------------------------------------------------

Jūsų patogumui, nuo v1.2 dokumentaciją įtraukiama naudojimosi instrukcija programuotojams. 
v1.2: 
- Pagrindinė klasė Studentas turi visus reikiamus metodus darbui su studentais.
- Įvedimui yra sukurti metodai, leidžiantis duomenis įvesti rankiniu būdų, generuojant tam tikras dalis arba automatiškai nuskaitant nuo failo. Taip pat, perdengtas įvedimo operatorius >> leidžia įvesti vardą, pavardę ir egzamino įvertinimą
- Išvedimui sukurtos funkcijos spausdinimas.cpp faile. Taip pat, perdengtas operatorius << leidžia spausdinti studento vardą, pavardę bei galutinius paskaičiuotus įvertinimus.
- Pagrindinė programos eiga pasirenkama main.cpp, įvedus vartotojui.

 
Lentelės, apibendrinančios įvedimo/išvedimo rekomendacijas:   

Įvedimas:
| Norimas būdas įvesti duomenis | Metodas/Funkcija |
| ------ | ------------ |
| Rankinis įvedimas | ivedimas_ranka() |
| Generavimas tam tikrų duomenų | ivedimas_pazymiu_generavimu() / ivedimas_generuojant_viska() |
| Automatinis (iš failo) | ivedimas_failu() (failu_funkcijos.cpp) |
| Per >> operatorių | Perdengtas >> operatorius, leidžiantis įvesti var_, pav_, egz_ |


Išvedimas:
| Norimas būdas išvesti duomenis | Metodas/Funkcija |
| ------ | ------------ |
| Spausdinti tik vieną iš galutinių | spaudsdinimas_atskirai() |
| Spausdinti abiejų galutinių | spaudsdinimas_kartu() |
| Per << operatorių | Perdengtas << operatorius, leidžinatis spausdinti var_, pav_, galutinis_pagal_vid ir galutinis_pagal_med |  


Pastaba: Pasirinkimas tarp išvedimo į ekraną ar į failą yra pateikiamas vartotojui programos vykdymo metu. Visos pateikots funkcijos veikia su bet kokiu Output stream'u.
#### Testavimas

Buvo sukurti testai ištestuoti rule of five ir perdengtus įvesties išvesties operatorius. Juos rasite test_studentas.cpp faile (Žemiau pateiktos nuotraukos)   
![image](https://github.com/user-attachments/assets/f8bc94a6-9c7f-43af-b43a-a14f428b0fe0)

![image](https://github.com/user-attachments/assets/f441c390-9d5b-48e5-a336-98bc9c269b10)

##### V1.5   
Buvo sukurta bazinė klasė Zmogus. Iš jos Studentas yra derived klasė. Zmogus yra abstrakčioji klasė (demonstracija apačioje). Programa ir testai veikia identiškai kaip v1.2. Taip pat, patogomui buvo sukurtas make testavimui.
![image](https://github.com/user-attachments/assets/fc018f87-13c5-4317-b332-b15439fafb8b)      

     
![image](https://github.com/user-attachments/assets/5d7d3eb8-6775-43e5-b68c-bdfad544bbb6)


Nuosavas Vector konteineris (V3.0): 
---------------------------------------------------
Versijoje 3.0 buvo sukurtas nuosavas Vector konteineris. Funkcionalumo prasme atitinka apie 90-100% STL vector. Pagrindinės member funkcijos pristatomos apačioje (Su visa klase galite susipažinti dokumentacijoje, pateiktoje po funkcijų aprašais):
* Default konsturktorius\
![image](https://github.com/user-attachments/assets/9c7370cf-7013-4f70-9a53-8b5feaffd87a)
* Init list\
![image](https://github.com/user-attachments/assets/75bc4b14-f215-4c71-b665-2029d05d391c)
* Destruktorius\
![image](https://github.com/user-attachments/assets/937a0fd6-a28b-4ca1-bc4f-b14c2fb07645) 
* Copy assign\
![image](https://github.com/user-attachments/assets/741d66ff-6426-466a-8968-8749709df113)  
* Iteratoriai\
![image](https://github.com/user-attachments/assets/06266c99-0365-411d-81b9-2172ec4ed78d) 
* Capacity\
![image](https://github.com/user-attachments/assets/4e6fbbeb-efa8-42d4-9cd9-83a13738f4a7)
* Element access\
![image](https://github.com/user-attachments/assets/148844d1-c5ae-4e52-83c4-503bf291b476)  
* Modifiers. Naudojant push_back, skirtingai nei STL vector, reserve capacity growth faktorius pakeistas į 10. Dėl šio pasirinkimo plačiau komentuojama prie optimizavimo skilties.\
![image](https://github.com/user-attachments/assets/2cf2fd70-6544-4205-8932-50acf1eb2772)  
* Non-member funkcijos. Šioje vietoje buvo nuspręsta neįtraukti palyginimo (<, >, etc) operatorių, nes nuo C++20 jie buvo pašalinti ir iš STL vector. Skirtingai nei STL vector, buvo pridėtas output galimybė  naudojant operatorių << (Išvedimas, kaip Python kalbos list)\
![image](https://github.com/user-attachments/assets/2fcb05e6-ae5e-4ef5-96bd-a940d31c827b)    

*Testavimas*
Taip pat buvo parašyti testai naudojant Catch klasės funkcionalumui testuoti. 
![image](https://github.com/user-attachments/assets/0f0f27af-6d3f-488b-9a2c-e05bbceebee2)


Kilus klausimams ar pastaboms, susisiekti el. paštu: valentinas.samatovicius@mif.stud.vu.lt
