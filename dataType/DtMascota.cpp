/*
 * DtMascota.cpp
 *
 *  Created on: 21 mar. 2019
 *      Author: Facundo
 */

#include "DtMascota.h"

DtMascota::DtMascota() {

}

DtMascota::DtMascota(string nombre,Genero genero, float peso, float racionDiaria){
	this-> nombre = nombre;
	this-> genero = genero;
	this-> peso = peso;
	this-> racionDiaria = racionDiaria;
}

string DtMascota::getNombre(){
	return this->nombre;
}

Genero DtMascota::getGenero(){
	return this->genero;
}

float DtMascota::getPeso(){
	return this->peso;
}

float DtMascota::getRacionDiaria(){
	return this->racionDiaria;
}
DtMascota::~DtMascota(){

}
ostream& operator << (ostream &salida, DtMascota& dtMascota) {
    salida <<
                     "Nombre: " << dtMascota.nombre <<"\n"<<
                     "Genero: " << dtMascota.genero <<"\n"<<
                     "Peso: " << dtMascota.peso <<endl;
    return salida;

}