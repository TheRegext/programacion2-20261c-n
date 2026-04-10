#pragma once
#include <string>
#include "animal.h"

class Mascota : public Animal {
public:
   Mascota();
   Mascota(std::string nombre, int edad, std::string tipo);
   
   void setNombre(std::string nombre);
   std::string getNombre();
   
   void pasear();
   
private:
   std::string _nombre;
};



