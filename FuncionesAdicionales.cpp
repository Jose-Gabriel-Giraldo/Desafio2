#include "funcionesadicionales.h"
#include <iostream>
#include "RedNacional.h"
#include "transacciones.h"

using namespace std;

void gestionDeRed(RedNacional& red){
    unsigned short int opcion;

    do{
        cout << "Seleccione 1 para agregar una estacion de servicio" << endl;
        cout << "Seleccione 2 para eliminar una estacion de servicio (Tenga en cuenta que todos los surtidores deben esta desactivados)" << endl;
        cout << "Seleccione 3 para calcular el monto total de las ventas en cada estacion de servicio discriminadas por categorias" << endl;
        cout << "Seleccione 4 para fijar los precios del combustible para la red" << endl;
        cout << "Seleccione 5 para salir al menu pricipal" << endl;

        cin >> opcion;

        while (opcion > 5) {
            cout << "Ingrese una opcion valida" << endl;
            cin >> opcion;
        }

        switch(opcion){
        case 1: {
            string nombreEstacion, gerente, region;
            int codigoIdentificador;
            double longitud, latitud;

            cout << "Ingrese el nombre de la estacion: " << endl;
            cin >> nombreEstacion;

            cout << "Ingrese el codigo de la estacion: " << endl;
            cin >> codigoIdentificador;

            cout << "Ingrese el nombre del gerente de la estacion: " << endl;
            cin >> gerente;

            cout << "Ingrese la region a la cual pertenece la estacion con mayuscula inicial (Norte, Centro, Sur): " << endl;
            cin >> region;

            cout << "Ingrese la longitud para las coordenadas de la estacion: " << endl;
            cin >> longitud;

            cout << "Ingrese la latitud para las coordenadas de la estacion: " << endl;
            cin >> latitud;

            red.agregarEstacionDeServicio(nombreEstacion, gerente, codigoIdentificador, longitud, latitud, region);
            cout << "Estacion de servicio agregada con exito." << endl;
            break;
        }

        case 2: {
            red.infoEstacionDeServicio();
            int codigoIdentificador;
            cout << "Ingrese el codigoIdentificador de la estacion que quiere eliminar: " << endl;
            cin >> codigoIdentificador;
            red.eliminarEstacionDeServicio(codigoIdentificador);
            break;
        }

        case 3: {
            red.calcularMontoTransaccion();
            break;
        }

        case 4: {
            string _region;
            unsigned short int _precio;
            string _categoria;

            cout << "Debe establecer el precio por region de forma individual" << endl;

            cout << "Ingrese la region para la cual establecer los precios (Norte, Centro, Sur): " << endl;
            cin >> _region;

            cout << "Ingrese la categoria del combustible (Regular, Premium, EcoExtra): " << endl;
            cin >> _categoria;

            cout << "Ingrese el precio que desea establecer en dicha region de dicha categoria (ejm: 2000): " << endl;
            cin >> _precio;

            red.establecerPrecio(_region, _categoria, _precio);
            cout << "El precio se establecio correctamente para la region " << _region << " y la categoria " << _categoria << "." << endl;
            break;
        }

        case 5: {
            cout << "Saliendo al menu inicial..." << endl;
            break;
        }
        default:
            cout << "Opcion no valida" << endl;

        }
        cout << endl;

    }while (opcion != 5);
}

void gestionEstacionesDeServicio(RedNacional& red){
    unsigned short int opcion;

    do{
        cout << "Seleccione 1 para agregar o eliminar surtidor de una estacion de servicio" << endl;
        cout << "Seleccione 2 para activar o desactivar surtidor de una estacion de servicio" << endl;
        cout << "Seleccione 3 para consultar el historial de transacciones de cada surtidor de una estacion de servicio" << endl;
        cout << "Seleccione 4 para reportar la cantidad de litros vendida segun la categoria de combustible" << endl;
        cout << "Seleccione 5 para simular una venta de combustible" << endl;
        cout << "Seleccione 6 para asignar la capacidad del tanque de suministro" << endl;
        cout << "Ingrese #7 para salir al menu inicial" << endl;
        cin >> opcion;

        while (opcion > 7){
            cout << "Ingrese una opcion valida" << endl;
            cin >> opcion;
        }

        switch (opcion) {
        case 1: {
            cout << "Estaciones en servicio: " << endl;
            red.infoEstacionDeServicio();
            int codigo;
            cout << "Ingrese el codigo de la estacion de servicio donde quiera hacer la operacion" << endl;
            cin >> codigo;
            EstacionDeServicio* estaciones = red.getestaciones();
            EstacionDeServicio* estacion = nullptr;
            for (int i = 0; i < red.getcantidadEstaciones(); i++){
                if (estaciones[i].getcodigoIdentificador() == codigo){
                    estacion = &estaciones[i];
                    break;
                }
            }

            if(!estacion){
                cout << "Estacion de servicio no encontrada" << endl;
                break;
            }

            cout << "Surtidores en la estacion de servicio" << codigo << endl;
            estacion->infoSurtidores();

            int opcion;
            cout << "Opciones: " << endl;
            cout << "1: Agregar surtidor" << endl;
            cout << "2: Eliminar surtidor" << endl;
            cin >> opcion;

            if (opcion == 1) {
                int codigoSurtidor;
                string modeloMaquina;
                cout << "Ingrese el codigo del nuevo surtidor: ";
                cin >> codigoSurtidor;
                cout << "Ingrese Modelo de maquina: ";
                cin >> modeloMaquina;
                estacion->agregarsurtidor(codigoSurtidor, modeloMaquina);

            } else if (opcion == 2) {
                int codigoSurtidor;
                cout << "Ingrese el codigo del surtidor a eliminar: ";
                cin >> codigoSurtidor;
                estacion->eliminarsurtidor(codigoSurtidor);
                estacion->infoSurtidores();

            } else {
                cout << "Opcion no valida." << endl;
            }
            break;

        }

        case 2: {
            cout << "Estaciones en servicio" << endl;
            red.infoEstacionDeServicio();
            int codigo;
            cout << "Ingrese el codgio de la estacion donde desea realizar la operacion: " << endl;
            cin >> codigo;

            EstacionDeServicio* estaciones = red.getestaciones();
            EstacionDeServicio* estacion = nullptr;

            for(int i = 0; i < red.getcantidadEstaciones(); i++){
                if (estaciones[i].getcodigoIdentificador() == codigo){
                    estacion = &estaciones[i];
                    break;
                }
            }

            if(!estacion) {
                cout << "Estacion de servicio no encontrada" << endl;
                break;
            }

            cout << "Surtidores en la estacion de servicio" << codigo << endl;
            estacion->infoSurtidores();

            int codigoSurtidor;
            cout << "Ingrese el codigo del surtidor que desea activar o desactivar" << endl;
            cin >> codigoSurtidor;

            bool estado;
            cout << "Ingrese A para activar o D para desactivar el surtidor: " << endl;
            cin >> estado;

            estacion->activar_desactivarSurtidor(codigoSurtidor, estado);
            break;

        }

        case 3: {
            red.infoEstacionDeServicio();
            int codigo;
            cout << "Ingrese el codigo de la estacion de la cual desea desea conocer sus transacciones" << endl;
            cin >> codigo;

            EstacionDeServicio* estacion = red.EstacionEnRed(codigo);
            if (estacion == nullptr) {
                cout << "No se a encontrado la estacion seleccionada" << endl;
                break;
            }

            cout << "Reporte de transacciones para la estacion" << codigo << endl;
            for (int i = 0; i < estacion->getnumSurtidores(); i++){
                cout << "Surtidor: " << estacion->getSurtidores()[i].getcodigoSurtidor() << endl;
                estacion->historialTransacciones(i);
            }

            break;
        }

        case 4: {
            red.infoEstacionDeServicio();
            int codigo;
            cout << "Ingrese el codigo de la estacion en la cual desea reportar los litros vendidos: " << endl;
            cin >> codigo;

            EstacionDeServicio* estacion = red.EstacionEnRed(codigo);
            if(estacion == nullptr){
                cout << "La estacion no se a podido encontrar" << endl;
                break;
            }

            cout << "Reporte de litros vendidos en la estacion" << codigo << endl;
            estacion->reporteLitrosVendidos();
            break;
        }

        case 5: {
            simulacion(red);
            break;
        }

        case 6: {
            cout << "La capacidad del tanque se inicializa de forma automatica en el momento de crear una estacion de servicio" << endl;
            break;
        }

        case 7: {
            cout << "Saliendo del sistema..." << endl;
            break;
        }

        default: {
            cout << "Opcion no valida" << endl;
        }
        }
    }while(opcion != 7);
}

void simulacion(RedNacional& red){
    cout << "Las estaciones en servicio son: " << endl;
    red.infoEstacionDeServicio();
    int codigoEstacion;
    cout << "Ingrese el codigo de la estacion para simular la venta" << endl;
    cin >> codigoEstacion;

    EstacionDeServicio* estacion = red.EstacionEnRed(codigoEstacion);
    estacion->simularVenta(red);
}

void verificarFuga(RedNacional& red){
    cout << "Las estaciones en servicio son: " << endl;
    red.infoEstacionDeServicio();
    int codigoEstacion;
    cout << "Ingrese el codigo de la estacion en la cual quiere verificar si existen fugas" << endl;
    cin >> codigoEstacion;

    EstacionDeServicio* estacion = red.EstacionEnRed(codigoEstacion);
    Tanque tanque = estacion->gettanque();
    Surtidor* surtidores = estacion->getSurtidores();
    int numSurtidores = estacion->getnumSurtidores();

    estacion->verificarFugas(tanque, surtidores, numSurtidores);
}
