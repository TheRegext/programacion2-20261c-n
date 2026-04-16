#pragma once
#include <string>

class Figura {
public:
	Figura();
   virtual float calcularArea() const = 0; /// virtual pura
   
   std::string getTipo() const;
protected:
   void setTipo(std::string tipo);
   
private:
   std::string _tipo;
};



