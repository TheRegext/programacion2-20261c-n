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
        int Buscar(int idTarea);

        int getCantidadRegistros();

};
