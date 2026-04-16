#include<iostream>
#include "fecha.h"
using namespace std;

int main (int argc, char *argv[]) {
	Fecha f;
   
   f.setCurrentDate();
   
   cout << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()<<endl;
   
	return 0;
}

