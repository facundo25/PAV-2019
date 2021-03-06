#ifndef DTGATO_H
#define DTGATO_H

#include "../dataType/DtMascota.h"


class DtGato : public DtMascota {

private:
	TipoPelo tipopelo;

public:
    DtGato();
	DtGato(string, Genero, float, float, TipoPelo);
	~DtGato();

	TipoPelo getTipoPelo();

	friend ostream& operator<<(ostream &os, DtGato&);
};

#endif /* DTGATO_H */
