#include "Masajista.h"
#include "MasajistaArchivo.h"
#include "MasajistaManager.h"
#include "Validacion.h"

#include <iostream>
#include <string>

using namespace std;

void MasajistaManager::buscarMasajista(){
    MasajistaArchivo mArchivo;
    Masajista registro;

    string dni;
    int posicion;

    int todoLosMasajistas = mArchivo.getCantidadMasajistas();

    if(todoLosMasajistas > 0){
        for(int i = 0; i < todoLosMasajistas; i++){
            registro = mArchivo.leer(i);
            cout << registro.mostrarDniNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    cout << "Ingrese el DNI del masajista: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    registro = mArchivo.leer(posicion);

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
    MasajistaArchivo mArchivo;
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

    cout << "Ingrese Telófono: ";
    cin >> telefono;

    cout << "Ingrese E-mail: ";
    cin >> email;

    estado = true;

    registro = Masajista(dni, nombre, apellido, cuit, direccion, telefono, email, estado);

    if(mArchivo.guardar(registro)){
        cout << endl;
        cout << "Nuevo masajista guardado con �xito." << endl;
    }
    else{
        cout << endl;
        cout << "Error inesperado, no se guard� el registro" << endl;
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::listarDnisNombres(){
    MasajistaArchivo mArchivo;
    Masajista registro;

    int cantidadEmpresas = mArchivo.getCantidadMasajistas();

    if(cantidadEmpresas >= 0){
        for(int i = 0; i < cantidadEmpresas; i ++){
            registro = mArchivo.leer(i);
            cout << registro.mostrarDniNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void MasajistaManager::listarMasajistas(){
    MasajistaArchivo mArchivo;
    Masajista registro;

    int todoLosMasajistas = mArchivo.getCantidadMasajistas();

    if(todoLosMasajistas > 0){
        for(int i = 0; i < todoLosMasajistas; i++){
            registro = mArchivo.leer(i);
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
    MasajistaArchivo mArchivo;
    Masajista registro;

    int todoLosMasajistas = mArchivo.getCantidadMasajistas();
    int cantidadActivos = 0;
    bool estado;

    if(todoLosMasajistas > 0){
        for(int i = 0; i < todoLosMasajistas; i++){
            registro = mArchivo.leer(i);
            estado = registro.getEstado();

            if(estado == true){
                cout << registro.mostrarDniNombre() << endl;

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


void MasajistaManager::mostrarCantidadMasajistas(){
    MasajistaArchivo mArchivo;

    int cantidadMasajistas = mArchivo.getCantidadMasajistas();

    cout << endl;
    cout << "Cantidad total de masajistas en la empresa: " << cantidadMasajistas << endl;
}


// Modificadores de registros

void MasajistaManager::modificarApellido(){
    MasajistaArchivo mArchivo;
    MasajistaManager mManager;
    Masajista registro;

    int posicion;
    std::string apellido, dni;

    mManager.listarDnisNombres();

    cout << "Ingrese el ID del masajista a modificar: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    if(posicion >= 0){
        registro = mArchivo.leer(posicion);

        cout << "El apellido actual es:" << endl;
        cout << "  id:        " << registro.getDni() << endl;
        cout << "  Nombre:    " << registro.getNombre() << endl;
        cout << "  Apellido:  " << registro.getApellido() << endl;

        cout << endl;
        cout << "Ingrese el nuevo apellido: ";
        cin >> apellido;

        registro.setDireccion(apellido);

        if (mArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Apellido y registro actualizados con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha ocurrido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el ID buscado." << endl;
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


void MasajistaManager::modificarCuit(){
    MasajistaArchivo mArchivo;
    MasajistaManager mManager;
    Masajista registro;

    int posicion;
    std::string cuit, dni;

    mManager.listarDnisNombres();

    cout << "Ingrese el ID del masajista a modificar: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    if(posicion >= 0){
        registro = mArchivo.leer(posicion);

        cout << "El CUIT actual es:" << endl;
        cout << "  id:        " << registro.getDni() << endl;
        cout << "  Nombre:    " << registro.getNombre() << " " << registro.getApellido() << endl;
        cout << "  CUIT:      " << registro.getCuit() << endl;
        cout << endl;
        cout << "Ingrese el nuevo CUIT: ";
        cin >> cuit;

        registro.setDireccion(cuit);

        if (mArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "CUIT y registro actualizados con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha ocurrido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el ID buscado." << endl;
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


void MasajistaManager::modificarDireccion(){
    MasajistaArchivo mArchivo;
    MasajistaManager mManager;
    Masajista registro;

    int posicion;
    std::string direccion, dni;

    mManager.listarDnisNombres();

    cout << "Ingrese el ID del masjista a modificar: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    if(posicion >= 0){
        registro = mArchivo.leer(posicion);

        cout << "La dirección actual es:" << endl;
        cout << "  id:        " << registro.getDni() << endl;
        cout << "  Nombre:    " << registro.getNombre() << "  " << registro.getApellido() << endl;
        cout << "  Dirección: " << registro.getDireccion() << endl;

        cout << endl;
        cout << "Ingrese la nueva dirección: ";
        cin >> direccion;

        registro.setDireccion(direccion);

        if (mArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Dirección y registro actualizados con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha ocurrido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el ID buscado." << endl;
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


void MasajistaManager::modificarEmail(){
    MasajistaArchivo mArchivo;
    MasajistaManager mManager;
    Masajista registro;

    int posicion;
    std::string dni, email;

    mManager.listarDnisNombres();

    cout << "Ingrese el ID del masajista a modificar: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    if(posicion >= 0){
        registro = mArchivo.leer(posicion);

        cout << "El E-mail actual es:" << endl;
        cout << "  id:        " << registro.getDni() << endl;
        cout << "  Nombre:    " << registro.getNombre() << " " << registro.getApellido() << endl;
        cout << "  E-mail:    " << registro.getEmail() << endl;

        cout << endl;
        cout << "Ingrese el nuevo E-mail: ";
        cin >> email;

        registro.setEmail(email);

        if (mArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "E-mail y registro actualizados con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha ocurrido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el ID buscado." << endl;
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


void MasajistaManager::modificarEstado(){
    MasajistaArchivo masArchivo;
    Masajista registro;

    string dni;
    bool estado;
    int posicion;

    masajistasActivos();

    cout << "Ingrese el DNI del masajista: ";
    cin >> dni;

    posicion = masArchivo.buscar(dni);

    if(posicion >= 0){
        registro = masArchivo.leer(posicion);
        estado = registro.getEstado();

        cout << "El estado acutal del masajista es: " << endl;
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
            cout << "Estado modificado y registro guardado con �xito." << endl;
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


void MasajistaManager::modificarNombre(){
    MasajistaArchivo mArchivo;
    MasajistaManager mManager;
    Masajista registro;

    int posicion;
    std::string dni, nombre;

    mManager.listarDnisNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    if(posicion >= 0){
        registro = mArchivo.leer(posicion);

        cout << "El nombre actual del masajista es:" << endl;
        cout << "  id:      " << registro.getDni() << endl;
        cout << "  Nombre:  " << registro.getNombre() << endl;
        cout << endl;
        cout << "Ingrese el nuevo nombre: ";
        cin >> nombre;

        registro.setNombre(nombre);

        if (mArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Nombre y registro actualizados con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha ocurrido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el ID buscado." << endl;
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


void MasajistaManager::modificarTelefono(){
    MasajistaArchivo mArchivo;
    MasajistaManager mManager;
    Masajista registro;

    int posicion;
    std::string dni, telefono;

    mManager.listarDnisNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> dni;

    posicion = mArchivo.buscar(dni);

    if(posicion >= 0){
        registro = mArchivo.leer(posicion);

        cout << "El teléfono actual del masajista es:" << endl;
        cout << "  id:        " << registro.getDni() << endl;
        cout << "  Nombre:    " << registro.getNombre() << " " << registro.getApellido() << endl;
        cout << "  Teléfono:  " << registro.getTelefono() << endl;
        cout << endl;
        cout << "Ingrese el nuevo número de telérono: ";
        cin >> telefono;

        registro.setNombre(telefono);

        if (mArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Teléfono y registro actualizados con éxito." << endl;
        }
        else{
            cout << endl;
            cout << "Ha ocurrido un error al intentar modificar el registro." << endl;
        }

    }
    else{
        if (posicion == -1){
            cout << endl;
            cout << "No existe el ID buscado." << endl;
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

