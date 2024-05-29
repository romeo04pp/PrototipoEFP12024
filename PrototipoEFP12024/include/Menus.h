#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Bitacora.h"
#include "Usuario.h"
#include "Clientes.h"

using namespace std;

class Menus
{
    public:
        void menuInicial(string nombreUsuario);
        void menuCatalogos(string nombreUsuario);
        void subMenuSeguridad(string nombreUsuario);
        void subMenuInformes(string nombreUsuario);

    protected:

    private:
};

#endif // MENUS_H
