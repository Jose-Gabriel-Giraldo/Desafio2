#include "transacciones.h"
#include <ctime>
#include <iostream>

using namespace std;

Transaccion::Transaccion(short int _cantidadLitros,  string _categoriaCombustible, string _metodoDePago, string _documentoUsuario, long int _cantidadDinero) {
    cantidadLitros = _cantidadLitros;
    categoriaCombustible = _categoriaCombustible;
    metodoDePago = _metodoDePago;
    documentoUsuario = _documentoUsuario;
    cantidadDinero = _cantidadDinero;

    time_t t = time(0);
    tm now = *localtime(&t);

    fecha[0] = now.tm_mday;
    fecha[1] = now.tm_mon + 1;
    fecha[2] = now.tm_year + 1900;

    hora[0] = now.tm_hour;
    hora[1] = now.tm_min;
    hora[2] = now.tm_sec;
}

short int Transaccion::getcantidadLitros() const{
    return cantidadLitros;
}

string Transaccion::getcategoriaCombustible() const{
    return categoriaCombustible;
}

string Transaccion::getmetodoDePago() const{
    return metodoDePago;
}

string Transaccion::getdocumentoUsuario() const{
    return documentoUsuario;
}

long int Transaccion::getcantidadDinero() const{
    return cantidadDinero;
}

int* Transaccion::getfecha() {
    return fecha;
}

int* Transaccion::gethora() {
    return hora;
}

void Transaccion::mostrarInformacion(){
    cout << "Informe transaccion" << endl;
    cout << "Fecha: " << fecha[0] << "/" << fecha[1] << "/" << fecha[2] << endl;
    cout << "Hora: " << hora[0] << ":" << hora[1] << ":" << hora[2] << endl;
    cout << "Categori: " << categoriaCombustible << endl;
    cout << "Cantidad de litros vendidos: " << cantidadLitros << endl;
    cout << "Monto total de la transaccion: " << cantidadDinero << endl;
    cout << "Metodo de pago: " << metodoDePago << endl;
    cout << "Documento del comprador: " << documentoUsuario << endl;

}
