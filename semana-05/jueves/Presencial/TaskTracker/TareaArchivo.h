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
        Tarea Leer(int posicion);
        int getCantidadRegistros();

};
