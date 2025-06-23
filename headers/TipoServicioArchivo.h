#pragma once

#include "Masajista.h"

#include <string>

class MasajistaArchivo{
    private:
        std::string _nombreArchivo;

    public:
        MasajistaArchivo();
        MasajistaArchivo(std::string nombreArchivo);

        int tamanioRegistro();
        bool guardar(Masajista registro);
        bool guardar(Masajista registro, int posicion);
        bool modificarEsstado(Masajista registro, int posicio);
        int getCantidadMasajistas();
        int buscar(std::string dniMasajista);

        Masajista leer(int posiciion);
};
