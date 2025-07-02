#pragma once

#include "Fecha.h"

class Servicio{
    private:
        int _idServicio;
        Fecha _fecha;
        char _nombreMasajista[30];
        char _nombreEmpresa[20];
        char _nombreSede[20];
        char _nombreTipo[20];
        int _cantidadHorasTipo;
        float _valorHoraTipo;

    public:
        Servicio();
        Servicio(int idServicio, Fecha fecha, std::string nombreMasajista, std::string nombreEmpresa, std::string nombreSede, std::string nombreTipo, int cantidadHorasTipo, float valorHoraTipo);

        // Getters
        int getIdServicio();
        Fecha getFecha();
        std::string getnombreMasajista();
        std::string getNombreEmpresa();
        std::string getNombreSede();
        std::string getNombreTpo();
        int getCantidadHorasTipo();
        float getValorHoraTipo();

        // Setters
        void setIdServicio(int idServicio);
        void setFecha(Fecha fecha);
        void setNombreMasajista(std::string nombreMasajista);
        void setNombreEmpresa(std::string nombreEmpresa);
        void setNombreSede(std::string nombreSede);
        void setNombreTipo(std::string nombreTipo);
        void setCantidadHoras(int cantidadHoras);
        void setValorHora(float valorHoraTipo);

        // Mostrar y convertir datos
        std::string enviarAcsv();
        std::string mostrarEnPantalla();
        std::string mostrarIdNombre();
};
