//
// Created by gsoto on 25/03/2019.
//

#include "Perro.h"
#include "RazaPerro.h"
#include <iostream>

Perro::Perro():Mascota(){}

Perro::Perro(RazaPerro raza, bool vacunaCachorro): Mascota(/*as,AS,as*/){
    this->raza=raza;
    this->vacunaCachorro=vacunaCachorro;
}

RazaPerro Perro::getraza() {
    return this->raza;
}

void Perro::setraza(RazaPerro raza) {
    this->raza=raza;
}

bool Perro::getvacunaCachorro() {
    return this->vacunaCachorro;
}

void Perro::setvacunaCachorro(bool vacunaCachorro) {
    this-> vacunaCachorro=vacunaCachorro;
}


float Perro::obtenerRacionDiaria() {}

Perro::~Perro(){}