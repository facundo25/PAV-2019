//
// Created by gsoto on 25/03/2019.
//
#include "Consulta.h"
#include "dataType/DtFecha.h"
#include <iostream>

Consulta::Consulta(){}

Consulta::Consulta(DtFecha fechaConsulta, string motivo){
    this->fechaConsulta=fechaConsulta;
    this->motivo=motivo;
};

DtFecha Consulta::getfechaConsulta() {
    return this->fechaConsulta;
}
void Consulta::setfechaConsulta(DtFecha fechaConsulta)  {

    this ->fechaConsulta=fechaConsulta;
}

string Consulta::getmotivo(){
    return this->motivo=motivo;
}

void Consulta::setmotivo(string motivo) {
    this->motivo=motivo;
}



Consulta::~Consulta(){}