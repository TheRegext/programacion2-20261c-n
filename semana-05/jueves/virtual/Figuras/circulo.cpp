#define _USE_MATH_DEFINES

#include <cmath>
#include "circulo.h"

Circulo::Circulo()
:_radio(0){
   setTipo("circulo");
}

Circulo::Circulo(float radio)
:Circulo(){
   setRadio(radio);
}

float Circulo::getRadio() const{
   return _radio;
}

void Circulo::setRadio(float radio){
   _radio = radio;
}
 
float Circulo::calcularArea() const{
   return M_PI * _radio * _radio;
}
