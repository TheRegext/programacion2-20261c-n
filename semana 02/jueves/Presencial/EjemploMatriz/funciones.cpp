#include <iostream>
using namespace std;
#include "funciones.h"

void mostrarMatriz(int matriz[5][6]){

    for (int i = 0; i < 5; i++){

        for (int j = 0; j < 6; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void mostrarSumaFilasMatriz_v1(int matriz[5][6])
{
    int resultados[5] = {};
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            resultados[i] += matriz[i][j];
        }
        cout << "fila " << i + 1 << " Suma = " << resultados[i] << endl;
    }
    return;
}

void mostrarSumaFilasMatriz_v2(int matriz[5][6])
{
    int resultado;
    for(int i = 0; i < 5; i++)
    {
        resultado=0;
        for(int j = 0; j < 6; j++)
        {
            resultado += matriz[i][j];
        }
        cout << "fila " << i + 1 << " Suma = " << resultado << endl;
    }
    return;
}
