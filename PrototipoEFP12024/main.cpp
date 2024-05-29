#include <iostream>
#include <cstdlib>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Usuarios.h"

using namespace std;

int main()
{
    Usuarios IngresoUsuario;
    int numero;
    do
    {
    system("cls");
    cout<<"\t\t\tHecho por: Pablo Romeo Palencia Rosales 9959-23-736"<<endl;

    cout<<"\t\t\t--------------------------------------"<<endl;
	cout<<"\t\t\t|        SISTEMA DE GESTION          |"<<endl;
	cout<<"\t\t\t--------------------------------------"<<endl;
	cout<<"\n\t\t\t 1. Iniciar Sesion con Usuario existente"<<endl;
	cout<<"\t\t\t 2. Salir del Sistema"<<endl;
    cout << "\n\t\t\t ------------------------------";
    cout << "\n\t\t\t|    Opciones a escoger: 1/2   |";
    cout << "\n\t\t\t ------------------------------";
	cout<< " "<<endl;

	cout<<"\n\n\t\t\tIngrese una opcion: ";
	cin>>numero;

        switch(numero)
        {
            case 1:
                IngresoUsuario.iniciarSesion();
                break;
            case 2:
                exit(0);
                break;

            default:
                cout<<"\t\t\tPor favor ingrese una opcion valida..."<<endl;
                cin.get();
        }
    } while(numero!= 2);
    return 0;
}
