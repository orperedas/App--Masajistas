#include "Empresa.h"

#include <cstring>

using namespace std;

Empresa::Empresa(){
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_cuit, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
}

Empresa::Empresa(int id, std::string nombre, std::string cuit, std::string direccion, std::string telefono,  std::string email){
    setId(id);
    setNombre(nombre);
    setCuit(cuit);
    setDireccion(direccion);
    setTelefono(telefono);
    setEmail(email);
}

// Getters
int Empresa::getId(){
    return _id;
}

std::string Empresa::getNombre(){
    return _nombre;
}

std::string Empresa::getCuit(){
    return _cuit;
}

std::string Empresa::getDireccion(){
    return _direccion;
}

std::string Empresa::getTelefono(){
    return _telefono;
}

std::string Empresa::getEmail(){
    return _email;
}

// Setters
void Empresa::setId(int id){
    _id = id;
}

void Empresa::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}

void Empresa::setCuit(std::string cuit){
    strcpy(_cuit, cuit.c_str());
}

void Empresa::setDireccion(std::string direccion){
    strcpy(_direccion, direccion.c_str());
}

void Empresa::setTelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}

void Empresa::setEmail(std::string email){
    strcpy(_email, email.c_str());
}
