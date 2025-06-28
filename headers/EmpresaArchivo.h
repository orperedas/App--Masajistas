#pragma once

#include "Empresa.h"

#include <string>

class EmpresaArchivo{
    private:
        std::string _nombreArchivo;

    public:
        EmpresaArchivo();
        EmpresaArchivo(std::string nombreArchivo);

        int tamanioRegistro();
        int getCantidadEmpresas();

        int buscar(int idEmpresa);
        bool guardar(Empresa registro);
        bool guardar(Empresa registro, int posicion);
        bool modificar(Empresa registro, int posicio);

        Empresa leer(int posiciion);
};
