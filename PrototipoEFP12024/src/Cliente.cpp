#include "Cliente.h"

Bitacora enviarDatosC;
Menus traerMenuCa;
void Clientes::menuClientes(string nombreUsuario)
{
    string userName = nombreUsuario;
    system("cls");
    int optEscoger;
    bool repetir = true;
    do
    {
            system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|    Pablo Romeo Palencia Rosales 9959-23-736   |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t-----------------------------------\n";
    cout << "\t\t\t|  Bienvenido al Menu de Clientes  |";
    cout << "\n\t\t\t-----------------------------------"<<endl;

    cout<<"\t\t\t 1. Registrar Clientes"<<endl;
	cout<<"\t\t\t 2. Imprimir Clientes"<<endl;
	cout<<"\t\t\t 3. Modificar Clientes"<<endl;
	//cout<<"\t\t\t 4. Buscar Clientes"<<endl;
	cout<<"\t\t\t 5. Borrar Clientes"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;
    cout << "\n\n\t\t\t---------------------------------------";
    cout << "\n\t\t\t|     Opciones a escoger: 1/2/3/4/5     ";
    cout << "\n\t\t\t---------------------------------------";

    cout << "\n\n\t\t\tIngrese la opcion que desea escoger: ";
    cin >> optEscoger;

    switch(optEscoger)
    {
    case 1:{
    registroCliente();
    enviarDatosC.ingresoDatosBitacora(userName,"2001","CCL"); //Create Cliente
    system("cls");

                break;
    }

    case 2:{
        system("cls");
        imprimirCliente();
        enviarDatosC.ingresoDatosBitacora(userName,"2002","RCL"); //REad Cliente
    break;
    }
    case 3:{
        system("cls");
        modificarCliente();
        enviarDatosC.ingresoDatosBitacora(userName,"2003","UCL"); //Update Cliente
        break;
        }
    case 4:
        system("cls");
       borrarCliente();
       enviarDatosC.ingresoDatosBitacora(userName,"2004","DCL"); //Delete Cliente
        break;
    case 5:
        system("cls");
       traerMenuCa.menuCatalogos(userName);
        break;
    default:
        cout << "Opcion invalida... Intente otra vez...";

    }
    }while(optEscoger!=5);
}
void Clientes::registroCliente()
{
	system("cls");
	fstream file;
	cout<<"\n----------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------- Ingresar Cliente --------------------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el ID del cliente: ";
	cin>>idCliente;
	cout<<"\n\t\t\tIngresa el Nombre del cliente: ";
	cin>>nombreCliente;
	cout<<"\t\t\tIngresa el NIT del cliente: ";
	cin>>nitCliente;

	cout<<"\n\t\t\tIngresa el Telefono del cliente: ";
	cin>>telefonoCliente;
	cout<<"\n\t\t\tIngresa el Apellido del cliente: ";
	cin>>apellidoCliente;
	cout<<"\t\t\tIngresa el Direccion del cliente: ";
	cin>>direccionCliente;

	cout<<"\n\t\t\tIngresa el Correo del cliente: ";
	cin>>correoCliente;
	cout<<"\n\t\t\tIngresa el Estatus del cliente: ";
	cin>>estatusCliente;

	file.open("Cliente.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente <<std::left<<std::setw(15)<< telefonoCliente <<std::left<<std::setw(15)<< apellidoCliente <<std::left<<std::setw(15)<< direccionCliente << std::left<<std::setw(15)<< correoCliente <<std::left<<std::setw(15)<< estatusCliente <<"\n";
		//file<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente << "\n";
	file.close();
}

void Clientes::modificarCliente()
{
    fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificar Clientes-------------------------"<<endl;
	file.open("Cliente.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Cliente que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> idCliente >> nombreCliente >> nitCliente;
		while(!file.eof())
		{
			if(participant_id!=idCliente)
			{

	file1<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente <<std::left<<std::setw(15)<< telefonoCliente <<std::left<<std::setw(15)<< apellidoCliente <<std::left<<std::setw(15)<< direccionCliente <<std::left<< std::setw(15)<< correoCliente <<std::left<<std::setw(15)<< estatusCliente <<"\n";

			}
			else
			{
				cout<<"\t\t\tIngresa Id del Cliente            : ";
                cin>>idCliente;
                cout<<"\t\t\tIngresa Nombre del Cliente        : ";
                cin>>nombreCliente;
                cout<<"\t\t\tIngresa eñ Nit del Cliente      : ";
                cin>>nitCliente;
                cout<<"\n\t\t\tIngresa el Telefono del cliente: ";
	cin>>telefonoCliente;
	cout<<"\n\t\t\tIngresa el Apellido del cliente: ";
	cin>>apellidoCliente;
	cout<<"\t\t\tIngresa el Direccion del cliente: ";
	cin>>direccionCliente;

	cout<<"\n\t\t\tIngresa el Correo del cliente: ";
	cin>>correoCliente;
	cout<<"\n\t\t\tIngresa el Estatus del cliente: ";
	cin>>estatusCliente;

    	//file1<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente std::setw(15)<< telefonoCliente <<std::left<<std::setw(15)<< apellidoCliente <<std::left<<std::setw(15)<< direccionCliente << std::setw(15)<< correoCliente <<std::left<<std::setw(15)<< estatusCliente "\n";
	file1<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente <<std::left<<std::setw(15)<< telefonoCliente <<std::left<<std::setw(15)<< apellidoCliente <<std::left<<std::setw(15)<< direccionCliente <<std::left<< std::setw(15)<< correoCliente <<std::left<<std::setw(15)<< estatusCliente <<"\n";

				found++;
			}
			file >> idCliente >> nombreCliente >> nitCliente;

		}
		file1.close();
		file.close();
		remove("Cliente.txt");
		rename("Record.txt","Cliente.txt");
	}
}

void Clientes::imprimirCliente()
{
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Clientes -------------------------"<<endl;
	file.open("Cliente.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> idCliente >> nombreCliente >> nitCliente >> telefonoCliente >> apellidoCliente >> correoCliente >> estatusCliente;

		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id: "<<idCliente<<endl;
			cout<<"\t\t\t Nombre: "<<nombreCliente<<endl;
			cout<<"\t\t\t Nit: "<<nitCliente<<endl;
			cout<<"\n\n\t\t\t Apellido: "<<apellidoCliente<<endl;
			cout<<"\t\t\t Telefono: "<<telefonoCliente<<endl;
			cout<<"\t\t\t Direccion: "<<direccionCliente<<endl;
			cout<<"\n\n\t\t\t Correo: "<<correoCliente<<endl;
			cout<<"\t\t\t Estatus: "<<estatusCliente<<endl;

            file >> idCliente >> nombreCliente >> nitCliente >> telefonoCliente >> apellidoCliente >> correoCliente >> estatusCliente;

		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	system("pause");
	file.close();
}

void Clientes::borrarCliente()
{

	system("cls");
	fstream file,file1;
	string id;
	int found=0;
	cout<<"\n------------------------- Borrar Cliente -------------------------"<<endl;
	file.open("Cliente.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
	    cout<<"\n Ingrese el Id para borrar: ";
		cin>>id;
		file1.open("Record.txt",ios::app | ios::out);

    file >> idCliente >> nombreCliente >> nitCliente >> telefonoCliente >> apellidoCliente >> correoCliente >> estatusCliente;
		while(!file.eof())
		{
			if(id!= idCliente)
			{
        	//file1<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente std::setw(15)<< telefonoCliente <<std::left<<std::setw(15)<< apellidoCliente <<std::left<<std::setw(15)<< direccionCliente << std::setw(15)<< correoCliente <<std::left<<std::setw(15)<< estatusCliente "\n";
				file1<<std::left<<std::setw(15)<< idCliente <<std::left<<std::setw(15)<< nombreCliente <<std::left<<std::setw(15)<< nitCliente <<std::left<<std::setw(15)<< telefonoCliente <<std::left<<std::setw(15)<< apellidoCliente <<std::left<<std::setw(15)<< direccionCliente <<std::left<< std::setw(15)<< correoCliente <<std::left<<std::setw(15)<< estatusCliente <<"\n";

			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de Usuario exitoso";
			}

            file >> idCliente >> nombreCliente >> nitCliente >> telefonoCliente >> apellidoCliente >> correoCliente >> estatusCliente;

		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("Cliente.txt");
		rename("Record.txt","Cliente.txt");
		exit(0);
	}
}
