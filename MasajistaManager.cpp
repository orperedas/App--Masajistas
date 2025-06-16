#include "MasajistaManager.h"
#include "Masajista.h"

#include <iostream>
#include <string>

using namespace std;

void MasajistaManager::cargarMasajista(){

    Masajista masajista;

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
}
