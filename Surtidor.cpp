#include "surtidor.h"
#include <iostream>

using namespace std;

Surtidor::Surtidor(int codigoSurtidor, string modeloMaquina, bool estado)
    : codigoSurtidor(codigoSurtidor), modeloMaquina(modeloMaquina), numTransacciones(0), estado(estado){
}

void Surtidor::activarSurtidor_desactivarSurtidor(bool estado){
    estado = estado;
}


void Surtidor::reportarTransaccion(int cantidadLitros, long int cantidadDinero, const string& metodoDePago, const string& documentoUsuario, const string& categoriaCombustible){
    transacciones[numTransacciones];
    numTransacciones++;
}

void Surtidor::consultarTransaccion(){
    if (numTransacciones == 0){
        cout << "No se encuentran transacciones realizadas" << endl;
        return;
    }

    for(int i = 0; i < numTransacciones; i++){
        transacciones[i].mostrarInformacion();
    }
}

int Surtidor::getnumTransacciones(){
    return numTransacciones;
}

Transaccion* Surtidor::gettransacciones(){
    return transacciones;
}

int Surtidor::getcodigoSurtidor(){
    return codigoSurtidor;
}

string Surtidor::getmodeloMaquina(){
    return modeloMaquina;
}

bool Surtidor::getestado() {
    return estado;
}
