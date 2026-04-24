#include <iostream>
#include "app.h"
using namespace std;

App::App(){
   setCantidadOpciones(1);
}

void App::mostrarOpciones(){
   cout << "----- MENU APP ---------"<<endl;
   cout << "1- TAREAS"<<endl;
   cout << "0- SALIR"<<endl;
   cout << "------------------------"<<endl;
}

void App::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
      _menuTarea.run();
      break;
   case 0:
      cout << "Gracias por usar mi app :)" << endl;
   }
}
