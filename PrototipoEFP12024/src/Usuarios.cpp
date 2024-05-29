#include "Usuarios.h"
using namespace std;

string pruebaU="admin", pruebaC="1234"; //prueba para iniciar sesion
string nombreUsuario, contra;
Menus llamarMenu; //Para clase menu llama menu general
Bitacora enviarDatosU; //para clase bitacora envia datos

void Usuarios::iniciarSesion()
{
    system("cls");
	fstream file, file1;
	int found=0;
	file.open("Usuarios.txt",ios::in);
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\t|      LOGIN USUARIOS     | "<<endl;
    cout<<"\t\t--------------------------\n"<<endl;
    cout<<"\t\tNombre Usuario: ";
    cin>>nombreUsuario;
    cout << "\t\tContrasena: ";
    char caracter;
        caracter= getch();
        contra="";
        while (caracter !=13)
        {
            if(caracter !=8)
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b";
                    contra = contra.substr(0, contra.length()-1);
                }
            }
            caracter = getch();
        }
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(nombreUsuario == nombre && contra == contrasena)
        {
            enviarDatosU.ingresoDatosBitacora(nombreUsuario,"1000","LGI");
            llamarMenu.menuInicial(nombreUsuario);
            return;
            found++;

        }
        else{
        if (nombreUsuario ==pruebaU && contra ==pruebaC) //deja iniciar sesion con el usuario predeterminado
            {
                enviarDatosU.ingresoDatosBitacora(nombreUsuario,"1000","LGI");
                llamarMenu.menuInicial(nombreUsuario);
                return;
                found++;
            }
        }
        file >> nombre >> contrasena;

    }
    if(found==0)
    {
        cout<<"\n\t\t\t El usuario o contraseña son incorrectos..." << endl;
        system("pause");
    }
    file.close();
}
void Usuarios::menuUsuario(string nombreUsuario)
{
    string userName = nombreUsuario;
    char x;
    int opcion;
	do
    {
	system("cls");
	cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t|    Pablo Romeo Palencia Rosales 9959-23-736   |" <<endl;
    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\n\t\t\t------------------------------------\n";
	cout << "\t\t\t|        CATALOGO USUARIOS         |"<<endl;
	cout << "\t\t\t------------------------------------"<<endl;
    cout<<"\t\t\t 1. Ingresar Usuario"<<endl;
	cout<<"\t\t\t 2. Imprimir Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificar Usuarios"<<endl;
	cout<<"\t\t\t 4. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 5. Regresar"<<endl;
	cout<<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t| Opcion a escoger:[1/2/3/4/5] |"<<endl;
	cout<<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\tIngrese opcion: ";
    cin>>opcion;
        switch(opcion)
        {
        case 1:
            ingresarUsuario();
            enviarDatosU.ingresoDatosBitacora(userName,"1001","CUS");
            break;
        case 2:
            imprimirUsuario();
            enviarDatosU.ingresoDatosBitacora(userName,"1002","RUS");
            break;
        case 3:
            modificarUsuario();
            enviarDatosU.ingresoDatosBitacora(userName,"1003","UUS");

            break;
        case 4:
            borrarUsuario(userName);
            enviarDatosU.ingresoDatosBitacora(userName,"1004","DUS");

            break;
        case 5:
            llamarMenu.subMenuInformes(userName);
            break;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            system ("pause");
            break;
        }
    }while(opcion!=5);
}
void Usuarios::ingresarUsuario()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------Ingresar Usuario---------------------------"<<endl;
	cout<<"\n\t\t\tIngresa el nombre de Usuario: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa la contraseña: ";
	cin>>contrasena;
	file.open("Usuarios.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
	file.close();
}
void Usuarios::modificarUsuario()
{
	system("cls");
	fstream file,file1;
	string name, c2;
	int found=0, opcion;
	cout<<"\n-------------------------Modificar Usuario-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	cout<<"\n Ingrese su nombre de usuario: ";
    cin>>name;
    cout<<" Ingrese la contraseña: ";
    cin>>c2;
    file1.open("Record.txt",ios::app | ios::out);
    file >> nombre >> contrasena;
    while(!file.eof())
    {
        if(name!=nombre && c2!=contrasena){
         file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
        }
        else{
            cout << "\n\tQue desea modificar?" << endl;
            cout << "\t1. Usuario" << endl;
            cout << "\t2. Contraseña" << endl;
            cout << "\tIngrese una opcion" << endl;
            cin >> opcion;
            if (opcion == 1){
                cout<<"\n Ingrese su nombre de usuario: ";
                cin>>nombre;
                file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
                nombreUsuario = nombre;
                found++;
            }
            else{
                if (opcion == 2){
                    cout<<" Ingrese la contrasena: ";
                    cin>>contrasena;
                    contra = contrasena;
                }
            file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
            found++;
            }
        }
        file >> nombre >> contrasena;
    }
    if(found==0)
    {
        cout<<"\n\t\t\t Usuario no encontrado...";
    }
    file1.close();
    file.close();
    remove("Usuarios.txt");
    rename("Record.txt","Usuarios.txt");
}
void Usuarios::imprimirUsuario()
{
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Imprimir Usuarios-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre: "<<nombre<<endl;
			cout<<"\t\t\t Contrasena: "<<contrasena<<endl;
			file >> nombre >> contrasena;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	system("pause");
	file.close();
}

void Usuarios::borrarUsuario()
{
	system("cls");
	fstream file,file1;
	string nombre2, contra2;
	int found=0;
	cout<<"\n-------------------------Borrar Usuario-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el usuario para borrar: ";
		cin>>nombre2;
		cout<<" Ingrese la contrasena: ";
		cin>>contra2;
		file1.open("Record.txt",ios::app | ios::out);
		file >> nombre >> contrasena;
		while(!file.eof())
		{
			if(nombre2!= nombre && contra2 != contrasena)
			{
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< contrasena<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de Usuario exitoso";
			}
			file >> nombre >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Usuario no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
		exit(0);
	}
}
