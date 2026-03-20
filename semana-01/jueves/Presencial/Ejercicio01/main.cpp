#include <iostream>
using namespace std;
#include "funciones.h"

int main()
{
    /// Ejemplo de parámetros por omisión
    float nota1 = pedirNumeroPositivo("Ingresar nota 1: ");
    float nota2 = pedirNumeroPositivo("Ingresar nota 2: ");
    float nota3 = pedirNumeroPositivo("Ingresar nota 3: ");
    cout << nota1 << " " << nota2 << " " << nota3 << endl;

    /// Ejemplo de sobrecarga de funciones
    // float suma = sumar(sumar(nota1, nota2), nota3);
    float suma = sumar(nota1, nota2, nota3);

    cout << "suma: " << suma << endl;

    /// Ejemplo de paràmetros por referencia

    int num1 = 10, num2 = 100;

    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;
    intercambiar(num1, num2);
    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;


    return 0;
}
