//
// Created by gsoto on 25/03/2019.
//

#ifndef PAV_2019_GATO_H
#define PAV_2019_GATO_H
#include <iostream>
#include "TipoPelo.h"
#include "Mascota.h"
using namespace std;

class Gato : Mascota {
private:
    TipoPelo tipoPelo;


public:
    Gato();
    Gato(string,Genero,float,TipoPelo);
    TipoPelo gettipoPelo();
    void settipoPelo(TipoPelo);

    ~Gato();

    float obtenerRacionDiaria();

};

#endif //PAV_2019_GATO_H
