#include "RedNacional.h"
#include "estaciondeservicio.h"
#include "tanque.h"
#include "surtidor.h"
#include "transacciones.h"
#include <iostream>
#include <string>

using namespace std;

EstacionDeServicio::EstacionDeServicio(string _nombreEstacion , string _gerente , int _codigoIdentificador, double _longitud, double _latitud, string _region)
    :nombreEstacion(_nombreEstacion), codigoIdentificador(_codigoIdentificador), gerente(_gerente), region(_region), tanque(), numSurtidores(0), longitud(_longitud), latitud(_latitud){
}

string EstacionDeServicio::getnombreEstacion() {
    return nombreEstacion;
}

int EstacionDeServicio::getcodigoIdentificador() {
    return codigoIdentificador;
}

string EstacionDeServicio::getgerente() {
    return gerente;
}

string EstacionDeServicio::getregion() {
    return region;
}

double EstacionDeServicio::getlongitud() {
    return longitud;
}

double EstacionDeServicio::getlatitud() {
    return latitud;
}

Tanque& EstacionDeServicio::gettanque() {
    return tanque;
}

Surtidor* EstacionDeServicio::getSurtidores() {
    return surtidores;
}

int EstacionDeServicio::surtidoresActivos() {
    int activos = 0;
    for (int i = 0; i < numSurtidores; i++){
        if(surtidores[i].getestado() == true){
            activos++;
        }
    }
    return activos;
}

int EstacionDeServicio::getnumSurtidores() {
    return numSurtidores;
}

void EstacionDeServicio::setnombreEstacion(string& nombreEstacion){
    nombreEstacion = nombreEstacion;
}

void EstacionDeServicio::setcodigoIdentificador(int _codigoIdentificador){
    codigoIdentificador = _codigoIdentificador;
}

void EstacionDeServicio::setgerente(string& _gerente){
    gerente = _gerente;
}

void EstacionDeServicio::setregion(string &_region){
    region = _region;
}

void EstacionDeServicio::setlongitud(double _longitud){
    longitud = _longitud;
}

void EstacionDeServicio::setlatitud(double _latitud){
    latitud = _latitud;
}

void EstacionDeServicio::setTanque(Tanque& nuevotanque){
    tanque = nuevotanque;
}

void EstacionDeServicio::agregarsurtidor(int codigoSurtidor, string modeloMaquina, bool estado){

    if (numSurtidores <= 12){
        Surtidor nuevoSurtidor(codigoSurtidor, modeloMaquina, estado);
        surtidores[numSurtidores] = nuevoSurtidor;
        numSurtidores++;
        cout << "Surtidor agregado exitosamente." << endl;
    }else {
        cout << "No se puede agregar mas surtidores." << endl;
    }
}

void EstacionDeServicio::eliminarsurtidor(int codigoSurtidor){
    int indiceSurtidor = -1;
    for (int i = 0; i < numSurtidores; i++){
        if (surtidores[i].getcodigoSurtidor() == codigoSurtidor){
            indiceSurtidor = i;
            break;
        }
    }

    if (indiceSurtidor == -1){
        cout << "No se a podido encontrar un surtidor con el codigo" << codigoSurtidor << endl;
        return;
    }

    if(surtidores[indiceSurtidor].getestado() == true){
        cout << "No es posible eliminar un surtidor activo" << endl;
        return;
    }

    for(int i = 0; i < numSurtidores - 1; i++){
        surtidores[i] = surtidores[i + 1];
    }

    numSurtidores--;
    cout << "Surtidor eliminado correctamente." << endl;
}

void EstacionDeServicio::activar_desactivarSurtidor(int codigoSurtidor, string actividad){
    int indiceSurtidor = -1;

    for (int i = 0; i < numSurtidores; i++){
        if (surtidores[i].getcodigoSurtidor() == codigoSurtidor){
            indiceSurtidor = i;
            break;
        }
    }

    if (indiceSurtidor == -1){
        cout << "No se a podido encontrar un surtidor con el codigo" << endl;
        return;
    }

    if (surtidores[indiceSurtidor].getestado() == true){
        cout << "El estado del surtidor es: " << (true ? "Activado" : "Desactivado") << endl;
    }

    if(actividad == "A"){
        surtidores[indiceSurtidor].setestado(true);
    } else if (actividad == "D"){
        surtidores[indiceSurtidor].setestado(false);
    }else{
        cout << "No se a ingresado una de las letras para determinar el estado del tanque, por lo tanto mantendra su estado por defecto: " << surtidores[indiceSurtidor].getestado() << endl;
    }

    return;
}

void EstacionDeServicio::calcularTransacciones(){
    unsigned long int totalVentasRegular = 0;
    unsigned long int totalVentasPremium = 0;
    unsigned long int totalVentasEcoExtra = 0;

    for(int i = 0; i < numSurtidores; i++){
        for(int j = 0; j < surtidores[i].getnumTransacciones(); j++){
            const Transaccion& transacciones = surtidores[i].gettransacciones()[j];

            if(transacciones.getcategoriaCombustible() == "Regular"){
                totalVentasRegular += transacciones.getcantidadDinero();

            }else if(transacciones.getcategoriaCombustible() == "Premium"){
                totalVentasPremium += transacciones.getcantidadDinero();

            }else if(transacciones.getcategoriaCombustible() == "EcoExtra"){
                totalVentasEcoExtra += transacciones.getcantidadDinero();
            }
        }
    }

    cout << "Venta total por categoria: " << endl;
    cout << "Regular: " << totalVentasRegular << endl;
    cout << "Premium: " << totalVentasPremium << endl;
    cout << "EcoExtra: " << totalVentasEcoExtra << endl;

}

void EstacionDeServicio::infoSurtidores() {
    if(numSurtidores = 0){
        cout << "No se encuentran surtidores en la estacion" << endl;
        return;
    }
    cout << "Surtidores de la estacion" << endl;
    for (int i = 0; i < numSurtidores; i++){
        cout << "\n" << endl;
        cout << "Codigo del surtidor: " << surtidores[i].getcodigoSurtidor() << endl;
        cout << " Modelo del surtidor: " << surtidores[i].getmodeloMaquina() << endl;
        cout << " Estado: " << surtidores[i].getestado() << endl;
        cout << "\n" << endl;
    }
}

void EstacionDeServicio::historialTransacciones(int posicion) {
    if (posicion < 0 || posicion >= numSurtidores){
        cout << "Surtidor no encontrado" << endl;
        return;
    }
    surtidores[posicion].consultarTransaccion();
}

void EstacionDeServicio::reporteLitrosVendidos(){
    int catidadLitrosVendidosRegular = 0;
    int catidadLitrosVendidosPremium = 0;
    int catidadLitrosVendidosEcoExtra = 0;

    for(int i = 0; i < numSurtidores; i++){
        for(int j = 0; j < surtidores[i].getnumTransacciones(); j++){
            if(surtidores[i].gettransacciones()[j].getcategoriaCombustible() == "Regular"){
                catidadLitrosVendidosRegular += surtidores[i].gettransacciones()[j].getcantidadLitros();

            }else if (surtidores[i].gettransacciones()[j].getcategoriaCombustible() == "Premium"){
                catidadLitrosVendidosPremium += surtidores[i].gettransacciones()[j].getcantidadLitros();

            }else if (surtidores[i].gettransacciones()[j].getcategoriaCombustible() == "EcoExtra"){
                catidadLitrosVendidosEcoExtra += surtidores[i].gettransacciones()[j].getcantidadLitros();
            }
        }
    }

    cout << "Cantidad de litros vendidos Reluar: " << catidadLitrosVendidosRegular << endl;
    cout << "Cantidad de litros vendidos Premium: " << catidadLitrosVendidosPremium << endl;
    cout << "Cantidad de litros vendidos EcoExtra: " << catidadLitrosVendidosEcoExtra << endl;
}


void EstacionDeServicio::verificarFugas(Tanque& tanque, Surtidor* surtidores, int numSurtidores) {
    int vendidoRegular = 0, vendidoPremium = 0, vendidoEcoExtra = 0;

    for(int i = 0; i < numSurtidores; i++){
        for(int j = 0; j < surtidores[i].getnumTransacciones(); j++){
            const Transaccion& transaccion = surtidores[i].gettransacciones()[j];
            if (transaccion.getcategoriaCombustible() == "Regular") {
                vendidoRegular += transaccion.getcantidadLitros();
            } else if (transaccion.getcategoriaCombustible() == "Premium") {
                vendidoPremium += transaccion.getcantidadLitros();
            } else if (transaccion.getcategoriaCombustible() == "EcoExtra") {
                vendidoEcoExtra += transaccion.getcantidadLitros();
            }
        }
    }

    short int capacidadRegular = tanque.getcapacidadInicialRegular();
    short int capacidadPremium = tanque.getcapacidadInicialPremium();
    short int capacidadEcoExtra = tanque.getcapacidadInicialEcoExtra();

    short int almacenadoRegular = tanque.getcapacidadActualRegular();
    double almacenadoPremium = tanque.getcapacidadActualPremium();
    double almacenadoEcoExtra = tanque.getcapacidadActualEcoExtra();

    if ((vendidoRegular + almacenadoRegular) < 0.95 * capacidadRegular) {
        cout << "Se presenta una fuga pra el combustible regular" << endl;
    }
    else{
        cout << "No se presenta una fuga para el combustible regular" << endl;
    }
    if ((vendidoPremium + almacenadoPremium) < 0.95 * capacidadPremium) {
        cout << "Se presenta una fuga pra el combustible Premium." << endl;
    }
    else{
        cout << "No se presenta una fuga para el combustible Premium." << endl;
    }
    if ((vendidoEcoExtra + almacenadoEcoExtra) < 0.95 * capacidadEcoExtra) {
        cout << "Se presenta una fuga pra el combustible EcoExtra." << endl;
    }
    else{
        cout << "No se presenta una fuga para el combustible EcoExtra." << endl;
    }
    cout << "Verificacion de fugas completada." << endl;
}

bool EstacionDeServicio::existeSurtidor(int codigoSurtidor) {
    for (int i = 0; i < numSurtidores; i++){
        if(surtidores[i].getcodigoSurtidor() == codigoSurtidor){
            return true;
        }
    }
    return false;
}

