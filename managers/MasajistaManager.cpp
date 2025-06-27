#include "Masajista.h"
#include "MasajistaArchivo.h"
#include "MasajistaManager.h"
#include "Validacion.h"

#include <iostream>
#include <string>

using namespace std;

void MasajistaManager::buscarMasajista(){
    MasajistaArchivo masArchivo;
    Masajista registro;

    string dni;
    int posicion;

    int todoLosMasajistas = masArchivo.getCantidadMasajistas();

    if(todoLosMasajistas > 0){
        for(int i = 0; i < todoLosMasajistas; i++){
            registro = masArchivo.leer(i);
            cout << registro.mostrarDniNombreMasajistas() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    cout << "Ingrese el DNI del masajista: ";
    cin >> dni;

    posicion = masArchivo.buscar(dni);

    registro = masArchivo.leer(posicion);

    if(posicion >= 0){
        cout << endl;
        cout << "Datos del masajista" << endl;
        cout << endl;
        cout << "Clave                Valor" << endl;
        cout << "-------------------  ------------------------" << endl;
        cout << "DNI:                 " << registro.getDni() << endl;
        cout << "Nombre:              " << registro.getNombre() << endl;
        cout << "Apellido:            " << registro.getApellido() << endl;
        cout << "Dirección:           " << registro.getDireccion() << endl;
        cout << "Teléfono:            " << registro.getTelefono() << endl;
        cout << "Correo electrónico:  " << registro.getEmail() << endl;

        if(registro.getEstado() == true){
            cout << "Estado:              Activo" << endl;
        }
        else{
            cout << "Estado:              Inactivo" << endl;
        }
    }
    else{
        cout << endl;
        cout << "El DNI ingresado no fue encontrado." << endl;
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::cargarMasajista(){
    MasajistaArchivo masArchivo;
    Masajista registro;
//    Validacion validador;

    string dni, nombre, apellido, cuit, direccion, telefono, email;
    bool estado;

    cout << "Ingrese el DNI del masajista: ";
    cin >> dni;

    cout << "Ingrese Nombre: ";
    cin >> nombre;

    cout << "Ingrese Apellido: ";
    cin >> apellido;

    cout << "ingrese el CUIT: ";
    cin >> cuit;

    cout << "Ingrese Dirección: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Ingrese Teléfono: ";
    cin >> telefono;

    cout << "Ingrese E-mail: ";
    cin >> email;

    estado = true;

    registro = Masajista(dni, nombre, apellido, cuit, direccion, telefono, email, estado);

    if(masArchivo.guardar(registro)){
        cout << endl;
        cout << "Nuevo masajista guardado con éxito." << endl;
    }
    else{
        cout << endl;
        cout << "Error inesperado, no se guardó el registro" << endl;
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::listarMasajistas(){
    MasajistaArchivo masArchivo;
    Masajista registro;

    int todoLosMasajistas = masArchivo.getCantidadMasajistas();

    if(todoLosMasajistas > 0){
        for(int i = 0; i < todoLosMasajistas; i++){
            registro = masArchivo.leer(i);
            cout << registro.mostrarEnPantalla() << endl;
        }

        cout << endl;
        cout << "Total de masajistas registrados: " << todoLosMasajistas << endl << endl;
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::masajistasActivos(){
    MasajistaArchivo masArchivo;
    Masajista registro;

    int todoLosMasajistas = masArchivo.getCantidadMasajistas();
    int cantidadActivos = 0;
    bool estado;

    if(todoLosMasajistas > 0){
        for(int i = 0; i < todoLosMasajistas; i++){
            registro = masArchivo.leer(i);
            estado = registro.getEstado();

            if(estado == true){
                cout << registro.getDni() << " ";
                cout << registro.getNombre() << " ";
                cout << registro.getApellido() << ": ";
                cout << "Estado actual: Activo" << endl;

                cantidadActivos ++;
            }
        }

        cout << endl;
        cout << "Total de masajistas activos: " << cantidadActivos << endl;
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::modificarEstadoMasajista(){
    MasajistaArchivo masArchivo;
    Masajista registro;

    string dni;
    bool estado, cambiarEstado;
    int posicion;

    registro.mostrarDniNombreMasajistas();

    cout << "Ingrese el DNI del masajista: ";
    cin >> dni;

    posicion = masArchivo.buscar(dni);

    if(posicion >= 0){
        registro = masArchivo.leer(posicion);
        estado = registro.getEstado();

        cout << "Estado acutal del masajista" << endl;
        cout << "  DNI: " << registro.getDni() << endl;
        cout << "  Nombre: " << registro.getNombre() << " " << registro.getApellido() << endl;

        if(estado == 1){
            cout << "Estado actual: Activo" << endl;
        }
        else{
            cout << "Estado actual: Inactivo" << endl;
        }

        estado = !estado;

        cout << endl;
        cout << "Estado modificado a: " << estado << endl;

        registro.setEstado(estado);

        if (masArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Estado modificado y registro guardado con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha habido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el DNI buscado." << endl;
        }
        else{
            if (posicion == -2){
                cout << endl;
                cout << "No se ha encontrado el archivo." << endl;
            }
        }
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::mostrarCantidadMasajistas(){
    MasajistaArchivo masArchivo;

    int cantidadMasajistas = masArchivo.getCantidadMasajistas();

    cout << endl;
    cout << "Cantidad total de masajistas en la empresa: " << cantidadMasajistas << endl;
}
