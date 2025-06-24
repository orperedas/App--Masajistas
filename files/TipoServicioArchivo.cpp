#include "TipoServicioArchivo.h"
#include "TipoServicioManager.h"

#include <iostream>
#include <cstring>

TipoServicioArchivo::TipoServicioArchivo(){
    _nombreArchivo = "TiposServicios.dat";
}


TipoServicioArchivo::TipoServicioArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

/*
bool TipoServicioArchivo::comprobarExisteArchivo(){
    const std::string nombreArchivo = _nombreArchivo.c_str();

    std::ifstream archivoLectura(nombreArchivo, std::ios::binary);

    if (!archivoLectura) {
        // El archivo no existe, lo creamos vac�o
        std::ofstream archivoNuevo(nombreArchivo, std::ios::binary);

        if (archivoNuevo) {
            std::cout << "Archivo 'servicios.dat' creado correctamente." << std::endl;
        } else {
            std::cerr << "Error: no se pudo crear el archivo 'servicios.dat'." << std::endl;
        }
    } else {
        std::cout << "El archivo 'servicios.dat' ya existe." << std::endl;
    }
}
*/

int TipoServicioArchivo::tamanioRegistro(){
    int tamanio = sizeof(TipoServicio);
}


bool TipoServicioArchivo::guardar(TipoServicio registro){
    FILE *tsArchivo;
    bool resultado;

    tsArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(tsArchivo == nullptr){
        return false;
    }

    resultado = fwrite(&registro, tamanioRegistro(), 1, tsArchivo);

    fclose(tsArchivo);

    return resultado;
}


bool TipoServicioArchivo::guardar(TipoServicio registro, int posicion){
    FILE *tsArchivo;
    int tamRegistro = tamanioRegistro();
    bool resultado;

    tsArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(tsArchivo == nullptr){
        return false;
    }

    fseek(tsArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, tsArchivo);

    fclose(tsArchivo);

    return resultado;
}


bool TipoServicioArchivo::modificarEsstado(TipoServicio registro, int posicion){
    FILE *tsArchivo;
    int tamRegistro = tamanioRegistro();
    bool resultado;

    tsArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(tsArchivo == nullptr){
        return false;
    }

    fseek(tsArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, tsArchivo);

    fclose(tsArchivo);

    return resultado;
}


int TipoServicioArchivo::getCantidadTipos(){
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


int TipoServicioArchivo::buscar(int idTipoServicio){
    FILE *tsArchivo;
    TipoServicio registro;

    int tamRegistro = tamanioRegistro();
    int posicion = 0;

    tsArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(tsArchivo == nullptr){
        return -1;
    }

    while(fread(&registro, tamRegistro, 1, tsArchivo) == 1){
        if(registro.getId() == idTipoServicio){
            fclose(tsArchivo);
            return posicion;
        }

        posicion ++;
    }

    fclose(tsArchivo);

    return -2;
}


TipoServicio TipoServicioArchivo::leer(int posicion){
    TipoServicio registro;

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
