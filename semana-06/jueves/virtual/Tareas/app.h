#include "menu.h"
#include "tareaMenu.h"
class App: public Menu {
public:
   App();
   void mostrarOpciones() override;
   void ejecutarOpcion(int opcion) override;
   
private:
   TareaMenu _menuTarea;
};


