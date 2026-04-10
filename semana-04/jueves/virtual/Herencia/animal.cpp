#include <iostream>
#include "animal.h"

using namespace std;

/**
   Constructor()
   : , , , {
   }

*/


/// lista de inicializacion
Animal::Animal()
:_edad(0), _tipo("Sin Definir"){
}

Animal::Animal(int edad, std::string tipo){
   setEdad(edad);
   setTipo(tipo);
}

void Animal::setEdad(int edad){
   if(edad >= 0){
      _edad = edad;
   }
   else{
      /// exception es lo correcto!
      /// cout << "La edad es incorrecta"; 
      _edad = 0;
   }
}

int Animal::getEdad(){
   return _edad;
}

void Animal::setTipo(std::string tipo){
   _tipo = tipo;
}

std::string Animal::getTipo(){
   return _tipo;
}

void Animal::comer(){
   cout << "El animal " << _tipo << " esta comiendo... y tiene " << _edad << " anios" << endl;
   
}

