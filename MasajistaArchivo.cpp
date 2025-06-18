#include "MasajistaArchivo.h"
#include "MasajistaManager.h"

#include <iostream>
#include <cstring>

using namespace std;

MasajistaArchivo::MasajistaArchivo(){
    _nombreArchivo = "masajistas.dat";
}

MasajistaArchivo::MasajistaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool MasajistaArchivo::guardar(Masajista registro){
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile == nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Masajista), 1, pFile);

    fclose(pFile);

    return resultado;
}

int MasajistaArchivo::getCantidadMasajistas(){
    int tamanioArchivo, tamanioRegistro, totalMasajistas;

    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tamanioArchivo = ftell(pFile);
    tamanioRegistro = sizeof(Masajista);
    totalMasajistas = tamanioArchivo / tamanioRegistro;

    fclose(pFile);

    return totalMasajistas;
}


Masajista MasajistaArchivo::leer(int posicion){
    Masajista registro;
    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, sizeof(Masajista) * posicion, SEEK_SET);
    fread(&registro, sizeof(Masajista), 1, pFile);

    fclose(pFile);

    return registro;
}
