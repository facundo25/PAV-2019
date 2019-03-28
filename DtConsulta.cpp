#include "DtConsulta.h"
#include <iostream>


DtConsulta::DtConsulta (DtFecha fechaConsulta, string motivo)/*:DtConsulta(fechaConsulta, motivo)*/{ //aca comente esto porque da error, revisar


}

DtConsulta::~DtConsulta(){

}

DtFecha DtConsulta()::getfechaConsulta(){
    return this->fechaConsulta;
}

string DtConsulta()::getmotivo(){
    return this->motivo;
}

