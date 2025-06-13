#include "Masajista.h"

#include <iostream>
#include <cstring>

using namespace std;

Masajista::Masajista(){
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_cuit, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
}

Masajista::Masajista(std::string dni, std::string nombre, std::string apellido, std::string cuit, std::string telefono, std::string direccion, std::string email){
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setCuit(cuit);
    setDireccion(direccion);
    setTelefono(telefono);
    setEmail(email);
}

std::string Masajista::getDni(){
    return _dni;
}

std::string Masajista::getNombre(){
    return _nombre;
}

std::string Masajista::getApellido(){
    return _apellido;
}

std::string Masajista::getCuit(){
    return _cuit;
}

std::string Masajista::getDireccion(){
    return _direccion;
}

std::string Masajista::getTelefono(){
    return _telefono;
}

std::string Masajista::getEmail(){
    return _email;
}


void Masajista::setDni(std::string dni){
    strcpy(_dni, dni.c_str());
}

void Masajista::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}

void Masajista::setApellido(std::string apellido){
    strcpy(_apellido, apellido.c_str());
}

void Masajista::setCuit(std::string cuit){
    strcpy(_cuit, cuit.c_str());
}

void Masajista::setDireccion(std::string direccion){
    strcpy(_direccion, direccion.c_str());
}

void Masajista::setTelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}

void Masajista::setEmail(std::string email){
    strcpy(_email, email.c_str());
}
