#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
  cout << sumar(5,6) << endl;
  cout << sumar(5,6, 7) << endl;
  cout << sumar(5.f,6.f) << endl;

  
  
  //j = pedirNumeroPositivo("Ingrese edad: ");
  //n = pedirNumeroPositivo("Ingrese la edad: ", "No es una edad valida");
  
  //cout << "La suma es: " << j + n << endl;
  
  /// declaracion 
  /// *
  /// &
  
  /// operador (uso)
  /// & variable => la direccion de memoria de la variable
  /// * puntero => valor de donde apunta ese puntero
  
  
  
/*
  mostrar(10); // valor literal 10
  mostrar(j);  // valor que contiene la variable (15)
  mostrar(j + 10);  // valor que contiene la variable (15)
*/
  ///mostrarR(j); // enviamos la variable j
  
  /// cout << "J: " << &j << endl;
  /// mostrarP(&j);
  
  //mostrarP(0x0000);



  return 0;
}
