#include <iostream>
#include "mascota.h"

using namespace std;

Mascota::Mascota()
:Animal(), _nombre("Sin nombre"){
   
}

Mascota::Mascota(std::string nombre, int edad, std::string tipo)
: Animal(edad, tipo){
   setNombre(nombre);
}

void Mascota::setNombre(std::string nombre){
   _nombre = nombre;
}

std::string Mascota::getNombre(){
   return _nombre;
}


void Mascota::pasear(){   
   cout << "Estamos paseando a " << _nombre << " y esta feliz :) "<<endl;
}
