#include "DtConsulta.h"
#include "DtFecha.h"
#include <iostream>

DtConsulta::DtConsulta(){}
DtConsulta::DtConsulta (DtFecha fechaConsulta, string motivo){

    this->fechaconsulta=fechaConsulta;
    this->motivo=motivo;

}

DtConsulta::~DtConsulta(){

}

DtFecha DtConsulta::getfechaConsulta(){
    return this->fechaconsulta;
}

string DtConsulta::getmotivo(){
    return this->motivo;
}

