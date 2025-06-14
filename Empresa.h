#pragma once

#include <string>

class Empresa{;
    private:
        int _id;
        char _nombre[30];
        char _cuit[11];
        char _direccion[50];
        char _telefono[15];
        char _email[50];

    public:
        Empresa();
        Empresa(int id, std::string nombre, std::string cuit, std::string direccion, std::string telefono, std::string email);

        // Getters
        int getId();
        std::string getNombre();
        std::string getCuit();
        std::string getDireccion();
        std::string getTelefono();
        std::string getEmail();

        // Setters
        void setId(int dni);
        void setNombre(std::string nombre);
        void setCuit(std::string cuit);
        void setDireccion(std::string direccion);
        void setTelefono(std::string telefono);
        void setEmail(std::string email);
};
