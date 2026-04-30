#pragma once
#include "Tarea.h"
#include <string>

class TareaArchivo{
    private:
        std::string _nombreArchivo;

    public:
        TareaArchivo();
        TareaArchivo(std::string nombreArchivo);
        bool Guardar(Tarea tarea);
        bool Guardar(Tarea tarea, int posicion);
        Tarea Leer(int posicion);
        void Leer(int cantidadALeer, Tarea *vec);
        int Buscar(int idTarea);
        bool Truncar();

        int getCantidadRegistros();

};
