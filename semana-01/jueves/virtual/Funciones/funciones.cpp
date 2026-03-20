#include <iostream>
#include "funciones.h"

using namespace std;

/*
  Valor
  que esta funcion recibe como argumento un valor, no una variable
*/
void mostrar(int n)
{
  cout << n << endl;

  n = 11;
}

/*
  Referencia
  esta funcion recibe como argumento una variable.
*/

void mostrarR(int &n)
{
  cout << n << endl;
  cout << "n: " <<  &n << endl;
  n = 22;
}


/*
  Direccion (puntero)
*/

void mostrarP(int *n){
  cout << n << endl;
  cout << "n: " <<  &n << endl;
}

int pedirNumeroPositivo(string mensaje, string error){
  int n;
  
  while(true){
    cout << mensaje;
    cin >> n;
    
    if(n > 0){
      break;
    }
    else{
      cout << " > " << error << "..." << endl;  
    }
  }
  
  return n;
}

int sumar(int n, int m){
  cout << "Suma de enteros: ";
  return n + m;
}

int sumar(int n, int m, int l){
  cout << "Suma de enteros de 3: ";
  return sumar(n, m) + l;
}


float sumar(float n, float m){
  cout << "Suma de decimales: ";
  return n + m;
}
