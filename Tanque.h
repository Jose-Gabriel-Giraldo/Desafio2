#ifndef TANQUE_H
#define TANQUE_H

#include <iostream>
using namespace std;
class Tanque
{
private:

    string categoria;
    int capacidadInicialRegular;
    int capacidadInicialPremium;
    int capacidadInicialEcoExtra;
    int capacidadActualRegular;
    int capacidadActualPremium;
    int capacidadActualEcoExtra;

public:

    //Constructor
    Tanque ();

    //Getters
    string getcategoria();
    short int getcapacidadInicialRegular();
    short int getcapacidadInicialPremium();
    short int getcapacidadInicialEcoExtra();
    short int getcapacidadActualRegular();
    short int getcapacidadActualPremium();
    short int getcapacidadActualEcoExtra();

    //Setters
    void setcategoria(const string& _categoria);
    void setcapacidadInicialRegular(short int _capacidadInicialRegular);
    void setcapacidadInicialPremium(short int _capacidadInicialPremium);
    void setcapacidadInicialEcoExtra(short int _capacidadInicialEcoExtra);
    void setcapacidadActualRegular(short int _capacidadActualRegular);
    void setcapacidadActualPremium(short int _capacidadInicialPremium);
    int setcapacidadActualEcoExtra(short int _capacidadInicialEcoExtra);

    //Funciones Adicionales
    void asignarCapacidadAleatoria();
    unsigned int gasolinaVendida(unsigned int cantidadLitros, const string& categoria);
    void mostrarInfo() ;

};

#endif // TANQUE_H
