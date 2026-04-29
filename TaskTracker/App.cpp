#include <iostream>
using namespace std;
#include "App.h"

void App::mostrarOpciones() {
    cout << endl;
    cout << "=== MENU PRINCIPAL ===" << endl;
    cout << "1 - TAREAS" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Opcion: ";
}

void App::ejecutar() {
    int opcion;
    do {
        mostrarOpciones();
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: _tareaMenu.ejecutar(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}
