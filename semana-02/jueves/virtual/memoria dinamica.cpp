#include <iostream>
using namespace std;

int main() {
   int *pNum;
   int *pOtro;
   
   pNum = new int;
   
   if(pNum == nullptr){
      cout << "No pudo pedir memoria..." << endl;
      return 0;
   }
   
   pOtro = new int [10];
   
   if(pOtro == nullptr){
      cout << "No pudo pedir memoria..." << endl;
      delete pNum;   
      return 0;
   }
      
   pNum[0] = 10;
   cout << pNum[0];
   
   delete pNum;
   delete [] pOtro;
   
	return 0;
}

