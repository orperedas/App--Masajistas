#pragma once

class ServicioManager{
    public:
        std::string buscarNombreMasajista(std::string dni_masajista);
        std::string buscarNombreEmpresa(int id_empresa);
        std::string buscarNombreSede(int id_Sede);
        std::string buscarNombreTipo(int id_tipo);
        float buscarValorHoraTipo(int id_tipo);

        void buscar();
        void cargar();
        void listarIdsNombres();
        void listarServicios();
        void listarSedesXEmpresa();
        void ServiciosActivos();
        void mostrarCantidadServicios();

        // Modificadores de registros
        void modificarCantidadHoras();
        void modificarFecha();
        void modificarMasajista();
        void modificarSede();
        void modificarTipoServicio();
};
