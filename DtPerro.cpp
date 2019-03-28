#include "DtPerro.h"
#include "RazaPerro.h"

DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCacchorro) : DtMascota(nombre, genero, peso, racionDiaria){
	this->raza = raza, this ->vacunaCachorro = vacunaCachorro ;
}

DtPerro::~DtPerro(){

}

ostream& operator << (ostream &salida, DtPerro& DtPerro) {
    salida <<
        "Nombre: " << DtPerro.nombre << "\n" <<
        "Genero: " << DtPerro.genero << "\n"
        "Peso: " << DtPerro.peso << "\n"
        "Racion diaria: " << DtPerro.racionDiaria << "\n"
            ;
    return salida;
}

RazaPerro DtPerro::getRazaPerro(){
	return this->raza;
}

bool DtPerro::getVacunaCachorro(){
return this->vacunaCachorro;
}