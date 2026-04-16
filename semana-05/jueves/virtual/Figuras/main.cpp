#include<iostream>
#include <ctime>

#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
using namespace std;


/***
   crea un objeto
   asigna el valor del objeto original (campo por campo)
   pasa a la funcion
*/


/// Polimorfismo Estatico

/// side effect
void mostrarFigura(const Figura &figura){
   cout << "El area de "<<figura.getTipo()<<" es: " << figura.calcularArea() << endl;
}
/*
void mostrarFigura(const Cuadrado &figura){
   cout << "El area de "<<figura.getTipo()<<" es: " << figura.calcularArea() << endl;
}

void mostrarFigura(const Circulo &figura){
   cout << "El area de "<<figura.getTipo()<<" es: " << figura.calcularArea() << endl;
}
*/

int main () {
   /// & *
   /**
      this es el puntero del objeto que esta llamando al metodo
   
      cuando se quiere acceder a una propiedad:
      puntero la forma de acceder es ->
      ref o valor la foram de acceder es con el .
   */
   
   
   Figura *figuras[10];
   int opcion;
   
   srand(time(0));
   
   for(int i=0; i<10; i++){
      cout << "Ingrese que quiere? 1 Circulo, 2 Cuadrado";
      cin >> opcion;
      
      switch(opcion){
      case 1:
         figuras[i] = new Circulo(2);
         break;
      case 2:
         figuras[i] = new Cuadrado(10);
         break;
      }
   }
   
   for(int i=0; i<10; i++){
      cout << "Tipo: " << figuras[i]->getTipo() 
         << " Area: " << figuras[i]->calcularArea() << endl;
   }
   
   for(int i=0; i<10; i++){
      delete figuras[i];
   }
   
   
   
   /*
   Cuadrado cuadrado(5);
   Circulo circulo(5);
   
   mostrarFigura(cuadrado);
   mostrarFigura(circulo);
   */
	
	return 0;
}

