#include "DtFecha.h"

DtFecha::DtFecha(){}

DtFecha::DtFecha (int dia, int mes, int ano){

    this -> dia=dia;
    this -> mes=mes;
    this -> ano=ano;
}
int DtFecha::getdia() {
    return this -> dia;
}
void DtFecha::setdia(int dia){
    this -> dia=dia;
}

int DtFecha::getmes() {
    return this -> mes;
}
void DtFecha::setmes(int mes){
    this -> mes=mes;
}

int DtFecha::getano() {
    return this -> ano;
}
void DtFecha::setano(int ano) {
    this->ano = ano;
}
DtFecha::~DtFecha(){}