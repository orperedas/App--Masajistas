#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "EmpresaManager.h"

#include "Fecha.h"

#include "Masajista.h"
#include "MasajistaArchivo.h"
#include "MasajistaManager.h"

#include "Sede.h"
#include "SedeArchivo.h"
#include "SedeManager.h"

#include "Servicio.h"
#include "ServicioArchivo.h"
#include "ServicioManager.h"

#include "TipoServicio.h"
#include "TipoServicioArchivo.h"
#include "TipoServicioManager.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void ServicioManager::buscar(){
    ServicioArchivo servArchivo;
    ServicioManager servManager;
    Servicio registro;

    int id, posicion;
    int todoLosServicios = servArchivo.getCantidadServicios();

    if(todoLosServicios > 0){
        servManager.listarServicios();
    }
    else{
        cout << endl;
        cout << "\t\tNo hay registros para mostrar." << endl;
    }

    cout << endl;

    cout << "Ingrese el ID del servicio: ";
    cin >> id;

    posicion = servArchivo.buscar(id);

    registro = servArchivo.leer(posicion);

    if(posicion >= 0){
        cout << endl;
        cout << "Datos del servicio" << endl;
        cout << endl;
        cout << "Clave                Valor" << endl;
        cout << "------------------  ------------------------" << endl;
        cout << "id:                 " << registro.getIdServicio() << endl;
        cout << "Fecha:              " << registro.getFecha().convertirACadena() << endl;
        cout << "Masajista:          " << registro.getnombreMasajista() << endl;
        cout << "Empresa:            " << registro.getNombreEmpresa() << endl;
        cout << "Sede:               " << registro.getNombreSede() << endl;
        cout << "Tipo de serrvicio:  " << registro.getNombreTpo() << endl;
        cout << "Empresa:            " << registro.getCantidadHorasTipo() << endl;
        cout << "Valor por hora:     ";
        cout << std::fixed << std::setprecision(2) << registro.getValorHoraTipo() << endl;
    }
    else{
        cout << endl;
        cout << "El ID ingresado no fue encontrado." << endl;
    }

    cout << endl;
    system("pause");
}


std::string ServicioManager::buscarNombreMasajista(std::string dni_masjista){
    MasajistaArchivo mArchivo;
    Masajista registro;

    std::string nombre = "";
    int posicion;

    posicion = mArchivo.buscar(dni_masjista);
    registro = mArchivo.leer(posicion);
    nombre = registro.getNombre() + " " + registro.getApellido();

    return nombre;
}

std::string ServicioManager::buscarNombreEmpresa(int id_empresa){
    EmpresaArchivo eArchivo;
    Empresa registro;

    std::string nombre = "";
    int posicion;

    posicion = eArchivo.buscar(id_empresa);
    registro = eArchivo.leer(posicion);
    nombre = registro.getNombre();

    return nombre;
}

std::string ServicioManager::buscarNombreSede(int id_sede){
    SedeArchivo sArchivo;
    Sede registro;

    std::string nombre = "";
    int posicion;

    posicion = sArchivo.buscar(id_sede);
    registro = sArchivo.leer(posicion);
    nombre = registro.getNombre();

    return nombre;
}

std::string ServicioManager::buscarNombreTipo(int id_tipo){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    std::string nombre = "";
    int posicion;

    posicion = tsArchivo.buscar(id_tipo);
    registro = tsArchivo.leer(posicion);
    nombre = registro.getNombre();

    return nombre;
}


float ServicioManager::buscarValorHoraTipo(int id_tipo){
    TipoServicioArchivo tsArchivo;
    TipoServicio registro;

    int posicion, valorHora;

    posicion = tsArchivo.buscar(id_tipo);
    registro = tsArchivo.leer(posicion);
    valorHora = registro.getValorHora();

    return valorHora;
}


void ServicioManager::cargar(){
    EmpresaManager empManager;
    Empresa regEmpresa;

    Fecha fecha;

    MasajistaManager manMasajista;
    Masajista regMasajista;

    SedeManager sedeManager;
    Sede regSede;

    ServicioArchivo servArchivo;
    ServicioManager servManager;
    Servicio regServicio;

    TipoServicioManager tsManager;
    TipoServicio regTipoServicio;


    int idServicio, cantidadHorasTipo;
    int anio, mes, dia;
    string nombreMasajista, posMasajista, nombreEmpresa, nombreSede, nombreTipo;
    float valorHoraTipo;
    int posicion, posEmpresa, posSede, posTipoServicio;

    // Genera el id contando los registros del archivo.
    idServicio = servArchivo.getCantidadServicios() + 1;

    cout << "Ingrese la fecha del servicio" << endl;
    cout << "ingrese el día";
    cin >> dia;
    fecha.setDia(dia);
    cout << "Ingrese el mes";
    cin >> mes;
    fecha.setMes(mes);
    cout << "Ingrese el año";
    cin >> anio;
    fecha.setAnio(anio);
    fecha.convertirACadena();

    cout << endl;
    cout << "ID  Masajista" << endl;
    manMasajista.listarDnisNombres();
    cout << "Ingrese el DNI del masajista" << endl;
    cin >> posMasajista;
    nombreMasajista = servManager.buscarNombreMasajista(posMasajista);

    cout << endl;
    cout << "ID  Empresa" << endl;
    empManager.listarIdsNombres();
    cout << "Ingrese el ID de la empresa: ";
    cin >> posEmpresa;
    nombreEmpresa = servManager.buscarNombreEmpresa(posEmpresa);

    cout << endl;
    cout << "ID  Sede" << endl;
    sedeManager.listarSedes();
    cout << "Ingrese el ID de la sede: ";
    cin >> posSede;
    nombreSede = servManager.buscarNombreSede(posSede);

    cout << endl;
    cout << "ID  Tipo de Servicio" << endl;
    tsManager.listarIdsNombres();
    cout << "Ingrese el ID del Tipo de Servicio: ";
    cin >> posTipoServicio;
    nombreTipo = servManager.buscarNombreTipo(posTipoServicio);

    cout << endl;
    cout << "Ingrese la cantidad de horas del servicio: ";
    cin >> cantidadHorasTipo;

    cout << endl;
    cout << "ID  Tipo de Servicio" << endl;
    tsManager.listarTipoServicios();
    cout << "Ingrese ID del valor por hora: ";
    cin >> valorHoraTipo;

    regServicio = Servicio(idServicio, fecha, nombreMasajista, nombreEmpresa, nombreSede, nombreTipo, cantidadHorasTipo, valorHoraTipo);

    if(servArchivo.guardar(regServicio)){
        cout << endl;
        cout << "Nuevo  de Servicio guardado con éxito." << endl;
    }
    else{
        cout << endl;
        cout << "Error inesperado, no se guardó el registro" << endl;
    }

    cout << endl;
    system("pause");
}


void ServicioManager::listarServicios(){
    ServicioArchivo servicioArchivo;
    Servicio registro;

    int todoLosServicios = servicioArchivo.getCantidadServicios();

    if(todoLosServicios > 0){
        for(int i = 0; i < todoLosServicios; i++){
            registro = servicioArchivo.leer(i);
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


// Modificadores de registros

void ServicioManager::modificarCantidadHoras(){
    Fecha fecha;

    ServicioArchivo sArchivo;
    ServicioManager sManager;
    Servicio registro;

    int id, posicion, cantidadHorasTipo;

    sManager.listarServicios();

    cout << "Ingrese el ID del de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "La fecha actual del servicio es:" << endl;
        cout << "  id:                  " << registro.getIdServicio() << endl;
        cout << "  Fecha:               " << registro.getFecha().convertirACadena() << endl;
        cout << "  Empresa              " << registro.getNombreEmpresa() << endl;
        cout << "  Sede                 " << registro.getNombreSede() << endl;
        cout << "  Horas del servicio:  " << registro.getCantidadHorasTipo() << endl;

        cout << endl;

        cout << "Ingrese la nueva cantidad de horas: ";
        cin >> cantidadHorasTipo;

        registro.setCantidadHoras(cantidadHorasTipo);

        if (sArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Fecha y registro actualizados con éxito." << endl;
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


void ServicioManager::modificarFecha(){
    Fecha fecha;

    ServicioArchivo sArchivo;
    ServicioManager sManager;
    Servicio registro;

    int id, posicion;
    int dia, mes, anio;

    sManager.listarServicios();

    cout << "Ingrese el ID del de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "La fecha actual del servicio es:" << endl;
        cout << "  id:         " << registro.getIdServicio() << endl;
        cout << "  Fecha:      " << registro.getFecha().convertirACadena() << endl;
        cout << "  Empresa     " << registro.getNombreEmpresa() << endl;
        cout << "  Sede        " << registro.getNombreSede() << endl;
        cout << "  Masajista:  " << registro.getnombreMasajista() << endl;

        cout << endl;

        cout << "Ingrese la fecha del servicio" << endl;
        cout << "ingrese el día";
        cin >> dia;
        fecha.setDia(dia);
        cout << "Ingrese el mes";
        cin >> mes;
        fecha.setMes(mes);
        cout << "Ingrese el año";
        cin >> anio;
        fecha.setAnio(anio);
        fecha.convertirACadena();

        registro.setFecha(fecha);

        if (sArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Fecha y registro actualizados con éxito." << endl;
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


void ServicioManager::modificarMasajista(){
    MasajistaManager mManager;

    ServicioArchivo sArchivo;
    ServicioManager sManager;
    Servicio registro;

    int id, posicion;
    std::string nombreMasajista, posMasajista;

    sManager.listarServicios();

    cout << "Ingrese el ID del de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "El Masajista actual del servicio es:" << endl;
        cout << "  id:         " << registro.getIdServicio() << endl;
        cout << "  Fecha:      " << registro.getFecha().convertirACadena() << endl;
        cout << "  Empresa     " << registro.getNombreEmpresa() << endl;
        cout << "  Sede        " << registro.getNombreSede() << endl;
        cout << "  Masajista:  " << registro.getnombreMasajista() << endl;

        cout << endl;
        cout << "ID  Masajista" << endl;
        mManager.listarDnisNombres();
        cout << "Ingrese el DNI del masajista" << endl;
        cin >> posMasajista;
        nombreMasajista = sManager.buscarNombreMasajista(posMasajista);

        registro.setNombreMasajista(nombreMasajista);

        if (sArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Masajista y registro actualizados con éxito." << endl;
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


void ServicioManager::modificarSede(){
    SedeManager sedeManager;

    ServicioArchivo servArchivo;
    ServicioManager servManager;
    Servicio registro;

    int id, posicion, posSede;
    std::string nombreSede;

    servManager.listarServicios();

    cout << "Ingrese el ID del de servicio a modificar: ";
    cin >> id;

    posicion = servArchivo.buscar(id);

    if(posicion >= 0){
        registro = servArchivo.leer(posicion);

        cout << "La sede actual del servicio es:" << endl;
        cout << "  id:         " << registro.getIdServicio() << endl;
        cout << "  Fecha:      " << registro.getFecha().convertirACadena() << endl;
        cout << "  Empresa     " << registro.getNombreEmpresa() << endl;
        cout << "  Sede        " << registro.getNombreSede() << endl;

        cout << endl;
        cout << "ID  Sede" << endl;
        sedeManager.listarIdsNombres();
        cout << "Ingrese el ID de la Sede" << endl;
        cin >> posSede;
        nombreSede = servManager.buscarNombreSede(posSede);

        registro.setNombreSede(nombreSede);

        if (servArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Sede y registro actualizados con éxito." << endl;
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


void ServicioManager::modificarTipoServicio(){
    TipoServicioManager tsManager;

    ServicioArchivo sArchivo;
    ServicioManager sManager;
    Servicio registro;

    int id, posicion, posSede;
    std::string nombreTipoServicio;

    sManager.listarServicios();

    cout << "Ingrese el ID del de servicio a modificar: ";
    cin >> id;

    posicion = sArchivo.buscar(id);

    if(posicion >= 0){
        registro = sArchivo.leer(posicion);

        cout << "El tipo de servicio actual del servicio es:" << endl;
        cout << "  id:                " << registro.getIdServicio() << endl;
        cout << "  Fecha:             " << registro.getFecha().convertirACadena() << endl;
        cout << "  Empresa            " << registro.getNombreEmpresa() << endl;
        cout << "  Sede               " << registro.getNombreSede() << endl;
        cout << "  Tipo de servicio:  " << registro.getNombreTpo() << endl;

        cout << endl;
        cout << "ID  Tipo de Servicio" << endl;
        tsManager.listarIdsNombres();
        cout << "Ingrese el ID del Tipo de Servicio" << endl;
        cin >> posSede;
        nombreTipoServicio = sManager.buscarNombreSede(posSede);

        registro.setNombreTipo(nombreTipoServicio);

        if (sArchivo.guardar(registro, posicion)){
            cout << endl;
            cout << "Tipo de Servicio y registro actualizados con éxito." << endl;
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
