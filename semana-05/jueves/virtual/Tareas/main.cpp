#include<iostream>
#include "tarea.h"
#include "tareaArchivo.h"
using namespace std;

int main () {
   TareaArchivo ta;
   Tarea t;
   Fecha f;
   f.setCurrentDate();
   
   t.setId(ta.getNuevoId());
   t.setFechaCreacion(f);
   t.setEstado(1);
   t.setTitulo("Explicar Polimorfismo.");
   
   if(ta.guardar(t)){
      cout << "Se guardo exitosamente" << endl;
   }
   else{
      cout << "No se pudo guardar" << endl;
   }
   
   
   int cantidad = ta.getCantidadRegistros();
   
   for(int i=0; i<cantidad; i++){
      t = ta.leer(i);
      cout << "-----------------------"<<endl;
      cout << "ID #" << t.getId() << endl;
      cout << "Tarea: " << t.getTitulo() << endl;   
   }
   
   
   

	return 0;
}

