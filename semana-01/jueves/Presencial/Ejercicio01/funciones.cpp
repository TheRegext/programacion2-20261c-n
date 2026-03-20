#include <iostream>
#include <string>
using namespace std;
#include "funciones.h"

float pedirNumeroPositivo(string mensaje){
    float numero;
//    cin >> numero;
//
//    while (!(numero > 0)){
//        cin >> numero;
//    }
    do{
        cout << mensaje;
        cin >> numero;
    }while(numero <= 0);

    return numero;
}

float sumar(float num1, float num2){
    cout << "Sumando dos nros..." << endl;
    return num1 + num2;
}
float sumar(float num1, float num2, float num3){
    cout << "Sumando tres nros..." << endl;
    return num1 + num2 + num3;
}

void intercambiar(int &num1, int &num2){
    int aux;
    aux = num1;
    num1 = num2;
    num2 = aux;
}


