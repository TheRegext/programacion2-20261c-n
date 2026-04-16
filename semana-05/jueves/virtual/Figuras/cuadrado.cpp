#include "cuadrado.h"

Cuadrado::Cuadrado()
:_lado(0){
   setTipo("cuadrado");
}

Cuadrado::Cuadrado(float lado)
:Cuadrado(){
   setLado(lado);
}

float Cuadrado::getLado() const{
   return _lado;
}

void Cuadrado::setLado(float lado){
   _lado = lado;
}

float Cuadrado::calcularArea() const{
   return _lado * _lado;
}
