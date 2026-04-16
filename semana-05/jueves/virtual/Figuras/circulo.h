#pragma once
#include "figura.h"

class Circulo: public Figura {
public:
	Circulo();
   Circulo(float radio);
   
   float getRadio() const;
   void setRadio(float radio);
   
   float calcularArea() const override;
private:
   float _radio;
};


