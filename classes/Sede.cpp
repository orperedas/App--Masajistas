#include "Sede.h"
#include "Empresa.h"

#include <cstring>

using namespace std;

Sede::Sede(){
    _id = 0;
    strcpy(_nombre, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
}

Sede::Sede(int id, std::string nombre, std::string direccion, std::string telefono, std::string email){
    setId(id);
    setNombre(nombre);
    setDireccion(direccion);
    setTelefono(telefono);
    setEmail(email);
}

int Sede::getId(){
    return _id;
}

std::string Sede::getNombre(){
    return _nombre;
}

std::string Sede::getDireccion(){
    return _direccion;
}

std::string Sede::getTelefono(){
    return _telefono;
}

std::string Sede::getEmail(){
    return _email;
}

// Setters
void Sede::setId(int id){
    _id = id;
}

void Sede::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}

void Sede::setDireccion(std::string direccion){
    strcpy(_direccion, direccion.c_str());
}

void Sede::setTelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}

void Sede::setEmail(std::string email){
    strcpy(_email, email.c_str());
}

