#include "figura.h"

Figura::Figura()
:_tipo("figura"){
	
}

std::string Figura::getTipo() const{
   return _tipo;
}

void Figura::setTipo(std::string tipo){
   _tipo = tipo;
}

