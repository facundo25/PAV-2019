/*
 * dtmascota.h
 *
 *  Created on: 21 mar. 2019
 *      Author: Facundo
 */

#ifndef DTMASCOTA_H
#define DTMASCOTA_H

#include <string>
#include <iostream>

using namespace std;

class DtMascota {
private:
	string nombre;
	Genero genero;
	float peso;
	float racionDiaria;
	
public:
	DtMascota();
	DtMascota(string, Genero, float, float);

	string getNombre();
	genero getGenero();
	float getPeso();
	float getRacionDiaria();

	void setNombre(string);
	void setGenero(Genero);
	void setPeso(float);
	void setRacionDiaria(float);

	virtual ~DtMascota();

};

#endif /* DTMASCOTA_H */
