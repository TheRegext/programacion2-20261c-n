#include <iostream>
using namespace std;

/**
Un profesor desea cargar las notas de los alumnos de su curso y quiere saber 
cuántos de sus estudiantes obtuvieron una calificación mayor que el promedio 
general.

El programa debe solicitar al usuario la cantidad de alumnos y 
debe permitir cargar una calificación por cada uno de ellos.


*/

int sumarVector(int vec[], int tam){
   int suma = 0; 
   for(int i=0; i<tam; i++){
      suma += vec[i];
   }
   return suma;   
}

int main() {
	int *pNotas, cantAlumnos, cantMayores;
   float promedio;
   
   cout << "Ingrese cantidad de alumnos: ";
   cin >> cantAlumnos;
   
   pNotas = new int[cantAlumnos]{};
   
   if(pNotas == nullptr){
      cout << "No se pudo pedir memoria..." << endl;
      exit(-2);
   }
   
   for(int i=0; i<cantAlumnos; i++){
      cout << "Ingrese la nota del alumno #" << i + 1 << ": ";
      cin >> pNotas[i];
   }
   
   promedio = (float)sumarVector(pNotas, cantAlumnos) / cantAlumnos;
   
   cantMayores = 0;
   for(int i=0; i<cantAlumnos; i++){
      if(pNotas[i] > promedio){
         cantMayores++;
      }
   }
   
   cout << "La cantidad mayores al promedio es: " << cantMayores << endl;
   
   delete [] pNotas;
   
	return 0;
}

