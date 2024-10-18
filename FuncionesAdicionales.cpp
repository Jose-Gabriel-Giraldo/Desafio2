#include "funcionesadicionales.h"
#include <iostream>
#include "RedNacional.h"
#include "transacciones.h"

using namespace std;

void gestionDeRed(RedNacional& red){
    unsigned short int opcion;

    do{
        cout << "            ____ Menu de gestion de red ____" << endl;
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

            while(region != "Norte" && region != "Centro" && region != "Sur"){
                cout << "Ingrese una de las tres regiones mencionadas (Norte, Centro, Sur, recuerde iniciar con mayuscula)." << endl;
                cin >> region;
            }

            cout << "Ingrese la longitud para las coordenadas de la estacion (ejm: 41.40338): " << endl;
            cin >> longitud;

            cout << "Ingrese la latitud para las coordenadas de la estacion (ejm: 2.17403): " << endl;
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

            while(_region != "Norte" && _region != "Centro" && _region != "Sur"){
                cout << "Ingrese una de las tres regiones mencionadas (Norte, Centro, Sur, recuerde iniciar con mayuscula)." << endl;
                cin >> _region;
            }

            cout << "Ingrese la categoria del combustible (Regular, Premium, EcoExtra): " << endl;
            cin >> _categoria;

            unsigned short int pres = red.obtenerPrecioPorRegiones(_region, _categoria);
            cout << "El precio actual de la gasolina en la region " << _region << " para la categoria "<< _categoria << " es: " << pres << endl;

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
        cout << "            ____ Menu de gestion de estaciones ____" << endl;
        cout << "Seleccione 1 para agregar o eliminar surtidor de una estacion de servicio" << endl;
        cout << "Seleccione 2 para activar o desactivar surtidor de una estacion de servicio" << endl;
        cout << "Seleccione 3 para consultar el historial de transacciones de cada surtidor de una estacion de servicio" << endl;
        cout << "Seleccione 4 para reportar la cantidad de litros vendida segun la categoria de combustible" << endl;
        cout << "Seleccione 5 para asignar la capacidad del tanque de suministro" << endl;
        cout << "Ingrese 6 para salir al menu inicial" << endl;
        cin >> opcion;

        while (opcion > 6){
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


            int opcion;
            cout << "Opciones: " << endl;
            cout << "1: Agregar surtidor" << endl;
            cout << "2: Eliminar surtidor" << endl;
            cin >> opcion;

            if (opcion == 1) {
                int codigoSurtidor;
                string modeloMaquina;
                bool estado = true;
                cout << "Ingrese el codigo del nuevo surtidor: ";
                cin >> codigoSurtidor;
                cout << "Ingrese Modelo de maquina: ";
                cin >> modeloMaquina;
                estacion->agregarsurtidor(codigoSurtidor, modeloMaquina, estado);
                estacion->infoSurtidores();

            } else if (opcion == 2) {
                int codigoSurtidor;
                estacion->infoSurtidores();
                cout << "Ingrese el codigo del surtidor a eliminar: ";
                cin >> codigoSurtidor;

                estacion->eliminarsurtidor(codigoSurtidor);

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

            string actividad;
            cout << "Ingrese A para activar o D para desactivar el surtidor: " << endl;
            cin >> actividad;

            estacion->activar_desactivarSurtidor(codigoSurtidor, actividad);
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

            cout << "La capacidad del tanque se generara automaticamente" << endl;
            red.infoEstacionDeServicio();
            int codigo;
            cout << "Ingrese el codigo de la estacio1n de la cual desea consultar la capacidad del tanque: " << endl;
            cin >> codigo;

            EstacionDeServicio* estacion = red.EstacionEnRed(codigo);
            if(estacion == nullptr){
                cout << "La estación no se ha podido encontrar" << endl;
                break;
            }

            estacion->gettanque().asignarCapacidadAleatoria();
            cout << "Informacion del tanque de la estacion: " << codigo << endl;
            estacion->gettanque().mostrarInfo();
            break;
        }

        case 6: {
            cout << "Saliendo del sistema..." << endl;
            break;
        }

        default: {
            cout << "Opcion no valida" << endl;
        }
        }
    }while(opcion != 6);
}

void simulacion(RedNacional& red){
    int _codigoIdentificador;
    cout << "Ingrese el codigo de la estacion para simular la venta: " << endl;
    cin >> _codigoIdentificador;

    EstacionDeServicio* estacion = red.EstacionEnRed(_codigoIdentificador);

    if(estacion == nullptr){
        cout << "Estacion no encontrada" << endl;
        return;
    }

    if (estacion->surtidoresActivos() == 0) {
        cout << "No se encuentran surtidores para realizar las transacciones." << endl;
        return;
    }

    int surtidorRandom = -1;
    int numSurtidores = estacion->getnumSurtidores();
    Surtidor* surtidores = estacion->getSurtidores();

    if(numSurtidores > 0){
        bool found = false;
        do{
            int SurtidorIndex = rand()% numSurtidores;
            if (surtidores[SurtidorIndex].getestado() == true){
                surtidorRandom = SurtidorIndex;
                found = true;
            }
        }while (!found);
    }else {
        cout << "No hay surtidores disponibles" << endl;
    }

    unsigned int cantidadLitros = 3 + rand() % 18;
    string categoriaCombustible;
    int categoriaRandom = rand() % 3;
    switch (categoriaRandom) {
    case 0: {
        categoriaCombustible = "Regular";
        break;
    }

    case 1: {
        categoriaCombustible = "Premium";
        break;
    }

    case 2: {
        categoriaCombustible = "EcoExtra";
        break;
    }
    }

    string regionEstacion = estacion->getregion();
    int precio = red.obtenerPrecioPorRegiones(regionEstacion, categoriaCombustible);

    string metodoPago;
    unsigned short int metodoPagoRandom = 1 + rand() % 3;
    switch (metodoPagoRandom) {
    case 1: {
        metodoPago = "Efectivo";
        break;
    }

    case 2: {
        metodoPago = "TDebito";
        break;
    }

    case 3: {
        metodoPago = "TCredito";
        break;
    }
    }


    string documentoUsuario = "";
    for (int i = 0; i < 6; i++) {
        documentoUsuario += to_string(rand() % 10);
    }

    cantidadLitros = estacion->gettanque().gasolinaVendida(cantidadLitros, categoriaCombustible);
    int cantidadDinero = cantidadLitros * precio;
    surtidores[surtidorRandom].reportarTransaccion(cantidadLitros, cantidadDinero, metodoPago, documentoUsuario, categoriaCombustible);


    cout << "Simulacion realizada con exito en el surtidor " << surtidores[surtidorRandom].getcodigoSurtidor() << endl;
    surtidores[surtidorRandom].gettransacciones()[surtidores[surtidorRandom].getnumTransacciones() -1].mostrarInformacion();
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
