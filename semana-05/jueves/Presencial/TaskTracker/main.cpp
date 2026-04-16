#include <iostream>
using namespace std;
#include "Tarea.h"
#include "TareaArchivo.h"


int main()
{
    TareaArchivo archivo("tareas.dat");
    int cant = archivo.getCantidadRegistros();

    for(int i = 0; i< cant; i++){
        Tarea t = archivo.Leer(i);
        cout << t.toString() << endl;
    }


    return 0;
}
