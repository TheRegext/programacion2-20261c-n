#ifndef TAREAMENU_H_INCLUDED
#define TAREAMENU_H_INCLUDED

#include "TareaGestor.h"

class TareaMenu {
    private:
        TareaGestor _gestor;
        void mostrarOpciones();

    public:
        void ejecutar();
};

#endif // TAREAMENU_H_INCLUDED
