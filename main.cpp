//
// Created by yoka on 21/03/19.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ui/shellColors.h"
#include <typeinfo>
#include "dataType/DtMascota.h"
#include "./dataType/DtGato.h"
#include "./dataType/DtPerro.h"
#include "./dataType/DtConsulta.h"
//#include <codecvt>
#include <stdexcept>
#include "./dataType/DtFecha.h"
#include "./dataType/DtConsulta.h"
#include "./clases/Socio.h"
#include "./clases/Gato.h"
#include "./clases/Perro.h"
#include "./clases/Consulta.h"
#include "./clases/Mascota.h"


#define MAX_SOCIOS 10
#define MAX_MASCOTAS 10
#define  MAX_CONSULTAS 20

using namespace std;

/**
 * Estructuras de socios y mascotas
 */
struct socios { //coleccion de socios

    Socio *socios[MAX_SOCIOS];
    int tope = 0;
} coleccionSocios;


struct mascotas {
    Mascota *mascotas[MAX_MASCOTAS];
    int tope;
} coleccionMascotas;

bool esGato = false;
bool esPerro = false;


/**
 * DEFINICION DE FUNCIONES SOLICITADAS Y AUXILIARES
 */

void limpiarPantalla();

void registrarSocio(string ci, string nombre, DtMascota &dtMascota);
DtConsulta** verConsultaAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas);
DtMascota** obtenerMascotas(string ciSocio, int& cantMascotas);
void ingresarConsulta(string motivo, string ci);
void agregarMascota(string ci, DtMascota& Mascota);
void eliminarSocio(string ci);
Socio * existeSocio (string ci);

/**
 * FIN DE DEFINCION DE FUNCIONES
 **/


int main() {

    int opcion = 0;
/*
 * HARDCODEO DE DATOS PARA PRUEBAS*/
/*
    cout << "[DATOS HARDCODEADOS] " << endl;
    DtGato dtGatotest = DtGato("GATO1", Hembra, 10, 0, Corto);
    DtGato dtGatotest2 = DtGato("GATO2", Macho, 20, 0, Largo);
    DtPerro dtPerrotest1= DtPerro("PERRO1",Macho,8,0,collie, true);
    DtGato dtGatotest3 = DtGato("GATO3", Hembra, 8, 0, Mediano);
    DtPerro dtPerrotest2= DtPerro("PERRO2",Macho,8,0,bulldog, true);
    DtPerro dtPerrotest3= DtPerro("PERRO3",Macho,8,0,pekines, false);
    //Socios
    registrarSocio("123", "JUAN", dtGatotest);
    registrarSocio("456", "ANA", dtGatotest2);
    registrarSocio("789", "MARIA", dtGatotest3);
    registrarSocio("321","PEDRO" , dtPerrotest1);
    agregarMascota("321",dtGatotest3);
    agregarMascota("321",dtPerrotest3);
    agregarMascota("321",dtGatotest2);
    registrarSocio("654", "LUIS", dtPerrotest2);
    registrarSocio("987", "DANIELA", dtPerrotest3);
    //CONSULTAS
    cout << "[TESTING] Agregando Consulta para socio 123 para test..." << endl;
 //   ingresarConsulta("GARRAPATAS", "123");
    cout << "[TESTING] Agregando Consulta para socio 456 para test..." << endl;
    //ingresarConsulta("VOMITOS", "456");
    //   cout << "[TESTING] Agregando Consulta para socio 456 para test..." << endl;
    //ingresarConsulta("VACUNAS", "456");
    cout << "[TESTING] Agregando Consulta para socio 789 para test..." << endl;
    //ingresarConsulta("CASTRACION", "789");
    cout << "[TESTING] Agregando Consulta para socio 789 para test..." << endl;
    //ingresarConsulta("EXAMENES", "789");
    cout << "[TESTING] Agregando Consulta para socio 789 para test..." << endl;
    //ingresarConsulta("CORTE DE PELO", "789");
    cout << "[TESTING] Agregando Consulta para socio 123 para test..." << endl;
    //ingresarConsulta("EXAMENES", "123");
    cout << "[TESTING] Agregando Consulta para socio 321 para test..." << endl;
    //ingresarConsulta("EXAMENES", "321");
    cout << "[TESTING] Agregando Consulta para socio 321 para test..." << endl;
    //
    // ingresarConsulta("CORTE DE PELO", "321");

 */
/*
 * FIN DE HARDCODEO DE DATOS PARA PRUEBAS/
 */

    while (opcion != 99) {

        cout << SH_FG_BLUE <<  "---------------------------------------"<< SH_DEFAULT << endl;
        cout << SH_FG_GREEN<<  "-PROGRAMACIÓN AVANZADA - LABORATORIO 0-"<< SH_DEFAULT << endl;
        cout << SH_FG_BLUE <<  "---------------------------------------"<< SH_DEFAULT << endl;
        cout << "1. Registrar socio" << endl;
        cout << "2. Agregar mascota" << endl;
        cout << "3. Ingresar consulta" << endl;
        cout << "4. Ver consultas anteriores a fecha..." << endl;
        cout << "5. Eliminar socio" << endl;
        cout << "6. Consultar mascotas de un socio" << endl;
        cout << SH_FG_RED<<"99. Salir" <<SH_DEFAULT<< endl << endl;

        cout << "Ingrese opción: ";
        cin >> opcion;

        cout << "---------------------------------------" << endl;
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
                    string pesoString;

                    bool selOK = false;
                    limpiarPantalla();
                    cout << "Ingrese CI: ";
                    cin >> ci;

                    cout << "Ingrese nombre: ";
                    cin >> nombre;

                    cout << "Ingrese nombre de la mascota: ";
                    cin >> nombreMascota;

                    while (!selOK) {

                        cout << "Ingrese genero (1.Hembra; 2.Macho): ";
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

                                cout << SH_FG_RED << "El genero seleccionado no es valido. Intente nuevamente" << SH_DEFAULT <<endl;
                                break;

                            }

                        }
                    }

                    cout << "Ingrese el peso en kgs (el separador decimal es el punto): ";
                    cin >> pesoString;
                    peso = strtof((pesoString).c_str(),0);

                    selOK = false;

                    while (!selOK) {

                        cout << "Ingrese tipo de mascota (1.Perro; 2.Gato): ";
                        cin >> seleccionMascota;

                        switch (seleccionMascota) {

                            case 1: {

                                RazaPerro raza;
                                int seleccionRaza;
                                int seleccionVacuna;
                                bool tieneVacuna;

                                bool boolPerroOK = false;

                                while (!boolPerroOK) {

                                    cout
                                            << "Ingrese raza (1.Labrador; 2.Ovejero; 3.Bulldog; 4.Pitbull; 5.Collie; 6.Pekines; 7.Otro): ";
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
                                            cout << SH_FG_RED <<"La raza ingresada no es correcta. Ingrese nuevamente." << SH_DEFAULT << endl;
                                            break;
                                        }
                                    }
                                }

                                boolPerroOK = false;

                                while (!boolPerroOK) {

                                    cout << "El perro tiene vacuna? (1.Si; 2.No): ";
                                    cin >> seleccionVacuna;

                                    switch (seleccionVacuna) {

                                        case 1: {
                                            tieneVacuna = true;
                                            boolPerroOK = true;
                                            break;
                                        }

                                        case 2: {
                                            tieneVacuna = false;
                                            boolPerroOK = true;
                                            break;
                                        }

                                        default: {
                                            cout << SH_FG_RED << "El valor ingresado para indicar si el perro tiene vacuna o no es incorrecto. Intentelo nuevamente."<<SH_DEFAULT << endl;
                                            break;
                                        }

                                    }

                                }

                                DtPerro dtPerro = DtPerro(nombreMascota, generoSeleccionado, peso, 0, raza,
                                                          tieneVacuna);
                                registrarSocio(ci, nombre, dtPerro);

                                selOK = true;
                                limpiarPantalla();
                                break;

                            }

                            case 2: {
                                int seleccionPelo;
                                TipoPelo tipopelo;
                                bool selGatoOK = false;
                                limpiarPantalla();
                                while (!selGatoOK) {
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
                                        default: {
                                            cout
                                                    <<SH_FG_RED << "El valor de tipo de pelo seleccionado no es correcto. Intentelo nuevamente."
                                                                   SH_DEFAULT<< endl;
                                            break;
                                        }
                                    }
                                }

                                DtGato dtGato = DtGato(nombreMascota, generoSeleccionado, peso, 0, tipopelo);
                                registrarSocio(ci, nombre, dtGato);

                                selOK = true;
                                break;
                            }
                            default: {
                                cout << "El tipo de mascota seleccionada no es correcta. Intente nuevamente." << endl;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case 2 : {

                limpiarPantalla();

                string nombreMascota;
                float pesoMascota;
                string ciSocio;
                int tipoMascota;
                int genero;
                string pesoString;

                cout << "\nIngrese la CI del socio: ";
                cin >> ciSocio;

                cout << "Ingrese el tipo de Mascota (1.Gato; 2.Perro): ";
                cin >> tipoMascota;

                if (tipoMascota == 1){
                    esGato = true;
                }
                else if (tipoMascota == 2) {
                    esPerro = true;
                }

                cout << "Ingrese el Nombre: ";
                cin >> nombreMascota;

                cout << "Ingrese genero (1.Hembra; 2.Macho): ";
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

                cout << "Ingrese el peso en kgs (el separador decimal es el punto): ";
                cin >> pesoString;
                pesoMascota=strtof((pesoString).c_str(),0);

                if (esGato == true){

                    int seleccionPelo;
                    float racionDiaria = 0;

                    cout << "Que tipo de pelo tiene? (1.Corto; 2.Mediano; 3.Largo): ";
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

                    DtGato nuevoGato = DtGato(nombreMascota, generoSeleccionado, pesoMascota, racionDiaria, tipopelo);
                    agregarMascota(ciSocio, nuevoGato);

                }
                else if (esPerro == true) {

                    RazaPerro raza;
                    int seleccionRaza;
                    int seleccionVacuna;
                    bool tieneVacuna;
                    float racionDiaria = 0;

                    cout << "Ingrese raza (1.Labrador; 2.Ovejero; 3.Bulldog; 4.Pitbull; 5.Collie; 6.Pekines; 7.Otro): ";
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
                        case 4: {
                            raza = pitbull;
                            break;
                        }
                        case 5: {
                            raza = collie;
                            break;
                        }
                        case 6: {
                            raza = pekines;
                            break;
                        }
                        case 7: {
                            raza = otro;
                            break;
                        }

                    }

                    cout << "El perro tiene vacuna? (1.Si; 2.No): ";
                    cin>> seleccionVacuna;

                    if (seleccionVacuna == 1) {
                        tieneVacuna = true;
                    } else {
                        tieneVacuna = false;
                    }

                    DtPerro nuevoPerro = DtPerro(nombreMascota, generoSeleccionado, pesoMascota, racionDiaria, raza, tieneVacuna);
                    agregarMascota(ciSocio, nuevoPerro);
                }

                break;

            }

            case 3 : { //INGRESAR CONSULTA

                limpiarPantalla();
                string ingresoMotivo;
                string ciSocio;

                cout << "Ingrese el motivo de la consulta: ";
                cin.ignore(); //se usa ignore porque el cout deja en el buffer un \n
                getline(cin, ingresoMotivo);

                cout << "Ingrese ci del socio: ";
                cin >> ciSocio;

                try {

                    ingresarConsulta(ingresoMotivo, ciSocio);
                    cout<< SH_FG_GREEN<< "CONSULTA INGRESADA"<< SH_DEFAULT<<endl;

                }catch (invalid_argument &error){

                    cout << SH_FG_RED << "\n\tHA OCURRIDO EL SIGUIENTE ERROR: " << SH_DEFAULT << endl;
                    cout << error.what() << endl;

                }

                break;

            }

            case 4 : {

                int dia, mes, anio, cantConsultas, auxCantConsultas;
                string ciSocio;
                bool selOK = false;

                limpiarPantalla();

                cout << "Ingrese la CI del socio a consultar: ";
                cin >> ciSocio;

                cout << endl << "Ingrese el dia: ";
                cin >> dia;

                cout << endl << "Ingrese el mes: ";
                cin >> mes;

                cout << endl << "Ingrese el anio: ";
                cin >> anio;

                while(!selOK){

                    cout << endl << "Ingrese la cantidad maxima de consultas a mostrar: ";
                    cin >> cantConsultas;

                    if(cantConsultas == 0){

                        cout << "Debe ingresar un numero mayor a cero" << endl;

                    }else if(cantConsultas > 20){

                        cout << "Un socio no puede tener mas de veinte consultas" << endl;

                    }else if(cantConsultas < 0){

                        cout << "Por favor, ingrese un numero correcto" << endl;

                    } else{

                        selOK = true;

                    }
                }

                auxCantConsultas = cantConsultas;

                DtFecha *fecha = new DtFecha(dia, mes, anio);
                DtConsulta **arregloConsulta = verConsultaAntesDeFecha(*fecha, ciSocio, cantConsultas);

                if(auxCantConsultas != cantConsultas && arregloConsulta != NULL){

                    cout << endl << "La cantidad de consultas a visualizar es superior a las que este socio cuenta. Se visualizaran: " << cantConsultas << "." << endl;

                }

                if (arregloConsulta != NULL) {

                    int numConsulta = 0;
                    DtFecha DtFec;
                    int cantConsFinal = 0;

                    for (int a = 0; a < cantConsultas; a++) {

                        DtFec = arregloConsulta[a]->getfechaConsulta();

                        numConsulta = a + 1; //Hago esto porque el array empieza en cero, entonces la primera consulta se va a presentar "Consulta 0"

                        cout << endl << "Consulta " << numConsulta << ":";
                        cout << endl << "Fecha: " << DtFec.getdia() << "/" << DtFec.getmes() << "/" << DtFec.getano();
                        cout << endl << "Motivo: " << arregloConsulta[a]->getmotivo() << endl;

                    }

                }else {

                    cout << "No existen consultas para la fecha indicada." << endl;

                }

                break;

            }

            case 5: {

                limpiarPantalla();

                string ciSocio;
                int indice1 = 0;

                cout << "\nIngrese la CI del socio a eliminar: ";
                cin >> ciSocio;

                eliminarSocio(ciSocio);

                break;

            }

            case 6: {
                limpiarPantalla();

                int cantMascotas;
                string ciSocio;

                cout << "Ingrese la CI del socio a consultar: ";
                cin >> ciSocio;

                cout << "Ingresar la cantidad de mascotas a visualizar: ";
                cin >> cantMascotas;

                try {

                    if ((existeSocio(ciSocio)) != NULL) {

                        DtMascota **arregloMascotas = obtenerMascotas(ciSocio, cantMascotas);

                        for (int x = 0; x < cantMascotas; x++) {

                            DtPerro *dtPerro = dynamic_cast<DtPerro *>(arregloMascotas[x]);

                            if (dtPerro != NULL) {
                                cout << *(dtPerro) << endl;
                            } else {
                                DtGato *dtGato = dynamic_cast<DtGato *>(arregloMascotas[x]);
                                cout << *(dtGato) << endl;
                            }

                        }

                    }
                } catch (invalid_argument &e) {

                    cout << e.what() << endl;


                }

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
    return 0;
}

///FUNCIONES

/**************FUNCIÓN LIMPIAR PANTALLA************/

void limpiarPantalla() {
    for (int i = 0; i < 50; i++) {
        cout << "\n";

    }
}
/****************************************************************************************************/

/************* FUNCIÓN EXISTE SOCIO ***************/

void registrarSocio(string ci, string nombre, DtMascota &dtMascota) {
    Socio *nuevoSocio = new Socio(ci, nombre);
    coleccionSocios.socios[coleccionSocios.tope] = nuevoSocio;
    coleccionSocios.tope++;
    try {
        DtGato &dtgato = dynamic_cast<DtGato &>(dtMascota);
        Gato *nuevoGato = new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(), dtgato.getTipoPelo());
        nuevoSocio->agregarMascotaSocio(nuevoGato);
    } catch (std::bad_cast &NombreVariable) {
        try {
            DtPerro &dtperro = dynamic_cast<DtPerro &>(dtMascota);
            Perro *nuevoPerro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRazaPerro(), dtperro.getVacunaCachorro());
            nuevoSocio->agregarMascotaSocio(nuevoPerro);
        }
        catch (std::bad_cast &NombreVariable) {
            cout << "Error\n";
        }
    }
}

/****************************************************************************************************/

/********************* INGRESAR CONSULTA********************/

void ingresarConsulta(string motivo, string ci) {
    Socio *socio = existeSocio(ci);
    DtFecha fecha =DtFecha(27, 2, 1985);
    Consulta *consulta= new Consulta(fecha, motivo);
    socio -> ingresarConsulta(consulta);

}

/************************************************************************************/


/* ****** FUNCIÓN EXISTE SOCIO ****** */

Socio * existeSocio (string ci){
    Socio* socio=NULL;
    int indice = 0;
    bool existe = false ;
    while (existe == false && indice < coleccionSocios.tope ){
        if (coleccionSocios.socios[indice]->getCi().compare(ci) == 0) {
            socio=coleccionSocios.socios[indice];
            existe = true;

        } else {
            indice ++;
        }

    }
    if (socio==NULL) {
        throw invalid_argument("\n No existe socio");
    }
    else{
        return socio;
    }
}


/* FUNCIÓN AGREGAR MASCOTA */

void agregarMascota (string ci, DtMascota& Mascota){
    Socio * socio=NULL;

    try {
        socio=existeSocio(ci);
        if (esPerro){
            try {
                DtPerro& perro = dynamic_cast<DtPerro&> (Mascota);
                Perro* nuevoPerro = new Perro(perro.getNombre(), perro.getGenero(), perro.getPeso(), perro.getRazaPerro(), perro.getVacunaCachorro());
                socio->agregarMascotaSocio(nuevoPerro);
                esPerro=false;
                cout << "\n Se agregó mascota del tipo Perro al socio indicado \n";

            }catch (std::bad_cast) {
                cout << "Error en el cast DtPerro \n";
            }

        }
        else if (esGato) {
            try {
                DtGato& gato = dynamic_cast<DtGato&> (Mascota);
                Gato* nuevoGato = new Gato(gato.getNombre(), gato.getGenero(), gato.getPeso(), gato.getTipoPelo());
                socio->agregarMascotaSocio(nuevoGato);
                esGato=false;
                cout << "\n Se agregó mascota del tipo Gato al socio indicado \n";

            }catch (std::bad_cast) {
                cout << "Error en el cast DtGato \n";
            }
        }

    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}


/************************************************************************************/


/* ****** FUNCIÓN CONSULTA ANTES DE FECHA ****** */


DtConsulta **verConsultaAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas) {
    bool encontreSocio = false; //encontreSocio va a ser True si se encuentra el socio
    bool noCI = false;          //noCI sera True si se alcanza el tope de Socios, por lo tanto, si no se encontro el Socio por su CI
    bool finCons = false;       //Indicador de que llegue al tope de Consultas a cargar

    int cont = 0, contCons = 0; //Contadores para los whiles

    int cantCons = 0;

    int test = 1;

    Socio *Soc;


    while (!encontreSocio && !noCI) {

        //Busco socio
        if (coleccionSocios.socios[cont]->getCi() == ciSocio) {

            Soc = coleccionSocios.socios[cont];
            encontreSocio = true;

        }


        if (!encontreSocio) {

            if (cont < coleccionSocios.tope) {

                cont++;

            } else {

                cout << endl << "No se encontro el socio con la CI ingresada" << endl;
                noCI = true;

            }

        }

    }

    if (encontreSocio) {

        Consulta **Con;
        DtFecha DtFec;
        int i; //Contador
        int dia, mes, anio;

        if(coleccionSocios.socios[cont]->getTopeConsulta() == 0){

            cout << "El socio no ha tenido ninguna consulta aun." << endl;
            DtConsulta **Consultas = NULL;

            return Consultas;

        }else {

            //Usando "getConsulta" obtengo el array de consultas-socio por el return y el tope por parametro
            //Obtengo las consultas del socio
            Con = coleccionSocios.socios[cont]->getConsultas(cantCons);

            DtConsulta **Consultas = NULL;

            //Si la cantidad de consultas a mostrar (ingresdo por el usuario) es mayor a al cantidad de consultas que existen--
            //-- el tamanio del "Consultas" a devolver va a ser igual al tope.
            if (cantConsultas > coleccionSocios.socios[cont]->getTopeConsulta()) {

                cantConsultas = coleccionSocios.socios[cont]->getTopeConsulta();

            }

            Consultas = new DtConsulta *[cantConsultas]; //Creo el array para devolver con tope = "cantConsultas" ingresada por el usuario

            i = 0;

            //Mientras no alcance el tope de consultas "cantConsultas" o el tope de consultas del socio (que pueden ser menor al cantConsultas)--
            //--recorro las consultas del socio chequeando si la fecha de ingreso es menor a la ingresada por el usuario.
            while (!finCons) {

                DtFec = Con[contCons]->getfechaConsulta();

                //Chequeo si la fecha pasada por parametros es menor a la fecha de la consulta--
                //--ver sobrecarga del '<' en el DtFecha.cpp
                if (DtFec < fecha) {

                    Consultas[i] = new DtConsulta(Con[contCons]->getfechaConsulta(), Con[contCons]->getmotivo());
                    i++;

                }

                //Si la cantidad de consultas cargadas 'i' y la cantidad de consultas + 1 (es +1 porque uno tiene cantConsultas va desfasado en 1)
                if (i < cantConsultas && (contCons + 1 ) < cantConsultas) {

                    contCons++;

                } else {

                    if (i == 0) { //Si no cargo nada, vuelvo la variable a retornar a NULL

                        Consultas = NULL;

                    }

                    finCons = true;

                }

            }

            return Consultas;

        }

    }else{ //No encontre socio: cargo la cantidad de consultas como 0

        DtConsulta **Consultas = NULL;

        return Consultas;

    }

}



/* ****** FUNCIÓN OBTERNER MASCOTA ****** */

DtMascota** obtenerMascotas( string ciSocio, int &cantMascotas){
    bool encontreSocio = false; //encontreSocio va a ser True si se encuentra el socio
    int cont=0;
    Socio * so=NULL;


    try {
        so=existeSocio(ciSocio);
        encontreSocio=true;
    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }
    if(encontreSocio){
        int topeMascota;
        Mascota ** mascotas = so->getMascotas(topeMascota);
        if(cantMascotas>topeMascota) {
            cantMascotas=topeMascota;
        }


        DtMascota ** resultado = new DtMascota * [cantMascotas];
        for(int x=0; x < cantMascotas; x++){
            Mascota * cadaMascota = mascotas[x];
            Perro * perro = dynamic_cast<Perro*> (cadaMascota);
            if(perro==NULL){
                Gato * gato = dynamic_cast<Gato*> (cadaMascota);
                DtGato * dtgato = new DtGato(gato->getNombre(),gato->getGenero(),gato->getPeso(),gato->obtenerRacionDiaria(),gato->gettipoPelo());
                //
                resultado[x] = dtgato;
            }
            else{
                DtPerro * dtperro = new DtPerro(perro->getNombre(),perro->getGenero(),perro->getPeso(),perro->obtenerRacionDiaria(),perro->getraza(),perro->getvacunaCachorro());
                resultado[x] = dtperro;
            }
        }
        return resultado;

    }
}

/****************************************************************************************************/

/************* FUNCIÓN ELIMINAR SOCIO ***************/

void eliminarSocio(string ci){
    Socio* socio=NULL;
    int indice1 =0;
    try {
        socio=existeSocio(ci);
        for(indice1; indice1 < coleccionSocios.tope; indice1++){
            if(coleccionSocios.socios[indice1]->getCi().compare(ci) == 0){
                coleccionSocios.socios[indice1] =  coleccionSocios.socios[coleccionSocios.tope-1];
                coleccionSocios.tope--;
                cout << "Socio borrado.." << endl;
            }
        }

    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }


}





////END FUNCIONES
