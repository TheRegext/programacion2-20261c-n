#include <iostream>
#include "gato.h"

using namespace std;

Gato::Gato()
: Mascota(), _esInterior(false){
   setTipo("Gato");
}

Gato::Gato(bool esInterior, std::string nombre, int edad)
:Mascota(nombre, edad, "Gato"){
   setEsInterior(esInterior);
}

void Gato::setEsInterior(bool esInterior){
   _esInterior = esInterior;
}
bool Gato::getEsInterior(){
   return _esInterior;
}

void Gato::maullar(){
   if(_esInterior){
      cout << "Miau... desde afuera..." << endl;
   }
   else{
      cout << "Miau... desde adentro..." << endl;
   }
}
