#include "DtPerro.h"
#include "enum/RazaPerro.h"

DtPerro::DtPerro() {}
DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCacchorro) : DtMascota(nombre, genero, peso, racionDiaria){
	this->raza = raza, this ->vacunaCachorro = vacunaCachorro ;
}

DtPerro::~DtPerro(){

}

ostream& operator << (ostream &salida, DtPerro& dtPerro) {
    salida <<
        "Nombre: " << dtPerro.nombre << "\n" <<
        "Genero: " << dtPerro.genero << "\n"<<
        "Peso: " << dtPerro.peso << "\n"<<
        "Racion diaria: " << dtPerro.racionDiaria << "\n"<<
        "Raza: " << dtPerro.raza << "\n"<<
        "Tiene vacuna: " <<dtPerro.vacunaCachorro <<endl;
    return salida;
}

RazaPerro DtPerro::getRazaPerro(){
	return this->raza;
}

bool DtPerro::getVacunaCachorro(){
return this->vacunaCachorro;
}
