#ifndef ESTACIONDESERVICIO_H
#define ESTACIONDESERVICIO_H
#include <iostream>
#include "tanque.h"
#include "surtidor.h"
#include "RedNacional.h"

using namespace std;

class RedNacional;
class EstacionDeServicio
{
private:

    string nombreEstacion, gerente, region;
    int codigoIdentificador, numSurtidores;
    double longitud, latitud;
    Tanque tanque;
    Surtidor surtidores[12];

public:

    //Constructor
    EstacionDeServicio() = default;
    EstacionDeServicio(string _nombreEstacion, string _gerente, int _codigoIdentificador, double _longitud, double _latitud, string _region);

    //Getters
    int getnumSurtidores();
    string getnombreEstacion();
    int getcodigoIdentificador();
    string getgerente();
    double getlongitud();
    double getlatitud();
    string getregion();
    Tanque& gettanque();
    Surtidor* getSurtidores();
    int surtidoresActivos();

    //Setters
    void setnombreEstacion(string& nombreEstacion);
    void setcodigoIdentificador(int _codigoIdentificador);
    void setgerente(string& _gerente);
    void setlongitud(double _longitud);
    void setlatitud(double _latitud);
    void setregion(string& _region);
    void setTanque(Tanque& nuevotanque);

    //Funciones Adicionales
    void agregarsurtidor(int codigoSurtidor, string modeloMaquina);
    void eliminarsurtidor(int codigoSurtidor);
    void activar_desactivarSurtidor(int codigoSurtidor, bool estado);
    void calcularTransacciones();
    void infoSurtidores();
    void historialTransacciones(int posicion);
    void reporteLitrosVendidos();
    void simularVenta(RedNacional& red);
    void verificarFugas(Tanque& tanque, Surtidor* surtidores, int numSurtidores);
};

#endif // ESTACIONDESERVICIO_H
