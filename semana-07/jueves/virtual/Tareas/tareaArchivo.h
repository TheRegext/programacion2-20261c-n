#pragma once
#include <string>
#include "tarea.h"

class TareaArchivo {
public:
	TareaArchivo(std::string nombreArchivo = "tareas.dat");
   
   bool crear(const Tarea &reg);
   bool actualizar(int pos, const Tarea &reg);
   
   Tarea leer(int pos);
   int leerTodos(Tarea vTareas[], int cantidad);
   
   int getCantidadRegistros();
   int getNuevoId();
   
   int buscarId(int id); /// Hay que hacerlo para el proximo jueves.

private:
   std::string _nombreArchivo;
};
