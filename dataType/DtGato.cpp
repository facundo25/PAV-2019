#include "DtGato.h"
//#include "enum/TipoPelo.h"
#include <iostream>

using namespace std;

DtGato::DtGato() {}

DtGato::DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipopelo) : DtMascota(nombre,
                                                                                                            genero,
                                                                                                            peso,
                                                                                                            racionDiaria) {
    this->tipopelo = tipopelo;
}

DtGato::~DtGato() {

}


TipoPelo DtGato::getTipoPelo() {
    return this->tipopelo;
}

ostream &operator<<(ostream &salida, DtGato &dtGato) {
    string stringTipoPelo;
    if (dtGato.getTipoPelo() == Corto) {
        stringTipoPelo = "Corto";
    } else if (dtGato.getTipoPelo() == Mediano) {
        stringTipoPelo = "Mediano";
    } else if (dtGato.getTipoPelo() == Largo) {
        stringTipoPelo = "Largo";
    } else {
        stringTipoPelo = "Sin definir";
    }


    salida <<
           "Nombre: " << dtGato.nombre << "\n" <<
           "Genero: " << dtGato.genero << "\n" <<
           "Peso: " << dtGato.peso << "\n" <<
           "Racion diaria: " << dtGato.racionDiaria
           << "\nTipoPelo: " << stringTipoPelo << endl;
    return salida;

}