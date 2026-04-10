///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

struct Fecha{
    int dia, mes, anio;
};

struct Alumno{
    char nombre[30], apellido[30];
    int dni, legajo;
    Fecha fechaNacimiento;
};

///tipos de datos registro: contienen un conjunto de valores de igual  o distinto tipo
int main(){
    Fecha hoy;///dia, mes, año

    hoy.anio=2026;
    hoy.dia=15;
    hoy.mes=5;
    cout<<hoy.dia<<"/"<<hoy.mes<<"/"<<hoy.anio<<endl;
    //Alumno reg, vecAlu[5];///nombre, apellido, dni, legajo,fecha de nacimiento

	system("pause");
	return 0;

}
