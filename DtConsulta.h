#ifndef DTCONSULTA_H
#define DTCONSULTA_H


#include <string>
#include <iostream>

using namespace std;

class DtConsulta {

private:
	DtFecha fechaconsulta;
	string motivo;

public:
	DtConsulta();
	DtConsulta(DtFecha, string);
	DtFecha getfechaConsulta();
	string getmotivo();

	void setfechaConsulta(DtFecha);
	void setmotivo(string);

	~DtConsulta();
};

#endif
