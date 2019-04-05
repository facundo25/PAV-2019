//
// Created by gsoto on 25/03/2019.
//
#include "../clases/Gato.h"
#include "../enum/TipoPelo.h"
#include "../clases/Mascota.h"
#include "../enum/Genero.h"
#include <iostream>

Gato::Gato(){}

Gato::Gato(string nombre, Genero genero,float peso,TipoPelo tipoPelo):Mascota (nombre, genero, peso){
    this->tipoPelo=tipoPelo;
}

TipoPelo Gato::gettipoPelo() {
    return this->tipoPelo;
}

void Gato::settipoPelo(TipoPelo tipoPelo) {
    this->tipoPelo=tipoPelo;
}

float Gato::obtenerRacionDiaria() {

    return this->getPeso() * 0.015;

}

Gato::~Gato(){}
