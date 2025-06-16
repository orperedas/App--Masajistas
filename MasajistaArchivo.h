#pragma once

#include "Masajista.h"

#include <string>

class MasajistaArchivo{
    private:
        std::string _nombreArchivo;

    public:
        MasajistaArchivo();
        MasajistaArchivo(std:string nombreArchivo);

        bool guardar(Postulante registro);
};
