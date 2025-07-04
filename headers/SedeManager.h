#pragma once

class SedeManager{
    public:
        void buscar();
        void cargar();
        void listarIdsNombres();
        void listarSedes();
        void sedesActivas();
        void sedesPorEmpresa();

        // Modificadores de registros
        void modificarDireccion();
        void modificarEmail();
        void modificarEstado();
        void modificarIdEmpresa();
        void modificarNombre();
        void modificarTelefono();
};
