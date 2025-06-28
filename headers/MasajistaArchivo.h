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
        int getCantidadMasajistas();

        int buscar(std::string dniMasajista);
        bool guardar(Masajista registro);
        bool guardar(Masajista registro, int posicion);
        bool modificar(Masajista registro, int posicio);

        Masajista leer(int posiciion);
};
