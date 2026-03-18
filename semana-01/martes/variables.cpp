///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

#include "prueba.h"

int a,b,c2=8;///VARIABLES GLOBALES: no se recomienda usarlas

///void cargarVector(int vec[5], int x)
///void cargarVector(int vec[], int x)
void cargarVector(int *vec, int x){
    int i;
    for(i=0;i<x;i++){
        cin>>vec[i];
    }

}

void mostrarVector(int *vec, int x){
    int i;
    for(i=0;i<x;i++){
        cout<<*(vec+i)<<endl;
    }

}

///PUNTERO: es un tipo de variable que almacena direcciones de memoria
///El nombre de un vector es un puntero constante que contiene la dirección
/// de la posición 0 del vector

///Cuando una variable ya declarada tiene delante el &->operador de dirección
///Cuando una variable PUNTERO ya declarada tiene un *->operador de indirección

///Aritmética de punteros: al sumar o restar un valor entero a una dirección,
///es dirección se incrementa (o decrementa), una cantidad de bytes equivalente
///al tamaño del tipo de datos multiplicado por el valor del número entero
int main(){
    const int a=5;
    int vec[a], *puntInt, var=10;
    puntInt=vec;
    cout<<&vec[1]-&vec[0]<<endl;
    system("pause");
  /*  cout<<" vec "<<vec<<endl;
    cout<<" puntInt "<<puntInt<<endl;
	cout<<"DIRECCION DE var "<<&var<<endl;
	puntInt=&var;
	cout<<"CONTENIDO DE var "<<*puntInt<<endl;
*/
	cargarVector(vec, a);

    cout<<endl;
    mostrarVector(vec, a);

	system("pause");

	return 0;

}
