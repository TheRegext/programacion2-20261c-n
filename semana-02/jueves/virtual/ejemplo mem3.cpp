#include <iostream>
using namespace std;

int menu(){
   int opcion;
   cout << " -------- MENU PRINCIPAL --------" << endl;
   cout << "1- Crear asistentes " << endl;
   cout << "2- Marcar asistencia" << endl;
   cout << "3- Mostrar estado de asistencia " << endl;
   cout << "0- Salir " << endl;
   cout << "---------------------------------"<<endl;
   cout << "Opcion: ";
   cin >> opcion;
   
   return opcion;
}

bool* crearAsistencia(int &cantAsistentes){
   bool *pAsistentes;
   
   cout << "Ingrese cantidad de asistentes: ";
   cin >> cantAsistentes;
   
   pAsistentes = new bool[cantAsistentes]{};
   
   if(pAsistentes == nullptr){
      cout << "No pudo pedir memoria..." << endl;
      exit(-1);
   }
   
   return pAsistentes;
}
   
void marcarAsistencia(bool *pAsistentes, int cantAsistentes){
   int numAsistente;
   cout << "Ingrese el numero de asistente: ";
   cin >> numAsistente;
   
   if(numAsistente > 0 && numAsistente <= cantAsistentes){
      pAsistentes[numAsistente-1] = true;
      cout << "El asiste #" << numAsistente << " esta entre nosotros..." <<endl;
   }
   else{
      cout << "Ese asistente no existe... es un fantasma?" << endl;
   }
}
   
void mostrarEstado(bool *pAsistentes, int cantAsistentes){
   
   for(int i=0; i<cantAsistentes; i++){
      if(pAsistentes[i]){
         cout << "Asistente "<<i+1<<": Asistio"<<endl;
      }
      else{
         cout << "Asistente "<<i+1<<": No Asistio"<<endl;
      }
   }
}
   
int main() {
   int opcion, cantAsistentes;
   bool *pAsistentes = nullptr;
   
   do{
      
      opcion = menu();
   
      switch(opcion){
         case 1:
            if(pAsistentes != nullptr){
               delete [] pAsistentes;
            }
            
            pAsistentes = crearAsistencia(cantAsistentes);
            break;
            
         case 2:
            if(pAsistentes != nullptr){
               marcarAsistencia(pAsistentes, cantAsistentes);   
            }
            else{
               cout << "Se debe crear las asistencias antes.." << endl;
            }
            
            break;
            
         case 3:
            if(pAsistentes != nullptr){
               mostrarEstado(pAsistentes, cantAsistentes);
            }
            else{
               cout << "Se debe crear las asistencias antes.." << endl;
            }
            break;
         
         case 0:
            if(pAsistentes != nullptr){
               delete [] pAsistentes;   
            }
            
            cout << "Gracia por usar mi APP... :)" << endl;
            break;
      }
      cout << endl;
      cout << endl;
   }while(opcion != 0);
   
   
	
	return 0;
}

