# include<iostream>
# include<cstring>
#include "Fecha.h"
using namespace std;

///clase Fecha

Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}

Fecha::Fecha(int d=1, int m=2, int a=3){
    dia=d;
    mes=m;
    anio=a;
}

void Fecha::setDia(int _dia){
    if(_dia>=1 && _dia<=31)dia=_dia;
}
int Fecha::getDia(){return dia;}
int Fecha::getMes(){ return mes;}
int Fecha::getAnio(){return anio;}

void Fecha::Cargar(){
    cout<<"DIA ";
    cin>>dia;
    cout<<"MES ";
    cin>>mes;
    cout<<"ANIO ";
    cin>>anio;
}

void Fecha::Mostrar(){
    cout<<"DIA "<<dia<<endl;
    cout<<"MES "<<mes<<endl;
    cout<<"ANIO "<<anio<<endl;
}

void Fecha::MostrarConBarra(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
///Fin clase Fecha
