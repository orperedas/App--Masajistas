#pragma once

class MasajistaManager{
    private:


    public:
        void buscarMasajista();
        void cargarMasajista();
        void listarDnisNombres();
        void listarMasajistas();
        void masajistasActivos();
        void mostrarCantidadMasajistas();

        // Modificadores de registros
        void modificarApellido();
        void modificarCuit();
        void modificarDireccion();
        void modificarDni();
        void modificarEmail();
        void modificarEstado();
        void modificarNombre();
        void modificarTelefono();
};
