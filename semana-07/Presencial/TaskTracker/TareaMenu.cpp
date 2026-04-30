#include <iostream>
using namespace std;
#include "TareaMenu.h"

void TareaMenu::mostrarOpciones() {
    cout << endl;
    cout << "=== TASK TRACKER ===" << endl;
    cout << "1 - NUEVA TAREA" << endl;
    cout << "2 - EDITAR TAREA" << endl;
    cout << "3 - MOSTRAR TAREA POR ID" << endl;
    cout << "4 - MOSTRAR TODAS LAS TAREAS" << endl;
    cout << "5 - LISTADO ORDENADO" << endl;
    cout << "6 - ELIMINAR TAREA" << endl;
    cout << "7 - TRUNCAR ARCHIVO DE TAREAS" << endl;


    cout << "0 - SALIR" << endl;
    cout << "Opcion: ";
}

void TareaMenu::ejecutar() {
    int opcion;
    do {
        mostrarOpciones();
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1: _gestor.Crear();        break;
            case 2: _gestor.Modificar();    break;
            case 3: _gestor.MostrarPorId(); break;
            case 4: _gestor.ListarTodas();  break;
            case 5: _gestor.ListarOrdenado();  break;
            case 6: _gestor.Eliminar();  break;
            case 7: _gestor.Truncar(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}
