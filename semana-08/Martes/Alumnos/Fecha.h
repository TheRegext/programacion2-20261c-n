#pragma once

///clase Fecha
class Fecha{
private:///variables de la clase
    int dia, mes, anio;
public:
    Fecha();
    Fecha(int d, int m, int a);
    void setDia(int _dia);
    int getDia();
    int getMes();
    int getAnio();

    void Cargar();
    void Mostrar();///prototipo del m�todo
    void MostrarConBarra();
};

///Fin clase Fecha

