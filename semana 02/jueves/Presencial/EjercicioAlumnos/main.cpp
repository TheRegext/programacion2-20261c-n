/*
Un profesor desea cargar las notas de los alumnos de su curso y
quiere saber cuántos de
sus estudiantes obtuvieron una calificación mayor que el
promedio general.
El programa debe solicitar al usuario la tamanioidad de alumnos y
debe permitir cargar una
calificación por cada uno de ellos.
*/
#include <iostream>
using namespace std;

void cargarVector(float *vec, int tamanio){
    for(int i=0; i <tamanio; i++){
        cin >> vec[i];
    }
}

float promediarVector(float *vec, int tamanio){
    float suma = 0;
    for(int i=0; i<tamanio; i++){
        suma += vec[i];
    }
    return suma / tamanio;
}

int contarElementosMayoresAValorComparacion(float *vec, int tamanio, float valorComparacion){
    int cant = 0;
    for(int i=0; i<tamanio; i++){
        if (vec[i] > valorComparacion){
           cant++;
        }
    }
    return cant;
}


int main()
{
    float *notas = nullptr;
    int tamanioAlumnos;

    cout << "Ingresar cantidad de alumnos: ";
    cin >> tamanioAlumnos;


    if (tamanioAlumnos <= 0){
        cout << "Cantidad de alumnos incorrecta.";
        return 0;
    }

    notas = new float [tamanioAlumnos];

    if (notas == nullptr){
        cout << "No se puede continuar con la ejecución del programa";
        return 0;
    }

    cout << "Cargar las " << tamanioAlumnos << " notas: ";
    cargarVector(notas, tamanioAlumnos);
    float promedioNotas = promediarVector(notas, tamanioAlumnos);
    int cantMayoresPromedio = contarElementosMayoresAValorComparacion(notas, tamanioAlumnos, promedioNotas);
    int aprobados = contarElementosMayoresAValorComparacion(notas, tamanioAlumnos, 5);

    cout << "Cantidad de notas mayores al promedio: " << cantMayoresPromedio << endl;
    cout << "Cantidad de aprobados: " << aprobados << endl;


    delete []notas;

    return 0;
}
