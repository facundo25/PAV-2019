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
    Mascota* arrayMascota[10];
    int topeMascota;
    Consulta* arrayConsulta[20];
    int topeConsulta;

public:
    Socio();

    Socio(string, string);

    string getCi();

    void setCi(string);

    string getNombre();

    void setNombre(string);

    DtFecha getFechaIngreso();

    void setFechaIngreso(DtFecha);

    Mascota** getMascotas(int &cantMasc);

    Consulta** getConsultas(int &canCon);

    int getTopeMascota();

    int getTopeConsulta();


    ~Socio();

    void agregarMascota(Mascota*);

    void ingresarConsulta(Consulta*);

};


#endif //OBLIGATORIO0_SOCIO_H
