#pragma once
#include <string>
#include "fecha.h"

class Tarea {
public:
	Tarea();
   Tarea(int id, std::string titulo, int estado);
   
   Tarea(int id, std::string titulo, int estado, Fecha creacion, 
         Fecha inicio, Fecha completado);
   
   
   
   int getId() const;
   void setId(int id);
   
   std::string getTitulo() const;
   void setTitulo(std::string titulo);
   
   int getEstado() const;
   void setEstado(int estado);
   
   std::string getEstadoString() const;
   
   Fecha getFechaCreacion() const;
   void setFechaCreacion(Fecha fechaCreacion);
   
   Fecha getFechaInicio() const;
   void setFechaInicio(Fecha fechaInicio);
   
   Fecha getFechaCompletado() const;
   void setFechaCompletado(Fecha fechaCompletado);
   
private:
   int _id;
   char _titulo[100];
   int _estado; //  0-eliminado
   
   
   Fecha _fechaCreacion;
   Fecha _fechaInicio;
   Fecha _fechaCompletado;
};

