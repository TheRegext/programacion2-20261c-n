#pragma once
#include <string>
#include "tarea.h"

class TareaArchivo {
public:
	TareaArchivo(std::string nombreArchivo = "tareas.dat");
   bool guardar(const Tarea &reg);
   Tarea leer(int pos);
   int getCantidadRegistros();
   int getNuevoId();
   
   int getPosById(int id); /// Hay que hacerlo para el proximo jueves.

private:
   std::string _nombreArchivo;
};
