#ifndef DTPERRO_H
#define DTPERRO_H

#include <iostream>
#include "DtMascota.h"
#include "RazaPerro.h"

using  namespace std;

class DtPerro : public DtMascota {

private:
	RazaPerro raza;
	bool vacunaCachorro;

public:
	DtPerro();
	DtPerro(string, Genero, float, float, RazaPerro, bool);
	~DtPerro();

	RazaPerro getRazaPerro();
	bool getVacunaCachorro();

	friend ostream& operator << (ostream &os, DtPerro&);
};


#endif // DTPERRO_H
