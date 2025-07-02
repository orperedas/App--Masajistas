#include "Servicio.h"

#include <iostream>
#include <cstring>

using namespace std;


Servicio::Servicio(){
    int _idServicio = 0;
    Fecha _fecha = Fecha();
    strcpy(_nombreMasajista, "");
    strcpy(_nombreEmpresa, "");
    strcpy(_nombreSede, "");
    strcpy(_nombreTipo, "");
    int _cantidadHoras = 0;
    float _valorHoraTipo = 0.0;
}

Servicio::Servicio(int idServicio, Fecha fecha, std::string nombreMasajista, std::string nombreEmpresa, std::string nombreSede, std::string nombreTipo, int cantidadHorasTipo, float valorHoraTipo){
    setIdServicio(idServicio);
    setFecha(fecha);
    setNombreMasajista(nombreMasajista);
    setNombreEmpresa(nombreEmpresa);
    setNombreSede(nombreSede);
    setNombreTipo(nombreTipo);
    setCantidadHoras(cantidadHorasTipo);
    setValorHora(valorHoraTipo);
}


// Getters
int Servicio::getIdServicio(){
    return _idServicio;
}

Fecha Servicio::getFecha(){
    return _fecha;
}

std::string Servicio::getnombreMasajista(){
    return _nombreMasajista;
}

std::string Servicio::getNombreEmpresa(){
    return _nombreEmpresa;
}

std::string Servicio::getNombreSede(){
    return _nombreSede;
}

std::string Servicio::getNombreTpo(){
    return _nombreTipo;
}

int Servicio::getCantidadHorasTipo(){
    return _cantidadHorasTipo;
}

float Servicio::getValorHoraTipo(){
    return _valorHoraTipo;
}


// Setters
void Servicio::setIdServicio(int idServicio){
    _idServicio = idServicio;
}

void Servicio::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Servicio::setNombreMasajista(std::string nombreMasajista){
    strcpy(_nombreMasajista, nombreMasajista.c_str());
}

void Servicio::setNombreEmpresa(std::string nombreEmpresa){
    strcpy(_nombreEmpresa, nombreEmpresa.c_str());
}

void Servicio::setNombreSede(std::string nombreSede){
    strcpy(_nombreSede, nombreSede.c_str());
}

void Servicio::setNombreTipo(std::string nombreTipo){
    strcpy(_nombreTipo, nombreTipo.c_str());
}

void Servicio::setCantidadHoras(int cantidadHorasTipo){
    _cantidadHorasTipo = cantidadHorasTipo;
}

void Servicio::setValorHora(float valorHoraTipo){
    _valorHoraTipo = valorHoraTipo;
}


// Mostrar y convertir datos
std::string Servicio::enviarAcsv(){
    string cadena = "";
    cadena = to_string(_idServicio) + ",";
    cadena += _fecha.convertirACadena() + ",";
    cadena += string(_nombreMasajista) + ",";
    cadena += string(_nombreEmpresa) + ",";
    cadena += string(_nombreSede) + ",";
    cadena += string(_nombreTipo) + ",";
    cadena += to_string(_cantidadHorasTipo) + ",";
    cadena += to_string(_valorHoraTipo);
}

std::string Servicio::mostrarEnPantalla(){
    string cadena = "";
    cadena = to_string(_idServicio) + "  ";
    cadena += _fecha.convertirACadena() + "  ";
    cadena += string(_nombreMasajista) + "  ";
    cadena += string(_nombreEmpresa) + "  ";
    cadena += string(_nombreSede) + "  ";
    cadena += string(_nombreTipo) + "  ";
    cadena += to_string(_cantidadHorasTipo) + "  ";
    cadena += to_string(_valorHoraTipo);
}
