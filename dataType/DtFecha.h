    //
// Created by yoka on 21/03/19.
//

#ifndef OBLIGATORIO0_DTFECHA_H
#define OBLIGATORIO0_DTFECHA_H


using namespace std;

#include <iostream>

class DtFecha  {
private:
    int dia;
    int mes;
    int ano;
public:
    DtFecha();
    DtFecha(int, int, int);

    int getdia();
    void setdia(int);

    int getmes();
    void setmes(int);

    int getano();
    void setano(int);

    ~DtFecha();

    friend bool operator< (DtFecha& dtFecha1, DtFecha& dtFecha2 );

};


#endif //OBLIGATORIO0_DTFECHA_H
