#include "Empresa.h"

#include <cstring>

using namespace std;

Empresa::Empresa(){
    int _id = 0;
    strcpy(_nombre, "");
    strcpy(_cuit, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    bool _estado;
}

Empresa::Empresa(int id, std::string nombre, std::string cuit, std::string direccion, std::string telefono,  std::string email, bool estado){
    setId(id);
    setNombre(nombre);
    setCuit(cuit);
    setDireccion(direccion);
    setTelefono(telefono);
    setEmail(email);
    setEstado(estado);
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

bool Empresa::getEstado(){
    return _estado;
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

void Empresa::setEstado(bool estado){
    _estado = estado;
}


std::string Empresa::enviarAcsv(){
    string cadena = "";
    cadena = to_string(_id) + ",";
    cadena += string(_nombre) + ",";
    cadena += string(_cuit) + ",";
    cadena += string(_direccion) + ",";
    cadena += string(_telefono) + ",";
    cadena += string(_email) + ",";
    cadena += to_string(_estado);

    return cadena;
}


std::string Empresa::mostrarEnPantalla(){
    string cadena = "";
    cadena = to_string(_id) + "  ";
    cadena += string(_nombre) + "  ";
    cadena += string(_cuit) + "  ";
    cadena += string(_direccion) + "  ";
    cadena += string(_telefono) + "  ";
    cadena += string(_email) + "  ";
    cadena += to_string(_estado);

    return cadena;
}

