#pragma once

#include <string>

class TipoServicio{
    private:
        int _id;
        char _nombre[50];
        char _descripcion[200];
        char _modalidad[20];
        float _valorHora;

    public:
        TipoServicio();
        TipoServicio(int id, std::string nombre, std::string descripcion, std::string modalidad, float valorHora);

        // Getters
        int getId();
        std::string getNombre();
        std::string getDescripcion();
        std::string getModalidad();
        float getValorHora();

        // Setters
        void setId(int id);
        void setNombre(std::string nombre);
        void setDescripcion(std::string descripcion);
        void setModalidad(std::string modalidad);
        void setValorHora(float valorHora);
};
