#pragma once

#include "TipoServicio.h"

#include <string>

class TipoServicioArchivo{
    private:
        std::string _nombreArchivo;

    public:
        TipoServicioArchivo();
        TipoServicioArchivo(std::string nombreArchivo);

        bool comprobarExisteArchivo();
        int tamanioRegistro();
        int getCantidadTipos();

        int buscar(int idTipoServicio);
        bool guardar(TipoServicio registro);
        bool guardar(TipoServicio registro, int posicion);
        bool modificar(TipoServicio registro, int posicio);

        TipoServicio leer(int posiciion);
};
