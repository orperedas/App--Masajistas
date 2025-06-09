#include <iostream>

using namespace std;

int main(){
    int opcion;

    do{
        cout << "=================================================" << endl;
        cout << "                 App Masajistas                  " << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     Sistema de gesti¢n de servicios masajes     " << endl;
        cout << "            alta, modificaci¢n y baja            " << endl;
        cout << "       de masajistas, empresas y servicios       " << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "  1. Masajistas" << endl;
        cout << "  2. Empresas" << endl;
        cout << "  3. Servicios" << endl;
        cout << endl;
        cout << "=================================================" << endl;
        cout << endl;
        cout << "     ngrese una opci¢n para continuar:  ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Has seleccionado la opci¢n 1" << endl;
                break;
            case 2:
                cout << "Has seleccionado la opci¢n 2" << endl;
                break;
            case 3:
                cout << "Has seleccionado la opci¢n 3" << endl;
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opci¢n inv lida. Intente de nuevo." << endl;
        }

        cout << endl;

    }
    while (opcion != 0);

    return 0;
}
