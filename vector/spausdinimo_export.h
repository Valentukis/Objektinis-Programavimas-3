#pragma once

#include "Vector.hpp"
#include "studentas.h"

#ifdef SPAUSDINIMO_EXPORTS
#define SPAUSDINIMO_API __declspec(dllexport)
#else
#define SPAUSDINIMO_API __declspec(dllimport)
#endif

extern "C" {
    SPAUSDINIMO_API void spausdinimas_kartu(Vector<Studentas>& grupe, bool spausdinimas);
    SPAUSDINIMO_API void spausdinimas_atskiras(Vector<Studentas>& grupe);
    SPAUSDINIMO_API int eigos_parinktis();
}
