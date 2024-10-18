#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <iostream>

using namespace std;

class Transaccion
{
private:

    string categoriaCombustible, metodoDePago, documentoUsuario;
    short int cantidadLitros;
    long int cantidadDinero;
    int fecha[3], hora[3];

public:
    //Constructor
    Transaccion(short int _cantidadLitros = 0,  string _categoriaCombustible = "", string _metodoDePago = "", string _documentoUsuario = "", long int _cantidadDinero = 0);

    //Getters
    int* getfecha();
    int* gethora();
    short int getcantidadLitros() const;
    string getcategoriaCombustible() const;
    string getmetodoDePago() const;
    string getdocumentoUsuario() const;
    long int getcantidadDinero() const;

    //Funciones Adicionales
    void mostrarInformacion();
};

#endif // TRANSACCION_H
