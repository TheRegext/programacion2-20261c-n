#include <iostream>
#include "tarea.h"
#include "tareaManager.h"
#include "utils.h"
using namespace std;

TareaManager::TareaManager()
   : _repoTareas(){
   
}

Tarea TareaManager::crearTarea(){
   int id = _repoTareas.getNuevoId(); 
   string titulo;
   
   cout << "El codigo es: #" << id << endl;
   cout << "Ingrese titulo: ";
   titulo = cargarCadena();

   return Tarea(id, titulo, 1); /// objeto anonimo
}

void TareaManager::guardarTarea(){
   Tarea reg = crearTarea();
   if(_repoTareas.guardar(reg)){
      cout << "Se guardo exitosamente" << endl;
   }
   else{
      cout << "No se pudo guardar" << endl;
   }
}

void TareaManager::listarTareas(){
   int cantidad = _repoTareas.getCantidadRegistros();
   
   for(int i=0; i<cantidad; i++){
      Tarea t = _repoTareas.leer(i);
      cout << "-----------------------"<<endl;
      cout << "ID #" << t.getId() << endl;
      cout << "Tarea: " << t.getTitulo() << endl;   
      cout << "Fecha Creacion: " << 
            t.getFechaCreacion().getDia() 
            << "/" << t.getFechaCreacion().getMes() 
            << "/" << t.getFechaCreacion().getAnio() << endl;   
   }
}


