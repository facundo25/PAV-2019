//
// Created by yoka on 21/03/19.
//

#ifndef OBLIGATORIO0_MASCOTA_H
#define OBLIGATORIO0_MASCOTA_H
#include <iostream>
#include "enum/Genero.h"

using namespace std;

class Mascota {

private:
    string nombre;
    Genero genero;
    float peso;

public:
    Mascota();
    Mascota(string, Genero, float);
    string getNombre();
    void setNombre(string);
    Genero getGenero();
    void setGenero(Genero);
    float getPeso();
    void setPeso(float);
    virtual float obtenerRacionDiaria() = 0;

    ~Mascota();


};

struct arrayMascota{

    Mascota *m[50];
    int Tope;

};

#endif //OBLIGATORIO0_MASCOTA_H
