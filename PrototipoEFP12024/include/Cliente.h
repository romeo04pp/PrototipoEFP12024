#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Bitacora.h"
#include "Menus.h"
using namespace std;


class Clientes
{
    public:
        void menuClientes(string nombreUsuario);
        void registroCliente();
        void modificarCliente();
        void imprimirCliente();
        void borrarCliente();

    protected:

    private:
        string idCliente, nombreCliente, nitCliente, telefonoCliente, apellidoCliente, direccionCliente, correoCliente, estatusCliente;
};

#endif // CLIENTES_H
