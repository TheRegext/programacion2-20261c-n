#pragma once 
#include "tareaArchivo.h"

class TareaManager {
public:
	TareaManager();
   
   void guardarTarea();
   void listarTareas();
   
private:
   Tarea crearTarea();
   TareaArchivo _repoTareas;
};

