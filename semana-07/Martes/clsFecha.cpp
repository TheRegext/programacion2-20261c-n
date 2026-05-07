///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;


class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0,int m=0, int a=0);
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();
    void cambiarDia(int d){
        if(d>=1 && d<=31) dia=d;
        else dia=0;
        }
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
   /// ~Fecha(){ cout<<"SE MURIO EL OBJETO :-("<<endl;}
   ///sobrecarga de operadores
   bool operator==(const Fecha &aux);
   bool operator==(const char* mes);
   void operator+=(int masDias);
   friend void SoyAmiga(Fecha &aux);

   friend istream &operator>>(istream &entrada, Fecha &aux);
   friend ostream &operator<<(ostream &salida, Fecha &aux);

};

void SoyAmiga(Fecha &aux){
        aux.dia=8;
        aux.mes=12;
        aux.anio=2026;
   }

///sobrecarga de operadores

istream &operator>>(istream &entrada, Fecha &aux){
    cout<<"DIA ";
    entrada>>aux.dia;
    cout<<"MES ";
    entrada>>aux.mes;
    cout<<"ANIO ";
    entrada>>aux.anio;
    return entrada;
}

ostream &operator<<(ostream &salida, Fecha &aux){
    cout<<"DIA ";
    salida<<aux.dia<<endl;
    cout<<"MES ";
    salida<<aux.mes<<endl;
    cout<<"ANIO ";
    salida<<aux.anio<<endl;
    return salida;
}
bool Fecha::operator==(const Fecha &aux){
    /*this->Mostrar();
    cout<<endl;
    aux.Mostrar();
    system("pause");*/
    if(dia!=aux.dia) return false;
    if(mes!=aux.mes) return false;
    if(anio!=aux.anio) return false;
    return true;
}

bool Fecha::operator==(const char *mesAComparar){
    char meses[3][10]={"ENERO","FEBRERO", "MARZO"};
    if(strcmp(mesAComparar, meses[mes-1])==0) return true;
    return false;
}

void Fecha::operator+=(int masDias){
    ///int diasMes[12]={31,28,}
    dia+=masDias;

}

///

void Fecha::Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
}




Fecha::Fecha(int d,int m, int a){
    dia=d;
    mes=m;
    anio=a;
}


int main(){
    Fecha hoy(1,1,1),ayer;

/*    if(hoy==ayer){
        cout<<"LAS FECHAS SON IGUALES"<<endl;
    }
    /*if(hoy.operator==(ayer)){
        cout<<"LAS FECHAS SON IGUALES"<<endl;
    }
    else{
        cout<<"LAS FECHAS SON DISTINTAS"<<endl;
    }*/
	/*if(hoy=="ENERO"){
        cout<<"EL MES DE LA FECHA ES ENERO"<<endl;
	}
	else{
        cout<<"EL MES DE LA FECHA NO ES ENERO"<<endl;
	}
	*/
	//hoy+=3;
	//SoyAmiga(hoy);
	cin>>hoy;
	cout<<hoy;
///	cout<<hoy<<endl;
	cout<<endl;
	system("pause");
	return 0;

}



///Sobrecargar el operador > de tal manera que sea verdadero si la fecha que llama es mayor que la que es recibida como parámetro
///Sobrecargar el operador < de tal manera que sea verdadero si la fecha que llama es mayor que la que es recibida como parámetro
///Sobrecargar el operador -= (ver funcionamiento del +=)
