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


int MasajistaArchivo::tamanioRegistro(){
    int tamanio = sizeof(Masajista);
    return tamanio;
}


bool MasajistaArchivo::guardar(Masajista registro){
    FILE *masArchivo;
    bool resultado;

    masArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(masArchivo == nullptr){
        return false;
    }

    resultado = fwrite(&registro, sizeof(Masajista), 1, masArchivo);

    fclose(masArchivo);

    return resultado;
}


bool MasajistaArchivo::guardar(Masajista registro, int posicion){
    FILE *masArchivo;
    int tamRegistro = tamanioRegistro();
    bool resultado;

    masArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(masArchivo == nullptr){
        return false;
    }

    fseek(masArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, masArchivo);

    fclose(masArchivo);

    return resultado;
}


int MasajistaArchivo::buscar(std::string dniMasajista){
    FILE *masArchivo;
    Masajista registro;
    int tamRegistro = tamanioRegistro();
    int posicion = 0;

    masArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(masArchivo == nullptr){
        return -1;
    }

    while(fread(&registro, tamRegistro, 1, masArchivo) == 1){
        if(registro.getDni() == dniMasajista){
            fclose(masArchivo);
            return posicion;
        }

        posicion ++;
    }

    fclose(masArchivo);

    return -2;
}


bool MasajistaArchivo::modificarEsstado(Masajista registro, int posicion){
    FILE *masArchivo;
    int tamRegistro = tamanioRegistro();
    bool resultado;

    masArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(masArchivo == nullptr){
        return false;
    }

    fseek(masArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, masArchivo);

    fclose(masArchivo);

    return resultado;
}


int MasajistaArchivo::getCantidadMasajistas(){
    int tamanioArchivo, tamRegistro, totalMasajistas;

    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    tamanioArchivo = ftell(pFile);
    tamRegistro = tamanioRegistro();
    totalMasajistas = tamanioArchivo / tamRegistro;

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
