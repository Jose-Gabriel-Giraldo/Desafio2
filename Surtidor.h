#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <iostream>
#include "transacciones.h"

using namespace std;

class Surtidor
{
private:
    int codigoSurtidor;
    string modeloMaquina;
    int numTransacciones;
    bool estado;
    Transaccion transacciones[100];

public:

    //Constructor
    Surtidor(int _codigoSurtidor = 0, string _modeloMaquina = "", bool _estado = true);

    //Getters
    int getcodigoSurtidor();
    string getmodeloMaquina();
    bool getestado();
    int getnumTransacciones();
    Transaccion* gettransacciones() ;

    //Setters
    void setcodigoSurtidor(int _codigoSurtidor);
    void setmodeloMaquina(string _modeloMaquina);
    void setestado(bool _estado);

    //Funciones Adicionales
    void activarSurtidor_desactivarSurtidor(bool _estado);
    void consultarTransaccion();
    short int reportarLitroPorCategoria();
    void reportarTransaccion(int cantidadLitros, long int cantidadDinero, const string& metodoDePago, const string& documentoUsuario, const string& categoriaCombustible);

};

#endif // SURTIDOR_H

