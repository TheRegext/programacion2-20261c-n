#include <cstring>
#include "tarea.h"

Tarea::Tarea()
   :_id(0), _titulo(""), _estado(0),
   _fechaCreacion(), _fechaInicio(), _fechaCompletado(){}

Tarea::Tarea(int id, std::string titulo, int estado, Fecha creacion, 
      Fecha inicio, Fecha completado){
   
   setId(id);
   setTitulo(titulo);
   setEstado(estado);
   
   setFechaCreacion(creacion);
   setFechaCompletado(completado);   
   setFechaInicio(inicio);
}

int Tarea::getId() const{
   return _id;
}

void Tarea::setId(int id){
   _id = id;
}

std::string Tarea::getTitulo() const{
   // return _titulo; /// convertirlo implicitamente 
   return std::string(_titulo); /// conversion explicita
}

void Tarea::setTitulo(std::string titulo){
   if(titulo.size() < 100){
      strcpy(_titulo, titulo.c_str());
   }
   else{
      strcpy(_titulo, "Titulo fuera de rango...");
   }
   
}

int Tarea::getEstado() const{
   return _estado;
}

void Tarea::setEstado(int estado){
   _estado = estado;
}

Fecha Tarea::getFechaCreacion() const{
   return _fechaCreacion;
}

void Tarea::setFechaCreacion(Fecha fechaCreacion){
   _fechaCreacion = fechaCreacion;
}

Fecha Tarea::getFechaInicio() const{
   return _fechaInicio;
}

void Tarea::setFechaInicio(Fecha fechaInicio){
   _fechaInicio = fechaInicio;
}

Fecha Tarea::getFechaCompletado() const{
   return _fechaCompletado;
}

void Tarea::setFechaCompletado(Fecha fechaCompletado){
   _fechaCompletado = fechaCompletado;
}
