#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "TareaMenu.h"

class App {
    private:
        TareaMenu _tareaMenu;
        void mostrarOpciones();

    public:
        void ejecutar();
};

#endif // APP_H_INCLUDED
