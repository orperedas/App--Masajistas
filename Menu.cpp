#include <iostream>
#include <stdlib.h>

#include "Menu.h"
#include "MasajistaManager.h"

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
        cout << "     Ingrese una opción para continuar:  ";
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
                cout << "La opción ingresada es inválida. Intente de nuevo." << endl;
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
                cout << "La opción ingresada es inválida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}


void Menu::empresas(){
    int opcion;

    do{
        Menu::cabeceraMenu();

        cout << "  ----- MENÚ EMPRESAS -----" << endl;
        cout << endl;
        cout << "    1. Listar empresa" << endl;
        cout << "    2. Agregar empresa" << endl;
        cout << "    3. Modificar empresa" << endl;
        cout << "    4. Eliminar empresa" << endl;
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
                cout << "Listado de empresa" << endl;
                break;
            case 2:
                cout << "Agregrar empresa" << endl;
                break;
            case 3:
                cout << "Modificar empresa" << endl;
                break;
            case 4:
                cout << "Eliminar empresa" << endl;
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada es inválida. Intente de nuevo." << endl;
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
        cout << "    1. Listar servicios" << endl;
        cout << "    2. Agregar servicio" << endl;
        cout << "    3. Modificar servicio" << endl;
        cout << "    4. Eliminar servicio" << endl;
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
                cout << "Listado de servicios" << endl;
                break;
            case 2:
                cout << "Agregrar servicio" << endl;
                break;
            case 3:
                cout << "Modificar servicio" << endl;
                break;
            case 4:
                cout << "Eliminar servicio" << endl;
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "La opción ingresada es inválida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);
}
