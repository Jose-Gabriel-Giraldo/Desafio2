#include "RedNacional.h"
#include "tanque.h"
#include "surtidor.h"
#include "estaciondeservicio.h"
#include <iostream>

using namespace std;

RedNacional::RedNacional(): cantidadEstaciones(0){

    precioPorRegion[0][0] = 4000;
    precioPorRegion[0][1] = 8000;
    precioPorRegion[0][2] = 16000;

    precioPorRegion[1][0] = 2000;
    precioPorRegion[1][1] = 4000;
    precioPorRegion[1][2] = 8000;

    precioPorRegion[2][0] = 3000;
    precioPorRegion[2][1] = 6000;
    precioPorRegion[2][2] = 9000;

}

unsigned short int RedNacional::obtenerPrecioPorRegiones(string& _region, string& _categoria){
    int indiceRegion = -1;
    int indiceCategoria = -1;

    if(_region == "Norte"){
        indiceRegion = 0;

    }else if (_region == "centro"){
        indiceRegion = 1;

    }else if(_region == "Sur"){
        indiceRegion = 2;

    }else{
        cout << "No se encuentra la region: " << _region <<endl;
        return NULL;
    }

    if(_categoria == "Regular"){
        indiceCategoria = 0;

    }else if(_categoria == "Premium"){
        indiceCategoria = 1;

    }else if(_categoria == "EcoExtra"){
        indiceCategoria = 2;

    }else{
        cout << "Categoria de combustible no valida." << endl;
        return NULL;
    }

    return precioPorRegion[indiceRegion][indiceCategoria];
}

unsigned short int RedNacional::establecerPrecio(string& _region, string& _categoria, unsigned short int _precio){
    int indiceRegion = -1;
    int indiceCategoria = -1;

    if(_region == "Norte"){
        indiceRegion = 0;

    }else if (_region == "centro"){
        indiceRegion = 1;

    }else if(_region == "Sur"){
        indiceRegion = 2;

    }else{
        cout << "No se encuentra la region: " << _region <<endl;
        return NULL;
    }

    if(_categoria == "Regular"){
        indiceCategoria = 0;

    }else if(_categoria == "Premium"){
        indiceCategoria = 1;

    }else if(_categoria == "EcoExtra"){
        indiceCategoria = 2;

    }else{
        cout << "Categoria de combustible no valida." << endl;
        return NULL;
    }

    precioPorRegion[indiceRegion][indiceCategoria] = _precio;
}

void RedNacional::agregarEstacionDeServicio(string _nombreEstacion, string _gerente, int _codigoIdentificador, double _longitud, double _latitud, string _region) {
    if (cantidadEstaciones < 100) {
        estaciones[cantidadEstaciones] = EstacionDeServicio(_nombreEstacion, _gerente, _codigoIdentificador, _longitud, _latitud, _region);
        cantidadEstaciones++;
    }
}

void RedNacional::eliminarEstacionDeServicio(int _codigoIdentificador){
    for(int i = 0; i < cantidadEstaciones; i++){
        if(estaciones[i].getcodigoIdentificador() == _codigoIdentificador){
            if(estaciones[i].surtidoresActivos()== 0){
                for(int j = i; j < cantidadEstaciones - 1; j++){
                    estaciones[j] = estaciones[j + 1];
                }

                cantidadEstaciones--;
                cout << "Estacion eliminada correctamente" << endl;
                return;

            }else{
                cout << "No se puede eliminar la estacion porque tiene por lo menos 1 surtidor activo" <<endl;
                return;
            }

        }
    }
    cout << "No se encuentra la estacion con el codigo proporcionado" << endl;
}

void RedNacional::calcularMontoTransaccion(){
    for (int i=0; i < cantidadEstaciones; i++){
        cout << "Las ventas para la estacion" << estaciones[i].getnombreEstacion() << endl;
        estaciones[i].calcularTransacciones();
    }
}

void RedNacional::infoEstacionDeServicio(){
    if (cantidadEstaciones == 0) {
        cout << "No se encuentran estaciones de servicio dentro de la red" << endl;
    } else {
        cout << "Estaciones en servicio" << endl;
        for(int i = 0; i < cantidadEstaciones; i++){
            cout << "CodigoIdentificador: " << estaciones[i].getcodigoIdentificador() << endl;
            cout << "Nombre de la estacion: " << estaciones[i].getnombreEstacion() << endl;
            cout << "Region de la estacion: " << estaciones[i].getregion() << endl;
        }
    }
}

EstacionDeServicio* RedNacional::getestaciones(){
    return estaciones;
}

EstacionDeServicio* RedNacional::EstacionEnRed(int _codigoIdentificador){
    for(int i = 0; i < cantidadEstaciones; i++){
        if (estaciones[i].getcodigoIdentificador() == _codigoIdentificador){
            return &estaciones[i];
        }
    }
    return nullptr;
}

int RedNacional::getcantidadEstaciones(){
    return cantidadEstaciones;
}
