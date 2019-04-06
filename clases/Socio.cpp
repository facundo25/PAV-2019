//
// Created by yoka on 14/03/19.
//
#include "./Socio.h"
#include "../dataType/DtFecha.h"
#include <iostream>

Socio::Socio() {}

Socio::Socio(string ci, string nombre) {
    this -> ci = ci;
    this -> nombre = nombre;
    DtFecha dtFecha=DtFecha(4,3,1990);
    this -> fechaIngreso = dtFecha;
    this -> topeConsulta = 0;
    this -> topeMascota = 0;
}

string Socio::getCi(){
    return this ->ci;
}
void Socio::setCi(string ci) {
    this -> ci = ci;
}

string Socio::getNombre(){
    return this -> nombre;
}
void Socio::setNombre(string nombre) {
    this ->nombre=nombre;

}
DtFecha Socio::getFechaIngreso() {
    return this -> fechaIngreso;
}

void Socio::setFechaIngreso(DtFecha fechaIngreso) {

    this ->fechaIngreso=fechaIngreso;
}

Mascota ** Socio::getMascotas(int &cantMasc){

    cantMasc= this-> topeMascota;
    return  this->arrayMascota;

}

Consulta ** Socio::getConsultas(int &canCon) {

    canCon= this-> topeConsulta;
    return  this-> arrayConsulta;

}

void Socio::agregarMascotaSocio(Mascota * mascota) {
    this -> arrayMascota[this->topeMascota]=mascota;
    this -> topeMascota++;

}


void Socio::ingresarConsulta(Consulta * consulta) {

    this -> arrayConsulta[this->topeConsulta]=consulta;
    this -> topeConsulta++;

}

Socio::~Socio(){}

int Socio::getTopeMascota() {

    return this->topeMascota;

}

int Socio::getTopeConsulta() {

    return this->topeConsulta;

}
