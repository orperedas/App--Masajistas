#include "SedeArchivo.h"
#include "SedeManager.h"

#include <iostream>
#include <cstring>

using namespace std;


SedeArchivo::SedeArchivo(){
    _nombreArchivo = "files/Sedes.dat";
}


SedeArchivo::SedeArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


int SedeArchivo::tamanioRegistro(){
    return sizeof(Sede);
}


int SedeArchivo::getCantidadSedes(){
    int tamanioArchivo, tamRegistro, cantidadSedes;

    FILE *sArchivo;
    sArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(sArchivo == nullptr){
        return 0;
    }

    fseek(sArchivo, 0, SEEK_END);

    tamanioArchivo = ftell(sArchivo);
    cantidadSedes = tamanioArchivo / tamanioRegistro();

    fclose(sArchivo);

    return cantidadSedes;
}


int SedeArchivo::buscar(int id){
    Sede registro;
    int posicion = 0;

    FILE *sArchivo;
    sArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(sArchivo == nullptr){
        return 0;
    }

    while(fread(&registro, tamanioRegistro(), 1, sArchivo)){
        if(registro.getId() == id){
            fclose(sArchivo);
            return posicion;
        }

        posicion ++;
    }

    fclose(sArchivo);

    return -1;
}


bool SedeArchivo::guardar(Sede registro){
    bool resultado;

    FILE *sArchivo;
    sArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(sArchivo == nullptr){
        return 0;
    }

    resultado = fwrite(&registro, tamanioRegistro(), 1, sArchivo);

    fclose(sArchivo);

    return resultado;
}


bool SedeArchivo::guardar(Sede registro, int posicion){
    int tamRegistro = tamanioRegistro();
    bool resultado;

    FILE *sArchivo;
    sArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(sArchivo == nullptr){
        return 0;
    }

    fseek(sArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, sArchivo);

    fclose(sArchivo);

    return resultado;
}


bool SedeArchivo::modificar(Sede registro, int posicion){
    int tamRegistro = tamanioRegistro();
    bool resultado;

    FILE *sArchivo;
    sArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(sArchivo == nullptr){
        return 0;
    }

    fseek(sArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, sArchivo);

    fclose(sArchivo);

    return resultado;
}


Sede SedeArchivo::leer(int posiciion){
    Sede registro;

    int tamRegistro = tamanioRegistro();

    FILE *sArchivo;
    sArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(sArchivo == nullptr){
        return registro;
    }

    fseek(sArchivo, posiciion * tamRegistro, SEEK_SET);
    fread(&registro, tamRegistro, 1, sArchivo);

    fclose(sArchivo);

    return registro;
}
