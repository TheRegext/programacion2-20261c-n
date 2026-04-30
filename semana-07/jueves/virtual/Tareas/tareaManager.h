#pragma once 
#include "tareaArchivo.h"

class TareaManager {
public:
	TareaManager();
   
   void guardarTarea();
   void listarTareas();
   void modificarTarea();
   
private:
   Tarea crearTarea();
   void mostrarTarea(const Tarea &reg);
   TareaArchivo _repoTareas;
};

