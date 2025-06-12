#include <iostream>

#include "Menu.h"

using namespace std;

int main(){

    Menu Menu;
    int opcion;

    do{
        cout << "=================================================" << endl;
        cout << "                 App Masajistas                  " << endl;
        cout << "=================================================" << endl;
        cout << "     Sistema de gesti¢n de servicios masajes     " << endl;
        cout << "            alta, modificaci¢n y baja            " << endl;
        cout << "       de masajistas, empresas y servicios       " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "  1. Masajistas" << endl;
        cout << "  2. Empresas" << endl;
        cout << "  3. Servicios" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Ingrese una opci¢n para continuar:  ";
        cin >> opcion;
        cout << endl;


        switch (opcion) {
            case 1:
                Menu.masajistas();
                break;
            case 2:
                cout << "Menu.empresas()" << endl;
                break;
            case 3:
                cout << "Menu.servicios()" << endl;
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "La ppci¢n ingresada es inv lida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);

    return 0;
}

