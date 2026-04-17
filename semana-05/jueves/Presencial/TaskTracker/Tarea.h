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

    public:
        Tarea(int id, int estado, std::string titulo);
        Tarea();

        int getId() const;
        int getEstado() const;
        std::string getTitulo() const;
        std::string getNombreEstado() const;

        void setId(int id);
        void setEstado(int estado);
        void setTitulo(std::string titulo);
        void inicializarFecha(Fecha &f);

        std::string toString();

    public:

};
