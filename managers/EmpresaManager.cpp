#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "EmpresaManager.h"

#include <iostream>
#include <cstring>

using namespace std;

void EmpresaManager::buscar(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int id, posicion;
    int todasLasEmpresas = empArchivo.getCantidadEmpresas();

    if(todasLasEmpresas > 0){
        for(int i = 0; i < todasLasEmpresas; i++){
            registro = empArchivo.leer(i);
            cout << registro.mostrarIdNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;

    }

    cout << "Ingrese el ID de empresa que desea buscar:";
    cin >> id;

    posicion = empArchivo.buscar(id);
    registro = empArchivo.leer(posicion);

    if(posicion >= 0){
        cout << endl;
        cout << "Datos del tipo de servicio" << endl;
        cout << endl;
        cout << "Clave                Valor" << endl;
        cout << "-------------------  ------------------------" << endl;
        cout << "id:                  " << registro.getId() << endl;
        cout << "Nombre:              " << registro.getNombre() << endl;
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
        cout << "El ID ingresado no fue encontrado." << endl;
    }

    cout << endl;
    system("pause");
}


void EmpresaManager::cargar(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int id;
    string nombre, cuit, direccion, telefono, email;
    bool estado;

    id = empArchivo.getCantidadEmpresas() + 1;

    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingresa CUIT: ";
    cin >> cuit;

    cout << "Ingrese dirección: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Ingrese teléfono: ";
    cin >> telefono;

    cout << "Ingrese email: ";
    cin.ignore();
    getline(cin, email);

    estado = true;

    registro = Empresa(id, nombre, cuit, direccion, telefono, email, estado);

    if(empArchivo.guardar(registro)){
        cout << endl;
        cout << "Nueva empresa guardada con éxito" << endl;
    }
    else{
        cout << endl;
        cout << "Error inesperado, no se guardó el registro." << endl;
    }

    cout << endl;
    system("pause");
}


void EmpresaManager::listarIdsNombres(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int cantidadEmpresas = empArchivo.getCantidadEmpresas();

    if(cantidadEmpresas >= 0){
        for(int i = 0; i < cantidadEmpresas; i ++){
            registro = empArchivo.leer(i);
            cout << registro.mostrarIdNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void EmpresaManager::listarEmpresas(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int cantidaEmpresas = empArchivo.getCantidadEmpresas();

    if(cantidaEmpresas >= 0){
        for(int i = 0; i < cantidaEmpresas; i ++){
            registro = empArchivo.leer(i);
            cout << registro.mostrarEnPantalla() << endl;
        }

        cout << endl;
        cout << "Total de empresas registrados: " << cantidaEmpresas << endl << endl;
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void EmpresaManager::EmpresasActivas(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int cantidadEmpresas = empArchivo.getCantidadEmpresas();
    int cantidadActivas = 0;
    bool estado;

    if(cantidadEmpresas >= 0){
        cout << "Empresas activos:" << endl;
        cout << "---------------------------" << endl;

        for(int i = 0; i < cantidadEmpresas; i++){
            registro = empArchivo.leer(i);
            estado = registro.getEstado();

            if(estado == true){
                cout << registro.getId() << "  ";
                cout << registro.getNombre() << "  ";
                cout << registro.getDireccion() << "  ";
                cout << registro.getTelefono() << "  ";
                cout << registro.getEmail() << endl;
            }
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void EmpresaManager::modificarEstado(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int id, posicion;
    bool estado;

    registro.mostrarIdNombre();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = empArchivo.buscar(id);

    if(posicion >= 0){
        registro = empArchivo.leer(posicion);
        estado = registro.getEstado();

        cout << "Estado acutal del tipo de servicio" << endl;
        cout << "  id:             " << registro.getId() << endl;
        cout << "  Nombre:         " << registro.getNombre() << endl;

        if(estado == 1){
            cout << "  Estado actual: Activo" << endl;
        }
        else{
            cout << "  Estado actual: Inactivo" << endl;
        }

        estado = !estado;

        cout << endl;

        if(estado == 1){
            cout << "El estado del masajista cambió a: Activo" << endl;
        }
        else{
            cout << "El estado del masajista cambió a: Inactivo" << endl;
        }

        registro.setEstado(estado);

        if (empArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Estado modificado y registro guardado con éxito." << endl;
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


void EmpresaManager::modificarDireccion(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int id, posicion;
    std::string direccion;

    registro.mostrarIdNombre();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = empArchivo.buscar(id);

    if(posicion >= 0){
        registro = empArchivo.leer(posicion);

        cout << "Valor por hora actual para:" << endl;
        cout << "  id: " << registro.getId() << endl;
        cout << "  Nombre: " << registro.getNombre() << endl;
        cout << "  Valor por hora: " << registro.getDireccion() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> direccion;

        registro.setDireccion(direccion);

        if (empArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Valor por hora y registro actualizados con éxito." << endl;
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


void EmpresaManager::modificarTelefono(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int id, posicion;
    std::string telefono;

    registro.mostrarIdNombre();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = empArchivo.buscar(id);

    if(posicion >= 0){
        registro = empArchivo.leer(posicion);

        cout << "Valor por hora actual para:" << endl;
        cout << "  id: " << registro.getId() << endl;
        cout << "  Nombre: " << registro.getNombre() << endl;
        cout << "  Valor por hora: " << registro.getTelefono() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> telefono;

        registro.setTelefono(telefono);

        if (empArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Valor por hora y registro actualizados con éxito." << endl;
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


void EmpresaManager::modificarEmail(){
    EmpresaArchivo empArchivo;
    Empresa registro;

    int id, posicion;
    std::string email;

    registro.mostrarIdNombre();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = empArchivo.buscar(id);

    if(posicion >= 0){
        registro = empArchivo.leer(posicion);

        cout << "Valor por hora actual para:" << endl;
        cout << "  id: " << registro.getId() << endl;
        cout << "  Nombre: " << registro.getNombre() << endl;
        cout << "  Valor por hora: " << registro.getEmail() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> email;

        registro.setEmail(email);

        if (empArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Valor por hora y registro actualizados con éxito." << endl;
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
