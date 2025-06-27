#include "TipoServicio.h"

#include <cstring>

using namespace std;

TipoServicio::TipoServicio(){
    int _id = 0;
    char _nombre[50];
    char _descripcion[200];
    char _modalidad[20];
    float _valorHora = 0.0;
    bool _estado = true;
}

TipoServicio::TipoServicio(int id, std::string nombre, std::string descripcion, std::string modalidad, float valorHora, bool estado){
    setId(id);
    setNombre(nombre);
    setDescripcion(descripcion);
    setModalidad(modalidad);
    setValorHora(valorHora);
    setEstado(estado);
}

int TipoServicio::getId(){return _id;}
std::string TipoServicio::getNombre(){return _nombre;}
std::string TipoServicio::getDescripcion(){return _descripcion;}
std::string TipoServicio::getModalidad(){return _modalidad;}
float TipoServicio::getValorHora(){return _valorHora;}
bool TipoServicio::getEstado(){return _estado;}


void TipoServicio::setId(int id){_id = id;}
void TipoServicio::setNombre(std::string nombre){strcpy(_nombre, nombre.c_str());}
void TipoServicio::setDescripcion(std::string descripcion){strcpy(_descripcion, descripcion.c_str());}
void TipoServicio::setModalidad(std::string modalidad){strcpy(_modalidad, modalidad.c_str());}
void TipoServicio::setValorHora(float valorHora){_valorHora = valorHora;}
void TipoServicio::setEstado(bool estado){_estado = estado;}


std::string TipoServicio::enviarAcsv(){
    string cadena = "";
    cadena = to_string(_id) + ",";
    cadena += string(_nombre) + ",";
    cadena += string(_descripcion) + ",";
    cadena += string(_modalidad) + ",";
    cadena = to_string(_valorHora) + ",";
    cadena = to_string(_estado);

    return cadena;
}


std::string TipoServicio::mostrarEnPantalla(){
    string cadena = "";
    cadena = to_string(_id) + " | ";
    cadena += string(_nombre) + " | ";
    cadena += string(_descripcion) + " | ";
    cadena += string(_modalidad) + " | ";
    cadena += to_string(_valorHora) + " | ";
    cadena += to_string(_estado);

    return cadena;
}


std::string TipoServicio::mostrarIdNombreTipo(){
    string cadena = "";
    cadena = to_string(_id) + "  ";
    cadena += string(_nombre);

    return cadena;
}
