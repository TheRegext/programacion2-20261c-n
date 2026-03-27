#include <iostream>
using namespace std;

int main()
{
    int tamanio;

    cout << "Tamaño del vector:";
    cin >> tamanio;

    int *vec;
    vec = new int [tamanio];

    if (vec == nullptr){
        cout << "No se pudo pedir memoria dinamica. ";
        return 1;
    }

    delete [] vec;
    return 0;
}
