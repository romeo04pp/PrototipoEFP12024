#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#include "Menus.h"

using namespace std;

class Usuarios
{

	public:
		void iniciarSesion();
		void menuUsuario(string nombreUsuario); //el parametro nombreUsuario es para la bitacora
		void ingresarUsuario();
		void imprimirUsuario();
        void modificarUsuario();
		void buscarUsuario();
		void borrarUsuario();

		private:
		string nombre, contrasena;
};

#endif // USUARIOS_H
