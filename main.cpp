//
// Created by yoka on 21/03/19.
//
#include <iostream>
#include <stdio.h>
#include "Socio.h"
#include "DtFecha.h"
#include "Gato.h"
#include "Perro.h"
#include "Consulta.h"
#include "Mascota.h"
#define MAX_SOCIOS 10

int main(){

    struct socios{

        Socio* socios[MAX_SOCIOS];
        int tope;
    }coleccionSocios;


    Socio s= Socio();
    return 0;
};