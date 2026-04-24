#ifndef TAREAGESTOR_H_INCLUDED
#define TAREAGESTOR_H_INCLUDED

#include "TareaArchivo.h"

class TareaGestor{
    private:
        TareaArchivo _repo;
        bool Existe(int id);
        void Mostrar(Tarea tarea);

    public:
        void Modificar();
        void Crear();
        void MostrarPorId();
        void ListarTodas();
};

#endif // TAREAGESTOR_H_INCLUDED
