//declaración de Librerías
#include <iostream>
#include <stdlib.h>

using namespace std;

//declaramos matriz cine. 
char cine[10][10]; //O=asiento vacío X = asiento ocupado
//declaramos variables de fila y columna para insertar o revisar asientos.
int fila, columna;
char area;
int b = 0;//bandera para llenar la matriz sólo una vez al iniciar el programa
/*
 Área A       Área B
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O
O O O O O|  |O O O O O

*/
//función para consultar datos.
void consultar(char area, int fila)
{
	int fs = 0;//bandera para contar sientos disponibles (Ni no hubiera ningun imprimirá la palabra ninguno
	if (area == 'A' || area == 'a')
	{
		cout << "Asientos Disponibles: ";
		for (int i = 0; i < 5; i++)
		{
			if (cine[fila][i] == 'O')
			{
				cout << i+1<<", ";//i+1 por el -1 de allá abajo.
				fs++;
			}
		}
		if (fs == 0)
			cout << "Ninguno";
		else
			cout << endl;
	}
	if (area == 'B' || area == 'b')
	{
		cout << "Asientos Disponibles: ";
		for (int i = 5; i < 10; i++)
		{
			if (cine[fila][i] == 'O')
			{
				cout << i + 1 << ", ";//i+1 por el -1 de allá abajo.
				fs++;
			}
		}
		if (fs == 0)
			cout << "Ninguno";
		else
			cout << endl;
	}
	
}
//función para mostrar matriz
void mostrarmatriz()
{
	cout << "No.  Area A       Area B\n";
	for (int i = 0; i < 10; i++)
	{
		if(i ==9)
			cout << i + 1 << " -";
		else
		cout << i+1 << " - ";

		for (int j = 0; j < 10; j++)
		{
			if(j!=4)
				cout<<cine[i][j] <<" ";
			if (j == 4)
				cout << cine[i][j] << "|  |";
		}
		cout << endl;
	}
}
//Funcion principal
int main()
{
	//limpia la pantalla y vuelve a escribir el menú de inicio
	system("cls");
	//llenamos la matriz 1 vez 
	if (b == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cine[i][j] = 'O';
			}
		}
		b = 1;//le asignamos el valor a b como 1 para que no vuelva a entrar a esta condiicon
	}
	//mostrarmatriz();

	
	//Creación del menú principal de bienvenida y selección de opción
	int opc;
	cout << "********** TEATRO *************\n\n\n";
	cout << "Escoge una de las siguientes opciones: ";
	cout << "\n1. Reservar un asiento. ";
	cout << "\n2. Consultar Disponibilidad de Asientos.";
	cout << "\n3. Cancelar una reservacion.  ";
	cout << "\n0. Salir:  ";
	cin >> opc; //leemos la variable opc
	//menú de acciones
	switch (opc)
	{
	case 1: 
		
		cout << "Ingresa el area (A o B): ";
		cin >> area;
		cout << "Ingresa la Fila (1-10): ";
		cin >> fila;
		consultar(area, (fila-1)); //fila -1 porque se empieza a contar en 0, pero los humanos promedio empiezan a contar en 1
		cout << "Selecciona Asiento: ";
		cin >> columna;
		//esta condición es sólo para que no agregen un asiento que no esté en el área.
		if (area == 'A' && columna > 5)
		{
			cout << "Debe seleccionar un asiento que este en el erea A\n";
			cout << "Selecciona Asiento: ";
			cin >> columna;
		}
		else if (area == 'B' && columna < 6)
		{
			cout << "Debe seleccionar un asiento que este en el area B\n";
			cout << "Selecciona Asiento: ";
			cin >> columna;
		}
		//validacion extra para no reservar uno ya reservado
		if (cine[fila - 1][columna - 1] == 'X')
			cout << "Asiento no disponible, seleccione otro\n";
		else
			cine[fila-1][columna-1] = 'X'; //lo mismo con columna -1
		cout << "Reservación Exitosa\n";
		break;
	case 2:
		cout << "\n\nAsientos Disponibles: O\n";
		cout << "Asientos Ocupados: X\n\n";
		mostrarmatriz();
		break;
	case 3:
		cout << "Ingresa el area (A o B): ";
		cin >> area;
		cout << "Ingresa la Fila (1-10): ";
		cin >> fila;
		consultar(area, (fila - 1)); //fila -1 porque se empieza a contar en 0, pero los humanos promedio empiezan a contar en 1
		cout << "Selecciona Asiento: ";
		cin >> columna;
		//esta condición es sólo para que no agregen un asiento que no esté en el área.
		if (area == 'A' && columna > 5)
		{
			cout << "Debe seleccionar un asiento que este en el area A\n";
			cout << "Selecciona Asiento: ";
			cin >> columna;
		}
		else if (area == 'B' && columna < 6)
		{
			cout << "Debe seleccionar un asiento que este en el area B\n";
			cout << "Selecciona Asiento: ";
			cin >> columna;
		}
		cine[fila - 1][columna - 1] = 'O'; //lo mismo con columna -1
		cout << "Reservacion Cancelada\n";
		break;
	case 0:
		exit(0);
		break;


	default:
		cout << "Ingrese una opcion valida";
		break;
	}
	system("pause");
	main();//vuelve recursivo el programa, no se cierra a menos que uno presione 0 en el menú
	system("pause");
	return 0;
}