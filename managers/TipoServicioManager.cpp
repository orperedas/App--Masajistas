#include "TipoServicio.h"
#include "TipoServicioArchivo.h"
#include "TipoServicioManager.h"
//#include "Validacion.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void TipoServicioManager::buscar(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;
//    Validacion validador;

    int id, posicion;

    int todoLosTipos = tsArchivo.getCantidadTipos();

    if(todoLosTipos > 0){
        for(int i = 0; i < todoLosTipos; i++){
            registro = tsArchivo.leer(i);
            cout << registro.mostrarIdNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;

    cout << "Ingrese el ID del tipo de servicio: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    registro = tsArchivo.leer(posicion);

    if(posicion >= 0){
        cout << endl;
        cout << "Datos del tipo de servicio" << endl;
        cout << endl;
        cout << "Clave                Valor" << endl;
        cout << "---------------  ------------------------" << endl;
        cout << "id:              " << registro.getId() << endl;
        cout << "Nombre:          " << registro.getNombre() << endl;
        cout << "Descripción:     " << registro.getDescripcion() << endl;
        cout << "Modalidad:       " << registro.getModalidad() << endl;
        cout << "Valor por hora:  ";
        cout << std::fixed << std::setprecision(2) << registro.getValorHora() << endl;
        cout << "Estado:          " << registro.getEstado() << endl;

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


void TipoServicioManager::cargar(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id;
    string nombre, descripcion, modalidad;
    float valorHora;
    bool estado;

    id = tsArchivo.getCantidadTipos() + 1;

    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese descripción: ";
    getline(cin, descripcion);

    cout << "Ingrese modalidad: ";
    cin >> modalidad;

    cout << "Ingrese valor por hora: ";
    cin >> valorHora;

    estado = true;

    registro = TipoServicio(id, nombre, descripcion, modalidad, valorHora, estado);

    if(tsArchivo.guardar(registro)){
        cout << endl;
        cout << "Nuevo Tipo de Servicio guardado con éxito." << endl;
    }
    else{
        cout << endl;
        cout << "Error inesperado, no se guardó el registro" << endl;
    }

    cout << endl;
    system("pause");
}


void TipoServicioManager::listarIdsNombres(){
    TipoServicioArchivo empArchivo;
    TipoServicio registro;

    int cantidadTipoServicios = empArchivo.getCantidadTipos();

    if(cantidadTipoServicios >= 0){
        for(int i = 0; i < cantidadTipoServicios; i ++){
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


void TipoServicioManager::listarTipoServicios(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int todoLosTipos = tsArchivo.getCantidadTipos();

    if(todoLosTipos > 0){
        for(int i = 0; i < todoLosTipos; i++){
            registro = tsArchivo.leer(i);
            cout << registro.mostrarEnPantalla() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void TipoServicioManager::TiposServiciosActivos(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int todoLosTipos = tsArchivo.getCantidadTipos();
    int cantidadActivos = 0;
    bool estado;

    if(todoLosTipos > 0){
        cout << "Tipos de Servicios Activos:" << endl;
        cout << "---------------------------" << endl;
        for(int i = 0; i < todoLosTipos; i++){
            registro = tsArchivo.leer(i);
            estado = registro.getEstado();

            if(estado == true){
                cout << registro.getId() << "   ";
                cout << registro.getNombre() << "   ";
                cout << registro.getModalidad() << "   ";
                cout << registro.getValorHora() << endl;

                cantidadActivos ++;
            }
        }

        cout << endl;
        cout << "Total de tipos de servicios activos: " << cantidadActivos << endl;
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}



// Modificadores de registros

void TipoServicioManager::modificarDescripcion(){
    TipoServicioArchivo tsArchivo;
    TipoServicioManager tsManager;
    TipoServicio registro;

    int id, posicion;
    std::string descripcion;

    tsManager.listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    if(posicion >= 0){
        registro = tsArchivo.leer(posicion);

        cout << "Descripción actual para:" << endl;
        cout << "  id:        " << registro.getId() << endl;
        cout << "  Nombre:    " << registro.getNombre() << endl;
        cout << "  Dirección: " << registro.getDescripcion() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> descripcion;

        registro.setDescripcion(descripcion);

        if (tsArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Descripción y registro actualizados con éxito." << endl;
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


void TipoServicioManager::modificarEstado(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id, posicion;
    bool estado;
    int cantidadTipoServicio = tsArchivo.getCantidadTipos();

    TipoServicioManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    if(posicion >= 0){
        registro = tsArchivo.leer(posicion);
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

        if (tsArchivo.guardar(registro, posicion)){
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


void TipoServicioManager::modificarModalidad(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id, posicion;
    std::string modalidad;

    TipoServicioManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    if(posicion >= 0){
        registro = tsArchivo.leer(posicion);

        cout << "Modalidad actual del Tipo de Servicio:" << endl;
        cout << "  id:        " << registro.getId() << endl;
        cout << "  Nombre:    " << registro.getNombre() << endl;
        cout << "  Teléfono:  " << registro.getModalidad() << endl;
        cout << endl;
        cout << "Ingrese la nuevo modalidad: ";
        cin >> modalidad;

        registro.setNombre(modalidad);

        if (tsArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Modalidad y registro actualizados con éxito." << endl;
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


void TipoServicioManager::modificarNombre(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id, posicion;
    std::string nombre;

    TipoServicioManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    if(posicion >= 0){
        registro = tsArchivo.leer(posicion);

        cout << "Nombre actual del Tipo de Servicio:" << endl;
        cout << "  id:      " << registro.getId() << endl;
        cout << "  Nombre:  " << registro.getNombre() << endl;
        cout << endl;
        cout << "Ingrese el nuevo nombre: ";
        cin >> nombre;

        registro.setNombre(nombre);

        if (tsArchivo.guardar(registro, posicion)){
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


void TipoServicioManager::modificarValorHora(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id, posicion;
    float valorHora;

    registro.mostrarIdNombre();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    if(posicion >= 0){
        registro = tsArchivo.leer(posicion);

        cout << "Valor por hora actual para:" << endl;
        cout << "  id: " << registro.getId() << endl;
        cout << "  Nombre: " << registro.getNombre() << endl;
        cout << "  Valor por hora: " << registro.getValorHora() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> valorHora;

        registro.setValorHora(valorHora);

        if (tsArchivo.guardar(registro, posicion)){
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
