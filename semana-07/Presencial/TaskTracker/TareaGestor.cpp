#include <iostream>
using namespace std;
#include "Tarea.h"
#include "TareaGestor.h"

void TareaGestor::Truncar(){
    char confirmar;
    cout << "Esta accion no se puede deshacer. Confirmar (S/N): ";
    cin >> confirmar;

    if (tolower(confirmar) == 's'){
        if (_repo.Truncar()){
            cout << "Archivo truncado correctamente" << endl;
        }
        else{
            cout << "No tiene permisos para truncar el archivo" << endl;
        }
    }
}

void TareaGestor::Eliminar(){
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

    char confirmar;
    cout << "Confirmar (S/N): ";
    cin >> confirmar;

    if (tolower(confirmar) == 's'){
        tarea.setEliminado(true);
        _repo.Guardar(tarea, pos);
    }
}

void TareaGestor::Ordenar(Tarea *vec, int cantidad){
    int i, j, pos;
    Tarea aux;

    for(i = 0; i < cantidad - 1; i++){
        pos = i;
        for(j = i + 1; j < cantidad; j++){
            if (vec[j].getTitulo() < vec[pos].getTitulo()){
                pos = j;
            }
        }
        aux = vec[i];
        vec[i] = vec[pos];
        vec[pos] = aux;
    }

}

void TareaGestor::ListarOrdenado()
{
    // Saber cantidad de registros
    int cant = _repo.getCantidadRegistros();
    if (cant == 0){
        return;
    }

    // Pedir memoria para cantidad registros en un vector
    Tarea *vec = nullptr;
    vec = new Tarea[cant];

    if (vec == nullptr){
        return;
    }

    // Leer el archivo completo a memoria
    _repo.Leer(cant, vec);

    // Ordenar vector
    Ordenar(vec, cant);

    // Mostrar vector
    for(int i=0; i<cant; i++){
        Mostrar(vec[i]);
    }

    delete []vec;
}

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
    cin.ignore();
    getline(cin, titulo);

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

        if (!reg.getEliminado()){
            Mostrar(reg);
        }
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
    cout << "ELIMINADO: " << (tarea.getEliminado()?"SI":"NO") << endl;
    cout << endl;

}
