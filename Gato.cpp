//
// Created by gsoto on 25/03/2019.
//
#include "Gato.h"
#include "TipoPelo.h"
#include <iostream>

Gato::Gato(){}

Gato::Gato(TipoPelo tipoPelo){
    this->tipoPelo=tipoPelo;
}

TipoPelo Gato::gettipoPelo() {
    return this->tipoPelo;
}

void Gato::settipoPelo(TipoPelo tipoPelo) {
    this->tipoPelo=tipoPelo;
}

Gato::~Gato(){}
