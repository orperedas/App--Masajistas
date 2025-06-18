#include "Masajista.h"
#include "MasajistaArchivo.h"
#include "MasajistaManager.h"

#include <iostream>
#include <string>

using namespace std;

void MasajistaManager::cargarMasajista(){

    Masajista masajista;
    MasajistaArchivo masArchivo;

    string dni, nombre, apellido, cuit, direccion, telefono, email;

    cout << "Ingrese DNI: ";
    cin >> dni;

    cout << "Ingrese Nombre: ";
    cin >> nombre;

    cout << "Ingrese Apellido: ";
    cin >> apellido;

    cout << "Ingrese CUIT: ";
    cin >> cuit;

    cout << "Ingrese Dirección: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Ingrese Teléfono: ";
    cin >> telefono;

    cout << "Ingrese E-mail: ";
    cin >> email;

    cout << "Dirección: " << direccion << endl;

    masajista = Masajista(dni, nombre, apellido, cuit, direccion, telefono, email);

    if(masArchivo.guardar(masajista)){
        cout << "Nuevo masajista guardado con éxito." << endl;
    }
    else{
        cout << "Error inesperado, no se guardó el registro" << endl;
    }
}


void MasajistaManager::listarMasajistas(){
    MasajistaArchivo masArchivo;
    Masajista registro;

    int todoLosMasajistas = masArchivo.getCantidadMasajistas();

    for(int i = 0; i < todoLosMasajistas; i++){
        registro = masArchivo.leer(i);

        cout << registro.toCsv() << endl;
    }
}


void MasajistaManager::mostrarCantidadMasajistas(){
    MasajistaArchivo masArchivo;

    int cantidadMasajistas = masArchivo.getCantidadMasajistas();

    cout << "Cantidad total de masajistas en la empresa: " << cantidadMasajistas << endl;
}
