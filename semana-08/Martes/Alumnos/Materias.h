#pragma once

class Materia{
private:
    int _codMateria;
    int _idCarrera;
    char _nombre[20];
    int _horas;
    int _legajoDocente;
    bool _cuatrimestral;
    bool _estado;

public:
    //CONSTRUCTOR
    Materia();
    Materia(int materia, int idCarrera, char* nombre, int horas, int idProf, bool cuatri, bool estado);

    //METDOS
    int getCodMateria();
    int getIdCarrera();
    char* getNombre();
    int getHoras();
    int getLegajoDocente();
    bool getEsCuatrimestral();
    bool getEstado();

    void setCodMateria(int codMat);
    void setIdCarrera(int idCarr);
    void setNombreMateria(char* nomMat);
    void setHoras(int horas);
    void setLegajoDocente(int idProf);
    void setEsCuatrimestral(bool esCuat);
    void setEstado(bool estado);

    void Mostrar();
    void Cargar();
};
