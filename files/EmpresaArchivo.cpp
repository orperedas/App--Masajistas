#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "EmpresaManager.h"

#include <iostream>
#include <cstring>

using namespace std;

EmpresaArchivo::EmpresaArchivo(){
    _nombreArchivo = "files/Empresas.dat";
}


EmpresaArchivo::EmpresaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


int EmpresaArchivo::tamanioRegistro(){
    return sizeof(Empresa);
}


int EmpresaArchivo::getCantidadEmpresas(){
    int tamanioArchivo, cantidadEmpresas;

    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr){
        return 0;
    }

    fseek(pArchivo, 0, SEEK_SET);

    tamanioArchivo = ftell(pArchivo);
    cantidadEmpresas = tamanioArchivo / tamanioRegistro();

    fclose(pArchivo);

    return cantidadEmpresas;
}


int EmpresaArchivo::buscar(int idEmpresa){
    Empresa registrio;
    int posicion = 0;

    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr){
        return 0;
    }

    while(fread(&registrio, tamanioRegistro(), 1, pArchivo)){
        if(registrio.getId() == idEmpresa){
            fclose(pArchivo);
            return posicion;
        }

        posicion ++;
    }

    fclose(pArchivo);

    return -2;

}


bool EmpresaArchivo::guardar(Empresa registro){
    bool resultado;

    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr){
        return 0;
    }

    resultado = fwrite(&registro, tamanioRegistro(), 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}


bool EmpresaArchivo::guardar(Empresa registro, int posicion){
    int tamRegistro = tamanioRegistro();
    bool resultado;

    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr){
        return 0;
    }

    fseek(pArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}


bool EmpresaArchivo::modificar(Empresa registro, int posicion){
    int tamRegistro = tamanioRegistro();
    bool resultado;

    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr){
        return 0;
    }

    fseek(pArchivo, posicion * tamRegistro, SEEK_SET);
    resultado = fwrite(&registro, tamRegistro, 1, pArchivo);

    fclose(pArchivo);

    return resultado;
}


Empresa EmpresaArchivo::leer(int posiciion){
    Empresa registro;

    int tamRegistro = tamanioRegistro();

    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr){
        return registro;
    }

    fseek(pArchivo, posiciion * tamRegistro, SEEK_SET);
    fread(&registro, tamRegistro, 1, pArchivo);

    fclose(pArchivo);

    return registro;
}
