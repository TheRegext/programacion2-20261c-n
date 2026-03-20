#pragma once
#include <string>

void mostrar(int n);
void mostrarR(int &n);
void mostrarP(int *n);
int pedirNumeroPositivo(std::string mensaje = "Ingrese un numero: ",
                         std::string error = "El numero debe ser positivo");
int sumar(int n, int m);
int sumar(int n, int m, int l);
float sumar(float n, float m);
