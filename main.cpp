//
// Created by yoka on 21/03/19.
//
#include <iostream>
#include <stdio.h>
#include <dataType/DtMascota.h>
#include <dataType/DtGato.h>
#include <dataType/DtPerro.h>
#include "clases/Socio.h"
#include "dataType/DtFecha.h"
#include "clases/Gato.h"
#include "clases/Perro.h"
#include "clases/Consulta.h"
#include "clases/Mascota.h"

#define MAX_SOCIOS 10
#define MAX_MASCOTAS 10

using namespace std;

struct socios{ //coleccion de socios

    Socio* socios[MAX_SOCIOS];
    int tope;
}coleccionSocios;

struct mascotas{

    Mascota *mascotas[MAX_MASCOTAS];
    int tope;
}coleccionMascotas;

void registrarSocio(string ci, string nombre, DtMascota& dtMascota);


int main(){

    system("clear");

    int opcion  = 0;





    while(opcion != 99) {

        cout << "---------------------------------------" << endl;
        cout << "--PROGRAMACIÓN AVANZADA - LABORATORIO 0" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Registrar socio" << endl;
        cout << "2. Agregar mascota" << endl;
        cout << "3. Ingresar consulta" << endl;
        cout << "4. Ver consultas anteriores a fecha..." << endl;
        cout << "5. Eliminar socio" << endl;
        cout << "6. Consultar mascotas de un socio" << endl;
        cout << "99. Salir" << endl << endl;

        cout << "Ingrese opción: ";
        cin >> opcion;

        cout << "---------------------------------------" << endl;
        coleccionSocios.tope=2;
        switch (opcion) {

            case 1 : {
                //verificar tope de socios
                if (coleccionSocios.tope == MAX_SOCIOS) {
                    //no puede agregar
                } else {
                    cout << "ingresar ci";
                    string ci;
                    cin >> ci;
                    cout << "ingrese nombre";
                    string nombre;
                    cin >> nombre;
                    cout << "ingrese nombre de la mascota";
                    string nombreMascota;
                    cin >> nombreMascota;
                    cout << "ingrese genero (1.hembra 2.macho)"; //hacer while con seleccion de genero correcta
                    int genero;
                    cin >> genero;
                    Genero generoSeleccionado;
                    switch (genero) {
                        case 1: {
                            generoSeleccionado = Hembra;
                            break;
                        }
                        case 2: {
                            generoSeleccionado = Macho;
                            break;
                        }
                    }
                    cout << "ingrese peso";
                    float peso;
                    cin >> peso;
                    cout << "Seleccione 1 para ingresar perro, 2 para ingresar gato?";
                    int seleccionMascota;
                    cin >> seleccionMascota;
                    if (seleccionMascota == 1) {
                        RazaPerro raza;
                        cout << "ingrese raza (mire las opciones del 1 al 8";
                        int seleccionRaza;
                        cin >> seleccionRaza;
                        switch (seleccionRaza) {
                            case 1: {
                                raza = labrador;
                                break;
                            }
                            case 2: {
                                raza = ovejero;
                                break;
                            }
                            case 3: {
                                raza = bulldog;
                                break;
                            }

                        }
                        cout << "El perro tiene vacuna, 1 si 2 no?";
                        int seleccionVacuna;
                        cin>> seleccionVacuna;
                        bool tieneVacuna;
                        if (seleccionVacuna == 1) {
                            tieneVacuna = true;
                        } else {
                            tieneVacuna = false;
                        }

                        DtPerro dtPerro = DtPerro(nombreMascota, generoSeleccionado, peso, 0, raza, tieneVacuna);
                        registrarSocio(ci, nombre, dtPerro);


                    } else {

                        cout << "Que tipo de pelo tiene? seleccione 1 corto, 2 mediano, 3 largo";
                        int seleccionPelo;
                        cin>> seleccionPelo;
                        TipoPelo tipopelo;
                        switch (seleccionPelo) {
                            case 1: {
                                tipopelo = Corto;
                                break;
                            }
                            case 2: {
                                tipopelo = Mediano;
                                break;
                            }
                            case 3: {
                                tipopelo = Largo;
                                break;
                            }
                        }


                    }
                    break;
                }


                case 2 : {

                    break;

                }

                case 3 : {

                    break;

                }

                case 4 : {

                    break;

                }

                case 5: {

                    break;

                }

                case 6: {

                    break;

                }

                case 99: {

                    break;

                }

                default: {

                    cout << endl << "Opcion no contemplada.";
                    break;

                }

            }

        }

    }

    Socio s= Socio();
    return 0;
};

///FUNCIONES


void registrarSocio(string ci, string nombre, DtMascota& dtMascota){


    Socio * nuevoSocio = new Socio(ci, nombre);
    coleccionSocios.tope++;
    coleccionSocios.socios[coleccionSocios.tope]=nuevoSocio;

    try {
        DtGato& dtgato = dynamic_cast<DtGato&>(dtMascota);
        Gato* nuevoGato= new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(),dtgato.getTipoPelo());
        nuevoSocio->agregarMascota(nuevoGato);

    }catch(std::bad_cast){
        try{
            DtPerro& dtperro = dynamic_cast<DtPerro&>(dtMascota);
            Perro* nuevoPerro= new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRazaPerro(), dtperro.getVacunaCachorro());
            nuevoSocio->agregarMascota(nuevoPerro);
        }
        catch(std::bad_cast) {
            cout << "Error\n";
        }
    }
}




/* ****** FUNCIÓN EXISTE SOCIO ****** */
/*
void existeSocio (string ci){
    int indice = 0;
    bool existe = false ;
    while (existe == false && indice < coleccionSocios.tope ){
        if (coleccionSocios.socios[indice]->getCi() == ci) {
            existe = true;
        } else {
            indice +1;
        }

    }
    if (!existe)
        throw invalid_argument("\n No existe socio");
}

*/
/* FUNCIÓN AGREGAR MASCOTA */
/*
void agregarMascota (string ci, DtMascota& dtMascota){
    try {
        existesocio(ci);
        if (esPerro){
            try {
                DtPerro& perro = dynamic_cast<DtPerro&> (mascota);
                Perro* nuevoPerro = new Perro(perro);
                coleccionMascotas.mascotas[coleccionMascotas.tope] = nuevoPerro;
                coleccionMascotas.tope++;
                cout << "\n Se agregó mascota del tipo Perro al socio indicado \n";

            }catch (std::bad_cast) {
                cout << "Error en el cast DtPerro \n";
            }

        }
        else if (esGato) {
            try {
                DtGato& gato = dynamic_cast<DtGato&> (mascota);
                Gato* nuevoGato = new Gato(gato);
                coleccionMascotas.mascotas[coleccionMascotas.tope] = nuevoGato;
                coleccionMascotas.tope++;
                cout << "\n Se agregó mascota del tipo Gato al socio indicado \n";

            }catch (std::bad_cast) {
                cout << "Error en el cast DtGato \n";
            }
        }

    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}
*/




////END FUNCIONES
