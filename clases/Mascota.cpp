#include "./Mascota.h"
#include "../enum/Genero.h"
#include <iostream>

using namespace std;

Mascota::Mascota(){}

Mascota::Mascota(string nombre, Genero genero, float peso){

    this->nombre=nombre;
    this->genero=genero;
    this->peso=peso;
}

string Mascota::getNombre(){

    return this->nombre;
}
void Mascota::setNombre(string nombre){
    this->nombre=nombre;
}

Genero Mascota::getGenero(){
    return this->genero;
}

void Mascota::setGenero(Genero genero){
    this->genero=genero;
}

float Mascota::getPeso(){
    return this ->peso;
}

void Mascota::setPeso(float peso){
    this->peso=peso;
}

Mascota::~Mascota(){};
