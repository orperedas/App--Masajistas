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
        bool guardar(TipoServicio registro);
        bool guardar(TipoServicio registro, int posicion);
        bool modificarEsstado(TipoServicio registro, int posicio);
        int getCantidadTipos();
        int buscar(int idTipoServicio);

        TipoServicio leer(int posiciion);
};
