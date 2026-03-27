#include <iostream>
using namespace std;
#include "funciones.h"

int main()
{
    int matriz[5][6] = {
      { 1, 2, 3, 4, 5, 6 },
      { 10, 20, 30, 40, 50, 60 },
      { 11, 22, 33, 44, 55, 66 },
      { 1, 1, 1, 1, 1, 1},
      { -1, -2, -3, -4, -5, -6 },
    };

    mostrarMatriz(matriz);
    cout << endl;
    mostrarSumaFilasMatriz_v1(matriz);
    cout << endl;
    mostrarSumaFilasMatriz_v2(matriz);


    return 0;
}
