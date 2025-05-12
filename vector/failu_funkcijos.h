#ifndef APDOROJIMO_H
#define APDOROJIMO_H

#include "studentas.h"
#include "spausdinimo_export.h"
int rasti_nd_skaiciu_faile(ifstream& fd);
void buferio_apdorojimas(Vector <Studentas> &grupe, size_t buffer_size, Vector <char> &buffer, ifstream &fd, int nd_sk);
void failo_generavimas(ifstream &fd);
void failo_pav_gavimas(ifstream &fd);
void ivedimas_failu(Vector <Studentas> &grupe);
#endif