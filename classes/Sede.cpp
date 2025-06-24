#include "Sede.h"
#include "Empresa.h"

#include <cstring>

using namespace std;

Sede::Sede(){
    int _id = 0;
    strcpy(_nombre, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    bool _estado;
}

Sede::Sede(int id, std::string nombre, std::string direccion, std::string telefono, std::string email, bool estado){
    setId(id);
    setNombre(nombre);
    setDireccion(direccion);
    setTelefono(telefono);
    setEmail(email);
    setEstado(estado);
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

bool Sede::getEstado(){
    return _estado;
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

void Sede::setEstado(bool estado){
    _estado = estado;
}


std::string Sede::enviarAcsv(){
    string cadena = "";
    cadena = to_string(_id) + ",";
    cadena += string(_nombre) + ",";
    cadena += string(_direccion) + ",";
    cadena += string(_telefono) + ",";
    cadena += string(_email) + ",";
    cadena += to_string(_estado);

    return cadena;
}


std::string Sede::mostrarEnPantalla(){
    string cadena = "";
    cadena = to_string(_id) + "  ";
    cadena += string(_nombre) + "  ";
    cadena += string(_direccion) + "  ";
    cadena += string(_telefono) + "  ";
    cadena += string(_email) + "  ";
    cadena += to_string(_estado);

    return cadena;
}
