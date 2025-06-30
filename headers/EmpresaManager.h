#pragma once

class EmpresaManager{
    public:
        void buscar();
        void cargar();
        void listarIdsNombres();
        void listarEmpresas();
        void EmpresasActivas();

        // Modificadores de registros
        void modificarCuit();
        void modificarDireccion();
        void modificarEmail();
        void modificarEstado();
        void modificarNombre();
        void modificarTelefono();
};
