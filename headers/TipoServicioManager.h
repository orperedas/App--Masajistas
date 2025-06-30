#pragma once

class TipoServicioManager{
    private:


    public:
        void buscar();
        void cargar();
        void listarIdsNombres();
        void listarTipoServicios();
        void TiposServiciosActivos();

        // Modificadores de registros
        void modificarDescripcion();
        void modificarEstado();
        void modificarModalidad();
        void modificarNombre();
        void modificarValorHora();
};
