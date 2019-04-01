//
// Created by gsoto on 25/03/2019.
//

#ifndef PAV_2019_CONSULTA_H
#define PAV_2019_CONSULTA_H
#include "dataType/DtFecha.h"
#include <iostream>

using namespace std;

class Consulta{
private:
    DtFecha fechaConsulta;
    string motivo;

public:
    Consulta();

    Consulta(DtFecha, string);
    DtFecha getfechaConsulta();
    void setfechaConsulta(DtFecha);
    string getmotivo();
    void setmotivo(string);

    ~Consulta();

};
/*
struct arrayConsulta
{

    Consulta *c[20];
    int Tope;

}coleccionDeConsultas;
*/
#endif //PAV_2019_CONSULTA_H
