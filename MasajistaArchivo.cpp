#include "MasajistaArchivo.h"
#include "MasajistaManager.h"

#include <iostream>
#include <cstring>

using namespace std;

MasajistaArchivo::MasajistaArchivo(){
    _nombreArchivo = "masajistas.dat";
}

MasajistaArchivo::MasajistaArchivo(std:string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool MasajistaArchivo::guardar(Postulante registro){
    FILE *pFile;
    pFile = fOpen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr){
        return false;
    }
}
