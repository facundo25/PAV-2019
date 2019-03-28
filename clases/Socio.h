//
// Created by yoka on 21/03/19.
//

#ifndef OBLIGATORIO0_SOCIO_H
#define OBLIGATORIO0_SOCIO_H

#include "dataType/DtFecha.h"
#include "Mascota.h"
#include "Consulta.h"
#include <iostream>

using namespace std;

class Socio {
private:
    string ci;
    string nombre;
    DtFecha fechaIngreso;
    arrayMascota Mascotas;
    arrayConsulta Consultas;

public:
    Socio();

    Socio(string, string, DtFecha);

    string getCi();

    void setCi(string);

    string getNombre();

    void setNombre(string);

    DtFecha getFechaIngreso();

    void setFechaIngreso(DtFecha);

    Mascota* getMascota(int PosMas);

    void setMascota(int PosMas, Mascota* Mascota);

    Consulta* getConsulta(int PosCon);

    void setConsulta(int PosCon, Consulta* Consulta);

    ~Socio();

};


#endif //OBLIGATORIO0_SOCIO_H
