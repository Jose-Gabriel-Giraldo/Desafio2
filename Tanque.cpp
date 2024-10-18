#include "tanque.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Tanque::Tanque() {}

void Tanque::mostrarInfo(){

    cout << "Gasolina en el tanque" << endl;
    cout << "Capacidad inicial en el tanque Regular: " << capacidadInicialRegular << " litros" << endl;
    cout << "Capacidad inicial en el tanque Premium: " << capacidadInicialPremium << " litros" << endl;
    cout << "Capacidad inicial en el tanque EcoExtra: " << capacidadInicialEcoExtra << " litros" << endl;
    cout << "Gasolina disponible en el tanque Regular: " << capacidadActualRegular << " litros" << endl;
    cout << "Gasolina disponible en el tanque Premium: " << capacidadActualPremium << " litros" << endl;
    cout << "Gasolina disponible en el tanque EcoExtra: " << capacidadActualEcoExtra << " litros" << endl;
}

void Tanque::asignarCapacidadAleatoria(){
    srand(time(0));

    capacidadInicialRegular = rand() % 101 + 100;
    capacidadInicialPremium = rand() % 101 + 100;
    capacidadInicialEcoExtra = rand() % 101 + 100;

    capacidadActualRegular = capacidadInicialRegular;
    capacidadActualPremium = capacidadInicialPremium;
    capacidadActualEcoExtra = capacidadInicialEcoExtra;

    cout << "Capacidades asignadas: " << endl;
    cout << "Regular: " << capacidadInicialRegular << " litros" << endl;
    cout << "premium: " << capacidadInicialPremium << " litros" << endl;
    cout << "Regular: " << capacidadInicialEcoExtra << " litros" << endl;

}

short int Tanque::getcapacidadInicialRegular() {
    return capacidadInicialRegular;
}

short int Tanque::getcapacidadInicialPremium() {
    return capacidadInicialPremium;
}

short int Tanque::getcapacidadInicialEcoExtra() {
    return capacidadInicialEcoExtra;
}

short int Tanque::getcapacidadActualRegular() {
    return capacidadActualRegular;
}

short int Tanque::getcapacidadActualPremium() {
    return capacidadActualPremium;
}

short int Tanque::getcapacidadActualEcoExtra() {
    return capacidadActualEcoExtra;
}

unsigned int Tanque::gasolinaVendida(unsigned int cantidadLitros, const string &categoria){
    if(categoria == "Regular"){
        if(capacidadActualRegular >= cantidadLitros){
            capacidadActualRegular -= cantidadLitros;
        }
        else{
            cout << "No se puede suplir el monto de litros establecido, se vendera el contenido restante" << endl;
            cantidadLitros = capacidadActualRegular;
            capacidadActualRegular -= cantidadLitros;
        }
    }

    else if(categoria == "Premium"){
        if(capacidadActualPremium >= cantidadLitros){
            capacidadActualPremium -= cantidadLitros;
        }

        else{
            cout << "No se puede suplir el monto de litros establecido, se vendera el contenido restante" << endl;
            cantidadLitros = capacidadActualPremium;
            capacidadActualPremium -= cantidadLitros;
        }
    }

    else if(categoria == "EcoExtra"){
        if (capacidadActualEcoExtra >= cantidadLitros){
            capacidadActualEcoExtra -= cantidadLitros;
        }

        else{
            cout << "No se puede suplir el monto de litros establecido, se vendera el contenido restante" << endl;
            cantidadLitros = capacidadActualEcoExtra;
            capacidadActualEcoExtra -= cantidadLitros;
        }
    }

    return cantidadLitros;
}
