#include "RedNacional.h"
#include "estaciondeservicio.h"
#include "tanque.h"
#include "surtidor.h"
#include "transacciones.h"
#include <iostream>
#include <string>

using namespace std;

EstacionDeServicio::EstacionDeServicio(string _nombreEstacion , string _gerente , int _codigoIdentificador, double _longitud, double _latitud, string _region)
    :nombreEstacion(_nombreEstacion), codigoIdentificador(_codigoIdentificador), gerente(_gerente), region(_region), tanque(), numSurtidores(0), longitud(_longitud), latitud(_latitud) {
    numSurtidores = 0;
}

string EstacionDeServicio::getnombreEstacion() {
    return nombreEstacion;
}

int EstacionDeServicio::getcodigoIdentificador() {
    return codigoIdentificador;
}

string EstacionDeServicio::getgerente() {
    return gerente;
}

string EstacionDeServicio::getregion() {
    return region;
}

double EstacionDeServicio::getlongitud() {
    return longitud;
}

double EstacionDeServicio::getlatitud() {
    return latitud;
}

Tanque& EstacionDeServicio::gettanque() {
    return tanque;
}

Surtidor* EstacionDeServicio::getSurtidores() {
    return surtidores;
}

int EstacionDeServicio::surtidoresActivos() {
    int activos = 0;
    for (int i = 0; i < numSurtidores; i++){
        if(surtidores[i].getestado() == true){
            activos++;
        }
    }
    return activos;
}

int EstacionDeServicio::getnumSurtidores() {
    return numSurtidores;
}

void EstacionDeServicio::setnombreEstacion(string& nombreEstacion){
    nombreEstacion = nombreEstacion;
}

void EstacionDeServicio::setcodigoIdentificador(int _codigoIdentificador){
    codigoIdentificador = _codigoIdentificador;
}

void EstacionDeServicio::setgerente(string& _gerente){
    gerente = _gerente;
}

void EstacionDeServicio::setregion(string &_region){
    region = _region;
}

void EstacionDeServicio::setlongitud(double _longitud){
    longitud = _longitud;
}

void EstacionDeServicio::setlatitud(double _latitud){
    latitud = _latitud;
}

void EstacionDeServicio::setTanque(Tanque& nuevotanque){
    tanque = nuevotanque;
}

void EstacionDeServicio::agregarsurtidor(int codigoSurtidor, string modeloSurtidor){
    if(numSurtidores > 12){
        cout << "No se puede agregar mas estaciones de surtidores en la estacion de servicio" << endl;
        return ;
    }

    surtidores[numSurtidores] = Surtidor(codigoSurtidor, modeloSurtidor);
    numSurtidores++;
    cout << "Surtidor agregado correctamente" << endl;
}

void EstacionDeServicio::eliminarsurtidor(int codigoSurtidor){
    int indiceSurtidor = -1;
    for (int i = 0; i < numSurtidores; i++){
        if (surtidores[i].getcodigoSurtidor() == codigoSurtidor){
            indiceSurtidor = i;
            break;
        }
    }

    if (indiceSurtidor == -1){
        cout << "No se a podido encontrar un surtidor con el codigo" << codigoSurtidor << endl;
        return;
    }

    if(surtidores[indiceSurtidor].getestado() == true){
        cout << "No es posible eliminar un surtidor activo" << endl;
        return;
    }

    for(int i = 0; i < numSurtidores - 1; i++){
        surtidores[i] = surtidores[i + 1];
    }

    numSurtidores--;
    cout << "Surtidor eliminado correctamente." << endl;
}

void EstacionDeServicio::activar_desactivarSurtidor(int codigoSurtidor, bool estado){
    int indiceSurtidor = -1;

    for (int i = 0; i < numSurtidores; i++){
        if (surtidores[i].getcodigoSurtidor() == codigoSurtidor){
            indiceSurtidor = i;
            break;
        }
    }

    if (indiceSurtidor = -1){
        cout << "No se a podido encontrar un surtidor con el codigo" << endl;
        return;
    }

    if (surtidores[indiceSurtidor].getestado() == true){
        cout << "El estado del surtidor es: " << (true ? "Activado" : "Desactivado") << endl;
        return;
    }

    surtidores[indiceSurtidor].activarSurtidor_desactivarSurtidor(estado);
    cout << "Surtidor" << (estado ? true : false);
}

void EstacionDeServicio::calcularTransacciones(){
    unsigned long int totalVentasRegular = 0;
    unsigned long int totalVentasPremium = 0;
    unsigned long int totalVentasEcoExtra = 0;

    for(int i = 0; i < numSurtidores; i++){
        for(int j = 0; j < surtidores[i].getnumTransacciones(); j++){
            const Transaccion& transacciones = surtidores[i].gettransacciones()[j];

            if(transacciones.getcategoriaCombustible() == "Regular"){
                totalVentasRegular += transacciones.getcantidadDinero();

            }else if(transacciones.getcategoriaCombustible() == "Premium"){
                totalVentasPremium += transacciones.getcantidadDinero();

            }else if(transacciones.getcategoriaCombustible() == "EcoExtra"){
                totalVentasEcoExtra += transacciones.getcantidadDinero();
            }
        }
    }

    cout << "Venta total por categoria: " << endl;
    cout << "Regular" << totalVentasRegular << endl;
    cout << "Premium" << totalVentasPremium << endl;
    cout << "EcoExtra" << totalVentasEcoExtra << endl;

}

void EstacionDeServicio::infoSurtidores() {
    if(numSurtidores = 0){
        cout << "No se encuentran surtidores en la estacion" << endl;
        return;
    }
    cout << "Surtidores de la estacion" << endl;
    for (int i = 0; i < numSurtidores; i++){
        cout << "\n" << endl;
        cout << "Codigo del surtidor: " << surtidores[i].getcodigoSurtidor() << endl;
        cout << " Modelo del surtidor: " << surtidores[i].getmodeloMaquina() << endl;
        cout << " Estado: " << surtidores[i].getestado() << endl;
        cout << "\n" << endl;
    }
}

void EstacionDeServicio::historialTransacciones(int posicion) {
    if (posicion < 0 || posicion >= numSurtidores){
        cout << "Surtidor no encontrado" << endl;
        return;
    }
    surtidores[posicion].consultarTransaccion();
}

void EstacionDeServicio::reporteLitrosVendidos(){
    int catidadLitrosVendidosRegular = 0;
    int catidadLitrosVendidosPremium = 0;
    int catidadLitrosVendidosEcoExtra = 0;

    for(int i = 0; i < numSurtidores; i++){
        for(int j = 0; j < surtidores[i].getnumTransacciones(); j++){
            if(surtidores[i].gettransacciones()[j].getcategoriaCombustible() == "Regular"){
                catidadLitrosVendidosRegular += surtidores[i].gettransacciones()[j].getcantidadLitros();

            }else if (surtidores[i].gettransacciones()[j].getcategoriaCombustible() == "Premium"){
                catidadLitrosVendidosPremium += surtidores[i].gettransacciones()[j].getcantidadLitros();

            }else if (surtidores[i].gettransacciones()[j].getcategoriaCombustible() == "EcoExtra"){
                catidadLitrosVendidosEcoExtra += surtidores[i].gettransacciones()[j].getcantidadLitros();
            }
        }
    }

    cout << "Cantidad de litros vendidos Reluar: " << catidadLitrosVendidosRegular << endl;
    cout << "Cantidad de litros vendidos Premium: " << catidadLitrosVendidosPremium << endl;
    cout << "Cantidad de litros vendidos EcoExtra: " << catidadLitrosVendidosEcoExtra << endl;
}

/*void EstacionDeServicio::simularVenta(RedNacional& red){

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
}*/

void EstacionDeServicio::verificarFugas(Tanque& tanque, Surtidor* surtidores, int numSurtidores) {
    int vendidoRegular = 0, vendidoPremium = 0, vendidoEcoExtra = 0;

    for(int i = 0; i < numSurtidores; i++){
        for(int j = 0; j < surtidores[i].getnumTransacciones(); j++){
            const Transaccion& transaccion = surtidores[i].gettransacciones()[j];
            if (transaccion.getcategoriaCombustible() == "Regular") {
                vendidoRegular += transaccion.getcantidadLitros();
            } else if (transaccion.getcategoriaCombustible() == "Premium") {
                vendidoPremium += transaccion.getcantidadLitros();
            } else if (transaccion.getcategoriaCombustible() == "EcoExtra") {
                vendidoEcoExtra += transaccion.getcantidadLitros();
            }
        }
    }

    short int capacidadRegular = tanque.getcapacidadInicialRegular();
    short int capacidadPremium = tanque.getcapacidadInicialPremium();
    short int capacidadEcoExtra = tanque.getcapacidadInicialEcoExtra();

    short int almacenadoRegular = tanque.getcapacidadActualRegular();
    double almacenadoPremium = tanque.getcapacidadActualPremium();
    double almacenadoEcoExtra = tanque.getcapacidadActualEcoExtra();

    if ((vendidoRegular + almacenadoRegular) < 0.95 * capacidadRegular) {
        cout << "Se presenta una fuga pra el combustible regular" << endl;
    }
    else{
        cout << "No se presenta una fuga para el combustible regular" << endl;
    }
    if ((vendidoPremium + almacenadoPremium) < 0.95 * capacidadPremium) {
        cout << "Se presenta una fuga pra el combustible Premium." << endl;
    }
    else{
        cout << "No se presenta una fuga para el combustible Premium." << endl;
    }
    if ((vendidoEcoExtra + almacenadoEcoExtra) < 0.95 * capacidadEcoExtra) {
        cout << "Se presenta una fuga pra el combustible EcoExtra." << endl;
    }
    else{
        cout << "No se presenta una fuga para el combustible EcoExtra." << endl;
    }
    cout << "Verificacion de fugas completada." << endl;
}
