#pragma once

#include "Servicio.h"

#include <string>

class ServicioArchivo{
    private:
        std::string _nombreArchivo;

    public:
        ServicioArchivo();
        ServicioArchivo(std::string nombreArchivo);

        int tamanioRegistro();
        int getCantidadServicios();

        int buscar(int idServicio);
        bool guardar(Servicio registro);
        bool guardar(Servicio registro, int posicion);
        bool modificar(Servicio registro, int posicio);

        Servicio leer(int posiciion);
};
