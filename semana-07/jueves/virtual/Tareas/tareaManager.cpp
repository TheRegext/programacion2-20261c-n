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
   if(_repoTareas.crear(reg)){
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
      mostrarTarea(t);
   }
}

void TareaManager::mostrarTarea(const Tarea &reg){
   cout << "-----------------------"<<endl;
   cout << "ID #" << reg.getId() << endl;
   cout << "Tarea: " << reg.getTitulo() << endl;   
   cout << "Fecha Creacion: " << 
      reg.getFechaCreacion().getDia() 
      << "/" << reg.getFechaCreacion().getMes() 
      << "/" << reg.getFechaCreacion().getAnio() << endl;   
   
   cout << "Estado: " << reg.getEstadoString() << endl;   
}

void TareaManager::modificarTarea(){
   int id;
   bool modifica;
   string titulo;
   
   cout << "Ingrese id a modificar: ";
   cin >> id;
   
   int pos = _repoTareas.buscarId(id); /// 0 - N (-1)
   
   if(pos == -1){
      cout << "El id no existe en el sistema" << endl;
      return;
   }
   
   Tarea reg = _repoTareas.leer(pos);
   
   cout << "TAREA A MODIFICAR: " << endl;
   
   mostrarTarea(reg);   
   
   cout << "-------------------------" << endl;
   
   cout << "Esta seguro de que quiere cambiar esta tarea? 1-Si 0-No" << endl;
   cin >> modifica;
   
   if(!modifica){
      return;
   }
   
   cout << "Ingrese nuevo titulo de tarea: ";
   titulo = cargarCadena();
   
   reg.setTitulo(titulo);
   
   if(_repoTareas.actualizar(pos, reg)){
      cout << "Guardado exitosamente!" << endl;
   }
   else{
      cout << "No se pudo guardar" << endl;
   }
}


