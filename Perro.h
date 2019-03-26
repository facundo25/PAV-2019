//
// Created by gsoto on 25/03/2019.
//

#ifndef PAV_2019_PERRO_H
#define PAV_2019_PERRO_H
#include <iostream>
#include "RazaPerro.h"
#include "Mascota.h"
using namespace std;

class Perro : public Mascota{
private:
    RazaPerro raza;
    bool vacunaCachorro;


public:
    Perro();
    Perro(RazaPerro, bool);
    RazaPerro getraza();
    void setraza(RazaPerro);
    bool getvacunaCachorro();
    void setvacunaCachorro(bool);

    ~Perro();

    float obtenerRacionDiaria();
};



#endif //PAV_2019_PERRO_H

