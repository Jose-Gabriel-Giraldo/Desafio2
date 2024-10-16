#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include "estaciondeservicio.h"
#include "tanque.h"
#include "surtidor.h"
#include "transacciones.h"
#include <iostream>

using namespace std;


class RedNacional
{
private:
    EstacionDeServicio estaciones [100];
    int cantidadEstaciones;
    unsigned short int precioPorRegion[3][3];

public:

    //Constructor
    RedNacional();

    int getcantidadEstaciones ();
    unsigned short int obtenerPrecioPorRegiones (string& _region, string& _categoria);
    unsigned short int establecerPrecio (string& _region, string& _categoria, unsigned short int precio);
    void agregarEstacionDeServicio (string _nombreEstacion , string _gerente , int _codigoIdentificador, double _longitud, double _latitud, string _region);
    void eliminarEstacionDeServicio (int _codigoIdentificador);
    void calcularMontoTransaccion();
    void infoEstacionDeServicio();
    EstacionDeServicio* getestaciones();
    EstacionDeServicio* EstacionEnRed(int _codigoIdentificador);
};

#endif // REDNACIONAL_H
