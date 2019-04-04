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
//#include <codecvt>
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

bool esGato = false;
bool esPerro = false;


//*********** DEFINICION DE FUNCIONES***********

void limpiarPantalla();

void registrarSocio(string ci, string nombre, DtMascota &dtMascota);
DtConsulta** verConsultaAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas);
DtMascota** obtenerMascotas(string ciSocio, int& cantMascotas);
void ingresarConsulta(string motivo, string ci);
void agregarMascota(string ci, DtMascota& Mascota);

//*********************************************

int main() {

    int opcion = 0;

    //TESTING - GSM 02/04/19 - Necesitaba un socio con una mascota para testear
    cout << "[TESTING] Agregando Socio-Mascota para test..." << endl;
    DtGato dtGatotest = DtGato("GATO1", Hembra, 10, 0, Corto);
    registrarSocio("123", "JUAN", dtGatotest);
    cout << "[TESTING] Agregando Consulta para socio 123 para test..." << endl;
    ingresarConsulta("motivo1", "123");
    cout << "[TESTING] Agregando Consulta para socio 123 para test..." << endl;
    ingresarConsulta("motivo22", "123");
    cout << "[TESTING] Agregando Consulta para socio 123 para test..." << endl;
    ingresarConsulta("motivo333", "123");
    //---

    while (opcion != 99) {

        cout << "---------------------------------------" << endl;
        cout << "--PROGRAMACIÓN AVANZADA - LABORATORIO 0-\n"
                "==========VETERINARIA LA NUTRIA=========" << endl;
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
                    limpiarPantalla();
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
                                            cout << "La raza ingresada no es correcta. Ingrese nuevamente." << endl;
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
                                            cout
                                                    << "El valor ingresado para indicar si el perro tiene vacuna o no es incorrecto. Intentelo nuevamente."
                                                    << endl;
                                            break;
                                        }

                                    }

                                }

                                DtPerro dtPerro = DtPerro(nombreMascota, generoSeleccionado, peso, 0, raza,
                                                          tieneVacuna);
                                registrarSocio(ci, nombre, dtPerro);

                                selOK = true;

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
                                                    << "El valor de tipo de pelo seleccionado no es correcto. Intentelo nuevamente."
                                                    << endl;
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
                    int pesoMascota;
                    string ciSocio;
                    int tipoMascota;

                    cout << "\n\tIngrese la CI del socio: \n";
                    cin >> ciSocio;

                    cout << "Ingrese el tipo de Mascota (1- Gato, 2-Perro): ";
                    cin >> tipoMascota;

                    if (tipoMascota == 1){
                        esGato = true;
                    }
                    else if (tipoMascota == 2) {
                        esPerro = true;
                    }

                    cout << "Ingrese el Nombre: ";
                    cin >> nombreMascota;
                    cout << "ingrese genero (1.hembra 2.macho)";
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

                    cout << "Ingrese el peso ";
                    cin >> pesoMascota;

                    if (esGato == true){
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
                        float racionDiaria = 0;
                        DtGato nuevoGato = DtGato(nombreMascota, generoSeleccionado, pesoMascota, racionDiaria, tipopelo);
                        agregarMascota(ciSocio, nuevoGato);
                    }
                    else if (esPerro == true) {
                        RazaPerro raza;
                        cout << "Ingrese raza (mire las opciones del 1 al 8) ";
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

                        cout << "El perro tiene vacuna, 1 si 2 no?";
                        int seleccionVacuna;
                        cin>> seleccionVacuna;
                        bool tieneVacuna;
                        if (seleccionVacuna == 1) {
                            tieneVacuna = true;
                        } else {
                            tieneVacuna = false;
                        }
                        float racionDiaria=0;
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

                    ingresarConsulta(ingresoMotivo, ciSocio);

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

                    if(auxCantConsultas != cantConsultas){

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
                            cout << endl << "Fecha: " << DtFec.getdia() << "/" << DtFec.getmes() << "/"
                                 << DtFec.getano();
                            cout << endl << "Motivo: " << arregloConsulta[a]->getmotivo() << endl;

                        }

                    }


                    break;

                }

                case 5: {
                    limpiarPantalla();
                    break;

                }

                case 6: {
                    int cantMascotas;
                    string ciSocio;
                    limpiarPantalla();
                    cout << "Ingrese la CI del socio a consultar: ";
                    cin >> ciSocio;

                    DtMascota **arregloMascotas = obtenerMascotas( ciSocio, cantMascotas);


                    for (int x=0; x <= cantMascotas; x++){

                        //nombre = arregloMascotas[x]->getNombre();
                       // cout << endl << "Nombre: " << arregloMascotas[x]->getNombre();
//                      //  cout << endl << "Motivo: " << arregloMascotas[x]->getmotivo();


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
        nuevoSocio->agregarMascota(nuevoGato);

    } catch (std::bad_cast &NombreVariable) {
        try {
            DtPerro &dtperro = dynamic_cast<DtPerro &>(dtMascota);
            Perro *nuevoPerro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRazaPerro(), dtperro.getVacunaCachorro());
            nuevoSocio->agregarMascota(nuevoPerro);
        }
        catch (std::bad_cast &NombreVariable) {
            cout << "Error\n";
        }
    }
}

/****************************************************************************************************/

/********************* INGRESAR CONSULTA********************/

void ingresarConsulta(string motivo, string ci) {
    int contador = 0;
    bool encontrado = false;

    Socio *socio = NULL;

    while (!encontrado && contador < MAX_SOCIOS) {

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

    } else {

        //agrego consulta
        DtFecha fecha = DtFecha(7, 5, 1991);
        Consulta *consulta = new Consulta(fecha, motivo);
        socio->ingresarConsulta(consulta);

    }

}

/************************************************************************************/


/* ****** FUNCIÓN EXISTE SOCIO ****** */

void existeSocio (string ci){
    int indice = 0;
    bool existe = false ;
    while (existe == false && indice < coleccionSocios.tope ){
        if (coleccionSocios.socios[indice]->getCi() == ci) {
            existe = true;
        } else {
            indice ++;
        }

    }
    if (!existe)
        throw invalid_argument("\n No existe socio");
}


/* FUNCIÓN AGREGAR MASCOTA */

void agregarMascota (string ci, DtMascota& Mascota){
    try {
        existeSocio(ci);
        if (esPerro){
            try {
                DtPerro& perro = dynamic_cast<DtPerro&> (Mascota);
                Perro* nuevoPerro = new Perro(perro.getNombre(), perro.getGenero(), perro.getPeso(), perro.getRazaPerro(), perro.getVacunaCachorro());
                coleccionMascotas.mascotas[coleccionMascotas.tope] = nuevoPerro;
                coleccionMascotas.tope++;
                cout << "\n Se agregó mascota del tipo Perro al socio indicado \n";

            }catch (std::bad_cast) {
                cout << "Error en el cast DtPerro \n";
            }

        }
        else if (esGato) {
            try {
                DtGato& gato = dynamic_cast<DtGato&> (Mascota);
                Gato* nuevoGato = new Gato(gato.getNombre(), gato.getGenero(), gato.getPeso(), gato.getTipoPelo());
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


                if (i < cantConsultas && contCons < cantConsultas) { //revisar la logica de este if

                    if (contCons < cantCons) {

                        contCons++;

                    }

                } else {

                    if (i == 0) { //Si no cargo nada, vuelvo la variable a retornar a NULL

                        Consultas = NULL;

                    }

                    finCons = true;

                }

            }

            return Consultas;

        }

    }else{ //No encontre socio: cargo la cantidad de consultas como 0 mark

        DtConsulta **Consultas = NULL;

        return Consultas;

    }

}



/* ****** FUNCIÓN OBTERNER MASCOTA ****** */

DtMascota** obtenerMascotas( string ciSocio, int &cantMascotas){
    cout << "ENTRO" << endl;
    cantMascotas=0;
    bool encontreSocio = false; //encontreSocio va a ser True si se encuentra el socio
    int cont=0;
    Socio * so=NULL;

    while( !encontreSocio && cont<=coleccionSocios.tope ){

        cout << "PASO 2" << endl;
        //cout << coleccionSocios.socios[cont]->getMascotas(cantMascotas) << endl;


        //Busco socio
        if(coleccionSocios.socios[cont]->getCi() == ciSocio){

            cout << "PASO 3" << endl;

            so=coleccionSocios.socios[cont];
            encontreSocio = true;

        }
        else{
            cont++; // Le sumo para pasar al siguiente cliente
            cout << "PASO 6" << endl;
        }

        if(encontreSocio) {
            cout << "PASO TRUE" << endl;
        }
        else{cout << "PASO FALSE" << endl;}


        cout << "PASO 4" << endl;
    }
    if(encontreSocio){
        Mascota ** mascotas = so->getMascotas(cantMascotas);

        DtMascota ** resultado = new DtMascota * [cantMascotas];
        for(int x=0; x <= cantMascotas; x++){
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


////END FUNCIONES
