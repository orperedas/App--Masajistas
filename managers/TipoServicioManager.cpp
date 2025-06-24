#include "TipoServicio.h"
#include "TipoServicioArchivo.h"
#include "TipoServicioManager.h"

#include <iostream>
#include <string>

using namespace std;

void TipoServicioManager::buscarTipoServicio(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id, posicion;

    int todoLosTipos = tsArchivo.getCantidadTipos();

    if(todoLosTipos > 0){
        for(int i = 0; i < todoLosTipos; i++){
            registro = tsArchivo.leer(i);
            cout << registro.mostrarIdNombreTipo() << endl;
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
        cout << "-------------------  ------------------------" << endl;
        cout << "id:                 " << registro.getId() << endl;
        cout << "Nombre:              " << registro.getNombre() << endl;
        cout << "Apellido:            " << registro.getDescripcion() << endl;
        cout << "Dirección:           " << registro.getModalidad() << endl;
        cout << "Teléfono:            " << registro.getValorHora() << endl;
        cout << "Correo electrónico:  " << registro.getEstado() << endl;

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


void TipoServicioManager::cargarTipoServicio(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id;
    string nombre, descripcion, modalidad;
    float valorHora;
    bool estado;

    cout << "Ingrese id: ";
    cin >> id;

    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese descripción: ";
    cin >> descripcion;

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
        for(int i = 0; i < todoLosTipos; i++){
            registro = tsArchivo.leer(i);
            estado = registro.getEstado();

            if(estado == true){
                cout << registro.getId() << " ";
                cout << registro.getNombre() << " ";
                cout << registro.getDescripcion() << ": ";
                cout << registro.getModalidad() << ": ";
                cout << registro.getValorHora() << ": ";

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


void TipoServicioManager::modificarEstadoTipoServicio(){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int id, posicion;
    bool estado, cambiarEstado;

    registro.mostrarIdNombreTipo();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = tsArchivo.buscar(id);

    if(posicion >= 0){
        registro = tsArchivo.leer(posicion);
        estado = registro.getEstado();

        cout << "Estado acutal del tipo de servicio" << endl;
        cout << "  id: " << registro.getId() << endl;
        cout << "  Nombre: " << registro.getNombre() << endl;

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
