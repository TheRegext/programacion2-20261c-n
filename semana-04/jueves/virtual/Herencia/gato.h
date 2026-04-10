#pragma once
#include <string>
#include "mascota.h"

class Gato: public Mascota {
public:
   Gato();
   Gato(bool esInterior, std::string nombre, int edad);
   
   void setEsInterior(bool esInterior);
   bool getEsInterior();
   
   void maullar();
   
private:
   bool _esInterior;
};

