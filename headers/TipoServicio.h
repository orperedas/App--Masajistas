#pragma once

#include <string>

class TipoServicio{
    private:
        int _id;
        char _nombre[50];
        char _descripcion[200];
        char _modalidad[20];
        float _valorHora;
        bool _estado;

    public:
        TipoServicio();
        TipoServicio(int id, std::string nombre, std::string descripcion, std::string modalidad, float valorHora, bool estado);

        // Getters
        int getId();
        std::string getNombre();
        std::string getDescripcion();
        std::string getModalidad();
        float getValorHora();
        bool getEstado();

        // Setters
        void setId(int id);
        void setNombre(std::string nombre);
        void setDescripcion(std::string descripcion);
        void setModalidad(std::string modalidad);
        void setValorHora(float valorHora);
        void setEstado(bool estado);

        std::string enviarAcsv();
        std::string mostrarEnPantalla();
        std::string mostrarIdNombreTipo();
};
