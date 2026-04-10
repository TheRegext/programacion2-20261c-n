#pragma once
#include <string>
/// PascalCase

class Animal {
public:
   Animal();
   Animal(int edad, std::string tipo);
   
   void setEdad(int edad);
   int getEdad();

   
   void comer();
   
   
protected:
   void setTipo(std::string tipo);
   std::string getTipo();
   
private:   
   int _edad;
   std::string _tipo;
};

