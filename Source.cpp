#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
using namespace std;


int main() {
	ifstream arch("cien.txt");
	string palabra;
	int op;
	Grafo<string> g;
	//g.insertar(0, new string("hello"));
	//g.mostrar();

	do {
		cout << "GRAFO::Martes" << endl;
		cout << "1. Cargar Archi" << endl;
		cout << "2. Insertar Arista" << endl;
		cout << "3. MostrarPadres" << endl;
		cout << "4. Mostrar Grafo" << endl;
		cout << "5. Iniciar MARCA = false y Padre = -1" << endl;
		cout << "6. BFS" << endl;
		cout << "7. DFS" << endl;
		cin >> op;
		
		switch (op)
		{
		case 1:
			if (arch.fail()) {
				cout << "no se encontro el archivo....";
				cin >> palabra;
			}
			else {
				while (!arch.eof())
				{
					arch >> palabra;
					g.insertar(0, new string(palabra));
				}
				arch.close();
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			g.mostrar();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}		
	} while (op != 0);

	return 0;
}
/*
if (arch.fail()) {
				cout << "no se encontro el archivo....";
				cin >> palabra;
			}
			else {
				while (!arch.eof())
				{
					arch >> palabra;
					g.insertar(0,new string(palabra));
				}
				arch.close();
			}
*/