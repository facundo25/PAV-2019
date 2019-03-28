//
// Created by gsoto on 25/03/2019.
//

#include "Perro.h"
#include "RazaPerro.h"
#include "Mascota.h"
#include <iostream>

Perro::Perro():Mascota(){}

Perro::Perro(string nombre, Genero genero, float peso, RazaPerro raza, bool vacunaCachorro): Mascota(nombre, genero, peso){
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


float Perro::obtenerRacionDiaria() {

//    float varPeso = this-> getPeso();
//    return varPeso * 0.025;

    return this-> getPeso() * 0.025;

}

Perro::~Perro(){}

