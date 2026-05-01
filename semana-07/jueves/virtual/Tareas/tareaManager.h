#pragma once 
#include "tareaArchivo.h"

class TareaManager {
public:
	TareaManager();
   
   void guardarTarea();
   void listarTareas();
   void modificarTarea();
   void mostrarTareasOrdenadas();
   
private:
   Tarea crearTarea();
   void mostrarTarea(const Tarea &reg);
   void ordenarTareas(Tarea vTareas[], int cantidad);
   TareaArchivo _repoTareas;
};

