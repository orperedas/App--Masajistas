#include <iostream>
#include <locale.h>

#include "Menu.h"

using namespace std;

int main(){
    setlocale(LC_CTYPE, "Spanish");

    Menu menu;
    menu.principal();

    return 0;
}



