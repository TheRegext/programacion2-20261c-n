#ifndef TAREAGESTOR_H_INCLUDED
#define TAREAGESTOR_H_INCLUDED

#include "TareaArchivo.h"

class TareaGestor{
    private:
        TareaArchivo _repo;
        bool Existe(int id);
        void Mostrar(Tarea tarea);
        void Ordenar(Tarea *vec, int cantidad);

    public:
        void Modificar();
        void Crear();
        void MostrarPorId();
        void ListarOrdenado();
        void ListarTodas();
        void Eliminar();
        void Truncar();
};

#endif // TAREAGESTOR_H_INCLUDED
