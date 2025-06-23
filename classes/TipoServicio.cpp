#include "TipoServicio.h"

#include <cstring>

using namespace std;

TipoServicio::TipoServicio(){
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_descripcion, "");
    strcpy(_modalidad, "");
    _valorHora = 0;
}

TipoServicio::TipoServicio(int id, std::string nombre, std::string descripcion, std::string modalidad, float valorHora){
    setId(id);
    setNombre(nombre);
    setDescripcion(descripcion);
    setModalidad(modalidad);
    setValorHora(valorHora);
}

int TipoServicio::getId(){
    return _id;
}

std::string TipoServicio::getNombre(){
    return _nombre;
}

std::string TipoServicio::getDescripcion(){
    return _descripcion;
}

std::string TipoServicio::getModalidad(){
    return _modalidad;
}

float TipoServicio::getValorHora(){
    return _valorHora;
}


void TipoServicio::setId(int id){
    _id = id;
}

void TipoServicio::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}

void TipoServicio::setDescripcion(std::string descripcion){
    strcpy(_descripcion, descripcion.c_str());
}

void TipoServicio::setModalidad(std::string modalidad){
    strcpy(_modalidad, modalidad.c_str());
}

void TipoServicio::setValorHora(float valorHora){
    _valorHora = valorHora;
}
