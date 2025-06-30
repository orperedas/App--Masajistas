#include "Sede.h"
#include "SedeArchivo.h"
#include "SedeManager.h"

#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "EmpresaManager.h"

#include <iostream>
#include <cstring>

using namespace std;

void SedeManager::buscar(){
    SedeArchivo sArchivo;
    Sede registroSede;

    EmpresaArchivo eArchivo;
    Empresa registroEmpresa;

    int id, posicion;
    int todasLasSedes = sArchivo.getCantidadSedes();

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID de Sede que desea buscar:";
    cin >> id;

    posicion = sArchivo.buscar(id);
    registroSede = sArchivo.leer(posicion);

    if(posicion >= 0){
        cout << endl;
        cout << "Datos del tipo de servicio" << endl;
        cout << endl;
        cout << "Clave                        Valor" << endl;
        cout << "---------------------------  ------------------------" << endl;
        cout << "id:                          " << registroSede.getId() << endl;
        cout << "Nombre:                      " << registroSede.getNombre() << endl;
        cout << "Dirección:                   " << registroSede.getDireccion() << endl;
        cout << "Teléfono:                    " << registroSede.getTelefono() << endl;
        cout << "Correo electrónico:          " << registroSede.getEmail() << endl;

        if(registroSede.getEstado() == true){
            cout << "Estado:                      Activo" << endl;
        }
        else{
            cout << "Estado:                      Inactivo" << endl;
        }

        if(registroSede.getIdEmpresa() == registroEmpresa.getId()){
            cout << "Empresa a la que pertenece:  " << registroEmpresa.getNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "El ID ingresado no fue encontrado." << endl;
    }

    cout << endl;
    system("pause");
}


void SedeManager::cargar(){
    SedeArchivo sArchivo;
    Sede registroSede;

    EmpresaManager empresaManager;
    Empresa registroEmpresa;

    int id, idEmpresa;
    string nombre, direccion, telefono, email;
    bool estado;

    id = sArchivo.getCantidadSedes() + 1;

    empresaManager.EmpresasActivas();

    cout << "Ingrese ID de la empresa a la que pertenece la sede:";
    cin >> idEmpresa;

    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese dirección: ";
    getline(cin, direccion);

    cout << "Ingrese teléfono: ";
    cin >> telefono;

    cout << "Ingrese email: ";
    cin.ignore();
    getline(cin, email);

    estado = true;

    registroSede = Sede(id, nombre, direccion, telefono, email, estado, idEmpresa);

    if(sArchivo.guardar(registroSede)){
        cout << endl;
        cout << "Nueva Sede guardada con éxito" << endl;
    }
    else{
        cout << endl;
        cout << "Error inesperado, no se guardó el registro." << endl;
    }

    cout << endl;
    system("pause");
}


void SedeManager::listarIdsNombres(){
    SedeArchivo sArchivo;
    Sede registro;

    int cantidadSedes = sArchivo.getCantidadSedes();

    if(cantidadSedes >= 0){
        for(int i = 0; i < cantidadSedes; i ++){
            registro = sArchivo.leer(i);
            cout << registro.mostrarIdNombre() << endl;
        }
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
}


void SedeManager::listarSedes(){
    SedeArchivo sArchivo;
    Sede registro;

    int cantidaSedes = sArchivo.getCantidadSedes();

    if(cantidaSedes >= 0){
        for(int i = 0; i < cantidaSedes; i ++){
            registro = sArchivo.leer(i);
            cout << registro.mostrarEnPantalla() << endl;
        }

        cout << endl;
        cout << "Total de Sedes registrados: " << cantidaSedes << endl << endl;
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}


void SedeManager::sedesActivas(){
    SedeArchivo sArchivo;
    Sede registroSede;

    int cantidadSedes = sArchivo.getCantidadSedes();
    int cantidadActivas = 0;
    bool estado;

    if(cantidadSedes >= 0){
        cout << "Sedes activos:" << endl;
        cout << "---------------------------" << endl;

        for(int i = 0; i < cantidadSedes; i++){
            registroSede = sArchivo.leer(i);
            estado = registroSede.getEstado();

            if(estado == true){
                cout << registroSede.mostrarEnPantalla() << endl;
                cantidadActivas ++;
            }
        }

        cout << "Sedes activas: " << cantidadActivas << endl;
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;
    system("pause");
}



void SedeManager::sedesPorEmpresa(){
    SedeArchivo sArchivo;
    Sede registroSede;

    EmpresaManager eManager;
    Empresa registroEmpresa;

    int cantidadSedes = sArchivo.getCantidadSedes();
    int idEmpresa, idSedeEmpresa;
    std::string nombreEmpresa;

    if(cantidadSedes > 0){
        eManager.listarIdsNombres();

        cout << "Ingrese el ID de la Empresa: ";
        cin >> idEmpresa;

        nombreEmpresa = registroEmpresa.getNombre();
        cout << "Sedes de " << nombreEmpresa << endl;

        for(int i = 0; i < cantidadSedes; i ++){
            registroSede = sArchivo.leer(i);
            idSedeEmpresa = registroSede.getIdEmpresa();

            if(idEmpresa == idSedeEmpresa){
                cout << registroSede.mostrarIdNombre() << endl;
            }
            else{
                cout << nombreEmpresa << "no tiene sedes asociadas." << endl;
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


// Modificadores de registros

void SedeManager::modificarDireccion(){
    SedeArchivo sArchivo;
    Sede registro;

    int id, posicion;
    std::string direccion;

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "Valor por hora actual para:" << endl;
        cout << "  id:        " << registro.getId() << endl;
        cout << "  Nombre:    " << registro.getNombre() << endl;
        cout << "  Dirección: " << registro.getDireccion() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> direccion;

        registro.setDireccion(direccion);

        if (sArchivo.guardar(registro, posicion)){
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


void SedeManager::modificarEmail(){
    SedeArchivo sArchivo;
    Sede registro;

    int id, posicion;
    std::string email;

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "Valor por hora actual para:" << endl;
        cout << "  id: " << registro.getId() << endl;
        cout << "  Nombre: " << registro.getNombre() << endl;
        cout << "  Valor por hora: " << registro.getEmail() << endl;

        cout << endl;
        cout << "Ingrese el nuevo valor por hora: ";
        cin >> email;

        registro.setEmail(email);

        if (sArchivo.guardar(registro, posicion)){
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


void SedeManager::modificarEstado(){
    SedeArchivo sArchivo;
    Sede registro;

    int id, posicion;
    bool estado;

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID de la Sede: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);
        estado = registro.getEstado();

        cout << "Estado acutal del masajista" << endl;
        cout << "  ID:            " << registro.getId() << endl;
        cout << "  Nombre:        " << registro.getNombre() << endl;

        if(estado == 1){
            cout << "  Estado actual: Activo" << endl;
        }
        else{
            cout << "  Estado actual: Inactivo" << endl;
        }

        estado = !estado;

        cout << endl;
        cout << "Estado modificado a: " << estado << endl;

        registro.setEstado(estado);

        if (sArchivo.guardar(registro, posicion)){
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


void SedeManager::modificarIdEmpresa(){
    SedeArchivo sArchivo;
    Sede registroSede;

    EmpresaManager empresaManager;
    Empresa registroEmpresa;


    int id, posicion, idEmpresa;

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> idEmpresa;

    posicion = sArchivo.buscar(idEmpresa);

    if(posicion >= 0){
        registroSede = sArchivo.leer(posicion);

        cout << "Empresa a la que pertenece la Sede:" << endl;
        cout << "  id:                          " << registroSede.getId() << endl;
        cout << "  Nombre:                      " << registroSede.getNombre() << endl;

        if(registroSede.getIdEmpresa() == registroEmpresa.getId()){
            cout << "  Empresa a la que pertenece:  " << registroEmpresa.getNombre() << endl;
        }

        empresaManager.listarIdsNombres();

        cout << endl;
        cout << "Ingrese el nuevo ID de Empresa: ";
        cin >> idEmpresa;

        registroSede.setIdEmpresa(idEmpresa);

        if (sArchivo.guardar(registroSede, posicion)){
            cout << endl;
            cout << "ID de Empres actualizado y registro guardado con éxito." << endl;
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


void SedeManager::modificarNombre(){
    SedeArchivo sArchivo;
    Sede registro;

    int id, posicion;
    std::string nombre;

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "Nombre actual de la Sede:" << endl;
        cout << "  id:      " << registro.getId() << endl;
        cout << "  Nombre:  " << registro.getNombre() << endl;
        cout << endl;
        cout << "Ingrese el nuevo nombre: ";
        cin >> nombre;

        registro.setNombre(nombre);

        if (sArchivo.guardar(registro, posicion)){
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


void SedeManager::modificarTelefono(){
    SedeArchivo sArchivo;
    Sede registro;

    int id, posicion;
    std::string telefono;

    SedeManager::listarIdsNombres();

    cout << "Ingrese el ID del tipo de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "Nombre actual de la Sede:" << endl;
        cout << "  id:        " << registro.getId() << endl;
        cout << "  Nombre:    " << registro.getNombre() << endl;
        cout << "  Teléfono:  " << registro.getNombre() << endl;
        cout << endl;
        cout << "Ingrese el nuevo número de telérono: ";
        cin >> telefono;

        registro.setNombre(telefono);

        if (sArchivo.guardar(registro, posicion)){
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
