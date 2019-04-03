#include "DtFecha.h"
#include <iostream>

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

bool operator< (DtFecha& dtFecha1, DtFecha& dtFecha2 ) {

    if(dtFecha1.getano() < dtFecha2.getano()) {

        return true;

    }else if(dtFecha1.getano() == dtFecha2.getano()){

        if (dtFecha1.getmes() < dtFecha2.getmes()) {

            return true;

        } else if(dtFecha1.getmes() == dtFecha2.getmes()){

            if (dtFecha1.getdia() < dtFecha2.getdia()) {

                return true;

            } else {

                return false;

            }

        }else{return false;}

    }else{return false;}

}