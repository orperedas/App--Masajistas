#pragma once

#include <string>

class Sede{
    private:
        int _id;
        char _nombre[30];
        char _direccion[50];
        char _telefono[15];
        char _email[50];
        bool _estado;
        int _idEmpresa;

    public:
        Sede();
        Sede(int id, std::string nombre, std::string direccion, std::string telefono, std::string email, bool estado, int idEmpresa);

        // Getters
        int getId();
        std::string getNombre();
        std::string getDireccion();
        std::string getTelefono();
        std::string getEmail();
        bool getEstado();
        int getIdEmpresa();

        // Setters
        void setId(int id);
        void setNombre(std::string nombre);
        void setDireccion(std::string direccion);
        void setTelefono(std::string telefono);
        void setEmail(std::string email);
        void setEstado(bool estado);
        void setIdEmpresa(int idEmpresa);

        std::string enviarAcsv();
        std::string mostrarEnPantalla();
        std::string mostrarIdNombre();
};
