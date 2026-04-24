#include <iostream>
using namespace std;
#include "Tarea.h"
#include "TareaGestor.h"

void TareaGestor::Modificar(){

    int id;

    cout << "Id de Tarea: ";
    cin >> id;

    if (!Existe(id)){
        cout << "No existe la tarea buscada." << endl;
        return;
    }

    int pos = _repo.Buscar(id);
    Tarea tarea = _repo.Leer(pos);

    Mostrar(tarea);

    int estado;
    cout << "Ingresar estado (0 - Pendiente | 1 - En curso | 2 - Finalizada) : ";
    cin >> estado;

    if (estado < tarea.getEstado()){
        cout << "No se puede volver a un estado anterior" << endl;
        return;
    }

    if (!(estado >= 0 && estado <= 2)){
        cout << "El estado ingresado es incorrecto";
        return;
    }

    tarea.setEstado(estado);

    char confirmar;
    cout << "Confirmar (S/N): ";
    cin >> confirmar;

    if (tolower(confirmar) == 's'){
        _repo.Guardar(tarea, pos);
    }


}
void TareaGestor::Crear(){

    string titulo;
    int id;

    id = _repo.getCantidadRegistros()+1;
    cout << "Id: " << id << endl;

    cout << "Titulo: ";
    cin >> titulo;

    if (titulo.length() == 0 || titulo.length() > 49){
        cout << "Titulo no puede ser vacio o mayor a 49 caracteres." << endl;
        return;
    }

    Tarea tarea(id, 0, titulo);

    char confirmar;
    cout << "Confirmar (S/N): ";
    cin >> confirmar;

    if (tolower(confirmar) == 's'){
        _repo.Guardar(tarea);
    }

}

bool TareaGestor::Existe(int id){
    return _repo.Buscar(id) >= 0;
}

void TareaGestor::MostrarPorId(){
   int id;
    int estado;

    cout << "Id de Tarea: ";
    cin >> id;

    if (!Existe(id)){
        cout << "No existe la tarea buscada." << endl;
        return;
    }

    int pos = _repo.Buscar(id);
    Tarea tarea = _repo.Leer(pos);

    Mostrar(tarea);
}
void TareaGestor::ListarTodas(){
    int cant = _repo.getCantidadRegistros();
    int i;

    if (cant >= 0){
        cout << "LISTA DE TAREAS" << endl << "---------------------" << endl;
    }

    for(i = 0; i < cant; i++){
        Tarea reg = _repo.Leer(i);
        Mostrar(reg);
    }
}
void TareaGestor::Mostrar(Tarea tarea){
    cout << "ID: " << tarea.getId() << endl;
    cout << "TITULO: " << tarea.getTitulo() << endl;
    cout << "ESTADO: " << tarea.getNombreEstado() << endl;
    cout << "CREACION: " << tarea.getCreacion().toString() << endl;
    if (tarea.getEstado() >= 1){
        cout << "INICIO  : " << tarea.getInicio().toString() << endl;
    }
    if (tarea.getEstado() == 2){
        cout << "FIN     : " << tarea.getFin().toString() << endl;
    }
    cout << endl;
}
