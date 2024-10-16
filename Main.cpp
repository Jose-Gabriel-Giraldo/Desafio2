#include "funcionesadicionales.h"
#include <iostream>
#include "RedNacional.h"
#include "estaciondeservicio.h"
#include <cstdlib>

using namespace std;

RedNacional redNacional;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    bool seguir = true;
    unsigned short int opcion;

    do {
        cout << "Bienvenido al sistema de comercio TerMax" << endl;
        cout << "______Menu______ " << endl;
        cout << "Seleccione 1 para acceder a los servicios de gestion de red." << endl;
        cout << "Seleccione 2 para acceder a los servicios de gestion de estaciones de servicio." << endl;
        cout << "Seleccione 3 para acceder a la opcion de sistema nacional de verificacion de fugas." << endl;
        cout << "Seleccione 4 para acceder a la opcion de simulacion de ventas." << endl;
        cout << "Ingrese un #5 para salir." << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestionDeRed(redNacional);
            break;

        case 2:
            gestionEstacionesDeServicio(redNacional);
            break;

        case 3:
            verificarFuga(redNacional);
            break;

        case 4:
            simulacion(redNacional);
            break;

        case 5:
            seguir = false;
            cout << "Gracias por usar el sistema. ¡Hasta luego!" << endl;
            break;

        default:
            cout << "Opción no válida." << endl;
            break;
        }

    } while (seguir);

    return 0;
}
