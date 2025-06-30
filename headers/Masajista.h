#pragma once

#include <string>

class Masajista{
    private:
        char _dni[10];
        char _nombre[20];
        char _apellido[20];
        char _cuit[11];
        char _direccion[50];
        char _telefono[15];
        char _email[50];
        bool _estado;

    public:
        Masajista();
        Masajista(std::string dni, std::string nombre, std::string apellido, std::string cuit, std::string direccion, std::string telefono, std::string email, bool estado);

        // Getters
        std::string getDni();
        std::string getNombre();
        std::string getApellido();
        std::string getCuit();
        std::string getDireccion();
        std::string getTelefono();
        std::string getEmail();
        bool getEstado();

        // Setters
        void setDni(std::string dni);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setCuit(std::string cuit);
        void setDireccion(std::string direccion);
        void setTelefono(std::string telefono);
        void setEmail(std::string email);
        void setEstado(bool estado);

        // Mostrar y convertir datos
        std::string enviarAcsv();
        std::string mostrarEnPantalla();
        std::string mostrarDniNombre();
};
