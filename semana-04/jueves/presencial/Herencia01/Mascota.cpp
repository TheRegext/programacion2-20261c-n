#include<iostream>
using namespace std;
#include "Mascota.h"

Mascota::Mascota(string especie, float peso, string nombre, string nombreDuenio):Animal(especie, peso){
    setNombre(nombre);
    setNombreDuenio(nombreDuenio);
}
void Mascota::irAlVeterinario(){
    cout << _nombre << " fue llevada por " << _nombreDuenio << " y pesó " << getPeso() << endl;
}
string  Mascota::getNombre(){
    return _nombre;
}
string  Mascota::getNombreDuenio(){
    return _nombreDuenio;
}

void Mascota::setNombre(string nombre){
    _nombre = nombre;
}
void Mascota::setNombreDuenio(string nombreDuenio){
    _nombreDuenio = nombreDuenio;
}
