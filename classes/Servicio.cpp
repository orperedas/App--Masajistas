#include "Servicio.h"

#include <iostream>
#include <cstring>

using namespace std;


Servicio::Servicio(){
    int _idServicio = 0;
    Fecha _fecha = Fecha();
    strcpy(_dniMasajista, "");
    int _idEmpresa = 0;
    int _idSede = 0;
    int _idTipo = 0;
    int _cantidadHoras = 0;
    float _valorHora = 0.0;
}

Servicio::Servicio(int idServicio, Fecha fecha, std::string dniMasajista, int idEmpresa, int idSede, int idTipo, int cantidadHoras, float valorHora){
    setIdServicio(idServicio);
    setFecha(fecha);
    setDniMasajista(dniMasajista);
    setIdEmpresa(idEmpresa);
    setIdSede(idSede);
    setIdTipo(idTipo);
    setCantidadHoras(cantidadHoras);
    setValorHora(valorHora);
}


// Getters
int Servicio::getIdServicio(){
    return _idServicio;
}

Fecha Servicio::getFecha(){
    return _fecha;
}

std::string Servicio::getDniMasajista(){
    return _dniMasajista;
}

int Servicio::getIdEmpresa(){
    return _idEmpresa;
}

int Servicio::getIdSede(){
    return _idSede;
}

int Servicio::getIdTpo(){
    return _idTipo;
}

int Servicio::getCantidadHoras(){
    return _cantidadHoras;
}

float Servicio::getValorHora(){
    return _valorHora;
}


// Setters
void Servicio::setIdServicio(int idServicio){
    _idServicio = idServicio;
}

void Servicio::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Servicio::setDniMasajista(std::string dniMasajista){
    strcpy(_dniMasajista, dniMasajista.c_str());
}

void Servicio::setIdEmpresa(int idEmpresa){
    _idEmpresa = idEmpresa;
}

void Servicio::setIdSede(int idSede){
    _idSede = idSede;
}

void Servicio::setIdTipo(int idTipo){
    _idTipo = idTipo;
}

void Servicio::setCantidadHoras(int cantidadHoras){
    _cantidadHoras = cantidadHoras;
}

void Servicio::setValorHora(float valorHora){
    _valorHora = valorHora;
}


// Mostrar y convertir datos
std::string Servicio::enviarAcsv(){
    string cadena = "";
    cadena = to_string(_idServicio) + ",";
    cadena += _fecha.convertirACadena() + ",";
    cadena += string(_dniMasajista) + ",";
    cadena += to_string(_idEmpresa) + ",";
    cadena += to_string(_idSede) + ",";
    cadena += to_string(_idTipo) + ",";
    cadena += to_string(_cantidadHoras) + ",";
    cadena += to_string(_valorHora);
}

std::string Servicio::mostrarEnPantalla(){
    string cadena = "";
    cadena = to_string(_idServicio) + "  ";
    cadena += _fecha.convertirACadena() + "  ";
    cadena += string(_dniMasajista) + "  ";
    cadena += to_string(_idEmpresa) + "  ";
    cadena += to_string(_idSede) + "  ";
    cadena += to_string(_idTipo) + "  ";
    cadena += to_string(_cantidadHoras) + "  ";
    cadena += to_string(_valorHora);
}
