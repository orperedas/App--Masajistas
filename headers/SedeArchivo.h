#pragma once

#include "Sede.h"

#include <string>

class SedeArchivo{
    private:
        std::string _nombreArchivo;

    public:
        SedeArchivo();
        SedeArchivo(std::string nombreArchivo);

        int tamanioRegistro();
        int getCantidadSedes();

        int buscar(int id);
        bool guardar(Sede registro);
        bool guardar(Sede registro, int posicion);
        bool modificar(Sede registro, int posicio);

        Sede leer(int posiciion);
};

