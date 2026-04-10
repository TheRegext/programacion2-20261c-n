#include<iostream>
#include "gato.h"

using namespace std;



int main () {
   Gato a(true, "Michi", 5);
      
   cout << "--------------------" << endl;
   
   // a.setTipo("Perro");
   
   a.comer();
   
   a.pasear();
   
   a.maullar();
 
	
	return 0;
}

