#include "DtGato.h"
#include <iostream>

using namespace std;

DtGato::DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipopelo) : DtMascota(nombre, genero, peso, racionDiaria){
	this->tipopelo = tipopelo;
}

DtGato::~DtGato(){

}

TipoPelo DtGato::getTipoPelo(){
	return this->tipopelo;
}

ostream& operator << (ostream &salida, DtGato& dtGato) {
    string stringTipoPelo;
    if(dtGato.getTipoPelo() == 1){
        stringTipoPelo = "Corto";
    }
    else if (dtGato.getTipoPelo() == 2){
        stringTipoPelo = "Mediano";
    }
    else if (dtGato.getTipoPelo() == 3){
        stringTipoPelo = "Largo";
    }
    else{
        stringTipoPelo = "Sin definir";
    }

    salida <<
        "Nombre: " << dtGato.getNombre << "\n"<<
        "Genero: " << dtGato.getGenero() <<"\n" <<
        "Peso: " << dtGato.getPeso() <<"\n" <<
        "Ración Diaria" << dtGato.getRacionDiaria() <<"\n" <<
        "TipoPelo: " << stringTipoPelo << "\n" <<
    return salida;

}