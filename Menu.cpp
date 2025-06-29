#include <iostream>
#include <stdlib.h>

#include "Menu.h"

#include "EmpresaManager.h"
#include "MasajistaManager.h"
#include "SedeManager.h"
#include "TipoServicioManager.h"

using namespace std;

void Menu::cabeceraMenu(){
    system("cls");
    cout << "=================================================" << endl;
    cout << "                 App Masajistas                  " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "    Sistema de gestión de servicios de masaje    " << endl;
    cout << "            alta, modificación y baja            " << endl;
    cout << "       de masajistas, empresas y servicios       " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << endl;
}


void Menu::principal(){
    int opcion;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ PRINCIPAL -----" << endl;
        cout << endl;
        cout << "  1. Masajistas" << endl;
        cout << "  2. Empresas" << endl;
        cout << "  3. Servicios" << endl;
        cout << endl;
        cout << "  0. Salir de App Masajistas" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opci≤n para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                Menu::masajistas();
                break;
            case 2:
                Menu::empresas();
                break;
            case 3:
                Menu::servicios();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "La opción ingresada no es válida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


// Menús de clases
void Menu::empresas(){
    int opcion;

    EmpresaManager empresaManager;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ EMPRESAS -----" << endl;
        cout << endl;
        cout << "    1. Agregar nueva empresa" << endl;
        cout << "    2. Buscar empresa" << endl;
        cout << "    3. Listado de todas las empresas" << endl;
        cout << "    4. Listado de empresas activas" << endl;
        cout << "    5. Modificar registro de Empresa" << endl;
        cout << endl;
        cout << "    6. ir al Menú Sedes" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                empresaManager.cargar();
                break;
            case 2:
                empresaManager.buscar();
                break;
            case 3:
                empresaManager.listarEmpresas();
                break;
            case 4:
                empresaManager.EmpresasActivas();
                break;
            case 5:
                Menu::modificarEmpresa();
                break;
            case 6:
                Menu::sedes();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es valida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


void Menu::masajistas(){
    int opcion;

    MasajistaManager masajistaManager;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ MASAJISTAS -----" << endl;
        cout << endl;
        cout << "    1. Agregar masajista" << endl;
        cout << "    2. Modificar estado de un masajista" << endl;
        cout << "    3. Buscar masajista" << endl;
        cout << "    4. Listar todos los masajistas" << endl;
        cout << "    5. Mostrar masajistas activos" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                masajistaManager.cargarMasajista();
                break;
            case 2:
                masajistaManager.modificarEstadoMasajista();
                break;
            case 3:
                masajistaManager.buscarMasajista();
                break;
            case 4:
                masajistaManager.listarMasajistas();
                break;
            case 5:
                masajistaManager.masajistasActivos();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es válida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


void Menu::sedes(){
    int opcion;

    SedeManager sedeManager;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ EMPRESAS -----" << endl;
        cout << endl;
        cout << "    1. Agregar sede" << endl;
        cout << "    2. Buscar sedes" << endl;
        cout << "    3. Listado de todas las sedes" << endl;
        cout << "    4. Listado de sedes activas" << endl;
        cout << "    5. Modificar registro de sede:" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                sedeManager.cargar();
                break;
            case 2:
                sedeManager.buscar();
                break;
            case 3:
                sedeManager.listarSedes();
                break;
            case 4:
                sedeManager.sedesActivas();
                break;
            case 5:
                //Menu::modificarSede;
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es valida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);

}


void Menu::servicios(){
    int opcion;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ SERVICIOS -----" << endl;
        cout << endl;
        cout << "    1. Agregar servicio" << endl;
        cout << "    2. Modificar estado de servicio" << endl;
        cout << "    3. Cambiar masajista de servicio" << endl;
        cout << "    4. Listar servicios" << endl;
        cout << "    5. Tipos de Servicios" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                cout << "Agregar servicio" << endl;
                break;
            case 2:
                cout << "Modificar estado de servicio" << endl;
                break;
            case 3:
                cout << "Cambiar masajista de servicio" << endl;
                break;
            case 4:
                cout << "Listar servicios" << endl;
                break;
            case 5:
                Menu::tipoServicio();
                break;
            case 0:
                cout << "Volviendo al men· principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es válida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


void Menu::tipoServicio(){
    int opcion;

    TipoServicioManager tipoServicioManager;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ SERVICIOS -----" << endl;
        cout << endl;
        cout << "    1. Agregar tipo de servicio" << endl;
        cout << "    2. Buscar tipo de servicio" << endl;
        cout << "    3. Listar todos los tipos de servicio" << endl;
        cout << "    4. Listar tipos de servicios activos" << endl;
        cout << endl;
        cout << "    Modifica tipo de servicio:" << endl;
        cout << "        5. Modificar estado" << endl;
        cout << "        6. Modificar valor por hora" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                tipoServicioManager.cargar();
                break;
            case 2:
                tipoServicioManager.buscar();
                break;
            case 3:
                tipoServicioManager.listarTipoServicios();
                break;
            case 4:
                tipoServicioManager.TiposServiciosActivos();
                break;
            case 5:
                tipoServicioManager.modificarEstado();
                break;
            case 6:
                tipoServicioManager.modificarValorHora();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es válida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


// Menús de modificación de registros

void Menu::modificarEmpresa(){
    int opcion;

    EmpresaManager empresaManager;

    do{
        Menu::cabeceraMenu();

        cout << "----- MENÚ MODIFICAR REGISTRO DE EMPRESAS -----" << endl;
        cout << endl;
        cout << "    1. Modificar nombre" << endl;
        cout << "    2. Modificar CUIT" << endl;
        cout << "    3. Modificar Dirección" << endl;
        cout << "    4. Modificar Teléfono" << endl;
        cout << "    5. Modificar Correo electrónico" << endl;
        cout << "    6. Modificar Estado" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                //empresaManager.modificarNombre();
                break;
            case 2:
                //empresaManager.modificarCuit();
                break;
            case 3:
                empresaManager.modificarDireccion();
                break;
            case 4:
                empresaManager.modificarTelefono();
                break;
            case 5:
                empresaManager.modificarEmail();
                break;
            case 6:
                empresaManager.modificarEstado();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es valida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


void Menu::modificarSede(){
    int opcion;

    SedeManager sedeManager;

    do{
        Menu::cabeceraMenu();

        cout << "----- MENÚ MODIFICAR REGISTRO DE EMPRESAS -----" << endl;
        cout << endl;
        cout << "    1. Modificar nombre" << endl;
        cout << "    2. Modificar Dirección" << endl;
        cout << "    3. Modificar Teléfono" << endl;
        cout << "    4. Modificar Correo electrónico" << endl;
        cout << "    5. Modificar Estado" << endl;
        cout << "    6. Modificar ID de Empresa" << endl;
        cout << endl;
        cout << "    0. Volver al Menú Principal" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opción para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                sedeManager.modificarNombre();
                break;
            case 2:
                sedeManager.modificarDireccion();
                break;
            case 3:
                sedeManager.modificarTelefono();
                break;
            case 4:
                sedeManager.modificarEmail();
                break;
            case 5:
                sedeManager.modificarEstado();
                break;
            case 6:
                sedeManager.modificarIdEmpresa();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada no es valida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}
