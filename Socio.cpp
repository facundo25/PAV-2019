//
// Created by yoka on 14/03/19.
//
#include "Socio.h"
#include "DtFecha.h"
#include <iostream>

Socio::Socio() {}

Socio::Socio(string ci, string nombre, DtFecha fechaIngreso) {
    this -> ci = ci;
    this -> nombre = nombre;
    this -> fechaIngreso = fechaIngreso;
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

Mascota * Socio::getMascota(int PosMas){

    return this-> Mascotas.m[PosMas];

}

void Socio::setMascota(int PosMas, Mascota* Mascota){

    this -> Mascotas.m[PosMas] = Mascota;

}

Consulta* Socio::getConsulta(int PosCon){

    return this -> Consultas.c[PosCon];

}

void Socio::setConsulta(int PosCon, Consulta* Consulta){

    this -> Consultas.c[PosCon] = Consulta;

}

Socio::~Socio(){}
