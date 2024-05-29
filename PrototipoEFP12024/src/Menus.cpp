#include "Menus.h"
#include "Usuarios.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <ctime>

Clientes traerMenuC;
Usuario traerMenu;
Bitacora imprimirBitacora;

void Menus::menuInicial(string nombreUsuario)
{
    string userName = nombreUsuario; //para la bitacora
    int op = 0; //para opciones
    bool repetir = true;
    do
    {
    system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|    Pablo Romeo Palencia Rosales 9959-23-736   |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------------------\n";
    cout << "\t\t\t|        Bienvenido al Menu General             |";
    cout << "\n\t\t\t-----------------------------------------------"<<endl;

    cout << "\n\t\t\t1. Menu Catalogos"<<endl;
    cout << "\t\t\t2. Menu Informes"<< endl;
    cout << "\t\t\t3. Menu Seguridad"<<endl;
    cout << "\t\t\t4. Salir del Sistema" << endl;
    cout << "\n\n\t\t\t---------------------------------";
    cout << "\n\t\t\t|   Opciones a escoger: 1/2/3/4  |";
    cout << "\n\t\t\t---------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> op;

    switch(op)
    {
    case 1:{
       system("cls");
       menuCatalogos(userName);
        break;
    }

    case 2:{
        system("cls");
        subMenuInformes(userName);
    break;
    }
    case 3:{
        system("cls");
        subMenuSeguridad(userName);
        break;
        }
    case 4:{
             exit(0);
        break;
    }
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(op!=4);
}

void Menus::menuCatalogos(string nombreUsuario)
{
    string userName = nombreUsuario; //bitacora
    system("cls");
    int op;
    bool repetir = true;
    do
    {
            system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|    Pablo Romeo Palencia Rosales 9959-23-736   |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t| Bienvenido al Menu de Catalogos |";
    cout << "\n\t\t\t---------------------------------"<<endl;

    cout << "\n\t\t\t1. Clientes"<<endl;
    cout << "\t\t\t2.  Usuarios (inicio sesion)"<<endl;
    cout << "\t\t\t3. Regresar" << endl;
    cout << "\n\n\t\t\t-------------------------------";
    cout << "\n\t\t\t|    Opciones a escoger: 1/2/3   |";
    cout << "\n\t\t\t---------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> op;

    switch(op)
    {
    case 1:{
    traerMenuC.menuClientes(userName);
       system("cls");

                break;
    }

    case 2:{
        system("cls");
        traerMenu.menuUsuarios(userName);
    break;
    }
    case 3:{
        system("cls");
    menuInicial(userName);
        break;
        }
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(op!=3);
}

void Menus::subMenuInformes(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int op;
    bool repetir = true;
    do
    {
    system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|    Pablo Romeo Palencia Rosales 9959-23-736   |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t|   Bienvenido al Menu de Informes   |";
    cout << "\n\t\t\t-----------------------------------"<<endl;

    cout << "\n\t\t\t1. Clientes"<<endl;
    cout << "\t\t\t2. Regresar" << endl;
    cout << "\n\n\t\t\t--------------------------------";
    cout << "\n\t\t\t|    Opciones a escoger: 1/2   |";
    cout << "\n\t\t\t----------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> op;

    switch(op)
    {
    case 1:{
       system("cls");
       //imprimirBitacora.imprimirDatosBitacora();
    break;
    }
    case 2:
        menuInicial(userName);
        break;

    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(op!=2);
}
void Menus::subMenuSeguridad(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int op;
    bool repetir = true;
    do
    {
    system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|    Pablo Romeo Palencia Rosales 9959-23-736   |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t|   Bienvenido al Menu de Seguridad  |";
    cout << "\n\t\t\t-----------------------------------"<<endl;

    cout << "\n\t\t\t1. Bitacora"<<endl;
    cout << "\t\t\t2. Regresar" << endl;
    cout << "\n\n\t\t\t--------------------------------";
    cout << "\n\t\t\t|    Opciones a escoger: 1/2   |";
    cout << "\n\t\t\t----------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> op;

    switch(op)
    {
    case 1:{
       system("cls");
       imprimirBitacora.imprimirDatosBitacora();
    break;
    }
    case 2:
        menuInicial(userName);
        break;

    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(op!=2);
}
