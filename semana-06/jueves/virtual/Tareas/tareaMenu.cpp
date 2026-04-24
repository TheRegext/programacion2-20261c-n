#include <iostream>
#include "tareaMenu.h"
#include <cstdio>

using namespace std;

TareaMenu::TareaMenu(){
   setCantidadOpciones(4);
}

void TareaMenu::mostrarOpciones(){ /// << este no....
   cout << "---------------------"<<endl;
   cout << "1. Guardar Tarea" << endl;   cout << "2. Modificar Tareas" << endl;
   cout << "3. Eliminar Tareas" << endl;
   cout << "4. Listar Tareas" << endl;   cout << "0. Salir" << endl;
   cout << "---------------------"<<endl;
}

void TareaMenu::ejecutarOpcion(int opcion){ /// particular
   switch(opcion){
   case 1:
      _managerTarea.guardarTarea();
      break;
   case 2:
      /// _managerTarea.modificarTarea();
      break;
   case 3:
      /// _managerTarea.eliminarTarea();
      break;
   case 4:
      _managerTarea.listarTareas();
      break;
   case 0:
      cout << "Saliendo del menu!"<<endl;
      break;
   }
}

