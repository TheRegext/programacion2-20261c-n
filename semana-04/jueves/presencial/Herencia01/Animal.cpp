#include <iostream>
using namespace std;
#include "Animal.h"


Animal::Animal(std::string especie, float peso){
    setEspecie(especie);
    setPeso(peso);
}
void Animal::comer(){
    cout << "Come para vivir" << endl;
}
void Animal::mostrarInfoBiologica(){
    cout << "Especie: " << _especie << " Peso: " << _peso << endl;
}
void Animal::setEspecie(std::string especie){
    _especie = especie;
}
void Animal::setPeso(float peso){
    if (peso < 0){
        _peso = 0;
    }
    else{
        _peso = peso;
    }
}
float Animal::getPeso(){
    return _peso;
}
