#include "ServicioArchivo.h"
#include "ServicioManager.h"

#include <iostream>
#include <cstring>

ServicioArchivo::ServicioArchivo(){
    _nombreArchivo = "files/TiposServicios.dat";
}


ServicioArchivo::ServicioArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


int ServicioArchivo::tamanioRegistro(){
    int tamanio = sizeof(Servicio);
    return tamanio;
}


int ServicioArchivo::getCantidadServicios(){
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


int ServicioArchivo::buscar(int idServicio){
    FILE *servicioArchivo;
    Servicio registro;

    int tamRegistro = tamanioRegistro();
    int posicion = 0;

    servicioArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(servicioArchivo == nullptr){
        return -1;
    }

    while(fread(&registro, tamRegistro, 1, servicioArchivo) == 1){
        if(registro.getIdServicio() == idServicio){
            fclose(servicioArchivo);
            return posicion;
        }

        posicion ++;
    }

    fclose(servicioArchivo);

    return -2;
}


bool ServicioArchivo::guardar(Servicio registro){
    FILE *servicioArchivo;
    bool resultado;

    servicioArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(servicioArchivo == nullptr){
        return false;
    }

    resultado = fwrite(&registro, tamanioRegistro(), 1, servicioArchivo);

    fclose(servicioArchivo);

    return resultado;
}


bool ServicioArchivo::guardar(Servicio registro, int posicion){
    FILE *servicioArchivo;
    int tamRegistro = tamanioRegistro();
    bool resultado;

    servicioArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(servicioArchivo == nullptr){
        return false;
    }

    fseek(servicioArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, servicioArchivo);

    fclose(servicioArchivo);

    return resultado;
}


bool ServicioArchivo::modificar(Servicio registro, int posicion){
    FILE *servicioArchivo;
    int tamRegistro = tamanioRegistro();
    bool resultado;

    servicioArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(servicioArchivo == nullptr){
        return false;
    }

    fseek(servicioArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, servicioArchivo);

    fclose(servicioArchivo);

    return resultado;
}


Servicio ServicioArchivo::leer(int posicion){
    Servicio registro;

    int tamRegistro = tamanioRegistro();

    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, tamRegistro * posicion, SEEK_SET);
    fread(&registro, tamRegistro, 1, pFile);

    fclose(pFile);

    return registro;
}
