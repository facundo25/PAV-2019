#include "./DtPerro.h"
#include "../enum/RazaPerro.h"

DtPerro::DtPerro() {}
DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCacchorro) : DtMascota(nombre, genero, peso, racionDiaria){
	this->raza = raza,
	this ->vacunaCachorro = vacunaCachorro ;
}

DtPerro::~DtPerro(){

}

ostream &operator << (ostream &salida, DtPerro& dtPerro) {
    string stringRazaPerro;
    if (dtPerro.getRazaPerro()== labrador){
        stringRazaPerro= "labrador";
    } else if(dtPerro.getRazaPerro()== ovejero){
        stringRazaPerro="ovejero";
    }else if(dtPerro.getRazaPerro()== bulldog){
        stringRazaPerro= "bulldog";
    }else if(dtPerro.getRazaPerro()==pitbull){
        stringRazaPerro = "pitbull";
    }else if(dtPerro.getRazaPerro()==collie){
        stringRazaPerro="collie";
    }else if(dtPerro.getRazaPerro()==pekines){
        stringRazaPerro="pekines";
    }else if(dtPerro.getRazaPerro()==otro){
        stringRazaPerro="otro";
    }

    salida <<
        "Nombre: " << dtPerro.nombre << "\n" <<
        "Genero: " << dtPerro.genero << "\n"<<
        "Peso: " << dtPerro.peso << "\n"<<
        "Racion diaria: " << dtPerro.racionDiaria << "\n"<<
        "Raza: " << stringRazaPerro<< "\n"<<
        "Tiene vacuna: " <<dtPerro.vacunaCachorro <<endl;
    return salida;
}

RazaPerro DtPerro::getRazaPerro(){
	return this->raza;
}

bool DtPerro::getVacunaCachorro(){
return this->vacunaCachorro;
}
