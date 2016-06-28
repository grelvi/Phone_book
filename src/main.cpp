#include <iostream>
#include <fstream>
#include <string>
#include "Contacto.h"

#define Cantidad 3

using namespace std;

int main()
{
	Contacto C1[Cantidad];
	Contacto C2[Cantidad];

	int Menu;
	char nombre[Limite];
	double numero;
	int posicion;

	Contacto *Lista = new Contacto [Cantidad];

	do
	{
	cout<<"Menu"<<endl;
	cout<<"\n#1 Agregar"<<endl;
	cout<<"\n#2 Modificar"<<endl;
	cout<<"\n#3 Eliminar"<<endl;
	cout<<"\n#4 Listar Contactos"<<endl;
	cout<<"\n#5 Salir"<<endl;
	cout<<"\nOpcion: #";
	cin>>Menu;

	switch (Menu)
	{

	default:
		{
			cout<<"\nOpcion Incorrecta"<<endl;

			cout<<endl;
			system("Pause");
			system("cls");

			break;
		}

	case 1:
		{
			cout<<"\n#1 Agregar"<<endl;

			for(int i = 0; i < Cantidad; i++)
			{
				cout<<"\nNombre #"<<i+1<<": ";
				cin>>nombre;
				cout<<"\nNumero: #"<<i+1<<": ";
				cin>>numero;

				strcpy(C1[i].Nombre, nombre);

				C1[i].Numero= numero;
			}

			ofstream ofs("Fichero.rob", ios::binary);
			ofs.write((char *)&C1, sizeof(C1));
			ofs.close();

			cout<<"\nSe ha agregado"<<endl;

			cout<<endl;
			system("Pause");
			system("cls");

			break;
		}

	case 2:
		{
			cout<<"\n#2 Modificar"<<endl;

			do
			{
				cout<<"\nEliga la posicion: ";
				cin>>posicion;
			
				if(posicion<1 || posicion>Cantidad)
				{
					cout<<"\nLa posicion no exite"<<endl;
				}

			}
			while(posicion<1 || posicion>Cantidad);

			cout<<"\nNombre: #"<<posicion<<": ";
			cin>>nombre;
			cout<<"\nNumero: #"<<posicion<<": ";
			cin>>numero;

			strcpy(C1[posicion-1].Nombre, nombre);

			C1[posicion-1].Numero= numero;			

			ofstream ofs("Fichero.rob", ios::binary);
			ofs.write((char *)&C1, sizeof(C1));
			ofs.close();

			cout<<"\nSe ha modificado"<<endl;

			cout<<endl;
			system("Pause");
			system("cls");

			break;
		}

	case 3:
		{
			cout<<"\n#3 Eliminar"<<endl;
			
			cout<<"\nEliga la posicion: ";
			cin>>posicion;

			strcpy(C1[posicion].Nombre, "");

			C1[posicion].Numero= 0;			

			ofstream ofs("Fichero.rob", ios::binary);
			ofs.write((char *)&C1, sizeof(C1));
			ofs.close();

			cout<<"\nSe ha eliminado"<<endl;

			cout<<endl;
			system("Pause");
			system("cls");

			break;
		}

	case 4:
		{
			cout<<"\n#4 Listar Contactos"<<endl;
			
			ifstream ifs("Fichero.rob", ios::binary);
			ifs.read((char *)&C2, sizeof(C2));

			for(int i=0; i<Cantidad; i++)
			{
				cout << "\nNombre #"<< i+1 <<": " << C2[i].Nombre << endl;

				cout << "\nNumero #"<< i+1 <<": "<< C2[i].Numero << endl;
			}

			ifs.close();

			cout<<endl;
			system("Pause");
			system("cls");

			break;
		}

	case 5:
		{
			cout<<"\n#5 Salir"<<endl;
			return 0;
		}
	}

	}
	while(Menu!=5);
}