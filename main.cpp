//
// Created by yoka on 21/03/19.
//
#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <dataType/DtMascota.h>
#include <dataType/DtGato.h>
#include <dataType/DtPerro.h>
#include <dataType/DtConsulta.h>
#include "dataType/DtFecha.h"
#include "dataType/DtConsulta.h"
#include "clases/Socio.h"
#include "clases/Gato.h"
#include "clases/Perro.h"
#include "clases/Consulta.h"
#include "clases/Mascota.h"


#define MAX_SOCIOS 10
#define MAX_MASCOTAS 10
#define  MAX_CONSULTAS 20

using namespace std;

struct socios { //coleccion de socios

    Socio *socios[MAX_SOCIOS];
    int tope;
} coleccionSocios;

struct mascotas {

    Mascota *mascotas[MAX_MASCOTAS];
    int tope;
} coleccionMascotas;

//*********** DEFINICION DE FUNCIONES***********

void registrarSocio(string ci, string nombre, DtMascota &dtMascota);
DtConsulta** verConsultaAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas);
//void ingresarCosnulta(string motivo, string ci);

//*********************************************

int main() {

    int opcion = 0;

    /*//TESTING - GSM 02/04/19 - Necesitaba un socio con una mascota para testear
    cout << "[TESTING] Agregando Socio-Mascota para test..." << endl;
    DtGato dtGatotest = DtGato("GATO1", Hembra, 10, 0, Corto);
    registrarSocio("123", "JUAN", dtGatotest);
    //---*/

    while (opcion != 99) {

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
        coleccionSocios.tope = 0;
        switch (opcion) {

            case 1 : {
                //verificar tope de socios
                if (coleccionSocios.tope == MAX_SOCIOS) {
                    //no puede agregar
                } else {

                    string ci;
                    string nombre;
                    string nombreMascota;
                    int genero;
                    Genero generoSeleccionado;
                    float peso;
                    int seleccionMascota;

                    bool selOK = false;

                    cout << "Ingrese CI: ";
                    cin >> ci;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    cout << "Ingrese nombre de la mascota: ";
                    cin >> nombreMascota;

                    while (!selOK) {

                        cout << "Ingrese genero (1.Hembra; 2.Macho): "; //hacer while con seleccion de genero correcta
                        cin >> genero;

                        switch (genero) {

                            case 1: {

                                generoSeleccionado = Hembra;
                                selOK = true;
                                break;

                            }
                            case 2: {

                                generoSeleccionado = Macho;
                                selOK = true;
                                break;

                            }
                            default: {

                                cout << "El genero seleccionado no es valido. Intente nuevamente" << endl;
                                break;

                            }

                        }
                    }

                    cout << "Ingrese peso: ";
                    cin >> peso;

                    selOK = false;

                    while(!selOK) {

                        cout << "Ingrese tipo de mascota (1.Perro; 2.Gato): ";
                        cin >> seleccionMascota;

                        switch (seleccionMascota) {

                            case 1: {

                                RazaPerro raza;
                                int seleccionRaza;
                                int seleccionVacuna;
                                bool tieneVacuna;

                                bool boolPerroOK = false;

                                while(!boolPerroOK) {

                                    cout << "Ingrese raza (1.Labrador; 2.Ovejero; 3.Bulldog; 4.Pitbull; 5.Collie; 6.Pekines; 7.Otro): ";
                                    cin >> seleccionRaza;

                                    switch (seleccionRaza) {

                                        case 1: {

                                            raza = labrador;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 2: {

                                            raza = ovejero;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 3: {

                                            raza = bulldog;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 4: {

                                            raza = pitbull;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 5: {

                                            raza = collie;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 6: {

                                            raza = pekines;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 7: {

                                            raza = otro;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        default: {

                                            cout << "La raza ingresada no es correcta. Ingrese nuevamente." << endl;
                                            break;

                                        }

                                    }
                                }

                                boolPerroOK = false;

                                while(!boolPerroOK) {

                                    cout << "El perro tiene vacuna? (1.Si; 2.No): ";
                                    cin >> seleccionVacuna;

                                    switch (seleccionVacuna){

                                        case 1:{

                                            tieneVacuna = true;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        case 2:{

                                            tieneVacuna = false;
                                            boolPerroOK = true;
                                            break;

                                        }

                                        default:{

                                            cout << "El valor ingresado para indicar si el perro tiene vacuna o no es incorrecto. Intentelo nuevamente." << endl;
                                            break;

                                        }

                                    }

                                }

                                DtPerro dtPerro = DtPerro(nombreMascota, generoSeleccionado, peso, 0, raza, tieneVacuna);
                                registrarSocio(ci, nombre, dtPerro);

                                selOK = true;

                                break;

                            }

                            case 2: {

                                int seleccionPelo;
                                TipoPelo tipopelo;

                                bool selGatoOK = false;

                                while(!selGatoOK){

                                    cout << "Que tipo de pelo tiene? (1.Corto; 2.Mediano; 3.Largo): ";
                                    cin >> seleccionPelo;

                                    switch (seleccionPelo) {

                                        case 1: {

                                            tipopelo = Corto;
                                            selGatoOK = true;
                                            break;

                                        }

                                        case 2: {

                                            tipopelo = Mediano;
                                            selGatoOK = true;
                                            break;

                                        }

                                        case 3: {

                                            tipopelo = Largo;
                                            selGatoOK = true;
                                            break;

                                        }
                                        default:{

                                            cout << "El valor de tipo de pelo seleccionado no es correcto. Intentelo nuevamente." << endl;
                                            break;

                                        }

                                    }

                                }

                                DtGato dtGato = DtGato(nombreMascota, generoSeleccionado, peso, 0, tipopelo);
                                registrarSocio(ci, nombre, dtGato);

                                selOK = true;

                                break;

                            }

                            default:{

                                cout << "El tipo de mascota seleccionada no es correcta. Intente nuevamente." << endl;
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

                    int dia, mes, anio, cantConsultas;
                    string ciSocio;

                    cout << "Ingrese la CI del socio a consultar: ";
                    cin >> ciSocio;

                    cout << endl << "Ingrese el dia: ";
                    cin >> dia;

                    cout << endl << "Ingrese el mes: ";
                    cin >> mes;

                    cout << endl << "Ingrese el anio: ";
                    cin >> anio;

                    cout << endl << "Ingrese la cantidad maxima de consultas a mostrar: ";
                    cin >> cantConsultas;

                    DtFecha *fecha = new DtFecha(dia, mes, anio);

                    DtConsulta **arregloConsulta = verConsultaAntesDeFecha(*fecha, ciSocio, cantConsultas);

                    int numConsulta = 0;
                    DtFecha DtFec;

                    //for (int i=0; i < cantSocios; i++)
                    for (int a=0; a <= cantConsultas; a++){

                        DtFec = arregloConsulta[a]->getfechaConsulta();
                        numConsulta = a + 1; //Hago esto porque el array empieza en cero, entonces la primera consulta se va a presentar "Consulta 0"

                        cout << endl << "Consulta " << numConsulta << ":";
                        cout << endl << "Fecha: " << DtFec.getdia() << "/" << DtFec.getmes() << "/" << DtFec.getano();
                        cout << endl << "Motivo: " << arregloConsulta[a]->getmotivo();


                    }



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

    Socio s = Socio();
    return 0;
};

///FUNCIONES

/* ****** FUNCIÓN EXISTE SOCIO ****** */

void registrarSocio(string ci, string nombre, DtMascota &dtMascota) {

    Socio *nuevoSocio = new Socio(ci, nombre);
    coleccionSocios.socios[coleccionSocios.tope] = nuevoSocio;

    coleccionSocios.tope++;


    try {
        DtGato &dtgato = dynamic_cast<DtGato &>(dtMascota);
        Gato *nuevoGato = new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(), dtgato.getTipoPelo());
        nuevoSocio->agregarMascota(nuevoGato);

    } catch (std::bad_cast &NombreVariable) {
        try {
            DtPerro &dtperro = dynamic_cast<DtPerro &>(dtMascota);
            Perro *nuevoPerro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(),
                                          dtperro.getRazaPerro(), dtperro.getVacunaCachorro());
            nuevoSocio->agregarMascota(nuevoPerro);
        }
        catch (std::bad_cast &NombreVariable) {
            cout << "Error\n";
        }
    }
}

/***********************************************************/

/********************* INGRESAR CONSULTA********************/

void ingresarConsulta(string motivo, string ci) {
    int contador = 0;
    bool encontrado = false;
    Socio * socio = NULL;
    while (!encontrado && contador < MAX_SOCIOS){
        if (coleccionSocios.socios[contador]->getCi() == ci) {
            //encontrado
            socio = coleccionSocios.socios[contador];
            encontrado = true;
        }
        contador++;
    }

    if(socio == NULL){
        throw invalid_argument("No existe el socio");
        //error
    }else{
        //agrego consulta
        DtFecha fecha = DtFecha(7,5,1991);
        Consulta *consulta = new Consulta(fecha,motivo);
        socio->ingresarConsulta(consulta);
    }
    
}

/************************************************************************************/


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

DtConsulta** verConsultaAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas){

    bool encontreSocio = false; //encontreSocio va a ser True si se encuentra el socio
    bool noCI = false;          //noCI sera True si se alcanza el tope de Socios, por lo tanto, si no se encontro el Socio por su CI
    bool finCons = false;       //Indicador de que llegue al tope de Consultas a cargar

    int cont = 0, contCons = 0; //Contadores para los whiles

    int cantCons = 0;

    int test = 1;

    Socio *Soc;

    cout << "flag 1" << endl;


    while( !encontreSocio && !noCI ){

        cout << "flag 2" << endl;

        //Busco socio
        if(coleccionSocios.socios[cont]->getCi() == ciSocio){

            cout << "flag 3" << endl;

            Soc = coleccionSocios.socios[cont];
            encontreSocio = true;

        }

        if(encontreSocio) {
            cout << "flag TRUE" << endl;
        }
        else{cout << "flag FALSE" << endl;}


        cout << "flag 4" << endl;

        if(!encontreSocio) {

            if (cont <= coleccionSocios.tope) {

                cont++;

            } else {

                cout << endl << "No se encontro el socio con la CI ingresada";
                noCI = true;

            }
        }

        cout << "flag 5" << endl;

    }

    if(encontreSocio){

        Consulta **Con;
        DtFecha DtFec;
        int i; //Contador
        int dia, mes, anio;

        cout << "flag cantConsultas: " << cantConsultas << endl;

        cout << "flag 6" << endl;

        DtConsulta **Consultas = new DtConsulta *[cantConsultas]; //Creo el array para devolver con tope = "cantConsultas" ingresada por el usuario

        cout << "flag 7" << endl;

        //Usando "getConsulta" obtengo el array de consultas-socio por el return y el tope por parametro
        //Obtengo las consultas del socio
        Con = coleccionSocios.socios[cont]->getConsultas(cantCons);

        cout << "flag 8" << endl;

        //Mientras no alcance el tope de consultas "cantConsultas" o el tope de consultas del socio (que pueden ser menor al cantConsultas)--
        //--recorro las consultas del socio chequeando si la fecha de ingreso es menor a la ingresada por el usuario.
        while(!finCons){

            cout << "flag 9" << endl;
            cout << "flag contCons: " << contCons << endl;

            DtFec = Con[contCons]->getfechaConsulta();

            cout << "flag 10" << endl;

            //Chequeo si la fecha pasada por parametros es menor a la fecha de la consulta--
            //--ver sobrecarga del '<' en el DtFecha.cpp
            if(DtFec < fecha){

                cout << "flag 11" << endl;

                Consultas[i] = new DtConsulta(Con[contCons]->getfechaConsulta(), Con[contCons]->getmotivo());
                i++;

            }


            if(i < cantConsultas){

                if(contCons < cantCons){

                    contCons++;

                }

            }else{

                finCons = true;

            }

        }

        return Consultas;

    }



}

////END FUNCIONES
