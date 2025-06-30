#pragma once

#include "Fecha.h"

class Servicio{
    private:
        int _idServicio;
        Fecha _fecha;
        char _dniMasajista[20];
        int _idEmpresa;
        int _idSede;
        int _idTipo;
        int _cantidadHoras;
        float _valorHora;

    public:
        Servicio();
        Servicio(int idServicio, Fecha fecha, std::string dniMasajista, int idEmpresa, int idSede, int idTipo, int cantidadHoras, float valorHora);

        // Getters
        int getIdServicio();
        Fecha getFecha();
        std::string getDniMasajista();
        int getIdEmpresa();
        int getIdSede();
        int getIdTpo();
        int getCantidadHoras();
        float getValorHora();

        // Setters
        void setIdServicio(int idServicio);
        void setFecha(Fecha fecha);
        void setDniMasajista(std::string dniMasajista);
        void setIdEmpresa(int idEmpresa);
        void setIdSede(int idSede);
        void setIdTipo(int idTipo);
        void setCantidadHoras(int cantidadHoras);
        void setValorHora(float valorHora);

        // Mostrar y convertir datos
        std::string enviarAcsv();
        std::string mostrarEnPantalla();
};
