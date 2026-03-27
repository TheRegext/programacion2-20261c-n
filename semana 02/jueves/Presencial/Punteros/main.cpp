#include <iostream>
using namespace std;

int main()
{
    int valor = 100;
    int &miReferencia = valor;
    int *miPuntero;

    int vec[5] = {1, 2, 3, 4, 5};

    miPuntero = &valor; // & - ampersand: operador de dirección

    cout << "miPuntero: " << miPuntero << endl;
    cout << "&valor   : " << &valor << endl;
    cout << "&miReferencia: " << &miReferencia << endl;

   *miPuntero = 200;  // * : operacion indirección

   cout << "valor: " << valor << endl;
   cout << "*miPuntero: " << *miPuntero << endl;
   cout << "&miPuntero: " << &miPuntero << endl;

   miPuntero = vec;

   cout << "*miPuntero: " << *miPuntero << endl;
   cout << "miPuntero[3]: " << miPuntero[3] << endl;

    return 0;
}
