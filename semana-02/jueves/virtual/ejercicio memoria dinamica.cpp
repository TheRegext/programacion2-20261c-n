#include <iostream>
#include <ctime>
using namespace std;
/***
Se desea cargar 1.000 números aleatorios enteros entre 1 y 100.000

determinar:
   Cuál es el número más alto generado.
   Cuántas veces se repitió ese número en el conjunto.
*/


int main() {
	
   const int CANTIDAD = 1000000;
   int *vec = new int[CANTIDAD];
   
   srand(time(0));
    
   for(int i=0; i<CANTIDAD; i++){
      vec[i] = rand() % 100000 + 1;
   }
   
   int imax = 0;
   for(int i=1; i<CANTIDAD; i++){
      if(vec[i]>vec[imax]){
         imax = i;
      }
   }
   
   cout << "El numero mas alto es: " << vec[imax] << endl;
   
   int cantidad = 0;
   for(int i=1; i<CANTIDAD; i++){
      if(vec[i] == vec[imax]){
         cantidad++;
      }
   }
   
   cout << "La cantida de veces que sale es: " << cantidad << endl;
   
   
   delete [] vec;
   
	return 0;
}

