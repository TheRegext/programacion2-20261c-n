#include <iostream>
using namespace std;
#include "Gato.h"

Gato::Gato(float peso, string nombre, string nombreDuenio, bool esDeInterior):Mascota("Felis catus", peso, nombre, nombreDuenio) {
    _esDeInterior = esDeInterior;
}

void Gato::maullar(){

    if(_esDeInterior){
        cout << "Miau amigable" << endl;
    }
    else{
        cout << "Hissssssss miaaaaauuu" << endl;
    }

}
