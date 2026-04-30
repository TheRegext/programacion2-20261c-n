#pragma once
#include <string>
#include "fecha.h"

class Tarea{
    private:
        int _id, _estado;
        char _titulo[50];
        Fecha _creacion;
        Fecha _inicio;
        Fecha _fin;
        bool _eliminado;

    public:
        Tarea(int id, int estado, std::string titulo);
        Tarea();

        int getId() const;
        int getEstado() const;
        std::string getTitulo() const;
        std::string getNombreEstado() const;
        bool getEliminado() const;

        void setId(int id);
        void setEstado(int estado);
        void setTitulo(std::string titulo);
        void setEliminado(bool eliminado);

        void inicializarFecha(Fecha &f);

        void setInicio(Fecha f);
        void setFin(Fecha f);

        Fecha getInicio();
        Fecha getFin();
        Fecha getCreacion();

        std::string toString();

    public:

};
