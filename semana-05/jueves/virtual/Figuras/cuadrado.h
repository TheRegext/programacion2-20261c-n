#pragma once
#include "figura.h"

class Cuadrado: public Figura {
public:
	Cuadrado();
   Cuadrado(float lado);
   
   float getLado() const;
   void setLado(float lado);
   
   float calcularArea() const override; /// Sobrecarga - Polimorfismo Estatico
   
private:
   float _lado;
};

