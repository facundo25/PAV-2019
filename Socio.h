//
// Created by yoka on 21/03/19.
//

#ifndef OBLIGATORIO0_SOCIO_H
#define OBLIGATORIO0_SOCIO_H

#include "DtFecha.h"
#include <iostream>

using namespace std;

class Socio {
private:
    string ci;
    string nombre;
    DtFecha fechaIngreso;
public:
    Socio();

    Socio(string, string, DtFecha);

    string getCi();

    void setCi(string);

    string getNombre();

    void setNombre(string);

    DtFecha getFechaIngreso();

    void setFechaIngreso(DtFecha);

    ~Socio();
};


#endif //OBLIGATORIO0_SOCIO_H
