//
// Created by gsoto on 25/03/2019.
//

#ifndef PAV_2019_GATO_H
#define PAV_2019_GATO_H
#include <iostream>
#include "../enum/TipoPelo.h"
#include "../enum/Genero.h"
#include "Mascota.h"
using namespace std;

class Gato : public Mascota {
private:
    TipoPelo tipoPelo;


public:
    Gato();

    Gato(string,Genero,float,TipoPelo);

    TipoPelo gettipoPelo();
    void settipoPelo(TipoPelo);

    float obtenerRacionDiaria();

    virtual ~Gato();

};

#endif //PAV_2019_GATO_H
