#ifndef DTPERRO_H_INCLUDED
#define DTPERRO_H_INCLUDED

#include "DtMascota.h"

class DtPerro : public DtMascota {

private:
	RazaPerro raza;
	bool vacunaCachorro;

public:
	DtPerro(string, Genero, float, float, RazaPerro, bool);
	~DtPerro();

	RazaPerro getRazaPerro();
	bool getVacunaCachorro();

	friend ostream& operator<<(ostream &os, DtPerro&);
};


#endif // DTPERRO_H_INCLUDED
