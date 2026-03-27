#include <iostream>
using namespace std;
/***
   PUNTEROS
   variables que almacenan una direccion de memoria
*/

int main() {
	int a;
   int *pB;
   
   pB = &a; /// el & obtiene la direccion de una variable
   
   a = 15;
   
   *pB = 22; /// el * se usa para acceder a la variable 
             /// donde se esta apuntando
   
   cout << a << endl;
   
   cout << pB << endl;
   
   
	return 0;
}

