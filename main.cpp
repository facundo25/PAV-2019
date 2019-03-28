//
// Created by yoka on 21/03/19.
//
#include <iostream>
#include <stdio.h>
#include "clases/Socio.h"
#include "dataType/DtFecha.h"
#include "clases/Gato.h"
#include "clases/Perro.h"
#include "clases/Consulta.h"
#include "clases/Mascota.h"
#define MAX_SOCIOS 10

using namespace std;

int main(){

    system("clear");

    int opcion  = 0;

    struct socios{

        Socio* socios[MAX_SOCIOS];
        int tope;
    }coleccionSocios;

    while(opcion != 99){

        cout << "---------------------------------------" << endl;
        cout << "--PROGRAMACIÓN AVANZADA - LABORATORIO 0" << endl;
        cout << "---------------------------------------" << endl;
        cout <<"1. Registrar socio" << endl;
        cout <<"2. Agregar mascota" << endl;
        cout <<"3. Ingresar consulta" << endl;
        cout <<"4. Ver consultas anteriores a fecha..." << endl;
        cout <<"5. Eliminar socio" << endl;
        cout <<"6. Consultar mascotas de un socio" << endl;
        cout <<"99. Salir" << endl << endl;

        cout << "Ingrese opción: ";
        cin >> opcion;

        cout << "---------------------------------------" << endl;

        switch(opcion){

            case 1 :{

                break;

            }

            case 2 :{

                break;

            }

            case 3 :{

                break;

            }

            case 4 :{

                break;

            }

            case 5:{

                break;

            }

            case 6:{

                break;

            }

            case 99:{

                break;

            }

            default:{

                cout << endl << "Opcion no contemplada.";
                break;

            }

        }

    }

    Socio s= Socio();
    return 0;
};